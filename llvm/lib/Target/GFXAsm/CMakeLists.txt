add_llvm_component_group(GFXAsm)

add_llvm_target(GFXAsmCodeGen
  GFXAsmTargetMachine.cpp

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
