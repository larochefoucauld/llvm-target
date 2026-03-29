add_llvm_component_group(GFXAsm)

set(LLVM_TARGET_DEFINITIONS GFXAsm.td)
tablegen(LLVM GFXAsmGenRegisterInfo.inc -gen-register-info)
add_public_tablegen_target(GFXAsmCommonTableGen)

add_llvm_target(GFXAsmCodeGen
  GFXAsmTargetMachine.cpp
  GFXAsmRegisterInfo.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  GFXAsmInfo

  ADD_TO_COMPONENT
  GFXAsm
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
