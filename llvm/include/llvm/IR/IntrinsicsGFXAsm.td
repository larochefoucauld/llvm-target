let TargetPrefix = "gfxasm" in {

  def int_gfxasm_clear: ClangBuiltin<"gfxasm_clear">,
    Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

  def int_gfxasm_flush: ClangBuiltin<"gfxasm_flush">,
    Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
 
  def int_gfxasm_putpixel: ClangBuiltin<"gfxasm_put_pixel">,
    Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
  def int_gfxasm_rand: ClangBuiltin<"gfxasm_rand">,
    Intrinsic<[llvm_i32_ty], [llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
} // TargetPrefix = "gfxasm"
