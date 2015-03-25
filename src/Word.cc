
#include "Word.h"
#include "Dictionary.h"

Word::Word() {}
Word::~Word() {}

void Word::setSlovak(string s) {
  this->slovak = s;
}

void Word::setEnglish(string s) {
  this->english = s;
}

void Word::setDeutsch(string s) {
  this->deutsch = s;
}

string Word::getSlovak() {
  return this->slovak;
}

string Word::getEnglish() {
  return this->english;
}

string Word::getDeutsch() {
  return this->deutsch;
}


string Word::getForm(int flag) {
  if (flag == Dictionary::SLOVAK)
    return this->slovak;
  else if (flag == Dictionary::DEUTSCH)
    return this->deutsch;
  return this->english;
}

string Word::getPhonetics(int flag) {
  if (flag == Dictionary::DEUTSCH)
    return this->deutsch_phonetics;
  return this->eng_phonetics;
}

void Word::setPhonetics(string s, int flag) {
  if (flag == Dictionary::ENGLISH)
    this->eng_phonetics = s;
  else if (flag == Dictionary::DEUTSCH)
    this->deutsch_phonetics = s;
}
