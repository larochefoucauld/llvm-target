#ifndef LLVM_LIB_TARGET_GFXASM_GFXASMINSTRINFO_H
#define LLVM_LIB_TARGET_GFXASM_GFXASMINSTRINFO_H

#include "llvm/CodeGen/TargetInstrInfo.h"

#include "GFXAsmRegisterInfo.h"
#include "MCTargetDesc/GFXAsmInfo.h"

#define GET_INSTRINFO_HEADER
#include "GFXAsmGenInstrInfo.inc"

namespace llvm {

class GFXAsmSubtarget;

class GFXAsmInstrInfo : public GFXAsmGenInstrInfo {
public:
  GFXAsmInstrInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_GFXASM_GFXASMINSTRINFO_H
