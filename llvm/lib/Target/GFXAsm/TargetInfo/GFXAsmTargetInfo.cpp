#include "GFXAsmTargetInfo.h"
#include "../GFXAsm.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheGFXAsmTarget() {
  GFXASM_DUMP_YELLOW
  static Target TheGFXAsmTarget;
  return TheGFXAsmTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGFXAsmTargetInfo() {
  GFXASM_DUMP_YELLOW
  RegisterTarget<Triple::gfxasm> X(getTheGFXAsmTarget(), "gfxasm",
                                "Graphical assembly", "GFXASM");
}
