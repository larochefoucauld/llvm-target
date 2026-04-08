#include "llvm/ADT/STLExtras.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCValue.h"
#include "llvm/Support/ErrorHandling.h"

#include "GFXAsm.h"
#include "GFXAsmMCTargetDesc.h"

using namespace llvm;

namespace {
class GFXAsmELFObjectWriter : public MCELFObjectTargetWriter {
public:
  GFXAsmELFObjectWriter(bool Is64Bit, uint8_t OSABI)
      : MCELFObjectTargetWriter(Is64Bit, OSABI, ELF::EM_GFXASM, true) {}

  ~GFXAsmELFObjectWriter() override = default;

protected:
  unsigned getRelocType(MCContext &Ctx, const MCValue &Target,
                        const MCFixup &Fixup, bool IsPCRel) const override;

  bool needsRelocateWithSymbol(const MCValue &Val, const MCSymbol &Sym,
                               unsigned Type) const override;
};
} // namespace

unsigned GFXAsmELFObjectWriter::getRelocType(MCContext &Ctx,
                                             const MCValue &Target,
                                             const MCFixup &Fixup,
                                             bool IsPCRel) const {
  MCFixupKind Kind = Fixup.getKind();
  if (Kind >= FirstLiteralRelocationKind)
    return Kind - FirstLiteralRelocationKind;

  llvm_unreachable("Unimplemented fixup -> relocation");
}

bool GFXAsmELFObjectWriter::needsRelocateWithSymbol(const MCValue &,
                                                    const MCSymbol &,
                                                    unsigned Type) const {
  return false;
}

std::unique_ptr<MCObjectTargetWriter>
llvm::createGFXAsmELFObjectWriter(bool Is64Bit, uint8_t OSABI) {
  return std::make_unique<GFXAsmELFObjectWriter>(Is64Bit, OSABI);
}