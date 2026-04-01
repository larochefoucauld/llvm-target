include "llvm/Target/Target.td"

include "GFXAsmRegisterInfo.td"
include "GFXAsmInstrInfo.td"
include "GFXAsmCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def GFXAsmInstrInfo : InstrInfo;
def GFXAsm : Target {
  let InstructionSet = GFXAsmInstrInfo;
}
