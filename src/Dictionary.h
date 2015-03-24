
#ifndef _DICTIONARY_
#define _DICTIONARY_

using namespace std;

#include <vector>
#include "Lexicon.h"
#include "Word.h"

class Dictionary {
  private:
	vector<Lexicon *> *lexicons;
	int actual;
	Word *actualWord;
	int from;
	int to;
	int howMany;
	int ok;
	int bad;

  public:
	static const int SLOVAK = 1;
	static const int ENGLISH = 2;
	static const int DEUTSCH = 3;

	Dictionary();
	~Dictionary();

	void addLexicon(Lexicon *lex);
	Lexicon *getLexicon(int position);
	void removeLexicon(Lexicon *lex);

	int getActual();
	void setActual(int actual);

	void setFrom(int f);
	void setTo(int t);
	int getFrom();
	int getTo();

	void setOk(int ok);
	void setBad(int bad);
	void setHowMany(int how);
	void incOk();
	void incBad();

	void decHowMany();

	int getOk();
	int getBad();
	int getHowMany();

	Word *getRandomWord();

	void setActualWord(Word *w);
	Word *getActualWord();
};

#endif
