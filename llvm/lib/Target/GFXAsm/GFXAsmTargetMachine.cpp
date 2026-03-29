#include <optional>

#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"

#include "GFXAsm.h"
#include "GFXAsmTargetMachine.h"
#include "TargetInfo/GFXAsmTargetInfo.h"

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
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()) {
  GFXASM_DUMP_CYAN
  initAsmInfo();
}

namespace {
/// GFXAsm Code Generator Pass Configuration Options.
class GFXAsmPassConfig : public TargetPassConfig {
public:
  GFXAsmPassConfig(GFXAsmTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  bool addInstSelector() override {
    GFXASM_DUMP_CYAN
    return false;
  }
};

} // namespace

TargetPassConfig *GFXAsmTargetMachine::createPassConfig(PassManagerBase &PM) {
  GFXASM_DUMP_CYAN
  return new GFXAsmPassConfig(*this, PM);
}

TargetLoweringObjectFile *GFXAsmTargetMachine::getObjFileLowering() const {
  GFXASM_DUMP_CYAN
  return TLOF.get();
}
