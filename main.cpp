
#include <iostream>
#include <cstdlib>
#include "src/Dictionary.h"
#include "src/Lexicon.h"
#include "src/Word.h"

#include <QtCore>
#include <QApplication> // QT
#include "mainwindow.h" // QT


int main(int argc,char *argv[])
{

    QApplication app(argc,argv);
    MainWindow *window = new MainWindow();
    //window->resize(640,480);
    window->show();
    return app.exec();

    return EXIT_SUCCESS;
}
