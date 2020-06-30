#if !defined(KEYBOARD_H)
#define KEYBOARD_H

#include "system.h"
#include "types.h"
#include "string.h"
#include "video.h"

char scanCodeToASCII(uint8 scanCode)
{
    char ascii;
    switch (scanCode)
    {
    case 1:
        ascii = 0x27; // '

    case 2:
        ascii = 0x30; // 1
    case 3:
        ascii = 0x31; // 2
    case 4:
        ascii = 0x32; // 3
    case 5:
        ascii = 0x33; // 4
    case 6:
        ascii = 0x34; // 5
    case 7:
        ascii = 0x35; // 6
    case 8:
        ascii = 0x36; // 7
    case 9:
        ascii = 0x37; // 8
    case 10:
        ascii = 0x38; // 9
    case 11:
        ascii = 0x39; // 0

    case 17:
        ascii = 0x71; // q
    case 18:
        ascii = 0x77; // w
    case 19:
        ascii = 0x65; // e
    case 20:
        ascii = 0x72; // r
    case 21:
        ascii = 0x74; // t
    case 22:
        ascii = 0x79; // y
    case 23:
        ascii = 0x75; // u
    case 24:
        ascii = 0x69; // i
    case 25:
        ascii = 0x6F; // o
    case 26:
        ascii = 0x70; // p

    case 31:
        ascii = 0x61; // a
    case 32:
        ascii = 0x73; // s
    case 33:
        ascii = 0x64; // d
    case 34:
        ascii = 0x66; // f
    case 35:
        ascii = 0x67; // g
    case 36:
        ascii = 0x68; // h
    case 37:
        ascii = 0x6A; // j
    case 38:
        ascii = 0x6B; // k
    case 39:
        ascii = 0x6C; // l
    default:
        ascii = 0x0;
    }

    return ascii;
}

char readChar(uint8 interactive)
{
    if (inportb(0x64) & 0x1)
    {
        if (interactive)
        {
            clearScreen();
            //print((string)scanCodeToASCII(inportb(0x60)), makeColor(COLOR_WHITE, COLOR_BLACK));
        }
        return scanCodeToASCII(inportb(0x60));
    }
}

#endif // KEYBOARD_H
