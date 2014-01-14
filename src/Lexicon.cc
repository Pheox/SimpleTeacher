// Lexicon.cc
// Vladimir Brigant
// posledna zmena: 22.6.2011

#include "Lexicon.h"
#include "Dictionary.h"
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;


Lexicon::Lexicon()
{
  	this->words = new vector<Word *>();
}

Lexicon::~Lexicon()
{
  for (int i=0;i < this->words->size();i++)
	delete this->words->at(i);
  delete this->words;
}
	
void Lexicon::addWord(Word *word)
{
  this->words->push_back(word);
}

Word *Lexicon::getWord(int position)
{
  return this->words->at(position);
}

void Lexicon::removeWord(Word *w){}



void Lexicon::parseFile(string path)
{
  string line;
  
  ifstream myfile(path.c_str());
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
	  
	  
	  char *pch;
	  pch = strtok((char *)line.c_str(),"-");
	  int a = 0;
	  string eng,slov,fon;
	  
	  
	  while (pch != NULL)
	  {
		printf ("%s\n",pch);
		if (!a)
		{// english
		  eng = string(pch);
		}
		else if (a == 1)
		  slov = string(pch);
		else if (a == 2)
		  fon = string(pch);
		
		pch = strtok (NULL, "-");
		a++;
	  }
	  
	  if (a)
	  {
		Word *w = new Word();
		w->setEnglish(eng);
		w->setSlovak(slov);
		w->setPhonetics(fon,Dictionary::ENGLISH);
		this->words->push_back(w);
	  }
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 
  
}



vector<Word *> *Lexicon::getWords(){return this->words;}


