//===- Core/AbsoluteAtom.h - An absolute Atom -----------------------------===//
//
//                             The LLVM Linker
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLD_CORE_ABSOLUTE_ATOM_H_
#define LLD_CORE_ABSOLUTE_ATOM_H_

#include "lld/Core/Atom.h"

namespace lld {

/// An AbsoluteAtom has no content.
/// It exists to represent content at fixed addresses in memory.
class AbsoluteAtom : public Atom {
public:
  virtual uint64_t value() const = 0;
  
  static inline bool classof(const Atom *a) {
    return a->definition() == definitionAbsolute;
  }
  static inline bool classof(const AbsoluteAtom *) { return true; }

protected:
  AbsoluteAtom() : Atom(definitionAbsolute) {}
  virtual ~AbsoluteAtom() {}
};

} // namespace lld

#endif // LLD_CORE_ABSOLUTE_ATOM_H_