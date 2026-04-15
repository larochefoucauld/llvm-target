#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"
#include "clang/Basic/TargetBuiltins.h"

#include "GFXAsm.h"

using namespace clang;
using namespace clang::targets;


static constexpr Builtin::Info BuiltinInfo[] = {
#define BUILTIN(ID, TYPE, ATTRS)                                               \
  {#ID, TYPE, ATTRS, nullptr, HeaderDesc::NO_HEADER, ALL_LANGUAGES},
#include "clang/Basic/BuiltinsGFXAsm.def"
};

void GFXAsmTargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Builder.defineMacro("__gfxasm__");
}

ArrayRef<Builtin::Info> GFXAsmTargetInfo::getTargetBuiltins() const {
   return llvm::ArrayRef(BuiltinInfo,
                        clang::GFXAsm::LastTSBuiltin - Builtin::FirstTSBuiltin);
}
