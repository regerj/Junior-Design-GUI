#ifndef HEADER_H
#define HEADER_H

#include <chrono>
#include <ctime>
#include <fstream>

#include "jdgui.h"
#include "frame.h"
#include "linkedList.h"

// Extern includes from main.cpp
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

// First animation construction function.
// Returns a pointer to a custom linked
// list. (see linkedList.h)
struct linkedList* constructAnimOne();
struct linkedList* constructAnimTwo();
struct linkedList* constructAnimThree();

#endif // HEADER_H
