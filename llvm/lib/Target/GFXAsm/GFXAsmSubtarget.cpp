#include "llvm/Target/TargetMachine.h"

#include "GFXAsm.h"
#include "GFXAsmSubtarget.h"

using namespace llvm;

#define DEBUG_TYPE "gfxasm-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "GFXAsmGenSubtargetInfo.inc"

GFXAsmSubtarget::GFXAsmSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                                 const StringRef &FS, const TargetMachine &TM)
    : GFXAsmGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  GFXASM_DUMP_CYAN
}
