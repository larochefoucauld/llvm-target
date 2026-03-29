add_llvm_component_library(LLVMGFXAsmDesc
  GFXAsmMCTargetDesc.cpp
  GFXAsmMCAsmInfo.cpp

  LINK_COMPONENTS
  MC
  Support
  GFXAsmInfo

  ADD_TO_COMPONENT
  GFXAsm
)
