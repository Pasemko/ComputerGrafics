//
// Created by apasemko on 4/16/2022.
//

#include "WMHolder.h"


void WMHolder::init()
{
    window_manager_ptr = createWM();
}

const WMHolder::WindowManagerPtr &WMHolder::get_window_manager_ptr() const
{
    return window_manager_ptr;
}
