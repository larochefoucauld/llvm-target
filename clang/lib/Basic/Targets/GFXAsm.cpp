#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"

#include "GFXAsm.h"

using namespace clang;
using namespace clang::targets;

void GFXAsmTargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Builder.defineMacro("__gfxasm__");
}

ArrayRef<Builtin::Info> GFXAsmTargetInfo::getTargetBuiltins() const {
  return std::nullopt;
}
