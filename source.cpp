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

struct linkedList* constructAnimTwo()
{   
    // Instantiate frame
    struct linkedList * animTwo;
    animTwo = new linkedList;
    frame * tempFrame = new frame;
    node * tempNode = new node;
    animTwo->head = tempNode;
    animTwo->head->frame = tempFrame;
    animTwo->iter = animTwo->head;

    for(int i = 0; i < 8; i++)
    {
        // Populate a plane
        populatePlane('g', i, animTwo);

        // Instantiate frame
        animTwo->iter->next = new node;
        tempFrame = new frame;
        animTwo->iter = animTwo->iter->next;
        animTwo->iter->frame = tempFrame;
    }

    std::cout << "Made it past first for loop" << std::endl;

    for(int i = 7; i > -1; i--)
    {
        // Populate a plane
        populatePlane('y', i, animTwo);

        // Instantiate frame
        animTwo->iter->next = new node;
        tempFrame = new frame;
        animTwo->iter = animTwo->iter->next;
        animTwo->iter->frame = tempFrame;
    }
    std::cout << "Made it past first for loop" << std::endl;

    for(int i = 0; i < 8; i++)
    {
        // Populate a plane
        populatePlane('o', i, animTwo);

        // Instantiate frame
        animTwo->iter->next = new node;
        tempFrame = new frame;
        animTwo->iter = animTwo->iter->next;
        animTwo->iter->frame = tempFrame;
    }
    std::cout << "Made it past first for loop" << std::endl;

    for(int i = 7; i > -1; i--)
    {
        // Populate a plane
        populatePlane('r', i, animTwo);

        // Instantiate frame
        animTwo->iter->next = new node;
        tempFrame = new frame;
        animTwo->iter = animTwo->iter->next;
        animTwo->iter->frame = tempFrame;
    }
    std::cout << "Made it past first for loop" << std::endl;

    for(int i = 0; i < 8; i++)
    {
        // Populate a plane
        populatePlane('p', i, animTwo);

        // Instantiate frame
        animTwo->iter->next = new node;
        tempFrame = new frame;
        animTwo->iter = animTwo->iter->next;
        animTwo->iter->frame = tempFrame;
    }
    std::cout << "Made it past first for loop" << std::endl;

    for(int i = 7; i > -1; i--)
    {
        // Populate a plane
        populatePlane('u', i, animTwo);

        // Instantiate frame
        animTwo->iter->next = new node;
        tempFrame = new frame;
        animTwo->iter = animTwo->iter->next;
        animTwo->iter->frame = tempFrame;
    }
    std::cout << "Made it past first for loop" << std::endl;

    for(int i = 0; i < 8; i++)
    {
        // Populate a plane
        populatePlane('b', i, animTwo);

        // Instantiate frame
        animTwo->iter->next = new node;
        tempFrame = new frame;
        animTwo->iter = animTwo->iter->next;
        animTwo->iter->frame = tempFrame;
    }
    std::cout << "Made it past first for loop" << std::endl;

    for(int i = 7; i > -1; i--)
    {
        // Populate a plane
        populatePlane('l', i, animTwo);

        // Instantiate frame
        animTwo->iter->next = new node;
        tempFrame = new frame;
        animTwo->iter = animTwo->iter->next;
        animTwo->iter->frame = tempFrame;
    }
    std::cout << "Made it past first for loop" << std::endl;

    for(int i = 0; i < 8; i++)
    {
        // Populate a plane
        populatePlane('b', i, animTwo);

        // Instantiate frame
        animTwo->iter->next = new node;
        tempFrame = new frame;
        animTwo->iter = animTwo->iter->next;
        animTwo->iter->frame = tempFrame;
    }

    std::cout << "made to end of anim2" << std::endl;
    return animTwo;
}

struct linkedList* constructAnimThree()
{
    // Instantiate frame
    struct linkedList * animThree;
    animThree = new linkedList;
    frame * tempFrame = new frame;
    node * tempNode = new node;
    animThree->head = tempNode;
    animThree->head->frame = tempFrame;
    animThree->iter = animThree->head;

    animThree->iter->frame->array[3][3][3] = 'g';
    animThree->iter->frame->array[4][3][3] = 'g';
    animThree->iter->frame->array[3][4][3] = 'g';
    animThree->iter->frame->array[4][4][3] = 'g';
    animThree->iter->frame->array[3][3][4] = 'g';
    animThree->iter->frame->array[4][3][4] = 'g';
    animThree->iter->frame->array[3][4][4] = 'g';
    animThree->iter->frame->array[4][4][4] = 'g';

    animThree->iter->next = new node;
    tempFrame = new frame;
    animThree->iter = animThree->iter->next;
    animThree->iter->frame = tempFrame;

    for(int i = 2; i < 6; i++)
    {
        for(int j = 2; j < 6; j++)
        {
           animThree->iter->frame->array[i][j][2] = 'g';
        }
    }

    for(int i = 2; i < 6; i++)
    {
        for(int j = 2; j < 6; j++)
        {
           animThree->iter->frame->array[i][2][j] = 'g';
        }
    }

    for(int i = 2; i < 6; i++)
    {
        for(int j = 2; j < 6; j++)
        {
           animThree->iter->frame->array[2][i][j] = 'g';
        }
    }

    for(int i = 2; i < 6; i++)
    {
        for(int j = 2; j < 6; j++)
        {
           animThree->iter->frame->array[5][i][j] = 'g';
        }
    }

    for(int i = 2; i < 6; i++)
    {
        for(int j = 2; j < 6; j++)
        {
           animThree->iter->frame->array[i][5][j] = 'g';
        }
    }

    for(int i = 2; i < 6; i++)
    {
        for(int j = 2; j < 6; j++)
        {
           animThree->iter->frame->array[i][j][5] = 'g';
        }
    }

    animThree->iter->next = new node;
    tempFrame = new frame;
    animThree->iter = animThree->iter->next;
    animThree->iter->frame = tempFrame;

    for(int i = 1; i < 7; i++)
    {
        for(int j = 1; j < 7; j++)
        {
           animThree->iter->frame->array[i][j][1] = 'g';
        }
    }

    for(int i = 1; i < 7; i++)
    {
        for(int j = 1; j < 7; j++)
        {
           animThree->iter->frame->array[i][1][j] = 'g';
        }
    }

    for(int i = 1; i < 7; i++)
    {
        for(int j = 1; j < 7; j++)
        {
           animThree->iter->frame->array[1][i][j] = 'g';
        }
    }

    for(int i = 1; i < 7; i++)
    {
        for(int j = 1; j < 7; j++)
        {
           animThree->iter->frame->array[6][i][j] = 'g';
        }
    }

    for(int i = 1; i < 7; i++)
    {
        for(int j = 1; j < 7; j++)
        {
           animThree->iter->frame->array[i][6][j] = 'g';
        }
    }

    for(int i = 1; i < 7; i++)
    {
        for(int j = 1; j < 7; j++)
        {
           animThree->iter->frame->array[i][j][6] = 'g';
        }
    }

    animThree->iter->next = new node;
    tempFrame = new frame;
    animThree->iter = animThree->iter->next;
    animThree->iter->frame = tempFrame;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
           animThree->iter->frame->array[i][j][0] = 'g';
        }
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
           animThree->iter->frame->array[i][0][j] = 'g';
        }
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
           animThree->iter->frame->array[0][i][j] = 'g';
        }
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
           animThree->iter->frame->array[7][i][j] = 'g';
        }
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
           animThree->iter->frame->array[i][7][j] = 'g';
        }
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
           animThree->iter->frame->array[i][j][7] = 'g';
        }
    }

    animThree->iter->next = new node;
    tempFrame = new frame;
    animThree->iter = animThree->iter->next;
    animThree->iter->frame = tempFrame;

    for(int i = 1; i < 7; i++)
    {
        for(int j = 1; j < 7; j++)
        {
           animThree->iter->frame->array[i][j][1] = 'g';
        }
    }

    for(int i = 1; i < 7; i++)
    {
        for(int j = 1; j < 7; j++)
        {
           animThree->iter->frame->array[i][1][j] = 'g';
        }
    }

    for(int i = 1; i < 7; i++)
    {
        for(int j = 1; j < 7; j++)
        {
           animThree->iter->frame->array[1][i][j] = 'g';
        }
    }

    for(int i = 1; i < 7; i++)
    {
        for(int j = 1; j < 7; j++)
        {
           animThree->iter->frame->array[6][i][j] = 'g';
        }
    }

    for(int i = 1; i < 7; i++)
    {
        for(int j = 1; j < 7; j++)
        {
           animThree->iter->frame->array[i][6][j] = 'g';
        }
    }

    for(int i = 1; i < 7; i++)
    {
        for(int j = 1; j < 7; j++)
        {
           animThree->iter->frame->array[i][j][6] = 'g';
        }
    }

    animThree->iter->next = new node;
    tempFrame = new frame;
    animThree->iter = animThree->iter->next;
    animThree->iter->frame = tempFrame;

    for(int i = 2; i < 6; i++)
    {
        for(int j = 2; j < 6; j++)
        {
           animThree->iter->frame->array[i][j][2] = 'g';
        }
    }

    for(int i = 2; i < 6; i++)
    {
        for(int j = 2; j < 6; j++)
        {
           animThree->iter->frame->array[i][2][j] = 'g';
        }
    }

    for(int i = 2; i < 6; i++)
    {
        for(int j = 2; j < 6; j++)
        {
           animThree->iter->frame->array[2][i][j] = 'g';
        }
    }

    for(int i = 2; i < 6; i++)
    {
        for(int j = 2; j < 6; j++)
        {
           animThree->iter->frame->array[5][i][j] = 'g';
        }
    }

    for(int i = 2; i < 6; i++)
    {
        for(int j = 2; j < 6; j++)
        {
           animThree->iter->frame->array[i][5][j] = 'g';
        }
    }

    for(int i = 2; i < 6; i++)
    {
        for(int j = 2; j < 6; j++)
        {
           animThree->iter->frame->array[i][j][5] = 'g';
        }
    }

    animThree->iter->next = new node;
    tempFrame = new frame;
    animThree->iter = animThree->iter->next;
    animThree->iter->frame = tempFrame;

    animThree->iter->frame->array[3][3][3] = 'g';
    animThree->iter->frame->array[4][3][3] = 'g';
    animThree->iter->frame->array[3][4][3] = 'g';
    animThree->iter->frame->array[4][4][3] = 'g';
    animThree->iter->frame->array[3][3][4] = 'g';
    animThree->iter->frame->array[4][3][4] = 'g';
    animThree->iter->frame->array[3][4][4] = 'g';
    animThree->iter->frame->array[4][4][4] = 'g';

    return animThree;
}
