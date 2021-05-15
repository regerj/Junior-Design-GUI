#include "jdgui.h"
#include "ui_jdgui.h"

// Constructor
JDGUI::JDGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JDGUI)
{
    ui->setupUi(this);

    ui->display->setText("Debug information displayed here");

    // Instantiate button array and link them to appropriate buttons
    QPushButton *buttons[24];
    buttons[0] = JDGUI::findChild<QPushButton *>("animButton1");
    buttons[1] = JDGUI::findChild<QPushButton *>("animButton2");
    buttons[2] = JDGUI::findChild<QPushButton *>("animButton3");
    buttons[3] = JDGUI::findChild<QPushButton *>("upButton");
    buttons[4] = JDGUI::findChild<QPushButton *>("leftButton");
    buttons[5] = JDGUI::findChild<QPushButton *>("inButton");
    buttons[6] = JDGUI::findChild<QPushButton *>("outButton");
    buttons[7] = JDGUI::findChild<QPushButton *>("rightButton");
    buttons[8] = JDGUI::findChild<QPushButton *>("downButton");
    buttons[9] = JDGUI::findChild<QPushButton *>("newFrameButton");
    buttons[10] = JDGUI::findChild<QPushButton *>("whiteButton");
    buttons[11] = JDGUI::findChild<QPushButton *>("yellowButton");
    buttons[12] = JDGUI::findChild<QPushButton *>("orangeButton");
    buttons[13] = JDGUI::findChild<QPushButton *>("redButton");
    buttons[14] = JDGUI::findChild<QPushButton *>("pinkButton");
    buttons[15] = JDGUI::findChild<QPushButton *>("purpleButton");
    buttons[16] = JDGUI::findChild<QPushButton *>("blueButton");
    buttons[17] = JDGUI::findChild<QPushButton *>("lightBlueButton");
    buttons[18] = JDGUI::findChild<QPushButton *>("neonBlueButton");
    buttons[19] = JDGUI::findChild<QPushButton *>("greenButton");
    buttons[20] = JDGUI::findChild<QPushButton *>("clearButton");
    buttons[21] = JDGUI::findChild<QPushButton *>("custAnimButton1");
    buttons[22] = JDGUI::findChild<QPushButton *>("custAnimButton2");
    buttons[23] = JDGUI::findChild<QPushButton *>("custAnimButton3");

    // Connect each button to the corresponding event handler
    connect(buttons[0], SIGNAL(released()), this, SLOT(animPressed()));
    connect(buttons[1], SIGNAL(released()), this, SLOT(animPressed()));
    connect(buttons[2], SIGNAL(released()), this, SLOT(animPressed()));
    connect(buttons[3], SIGNAL(released()), this, SLOT(upPressed()));
    connect(buttons[4], SIGNAL(released()), this, SLOT(leftPressed()));
    connect(buttons[5], SIGNAL(released()), this, SLOT(inPressed()));
    connect(buttons[6], SIGNAL(released()), this, SLOT(outPressed()));
    connect(buttons[7], SIGNAL(released()), this, SLOT(rightPressed()));
    connect(buttons[8], SIGNAL(released()), this, SLOT(downPressed()));
    connect(buttons[9], SIGNAL(released()), this, SLOT(newFrame()));
    connect(buttons[10], SIGNAL(released()), this, SLOT(changeColour()));
    connect(buttons[11], SIGNAL(released()), this, SLOT(changeColour()));
    connect(buttons[12], SIGNAL(released()), this, SLOT(changeColour()));
    connect(buttons[13], SIGNAL(released()), this, SLOT(changeColour()));
    connect(buttons[14], SIGNAL(released()), this, SLOT(changeColour()));
    connect(buttons[15], SIGNAL(released()), this, SLOT(changeColour()));
    connect(buttons[16], SIGNAL(released()), this, SLOT(changeColour()));
    connect(buttons[17], SIGNAL(released()), this, SLOT(changeColour()));
    connect(buttons[18], SIGNAL(released()), this, SLOT(changeColour()));
    connect(buttons[19], SIGNAL(released()), this, SLOT(changeColour()));
    connect(buttons[20], SIGNAL(released()), this, SLOT(changeColour()));
    connect(buttons[21], SIGNAL(released()), this, SLOT(custAnimPressed()));
    connect(buttons[22], SIGNAL(released()), this, SLOT(custAnimPressed()));
    connect(buttons[23], SIGNAL(released()), this, SLOT(custAnimPressed()));

    return;
}

// Deconstructor
JDGUI::~JDGUI()
{
    delete ui;
}

// Event hanlder for if a precoded animation is pressed
void JDGUI::animPressed()
{
    std::cout << "animPressed()" << std::endl;              // Debug stuff
    custAnim = false;                                       // Global bool for if custom anim is active
    QPushButton *button = (QPushButton *)sender();          // Get the senders button pointer
    QString butVal = button->text();                        // Pull its text
    if(butVal == "Animation 1")                             // If its anim1
    {
        std::cout << "anim1pressed" << std::endl;           // Debug stuff
        anim = 1;                                           // Set anim as 1
        if(currAnim)                                        // If currAnim is active
        {
            // Free memory here
        }
        currAnim = constructAnimOne();                      // Construct the first anim
        currAnim->iter = currAnim->head;                    // Set the iter at the head

        std::cout << "beginning time loop" << std::endl;    // Debug stuff

        double startTime = GetTickCount();                  // Grab tick count to time loop
        outputFile.write("Transmision begin\n", 18);        // Write the file to transmission begin
        while(anim == 1 && currAnim->iter != NULL)          // While anim is still occuring
        {
            double currTime = GetTickCount() - startTime;   // Pull elapsed time
            if(currTime >= 500)                             // If its been at least half a second
            {
                currAnim->iter->frame->transmit();          // Transmit another frame
                currAnim->iter = currAnim->iter->next;      // Iterate
                startTime = GetTickCount();                 // Reset timer
            }
        }
    }

    // IDENTICAL TO ABOVE IF BLOCK, JUST FOR ANIM 2
    else if(butVal == "Animation 2")
    {
        std::cout << "anim2pressed" << std::endl;
        anim = 2;
        if(currAnim)
        {
            // Free memory here
        }
        //currAnim = constructAnimTwo();
        currAnim->iter = currAnim->head;

        std::cout << "beginning time loop" << std::endl;

        double startTime = GetTickCount();
        outputFile.write("Transmision begin\n", 18);
        while(anim == 2 && currAnim->iter != NULL)
        {
            double currTime = GetTickCount() - startTime;
            if(currTime >= 500)
            {
                currAnim->iter->frame->transmit();
                currAnim->iter = currAnim->iter->next;
                startTime = GetTickCount();
            }
        }
    }

    // IDENTICAL TO ABOVE IF BLOCK JUST FOR ANIM 3
    else if(butVal == "Animation 3")
    {
        std::cout << "anim3pressed" << std::endl;
        anim = 3;
        if(currAnim)
        {
            // Free memory here
        }
        //currAnim = constructAnimThree();
        currAnim->iter = currAnim->head;

        std::cout << "beginning time loop" << std::endl;

        double startTime = GetTickCount();
        outputFile.write("Transmision begin\n", 18);
        while(anim == 3 && currAnim->iter != NULL)
        {
            double currTime = GetTickCount() - startTime;
            if(currTime >= 500)
            {
                currAnim->iter->frame->transmit();
                currAnim->iter = currAnim->iter->next;
                startTime = GetTickCount();
            }
        }
    }
}

// Event hanlder for up button press
void JDGUI::upPressed()
{
    if(custAnim)                                            // If custom animation being used
    {
        if(pointerZ < 7)                                    // If pointer is within bounds
        {
            pointerZ++;                                     // Increment Z pointer
            std::cout << "Z: " << pointerZ << std::endl;    // Debug stuff
        }
        else                                                // Otherwise
            std::cout << "Z upper bound hit" << std::endl;  // Debug info and dont increment
    }
    return;
}

// Event handler for the left button press
// IDENTICAL TO upPressed but for left
void JDGUI::leftPressed()
{
    if(custAnim)
    {
        if(pointerX > 0)
        {
            pointerX--;
            std::cout << "X: " << pointerX << std::endl;
        }
        else
            std::cout << "X lower bound hit" << std::endl;
    }
    return;
}

// Event handler for the in button press
// IDENTICAL TO upPressed but for in
void JDGUI::inPressed()
{
    if(custAnim)
    {
        if(pointerY < 7)
        {
            pointerY++;
            std::cout << "Y: " << pointerY << std::endl;
        }
        else
            std::cout << "Y upper bound hit" << std::endl;
    }
    return;
}

// Event handler for the out button press
// IDENTICAL TO upPressed but for out
void JDGUI::outPressed()
{
    if(custAnim)
    {
        if(pointerY > 0)
        {
            pointerY--;
            std::cout << "Y: " << pointerY << std::endl;
        }
        else
            std::cout << "Y lower bound hit" << std::endl;
    }
    return;
}

// Event handler for the right button press
// IDENTICAL TO upPressed but for right
void JDGUI::rightPressed()
{
    if(custAnim)
    {
        if(pointerX < 7)
        {
        pointerX++;
        std::cout << "X: " << pointerX << std::endl;
        }
        else
            std::cout << "X upper bound hit" << std::endl;
    }
    return;
}

// Event handler for the down button press
// IDENTICAL TO upPressed but for down
void JDGUI::downPressed()
{
    if(custAnim)
    {
        if(pointerZ > 0)
        {
            pointerZ--;
            std::cout << "Z: " << pointerZ << std::endl;
        }
        else
            std::cout << "Z lower bound hit" << std::endl;
    }
    return;
}

// Event handler to create a new frame
void JDGUI::newFrame()
{
    // Reset pointer
    pointerX = 0;
    pointerY = 0;
    pointerZ = 0;

    // If custom animation then instantiate a new frame and append it
    // to the linked list that is globaly declared. Transmit this
    // new frame.
    if(custAnim)
    {
        frame * tempFrame = NULL;
        currAnim->iter->next = new node;
        tempFrame = new frame;
        currAnim->iter = currAnim->iter->next;
        currAnim->iter->frame = tempFrame;
        currAnim->iter->frame->transmit();
    }
    return;
}

// Event handler for if a colour has been pressed.
void JDGUI::changeColour()
{
    // Grab the button that sent the signal and pull its text
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();

    // Discriminate between buttons and set the custom animation array at the
    // pointer location to the corresponding char for the colour
    if(custAnim && butVal == "White")
        currAnim->iter->frame->array[pointerX][pointerY][pointerZ] = 'w';
    else if(custAnim && butVal == "Yellow")
        currAnim->iter->frame->array[pointerX][pointerY][pointerZ] = 'y';
    else if(custAnim && butVal == "Orange")
        currAnim->iter->frame->array[pointerX][pointerY][pointerZ] = 'o';
    else if(custAnim && butVal == "Red")
        currAnim->iter->frame->array[pointerX][pointerY][pointerZ] = 'r';
    else if(custAnim && butVal == "Pink")
        currAnim->iter->frame->array[pointerX][pointerY][pointerZ] = 'p';
    else if(custAnim && butVal == "Purple")
        currAnim->iter->frame->array[pointerX][pointerY][pointerZ] = 'u';
    else if(custAnim && butVal == "Blue")
        currAnim->iter->frame->array[pointerX][pointerY][pointerZ] = 'b';
    else if(custAnim && butVal == "Light Blue")
        currAnim->iter->frame->array[pointerX][pointerY][pointerZ] = 'l';
    else if(custAnim && butVal == "Neon Blue")
        currAnim->iter->frame->array[pointerX][pointerY][pointerZ] = 'n';
    else if(custAnim && butVal == "Green")
        currAnim->iter->frame->array[pointerX][pointerY][pointerZ] = 'g';
    else if(custAnim && butVal == "Clear Current Color")
        currAnim->iter->frame->array[pointerX][pointerY][pointerZ] = 'x';
    return;
}

// Event handler for selecting a custom animation
void JDGUI::custAnimPressed()
{
    // Set custAnim and pull the sending button and its text
    custAnim = true;
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();

    // If its the first custom anim, create a new linked list for
    // the anim and instantiate its members and transmit the first frame
    // or play the selected custom animation if it has already been made
    if(custAnim && butVal == "Custom Animation 1")
    {
        if(custAnim1 == NULL)
        {
            custAnim1 = new struct linkedList;
            frame * tempFrame = new frame;
            node * tempNode = new node;
            custAnim1->head = tempNode;
            custAnim1->head->frame = tempFrame;
            custAnim1->iter = custAnim1->head;
            outputFile.write("Transmision begin\n", 18);
            custAnim1->iter->frame->transmit();
        }
        else
        {
            custAnim1->iter = custAnim1->head;

            double startTime = GetTickCount();

            outputFile.write("Transmision begin\n", 18);
            while(custAnim1->iter != NULL)
            {
                double currTime = GetTickCount() - startTime;
                if(currTime >= 500)
                {
                    custAnim1->iter->frame->transmit();
                    custAnim1->iter = custAnim1->iter->next;
                    startTime = GetTickCount();
                }
            }
        }
        // Signify that the current anim is custAnim1
        currAnim = custAnim1;
    }
    // IDENTICAL CODE TO CUSTANIM1
    else if(custAnim && butVal == "Custom Animation 2")
    {
        if(custAnim2 == NULL)
        {
            frame * tempFrame = new frame;
            node * tempNode = new node;
            custAnim2->head = tempNode;
            custAnim2->head->frame = tempFrame;
            custAnim2->iter = custAnim2->head;
            outputFile.write("Transmision begin\n", 18);
            custAnim2->iter->frame->transmit();
        }
        else
        {
            custAnim2->iter = custAnim2->head;

            double startTime = GetTickCount();

            outputFile.write("Transmision begin\n", 18);
            while(custAnim2->iter != NULL)
            {
                double currTime = GetTickCount() - startTime;
                if(currTime >= 500)
                {
                    custAnim2->iter->frame->transmit();
                    custAnim2->iter = custAnim2->iter->next;
                    startTime = GetTickCount();
                }
            }
        }
        currAnim = custAnim2;
    }
    // IDENTICAL CODE TO CUSTANIM1
    else if(custAnim && butVal == "Custom Animation 3")
    {
        if(custAnim3 == NULL)
        {
            frame * tempFrame = new frame;
            node * tempNode = new node;
            custAnim3->head = tempNode;
            custAnim3->head->frame = tempFrame;
            custAnim3->iter = custAnim3->head;
            outputFile.write("Transmision begin\n", 18);
            custAnim3->iter->frame->transmit();
        }
        else
        {
            custAnim2->iter = custAnim2->head;

            double startTime = GetTickCount();

            outputFile.write("Transmision begin\n", 18);
            while(custAnim2->iter != NULL)
            {
                double currTime = GetTickCount() - startTime;
                if(currTime >= 500)
                {
                    custAnim2->iter->frame->transmit();
                    custAnim2->iter = custAnim2->iter->next;
                    startTime = GetTickCount();
                }
            }
        }
        currAnim = custAnim3;
    }
}
