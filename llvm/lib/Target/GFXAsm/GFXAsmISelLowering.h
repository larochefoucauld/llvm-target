#ifndef LLVM_LIB_TARGET_GFXASM_GFXASMISELLOWERING_H
#define LLVM_LIB_TARGET_GFXASM_GFXASMISELLOWERING_H

#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

#include "GFXAsm.h"

namespace llvm {

class GFXAsmSubtarget;
class GFXAsmTargetMachine;

namespace GFXAsmISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace GFXAsmISD

class GFXAsmTargetLowering : public TargetLowering {
public:
  explicit GFXAsmTargetLowering(const TargetMachine &TM,
                                const GFXAsmSubtarget &STI);

  /// This method returns the name of a target specific DAG node.
  const char *getTargetNodeName(unsigned Opcode) const override;

  GFXAsmSubtarget const &getSubtarget() const { return STI; }

private:
  const GFXAsmSubtarget &STI;
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_GFXASM_GFXASMISELLOWERING_H
