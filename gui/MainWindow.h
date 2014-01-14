// MainWindow.h
// Vladimir Brigant
// posledna zmena: 22.6.2011



#ifndef MAIN_WINDOW__H
#define MAIN_WINDOW__H

#include <QtCore>
#include <QWidget>
#include <QDesktopServices>
#include "ui_main.h"
#include "Dictionary.h"


using namespace std;

class MainWindow : public QMainWindow {
	Q_OBJECT

	public:
	
	private:
		Ui::MainWindow ui;
		Dictionary *dict;
		
	public:
		MainWindow ( QWidget * parent = 0, Qt::WindowFlags f = 0 );
		~MainWindow();
		void setDictionary(Dictionary *d);
		Dictionary *getDictionary();
		
	public slots:
	  void fromComboBox_activated(int);
	  void toComboBox_activated(int);
	  void setLexiconButton_clicked();	
	  void startButton_clicked();
	  void iknowButton_clicked();
	  void dunnoButton_clicked();
	  void showTranslatedButton_clicked();
	  
	signals:
};

#endif // MAIN_WINDOW__H

