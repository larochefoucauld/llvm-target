add_llvm_component_group(GFXAsm)

set(LLVM_TARGET_DEFINITIONS GFXAsm.td)

tablegen(LLVM GFXAsmGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM GFXAsmGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM GFXAsmGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM GFXAsmGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM GFXAsmGenDAGISel.inc -gen-dag-isel)

add_public_tablegen_target(GFXAsmCommonTableGen)

add_llvm_target(GFXAsmCodeGen
  GFXAsmTargetMachine.cpp
  GFXAsmRegisterInfo.cpp
  GFXAsmInstrInfo.cpp
  GFXAsmSubtarget.cpp
  GFXAsmAsmPrinter.cpp
  GFXAsmISelDagToDag.cpp
  GFXAsmISelLowering.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  GFXAsmInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  GFXAsm
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
