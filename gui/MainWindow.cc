// MainWindow.cc
// Vladimir Brigant
// posledna zmena: 22.6.2011

#include <QtCore>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "MainWindow.h"
#include <QFileDialog>
#include <QMessageBox>


// konstruktor
MainWindow::MainWindow(QWidget * parent, Qt::WindowFlags f) : QMainWindow ( parent,f ) 
{
	ui.setupUi(this);
	this->dict = new Dictionary();
	this->dict->setHowMany(20);
	
	/// ui.wordLabel, ui.translatedLabel
	/// ui.fromComboBox, ui.toComboBox
	/// ui.startButton
	ui.fromComboBox->addItem("Slovak");
	ui.fromComboBox->addItem("English");
	ui.fromComboBox->addItem("Deutsch");
	
	ui.toComboBox->addItem("Slovak");
	ui.toComboBox->addItem("English");
	ui.toComboBox->addItem("Deutsch");
	
	//int a = 33;
	ui.dobreLabel->setText(QString::number(0));
	ui.zleLabel->setText(QString::number(0));
	ui.scoreLabel->setText(QString("0 %"));
	
	QObject::connect(ui.fromComboBox, SIGNAL(activated(int)), this, SLOT(fromComboBox_activated(int)));	
	QObject::connect(ui.toComboBox, SIGNAL(activated(int)), this, SLOT(toComboBox_activated(int)));	
	// actionSet_Lexicon (Add, Change)
	QObject::connect(ui.setLexiconButton, SIGNAL(clicked()), this, SLOT(setLexiconButton_clicked()));	
	QObject::connect(ui.startButton, SIGNAL(clicked()), this, SLOT(startButton_clicked()));
	
	QObject::connect(ui.iknowButton, SIGNAL(clicked()), this, SLOT(iknowButton_clicked()));
	QObject::connect(ui.dunnoButton, SIGNAL(clicked()), this, SLOT(dunnoButton_clicked()));
	QObject::connect(ui.showTranslatedButton, SIGNAL(clicked()), this, SLOT(showTranslatedButton_clicked()));
	
}


void MainWindow::fromComboBox_activated(int i){
  this->dict->setFrom(i+1);
}

void MainWindow::toComboBox_activated(int i){  
  this->dict->setTo(i+1);
}


void MainWindow::setLexiconButton_clicked()
{
 // opedir
 QFileDialog dialog(this);
 dialog.setFileMode(QFileDialog::AnyFile);
 //dialog.setNameFilter(tr("Config files (*.conf)"));
 dialog.setDirectory(QDir::current());
	
 QStringList fileNames;
 	
  if (dialog.exec())
	  fileNames = dialog.selectedFiles();
	
  if (!fileNames.size()) return;
  else cout << fileNames[0].toStdString() << endl;
 
  // fileNames[0].toStdString() - nazov suboru na parsovanie slov
 Lexicon *lex = new Lexicon();
 lex->parseFile(fileNames[0].toStdString().c_str());
 
 cout << lex << endl;
 this->dict->addLexicon(lex);
 
 
 this->ui.okLabel->setText("OK");
}


void MainWindow::startButton_clicked()
{
	
	Word *w = this->dict->getRandomWord();
	this->dict->setActualWord(w);
	cout << w << endl;
	this->ui.translatedLabel->setText("");
	this->ui.pronunciationLabel->setText(QString::fromUtf8(w->getPhonetics(this->dict->getFrom()).c_str()));
	
	this->ui.wordLabel->setText(QString((w->getForm(this->dict->getFrom())).c_str()));
	//this->ui.translatedLabel->setText(QString((w->getForm(this->dict->getTo())).c_str()));
	// TODO - toto do cyklu
}


void MainWindow::iknowButton_clicked()
{
	Word *w = this->dict->getRandomWord();
	this->dict->setActualWord(w);
	cout << w << endl;
	this->ui.translatedLabel->setText("");
	this->ui.pronunciationLabel->setText(QString::fromUtf8(w->getPhonetics(this->dict->getFrom()).c_str()));
	
	this->ui.wordLabel->setText(QString((w->getForm(this->dict->getFrom())).c_str()));
	//this->ui.translatedLabel->setText(QString((w->getForm(this->dict->getTo())).c_str()));
	//this->ui.dobreLabel->setText 
	this->dict->incOk();
	this->ui.dobreLabel->setText(QString::number(this->dict->getOk()));
	this->ui.scoreLabel->setText(QString::number((double)this->dict->getOk()/(this->dict->getOk()+this->dict->getBad())*100,'g',3)+" %");
	this->dict->decHowMany();
	this->ui.remainingLabel->setText(QString::number(this->dict->getHowMany()));
	
	
	if (!this->dict->getHowMany())
	{
	  // TODO
	  QMessageBox box;
	  box.setText("Koniec testu!\nDosiahli ste uspesnost " + QString::number((double)this->dict->getOk()/(this->dict->getOk() + this->dict->getBad())*100) + " %");
	  box.exec();
	}
}


void MainWindow::dunnoButton_clicked()
{
	Word *w = this->dict->getRandomWord();
	this->dict->setActualWord(w);
	cout << w << endl;
	this->ui.translatedLabel->setText("");
	//this->ui.pronunciationLabel->setText(QString((w->getPhonetics(this->dict->getFrom())).c_str()));
	//this->ui.pronunciationLabel->setText(QString::fromUtf8("ľššľľ"));
	this->ui.pronunciationLabel->setText(QString::fromUtf8(w->getPhonetics(this->dict->getFrom()).c_str()));
	
	this->ui.wordLabel->setText(QString((w->getForm(this->dict->getFrom())).c_str()));
	//this->ui.translatedLabel->setText(QString((w->getForm(this->dict->getTo())).c_str()));
	this->dict->incBad();
	this->ui.zleLabel->setText(QString::number(this->dict->getBad()));
	this->ui.scoreLabel->setText(QString::number((double)this->dict->getOk()/(this->dict->getOk()+this->dict->getBad())*100,'g',3)+" %");
	this->dict->decHowMany();
	this->ui.remainingLabel->setText(QString::number(this->dict->getHowMany()));
	
	if (!this->dict->getHowMany())
	{
	  // TODO
	  QMessageBox box;
	  box.setText("Koniec testu!\nDosiahli ste uspesnost " + QString::number((double)this->dict->getOk()/(this->dict->getOk() + this->dict->getBad())*100) + " %");
	  box.exec();
	}
}


void MainWindow::showTranslatedButton_clicked()
{
	this->ui.translatedLabel->setText(QString((this->dict->getActualWord()->getForm(this->dict->getTo())).c_str()));
}


// destruktor
MainWindow::~MainWindow()
{

}


void MainWindow::setDictionary(Dictionary *d){this->dict = d;}

Dictionary *MainWindow::getDictionary(){return this->dict;}
				