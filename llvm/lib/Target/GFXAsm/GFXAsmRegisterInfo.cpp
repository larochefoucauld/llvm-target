#include "llvm/CodeGen/TargetInstrInfo.h"

#include "GFXAsm.h"
#include "GFXAsmFrameLowering.h"
#include "GFXAsmRegisterInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "GFXAsmGenRegisterInfo.inc"

GFXAsmRegisterInfo::GFXAsmRegisterInfo() : GFXAsmGenRegisterInfo(GFXAsm::R0) {
  GFXASM_DUMP_GREEN
}

const MCPhysReg *
GFXAsmRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  GFXASM_DUMP_GREEN
  return CSR_GFXAsm_SaveList;
}

BitVector GFXAsmRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  GFXASM_DUMP_GREEN
  GFXAsmFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(GFXAsm::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(GFXAsm::R2);
  }
  return Reserved;
}

bool GFXAsmRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool GFXAsmRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                             int SPAdj, unsigned FIOperandNum,
                                             RegScavenger *RS) const {
  GFXASM_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register GFXAsmRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  GFXASM_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? GFXAsm::R2 : GFXAsm::R1;
}

const uint32_t *
GFXAsmRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                         CallingConv::ID CC) const {
  GFXASM_DUMP_GREEN
  return CSR_GFXAsm_RegMask;
}
