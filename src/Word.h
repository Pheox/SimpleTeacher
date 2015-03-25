
#ifndef _WORD_
#define _WORD_

using namespace std;

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

class Word {
  private:
  string slovak;
  string english;
  string deutsch;
  string eng_phonetics;
  string deutsch_phonetics;

  public:
  Word();
  ~Word();

  void setSlovak(string s);
  void setEnglish(string s);
  void setDeutsch(string s);

  string getSlovak();
  string getEnglish();
  string getDeutsch();

  string getForm(int flag);

  void setPhonetics(string s,int flag);
  string getPhonetics(int flag);

  friend ostream& operator<<(ostream& out, Word *w) {
    out << "Word:" << endl;
    out << "Slovak: " << w->getSlovak() << endl;
    out << "English:" << w->getEnglish() << endl;
    out << "Deutsch:" << w->getDeutsch() << endl;

    return out;
  }
};

#endif
