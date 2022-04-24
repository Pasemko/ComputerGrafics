//
// Created by apasemko on 4/23/2022.
//

#include "PrimitivesRasteringWMHolder.h"

WMHolder::WindowManagerPtr PrimitivesRasteringWMHolder::createWM() const
{
    return std::make_shared<PrimitivesRasteringWM>();
}
