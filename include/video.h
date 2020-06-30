#if !defined(VIDEO_H)
#define VIDEO_H

#include "types.h"
#include "string.h"
#include "system.h"

uint8 cursorX, cursorY = 0;
const uint8 sw = 80, sh = 25, sd = 2;
const string vidmem = (string)0xb8000;

void clearScreen()
{
    for (uint8 y = 0; y < sh; y++)
    {
        for (uint8 x = 0; x < sw; x++)
        {
            vidmem[(x + sw * y) * sd] = 0x0;
        }
    }
}

void updateCursor()
{
    unsigned temp;

    temp = cursorY * sw + cursorX; // Position = (y * width) +  x

    outportb(0x3D4, 14);        // CRT Control Register: Select Cursor Location
    outportb(0x3D5, temp >> 8); // Send the high byte across the bus
    outportb(0x3D4, 15);        // CRT Control Register: Select Send Low byte
    outportb(0x3D5, temp);      // Send the Low byte of the cursor location
}

void updateCursorByPos(uint8 x, uint8 y)
{
    cursorX = x;
    cursorY = y;
    updateCursor();
}

void print(string str, VGAColor color)
{
    uint16 i = 0;
    while (str[i] != '\0')
    {
        vidmem[sd * i] = str[i];
        vidmem[sd * i + 1] = color;
        i++;
    }
}

void initialize()
{
    clearScreen();
    updateCursor();
}

VGAColor makeColor(enum VGA_COLORS fg, enum VGA_COLORS bg)
{
    VGAColor color = 0x0;
    color = fg | bg << 4;
    return color;
}

#endif // VIDEO_H
