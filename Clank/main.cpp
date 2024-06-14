#include "mainmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainMenu menu;
    menu.show();
    return app.exec();
}
