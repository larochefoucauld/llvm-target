#ifndef LLVM_LIB_TARGET_GFXASM_MCTARGETDESC_GFXASMMCTARGETDESC_H
#define LLVM_LIB_TARGET_GFXASM_MCTARGETDESC_GFXASMMCTARGETDESC_H

// Defines symbolic names for GFXAsm registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "GFXAsmGenRegisterInfo.inc"

// Defines symbolic names for the GFXAsm instructions.
#define GET_INSTRINFO_ENUM
#include "GFXAsmGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_GFXASM_MCTARGETDESC_GFXASMMCTARGETDESC_H
