#ifndef LLVM_LIB_TARGET_GFXASM_GFXASM_H
#define LLVM_LIB_TARGET_GFXASM_GFXASM_H

#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#include "MCTargetDesc/GFXAsmMCTargetDesc.h"

#define GFXASM_DUMP_ENABLE

#ifdef GFXASM_DUMP_ENABLE
#define GFXASM_DUMP(Color)                                                     \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
#else
#define GFXASM_DUMP(Color)
#endif

#define GFXASM_DUMP_RED GFXASM_DUMP(llvm::raw_ostream::RED)
#define GFXASM_DUMP_GREEN GFXASM_DUMP(llvm::raw_ostream::GREEN)
#define GFXASM_DUMP_YELLOW GFXASM_DUMP(llvm::raw_ostream::YELLOW)
#define GFXASM_DUMP_CYAN GFXASM_DUMP(llvm::raw_ostream::CYAN)
#define GFXASM_DUMP_MAGENTA GFXASM_DUMP(llvm::raw_ostream::MAGENTA)
#define GFXASM_DUMP_WHITE GFXASM_DUMP(llvm::raw_ostream::WHITE)

namespace llvm {

class GFXAsmTargetMachine;
class FunctionPass;
class GFXAsmSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerGFXAsmMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                     AsmPrinter &AP);
bool LowerGFXAsmMachineOperandToMCOperand(const MachineOperand &MO,
                                          MCOperand &MCOp,
                                          const AsmPrinter &AP);

FunctionPass *createGFXAsmISelDag(GFXAsmTargetMachine &TM,
                                  CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_GFXASM_GFXASM_H
