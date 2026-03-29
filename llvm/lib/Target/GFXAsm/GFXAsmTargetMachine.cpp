#include "GFXAsmTargetMachine.h"
#include "GFXAsm.h"

#include "TargetInfo/GFXAsmTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGFXAsmTarget() {
  // Register the target.
  GFXASM_DUMP_CYAN
  RegisterTargetMachine<GFXAsmTargetMachine> A(getTheGFXAsmTarget());
}

GFXAsmTargetMachine::GFXAsmTargetMachine(const Target &T, const Triple &TT,
                                         StringRef CPU, StringRef FS,
                                         const TargetOptions &Options,
                                         std::optional<Reloc::Model> RM,
                                         std::optional<CodeModel::Model> CM,
                                         CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(
          T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32", TT, CPU, FS, Options,
          Reloc::Static, getEffectiveCodeModel(CM, CodeModel::Small), OL) {
  GFXASM_DUMP_CYAN
  initAsmInfo();
}
