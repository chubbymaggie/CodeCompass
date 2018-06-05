#ifndef CC_MODEL_MACROEXPANSION_H
#define CC_MODEL_MACROEXPANSION_H

#include <string>
#include <memory>

#include <odb/core.hxx>
#include <odb/lazy-ptr.hxx>

#include "cppastnode.h"

namespace cc
{
namespace model
{

#pragma db object
struct CppMacroExpansion
{
  #pragma db id auto
  int id;

  // #pragma db unique
  #pragma db not_null
  CppAstNodeId astNodeId;

  std::string expansion;

  std::string toString() const
  {
    std::string ret("CppMacroExpansion");

    ret
      .append("\nid = ").append(std::to_string(id))
      .append("\nexpansion = ").append(expansion)
      .append("\nastNodeId = ").append(std::to_string(astNodeId));

    return ret;
  }
};

typedef std::shared_ptr<CppMacroExpansion> CppMacroExpansionPtr;

#pragma db view object(CppMacroExpansion)
struct CppMacroExpansionCount
{
  #pragma db column("count(" + CppMacroExpansion::id + ")")
  std::size_t count;
};

} // model
} // cc

#endif //CC_MODEL_MACROEXPANSION_H
