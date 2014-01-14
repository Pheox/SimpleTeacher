
#include <iostream>
#include <cstdlib>
#include "Dictionary.h"
#include "Lexicon.h"
#include "Word.h"

#include <QtCore>
#include <QApplication> // QT
#include "MainWindow.h" // QT


int main(int argc,char *argv[])
{

QApplication app(argc,argv);
MainWindow *window = new MainWindow();
//window->resize(640,480);
window->show();
return app.exec();  

return EXIT_SUCCESS;  
}

