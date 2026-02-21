#include "../GFXAsm.h"
#include "llvm/Support/raw_ostream.h"

// We need to define this function for linking to succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGFXAsmTargetMC() { GFXASM_DUMP_MAGENTA }
