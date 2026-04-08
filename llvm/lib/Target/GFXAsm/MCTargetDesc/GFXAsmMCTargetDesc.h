#ifndef LLVM_LIB_TARGET_GFXASM_MCTARGETDESC_GFXASMMCTARGETDESC_H
#define LLVM_LIB_TARGET_GFXASM_MCTARGETDESC_GFXASMMCTARGETDESC_H

#include <memory>

namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createGFXAsmMCCodeEmitter(const MCInstrInfo &MCII,
                                         MCContext &Ctx);
MCAsmBackend *createGFXAsmAsmBackend(const Target &T,
                                     const MCSubtargetInfo &STI,
                                     const MCRegisterInfo &MRI,
                                     const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter>
createGFXAsmELFObjectWriter(bool Is64Bit, uint8_t OSABI);
} // namespace llvm

// Defines symbolic names for GFXAsm registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "GFXAsmGenRegisterInfo.inc"

// Defines symbolic names for the GFXAsm instructions.
#define GET_INSTRINFO_ENUM
#include "GFXAsmGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_GFXASM_MCTARGETDESC_GFXASMMCTARGETDESC_H
