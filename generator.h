#pragma once

#include "context.h"

namespace wis {
class Generator
{
public:
    void GenerateHandleTraits(const Context& context, std::ostream& stream);
    void GenerateMovableHandles(const Context& context, std::ostream& stream);
    void GenerateLoader(const Context& context, std::ostream& stream);
};
}