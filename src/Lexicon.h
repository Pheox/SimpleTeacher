#ifndef _LEXICON_
#define _LEXICON_

using namespace std;

#include <vector>
#include <iostream>
#include "Word.h"


class Lexicon
{
  private:
	vector<Word *> *words;

  public:
	Lexicon();
	~Lexicon();

	void addWord(Word *word);
	Word *getWord(int position);
	void removeWord(Word *w);

	vector<Word *> *getWords();

	void parseFile(string path);


	// pretazenie operatoru <<
	friend ostream& operator<<(ostream& out, Lexicon *lex) // output
	{
		out << "Lexicon:" << endl;
		for (unsigned int i=0; i < lex->getWords()->size();i++)
		  out<< "Word:" << lex->getWords()->at(i)->getEnglish() << " - " << lex->getWords()->at(i)->getSlovak() << endl;
		return out;
	}
};

#endif
