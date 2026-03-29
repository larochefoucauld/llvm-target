#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

#include "GFXAsm.h"
#include "GFXAsmInfo.h"
#include "GFXAsmMCAsmInfo.h"
#include "TargetInfo/GFXAsmTargetInfo.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "GFXAsmGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "GFXAsmGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "GFXAsmGenSubtargetInfo.inc"

static MCRegisterInfo *createGFXAsmMCRegisterInfo(const Triple &TT) {
  GFXASM_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitGFXAsmMCRegisterInfo(X, GFXAsm::R0);
  return X;
}

static MCInstrInfo *createGFXAsmMCInstrInfo() {
  GFXASM_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitGFXAsmMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *
createGFXAsmMCSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS) {
  GFXASM_DUMP_MAGENTA
  return createGFXAsmMCSubtargetInfoImpl(TT, CPU, CPU, FS);
}

static MCAsmInfo *createGFXAsmMCAsmInfo(const MCRegisterInfo &MRI,
                                        const Triple &TT,
                                        const MCTargetOptions &Options) {
  GFXASM_DUMP_MAGENTA
  MCAsmInfo *MAI = new GFXAsmELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(GFXAsm::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

// We need to define this function for linking to succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGFXAsmTargetMC() {
  GFXASM_DUMP_MAGENTA
  Target &TheGfxAsmTarget = getTheGFXAsmTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheGfxAsmTarget,
                                    createGFXAsmMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheGfxAsmTarget, createGFXAsmMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheGfxAsmTarget,
                                          createGFXAsmMCSubtargetInfo);
  // Register the MC asm info.
  RegisterMCAsmInfoFn X(TheGfxAsmTarget, createGFXAsmMCAsmInfo);
}
