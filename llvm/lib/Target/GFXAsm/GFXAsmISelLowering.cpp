#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#include "GFXAsm.h"
#include "GFXAsmISelLowering.h"
#include "GFXAsmRegisterInfo.h"
#include "GFXAsmSubtarget.h"

#define DEBUG_TYPE "gfxasm-lower"

using namespace llvm;

GFXAsmTargetLowering::GFXAsmTargetLowering(const TargetMachine &TM,
                                           const GFXAsmSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  GFXASM_DUMP_RED
  addRegisterClass(MVT::i32, &GFXAsm::GPRRegClass);
}

const char *GFXAsmTargetLowering::getTargetNodeName(unsigned Opcode) const {
  GFXASM_DUMP_RED
  switch (Opcode) {
  case GFXAsmISD::CALL:
    return "GFXAsmISD::CALL";
  case GFXAsmISD::RET:
    return "GFXAsmISD::RET";
  }
  return nullptr;
}
