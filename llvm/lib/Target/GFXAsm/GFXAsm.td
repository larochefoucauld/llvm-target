include "llvm/Target/Target.td"

include "GFXAsmRegisterInfo.td"
include "GFXAsmInstrInfo.td"

def GFXAsmInstrInfo : InstrInfo;
def GFXAsm : Target {
  let InstructionSet = GFXAsmInstrInfo;
}
