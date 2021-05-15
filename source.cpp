#include "header.h"

// Populate a selected plane with a selected char in the animation
// at the frame of its current iter
void populatePlane(char ch, int index, struct linkedList* animOne)
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            animOne->iter->frame->array[index][i][j] = ch;
        }
    }
}

// Function to create the first animation
struct linkedList* constructAnimOne()

{
    // Instantiate frame
    struct linkedList * animOne;
    animOne = new linkedList;
    frame * tempFrame = new frame;
    node * tempNode = new node;
    animOne->head = tempNode;
    animOne->head->frame = tempFrame;
    animOne->iter = animOne->head;

    // Populate frame
    populatePlane('y', 0, animOne);
    populatePlane('o', 1, animOne);
    populatePlane('r', 2, animOne);
    populatePlane('p', 3, animOne);
    populatePlane('u', 4, animOne);
    populatePlane('b', 5, animOne);
    populatePlane('l', 6, animOne);
    populatePlane('n', 7, animOne);

    // Instantiate frame
    animOne->iter->next = new node;
    tempFrame = new frame;
    animOne->iter = animOne->iter->next;
    animOne->iter->frame = tempFrame;

    // Populate frame
    populatePlane('o', 0, animOne);
    populatePlane('r', 1, animOne);
    populatePlane('p', 2, animOne);
    populatePlane('u', 3, animOne);
    populatePlane('b', 4, animOne);
    populatePlane('l', 5, animOne);
    populatePlane('n', 6, animOne);
    populatePlane('g', 7, animOne);

    // Instantiate frame
    animOne->iter->next = new node;
    tempFrame = new frame;
    animOne->iter = animOne->iter->next;
    animOne->iter->frame = tempFrame;

    // Populate frame
    populatePlane('r', 0, animOne);
    populatePlane('p', 1, animOne);
    populatePlane('u', 2, animOne);
    populatePlane('b', 3, animOne);
    populatePlane('l', 4, animOne);
    populatePlane('n', 5, animOne);
    populatePlane('g', 6, animOne);
    populatePlane('y', 7, animOne);

    // Instantiate frame
    animOne->iter->next = new node;
    tempFrame = new frame;
    animOne->iter = animOne->iter->next;
    animOne->iter->frame = tempFrame;

    // Populate frame
    populatePlane('p', 0, animOne);
    populatePlane('u', 1, animOne);
    populatePlane('b', 2, animOne);
    populatePlane('l', 3, animOne);
    populatePlane('n', 4, animOne);
    populatePlane('g', 5, animOne);
    populatePlane('y', 6, animOne);
    populatePlane('o', 7, animOne);

    // Instantiate frame
    animOne->iter->next = new node;
    tempFrame = new frame;
    animOne->iter = animOne->iter->next;
    animOne->iter->frame = tempFrame;

    // Populate frame
    populatePlane('u', 0, animOne);
    populatePlane('b', 1, animOne);
    populatePlane('l', 2, animOne);
    populatePlane('n', 3, animOne);
    populatePlane('g', 4, animOne);
    populatePlane('y', 5, animOne);
    populatePlane('o', 6, animOne);
    populatePlane('r', 7, animOne);

    // Instantiate frame
    animOne->iter->next = new node;
    tempFrame = new frame;
    animOne->iter = animOne->iter->next;
    animOne->iter->frame = tempFrame;

    // Populate frame
    populatePlane('b', 0, animOne);
    populatePlane('l', 1, animOne);
    populatePlane('n', 2, animOne);
    populatePlane('g', 3, animOne);
    populatePlane('y', 4, animOne);
    populatePlane('o', 5, animOne);
    populatePlane('r', 6, animOne);
    populatePlane('p', 7, animOne);

    // Instantiate frame
    animOne->iter->next = new node;
    tempFrame = new frame;
    animOne->iter = animOne->iter->next;
    animOne->iter->frame = tempFrame;

    // Populate frame
    populatePlane('l', 0, animOne);
    populatePlane('n', 1, animOne);
    populatePlane('g', 2, animOne);
    populatePlane('y', 3, animOne);
    populatePlane('o', 4, animOne);
    populatePlane('r', 5, animOne);
    populatePlane('p', 6, animOne);
    populatePlane('u', 7, animOne);

    // Instantiate frame
    animOne->iter->next = new node;
    tempFrame = new frame;
    animOne->iter = animOne->iter->next;
    animOne->iter->frame = tempFrame;

    // Populate frame
    populatePlane('n', 0, animOne);
    populatePlane('g', 1, animOne);
    populatePlane('y', 2, animOne);
    populatePlane('o', 3, animOne);
    populatePlane('r', 4, animOne);
    populatePlane('p', 5, animOne);
    populatePlane('u', 6, animOne);
    populatePlane('b', 7, animOne);

    // Instantiate frame
    animOne->iter->next = new node;
    tempFrame = new frame;
    animOne->iter = animOne->iter->next;
    animOne->iter->frame = tempFrame;

    // Populate frame
    populatePlane('g', 0, animOne);
    populatePlane('y', 1, animOne);
    populatePlane('o', 2, animOne);
    populatePlane('r', 3, animOne);
    populatePlane('p', 4, animOne);
    populatePlane('u', 5, animOne);
    populatePlane('b', 6, animOne);
    populatePlane('l', 7, animOne);

    // animOne->iter->next = animOne->head;

    return animOne;
}

// W.I.P. Function to construct the second pre
// programmed animation. INCOMPLETE
struct linkedList* constructAnimTwo()
{
    struct linkedList animTwo;
    frame * tempFrame = new frame;
    node * tempNode = new node;
    animTwo.head = tempNode;
    animTwo.head->frame = tempFrame;
    animTwo.iter = animTwo.head;

    struct tm * currTime = NULL;

    time_t now = time(0);
    currTime = localtime(&now);

    switch(currTime->tm_hour)
    {
    case 0:
        animTwo.iter->frame->array[0][0][4] = 'w';
        animTwo.iter->frame->array[0][0][5] = 'w';
        animTwo.iter->frame->array[0][0][6] = 'w';
        animTwo.iter->frame->array[0][0][7] = 'w';
        break;
    //case 1:
        //animTwo.iter->frame->array;
    }
}
