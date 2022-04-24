//
// Created by apasemko on 4/23/2022.
//

#ifndef COMPUTERGRAPHICS_PRIMITIVESRASTERINGWMHOLDER_H
#define COMPUTERGRAPHICS_PRIMITIVESRASTERINGWMHOLDER_H

#include "../utils/WMHolder.h"
#include "PrimitivesRasteringWM.h"

class PrimitivesRasteringWMHolder :
        public WMHolder
{
public:
    WindowManagerPtr createWM() const override;
};


#endif //COMPUTERGRAPHICS_PRIMITIVESRASTERINGWMHOLDER_H
