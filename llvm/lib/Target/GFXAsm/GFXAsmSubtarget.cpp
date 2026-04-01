#include "llvm/Target/TargetMachine.h"

#include "GFXAsm.h"
#include "GFXAsmSubtarget.h"

using namespace llvm;

#define DEBUG_TYPE "gfxasm-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "GFXAsmGenSubtargetInfo.inc"

GFXAsmSubtarget::GFXAsmSubtarget(const Triple &TT, const std::string &CPU,
                                 const std::string &FS, const TargetMachine &TM)
    : GFXAsmGenSubtargetInfo(TT, CPU, CPU, FS), TLInfo(TM, *this),
      FrameLowering(*this) {
  GFXASM_DUMP_CYAN
}
