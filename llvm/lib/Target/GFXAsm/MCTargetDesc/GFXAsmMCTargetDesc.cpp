#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

#include "GFXAsm.h"
#include "GFXAsmInfo.h"
#include "TargetInfo/GFXAsmTargetInfo.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "GFXAsmGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "GFXAsmGenInstrInfo.inc"

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

// We need to define this function for linking to succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGFXAsmTargetMC() {
  GFXASM_DUMP_MAGENTA
  Target &TheGfxAsmTarget = getTheGFXAsmTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheGfxAsmTarget,
                                    createGFXAsmMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheGfxAsmTarget, createGFXAsmMCInstrInfo);
}
