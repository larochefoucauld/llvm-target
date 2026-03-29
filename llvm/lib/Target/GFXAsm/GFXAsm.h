#ifndef LLVM_LIB_TARGET_GFXASM_GFXASM_H
#define LLVM_LIB_TARGET_GFXASM_GFXASM_H

#include "MCTargetDesc/GFXAsmMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"

#define GFXASM_DUMP(Color)                                                     \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }

#define GFXASM_DUMP_RED GFXASM_DUMP(llvm::raw_ostream::RED)
#define GFXASM_DUMP_GREEN GFXASM_DUMP(llvm::raw_ostream::GREEN)
#define GFXASM_DUMP_YELLOW GFXASM_DUMP(llvm::raw_ostream::YELLOW)
#define GFXASM_DUMP_CYAN GFXASM_DUMP(llvm::raw_ostream::CYAN)
#define GFXASM_DUMP_MAGENTA GFXASM_DUMP(llvm::raw_ostream::MAGENTA)
#define GFXASM_DUMP_WHITE GFXASM_DUMP(llvm::raw_ostream::WHITE)

#endif // LLVM_LIB_TARGET_GFXASM_GFXASM_H
