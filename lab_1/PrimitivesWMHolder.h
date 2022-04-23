//
// Created by apasemko on 4/16/2022.
//

#ifndef COMPUTERGRAPHICS_PRIMITIVESWMHOLDER_H
#define COMPUTERGRAPHICS_PRIMITIVESWMHOLDER_H

#include "../util/WMHolder.h"
#include "PrimitivesWM.h"


class PrimitivesWMHolder :
        public WMHolder
{
public:
    WindowManagerPtr createWM() const override;
};


#endif //COMPUTERGRAPHICS_PRIMITIVESWMHOLDER_H
