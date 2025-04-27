#ifndef __DRIVER_MOUSEH
#define __DRIVER_MOUSEH

#include <basic.h>

typedef struct __mouse_mouse_input
{
    u8 button;
    i8 xmove;
    i8 ymove;
} MouseInput;


void EnableMouse();
MouseInput GetMouseInput();

#endif