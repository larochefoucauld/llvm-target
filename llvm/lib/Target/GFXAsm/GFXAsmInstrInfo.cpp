#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

#include "GFXAsm.h"
#include "GFXAsmInstrInfo.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "GFXAsmGenInstrInfo.inc"

#define DEBUG_TYPE "gfxasm-inst-info"

GFXAsmInstrInfo::GFXAsmInstrInfo() : GFXAsmGenInstrInfo() { GFXASM_DUMP_GREEN }
