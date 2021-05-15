#ifndef JDGUI_H
#define JDGUI_H

#include <QMainWindow>

#include "header.h"

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

// QT UI namespace stuff
QT_BEGIN_NAMESPACE
namespace Ui { class JDGUI; }
QT_END_NAMESPACE

// JDGUI Class handled by QT
class JDGUI : public QMainWindow
{
    Q_OBJECT

public:
    JDGUI(QWidget *parent = nullptr);   // Constructor
    ~JDGUI();                           // Destructor

private:
    Ui::JDGUI *ui;                      // UI pointer

// Event hanlder slots, connected to buttons in jdgui.cpp
private slots:
    void animPressed();
    void upPressed();
    void leftPressed();
    void inPressed();
    void outPressed();
    void rightPressed();
    void downPressed();
    void newFrame();
    void changeColour();
    void custAnimPressed();
};
#endif // JDGUI_H
