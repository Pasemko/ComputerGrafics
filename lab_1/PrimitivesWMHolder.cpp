//
// Created by apasemko on 4/16/2022.
//

#include "PrimitivesWMHolder.h"

WMHolder::WindowManagerPtr PrimitivesWMHolder::createWM() const
{
    return std::make_shared<PrimitivesWM>();
}
