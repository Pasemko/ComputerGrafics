//
// Created by apasemko on 4/16/2022.
//

#ifndef COMPUTERGRAPHICS_WMHOLDER_H
#define COMPUTERGRAPHICS_WMHOLDER_H

#include "WindowManager.h"
#include <memory>


class WMHolder
{
public:
    using WindowManagerPtr = std::shared_ptr<WindowManager>;

public:
    virtual ~WMHolder() = default;
    virtual WindowManagerPtr createWM() const = 0;
    void init();

public:
    WindowManagerPtr window_manager_ptr;

    const WindowManagerPtr &get_window_manager_ptr() const;
};


#endif //COMPUTERGRAPHICS_WMHOLDER_H
