#!/usr/bin/python


import os
import sys
import json
import time
import httplib2


h = httplib2.Http(".cache")

# Yandex Rich Content API
yandex_rich_api_key = "rca.1.1.20150328T101806Z.d2ce79d2ea0bb3f3.b42c0116c83c76e06b3880d6c1d501d708c2eef2"
# Yandex Translate API
yandex_transl_api_key = "trnsl.1.1.20150328T103835Z.216b72177c4e1a34.9b9fc5fe15740e1f29f01de2695e6708d7ccf2d8"

# Microsoft Bing Translator API key/Data Market Azure account key - no simple useful API
bing_api_key = "htHL5nNC6pLjmy7mrwW7e+KlCzqJGmqG9+i57VXdrFk"

# Google Translator template
# http://translate.google.com/translate_a/t?client=t&text='.$word.'&hl=en&sl=en&tl=hi&ie=UTF-8&oe=UTF-8&multires=1&otf=1&ssel=3&tsel=3&sc=1



def transl_google(word, from_lang, to_lang):
  # resp, content = h.request("http://translate.google.com/translate_a/single?client=t&sl=en&tl=sk&hl=cs&dt=bd&dt=ex&dt=ld&dt=md&dt=qc&dt=rw&dt=rm&dt=ss&dt=t&dt=at&ie=UTF-8&oe=UTF-8&prev=btn&ssel=3&tsel=6&tk=519869|186773&q=asd",
  #   headers={'User-Agent':'Mozilla/4.0'})
  resp, content = h.request("http://translate.google.com/translate_a/t?text=%s&oe=UTF-8&tl=%s&client=z&sl=%s&ie=UTF-8&" % (word, to_lang, from_lang),
    headers={'User-Agent':'Mozilla/4.0'})

  # NOTE: Includes phonetics transcription, but content is not easily parsable - not JSON
  # resp, content = h.request("http://translate.google.com/translate_a/single?client=t&text=%s&oe=UTF-8&tl=%s&client=z&sl=%s&ie=UTF-8&hl=en&dt=bd&dt=ld&dt=md&dt=qc&dt=rw&dt=rm&dt=ss&dt=t&dt=at&prev=btn" % (word, to_lang, from_lang),
  #   headers={'User-Agent':'Mozilla/4.0'})
  print content
  content_json = json.loads(content)
  meanings = content_json["dict"][0]["entry"]

  mean_str = ""

  for meaning in meanings:
    mean_str += meaning["word"] + " "
  return mean_str

def transl_yandex(text, from_lang, to_lang):
  resp, content = h.request("https://translate.yandex.net/api/v1.5/tr.json/translate?key=%s&lang=%s-%s&text=%s%%3F" %
    (yandex_transl_api_key, from_lang, to_lang, text))

  content_json = json.loads(content)
  print content
  if content_json["code"] != 200:
    print resp
    return None
  return content_json["text"][0]


def get_phonetics(path, from_lang, to_lang):
  infile = open(os.path.abspath(path), mode='r')
  outfile = open(os.path.abspath(path)+".lex", mode='w')

  for line in infile:
    time.sleep(2)
    translated = transl_google(line, from_lang, to_lang)
    full_form = word + " - " + translated +'\n'
    outfile.write(full_form)

  infile.close()
  outfile.close()

def help():
  print "./get_phonetics.py <lexicon> <from_lang> <to_lang>"

if __name__ == '__main__':
  if len(sys.argv) != 4:
    help()
  else:
    lexicon_path = sys.argv[1]
    from_lang = sys.argv[2]
    to_lang = sys.argv[3]
    get_phonetics(lexicon_path, from_lang, to_lang)
