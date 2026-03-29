//===----------------------------------------------------------------------===//
// GFXAsm profiles and nodes
//===----------------------------------------------------------------------===//

def gfxasm_ret      : SDNode<"GFXAsmISD::RET", SDTNone,
                            [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "GFXAsmInstrFormats.td"

//===----------------------------------------------------------------------===//
// GFXAsm Operand, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

class SImmAsmOperand<int width> : AsmOperandClass {
  let Name = "SImm" # width;
  let RenderMethod = "addImmOperands";
  let DiagnosticType = !strconcat("Invalid", Name);
}

def simm16 : Operand<i32>, ImmLeaf<i32, [{return isInt<16>(Imm);}]> {
  let ParserMatchClass = SImmAsmOperand<16>;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeSImmOperand<16>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isInt<16>(Imm);
    return MCOp.isBareSymbolRef();
  }];
  let OperandType = "OPERAND_SIMM16";
  let OperandNamespace = "GFXAsmOp";
}

//===----------------------------------------------------------------------===//
// GFXAsm Instructions
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1 in
def BR : GFXAsmInst<0x0, (outs), (ins GPR:$rs1), "br $rs1",
                  [(brind GPR:$rs1)]>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET : GFXAsmPseudoInst<(outs), (ins), "# PseudoRET",
                [(gfxasm_ret)]>,
                PseudoInstExpansion<(BR R0)>;

let isAsCheapAsAMove = 1, isCodeGenOnly = 1, isReMaterializable = 1 in
def MOV : GFXAsmInst<0x0, (outs GPR:$rd), (ins simm16:$imm),
                     "mov $rd $imm",
                     [(set GPR:$rd, simm16:$imm)]>;
