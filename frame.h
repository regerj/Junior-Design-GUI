#ifndef FRAME_H
#define FRAME_H

#include <windows.h>
#include <iostream>
#include <fstream>

// Extern includes found in main.cpp
extern struct linkedList * currAnim;
extern struct linkedList * custAnim1;
extern struct linkedList * custAnim2;
extern struct linkedList * custAnim3;
extern bool custAnim;
extern int anim;
extern int pointerX;
extern int pointerY;
extern int pointerZ;
extern std::fstream outputFile;

// Frame class, contains the 8x8x8 char array and transmit function.
class frame
{
public:
    frame();
    char array[8][8][8];
    void transmit();
};

#endif // FRAME_H
