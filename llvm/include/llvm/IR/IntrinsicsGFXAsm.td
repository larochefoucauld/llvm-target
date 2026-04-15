let TargetPrefix = "gfxasm" in {

  def int_gfxasm_clear:
    Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

  def int_gfxasm_flush:
    Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
 
  def int_gfxasm_putpixel:
    Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
  def int_gfxasm_rand:
    Intrinsic<[llvm_i32_ty], [llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
} // TargetPrefix = "gfxasm"
