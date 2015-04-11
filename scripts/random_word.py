#!/usr/bin/python

import os
import sys
import json
import time
import random


def get_trans_item(rand_word_it, from_lang):
  from_word = ""
  to_word = ""

  if from_lang == "en":
    from_word = rand_word_it[:rand_word_it.find("---")]
    to_word = rand_word_it[rand_word_it.find("---") + 4: -1]
  else:
    from_word = rand_word_it[rand_word_it.find("---") + 4: -1]
    to_word = rand_word_it[:rand_word_it.find("---")]
  return (from_word, to_word)



def get_random(path, from_lang):
  infile = open(os.path.abspath(path), mode='r')

  words = []
  for line in infile:
    if not line.startswith("#"):
      words.append(line)
  infile.close()

  words_count = len(words)
  exit = 0

  while not exit:
    rand_word_it = words[random.randint(0, words_count - 1)]
    rand_word = ""

    from_word, to_word = get_trans_item(rand_word_it, from_lang)

    sys.stdout.write(from_word + " - ")

    cmd = raw_input("")
    if cmd == "x":
      exit = 1
    sys.stdout.write(to_word + "\n")

  return


def help():
  print "./random_word.py <lexicon> <from_lang>"


### MAIN ###

if __name__ == '__main__':
  if len(sys.argv) != 3:
    help()
  else:
    lexicon_path = sys.argv[1]
    from_lang = sys.argv[2]
    get_random(lexicon_path, from_lang)
