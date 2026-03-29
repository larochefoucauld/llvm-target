#ifndef LLVM_LIB_TARGET_GFXASM_INSTPRINTER_GFXASMINSTPRINTER_H
#define LLVM_LIB_TARGET_GFXASM_INSTPRINTER_GFXASMINSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCRegister.h"
#include "llvm/Support/ErrorHandling.h"

namespace llvm {

class GFXAsmInstPrinter : public MCInstPrinter {
public:
  GFXAsmInstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                    const MCRegisterInfo &MRI)
      : MCInstPrinter(MAI, MII, MRI) {}

  std::pair<const char *, uint64_t>
  getMnemonic(const MCInst &MI) const override {
    llvm_unreachable("GFXAsmInstPrinter::getMnemonic");
  }

  // Override MCInstPrinter.
  void printRegName(raw_ostream &O, MCRegister Reg) override {}
  void printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
                 const MCSubtargetInfo &STI, raw_ostream &O) override {}
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_GFXASM_INSTPRINTER_GFXASMINSTPRINTER_H
