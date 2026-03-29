#ifndef LLVM_LIB_TARGET_GFXASM_GFXASMTARGETMACHINE_H
#define LLVM_LIB_TARGET_GFXASM_GFXASMTARGETMACHINE_H

#include "GFXAsmSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheGFXAsmTarget;

class GFXAsmTargetMachine : public CodeGenTargetMachineImpl {
public:
  GFXAsmTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                      StringRef FS, const TargetOptions &Options,
                      std::optional<Reloc::Model> RM,
                      std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                      bool JIT);

  const GFXAsmSubtarget *getSubtargetImpl(const Function &) const override {
    GFXASM_DUMP_CYAN
    return &Subtarget;
  }

  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;

private:
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  GFXAsmSubtarget Subtarget;
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_GFXASM_GFXASMTARGETMACHINE_H
