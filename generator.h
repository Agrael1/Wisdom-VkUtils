#pragma once

#include "context.h"

namespace wis {
class Generator
{
public:
    void GenerateHandleTraits(const Context& context, std::ostream& stream);

private:
    static std::string MakeHandleTraits(const Context& context);
    static std::string MakeHandleTrait(const Handle& handle);
};
}