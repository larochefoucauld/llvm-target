#include "GFXAsm.h"
#include "TargetInfo/GFXAsmTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "GFXAsmGenRegisterInfo.inc"

static MCRegisterInfo *createGFXAsmMCRegisterInfo(const Triple &TT) {
  GFXASM_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitGFXAsmMCRegisterInfo(X, GFXAsm::R0);
  return X;
}

// We need to define this function for linking to succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGFXAsmTargetMC() {
  GFXASM_DUMP_MAGENTA
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(getTheGFXAsmTarget(),
                                    createGFXAsmMCRegisterInfo);
}
