#include "llvm/CodeGen/TargetInstrInfo.h"

#include "GFXAsm.h"
#include "GFXAsmFrameLowering.h"
#include "GFXAsmRegisterInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "GFXAsmGenRegisterInfo.inc"

GFXAsmRegisterInfo::GFXAsmRegisterInfo() : GFXAsmGenRegisterInfo(GFXAsm::R0) {
  GFXASM_DUMP_GREEN
}
