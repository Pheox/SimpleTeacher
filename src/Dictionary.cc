// Dictionary.cc
// Vladimir Brigant
// posledna zmena: 22.6.2011


#include "Dictionary.h"
#include <ctime>
#include <cstdlib>


Dictionary::Dictionary()
{
  //vector<Lexicon *> *lexicons;
  this->from = Dictionary::ENGLISH;
  this->to = Dictionary::SLOVAK;
  this->lexicons = new vector<Lexicon *>();
  this->actualWord = NULL;
  this->ok = 0;
  this->bad = 0;
  this->howMany = 0;
}

Dictionary::~Dictionary()
{
  for (unsigned int i=0; i < this->lexicons->size();i++)
	delete this->lexicons->at(i);
  delete this->lexicons;
}
	
	
void Dictionary::addLexicon(Lexicon *lex)
{
	this->lexicons->push_back(lex);
}
	
	
Lexicon *Dictionary::getLexicon(int position)
{
  
}
	
void Dictionary::removeLexicon(Lexicon *lex)
{}
	
int Dictionary::getActual()
{
	return this->actual;
}
	
void Dictionary::setActual(int actual)
{
  this->actual = actual;
}



void Dictionary::setFrom(int f){this->from = f;}
void Dictionary::setTo(int t){this->to = t;}
int Dictionary::getFrom(){return this->from;}
int Dictionary::getTo(){return this->to;}

	
Word *Dictionary::getRandomWord()
{
	///toto vyoptimalizovat
	int all = 0;
	for (int i=0;i < this->lexicons->size();i++)
		all += this->lexicons->at(i)->getWords()->size();
  
	cout << "pocet vsetkych slov: " << all << endl;
	
	// vyber jedneho hesla
	srand(time(NULL));
	int random = rand() % all + 1; 
	
	cout << random << endl;  //number between 1 and 10
	
	int tmp_counter = 0;
	for (int i=0;i < this->lexicons->size();i++)
	{
		tmp_counter += this->lexicons->at(i)->getWords()->size();
		if (tmp_counter < random)
		{
			//random -= tmp_counter;
			continue;
		}
		else
		{
			cout << "im there " << endl;
 			return this->lexicons->at(i)->getWords()->at(tmp_counter-random);
		}
	}
}


void Dictionary::setActualWord(Word *w)
{
	this->actualWord = w; 
}
	
Word *Dictionary::getActualWord()
{
	return this->actualWord; 
}

void Dictionary::setOk(int ok){this->ok = ok;}
void Dictionary::setBad(int bad){this->bad = bad;}
void Dictionary::setHowMany(int how){this->howMany = how;}

int Dictionary::getOk(){return this->ok;}
int Dictionary::getBad(){return this->bad;}
int Dictionary::getHowMany(){return this->howMany;}

void Dictionary::incOk(){this->ok = this->ok + 1; }
void Dictionary::incBad(){this->bad = this->bad + 1;}

void Dictionary::decHowMany(){this->howMany -= 1;}

