#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "frame.h"

// Node struct with just a frame class
// object pointer, and a node pointer.
struct node
{
    frame* frame = NULL;
    node* next = NULL;
};

// Linked list struct with a head and
// iter pointers.
struct linkedList
{
    node* head = NULL;
    node* iter = NULL;
};

#endif // LINKEDLIST_H
