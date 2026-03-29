#ifndef LLVM_LIB_TARGET_GFXASM_MCTARGETDESC_GFXASMINFO_H
#define LLVM_LIB_TARGET_GFXASM_MCTARGETDESC_GFXASMINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace GFXAsmOp {

enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};

} // namespace GFXAsmOp

} // namespace llvm

#endif // LLVM_LIB_TARGET_GFXASM_MCTARGETDESC_GFXASMINFO_H
