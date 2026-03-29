#ifndef LLVM_LIB_TARGET_GFXASM_MCTARGETDESC_GFXASMMCASMINFO_H
#define LLVM_LIB_TARGET_GFXASM_MCTARGETDESC_GFXASMMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class GFXAsmELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit GFXAsmELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_GFXASM_MCTARGETDESC_GFXASMMCASMINFO_H
