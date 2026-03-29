#ifndef LLVM_LIB_TARGET_GFXASM_GFXASMREGISTERINFO_H
#define LLVM_LIB_TARGET_GFXASM_GFXASMREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "GFXAsmGenRegisterInfo.inc"

namespace llvm {

struct GFXAsmRegisterInfo : public GFXAsmGenRegisterInfo {
public:
  GFXAsmRegisterInfo();
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_GFXASM_GFXASMREGISTERINFO_H
