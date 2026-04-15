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
  let EncoderMethod = "getSImm16OpValue";
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

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1, r2 = 0, r3_imm = 0 in
def BR : GFXAsmInst<0xBB, (outs), (ins GPR:$r1), "BR $r1",
                  [(brind GPR:$r1)]>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET : GFXAsmPseudoInst<(outs), (ins), "# PseudoRET",
                [(gfxasm_ret)]>,
                PseudoInstExpansion<(BR R0)>;

let isAsCheapAsAMove = 1, isCodeGenOnly = 1, isReMaterializable = 1, r2 = 0 in
def MOVi : GFXAsmInst<0xAA, (outs GPR:$r1), (ins simm16:$r3_imm),
                     "MOVi $r1 $r3_imm",
                     [(set GPR:$r1, simm16:$r3_imm)]>;

let r1 = 0, r2 = 0, r3_imm = 0 in
def CLEAR : GFXAsmInst<0xFF, (outs), (ins), "CLEAR", [(int_gfxasm_clear)]>;

let r1 = 0, r2 = 0, r3_imm = 0 in
def FLUSH : GFXAsmInst<0xFE, (outs), (ins), "FLUSH", [(int_gfxasm_flush)]>;

def PUTPIXEL : GFXAsmInst<0xFD, (outs), (ins GPR:$r1, GPR:$r2, GPR:$r3_imm),
                      "PUTPIXEL $r1 $r2 $r3_imm", [(int_gfxasm_putpixel GPR:$r1, GPR:$r2, GPR:$r3_imm)]>;
let r3_imm = 0 in
def RAND : GFXAsmInst<0xFC, (outs GPR:$r1), (ins GPR:$r2),
                      "RAND $r1 $r2", [(set GPR:$r1, (int_gfxasm_rand GPR:$r2))]>;

let r2 = 0 in
def RANDi : GFXAsmInst<0xFB, (outs GPR:$r1), (ins simm16:$r3_imm), "RANDi $r1, $r3_imm", 
                      [(set GPR:$r1, (int_gfxasm_rand simm16:$r3_imm))]>;
