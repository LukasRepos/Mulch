#if !defined(System_H)
#define System_H

#include "types.h"

uint8 inportb(uint16 _port)
{
    uint8 rv;
    __asm__ __volatile__("inb %1, %0"
                         : "=a"(rv)
                         : "dN"(_port)); // connect to a port and return its value
    return rv;
}

void outportb(uint16 _port, uint8 _data)
{
    __asm__ __volatile__("outb %1, %0"
                         :
                         : "dN"(_port), "a"(_data)); // connect to a port and write into it
}

#endif // System_H
