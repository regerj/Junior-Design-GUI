#include "header.h"

// Global variables
struct linkedList * currAnim = NULL;    // Pointer to current animation
struct linkedList * custAnim1 = NULL;   // Pointer to saved custom anim1
struct linkedList * custAnim2 = NULL;   // Pointer to saved custom anim2
struct linkedList * custAnim3 = NULL;   // Pointer to saved custom anim3
bool custAnim = false;                  // Bool to represent if a custAnim is playing
int anim = 0;                           // anim to represent which pre-animation is selected
int pointerX = 0;                       // X coord for pointer
int pointerY = 0;                       // Y coord for pointer
int pointerZ = 0;                       // Z coord for pointer
std::fstream outputFile;                // Output file object

#include <QApplication>

int main(int argc, char *argv[])
{
    outputFile.open("output.txt", std::ios::out);   // Create the output file for debugging
    outputFile.close();                             // Close it
    outputFile.open("output.txt");                  // Reopen it

    QApplication a(argc, argv);                     // Launch the application
    JDGUI w;                                        // Instantiate the GUI
    w.show();                                       // Show it

    return a.exec();                                // Execute it
}
