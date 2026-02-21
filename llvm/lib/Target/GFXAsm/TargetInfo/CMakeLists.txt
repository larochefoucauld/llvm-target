add_llvm_component_library(LLVMGFXAsmInfo
  GFXAsmTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  GFXAsm
)
