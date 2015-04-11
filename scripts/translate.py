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


def transl_yandex(text, from_lang, to_lang):
  resp, content = h.request("https://translate.yandex.net/api/v1.5/tr.json/translate?key=%s&lang=%s-%s&text=%s%%3F" %
    (yandex_transl_api_key, from_lang, to_lang, text))

  content_json = json.loads(content)
  if content_json["code"] != 200:
    return None
  return content_json["text"][0]


def get_phonetics(path, from_lang, to_lang):
  infile = open(os.path.abspath(path), mode='r')
  outfile = open(os.path.abspath(path)+".lex", mode='w')

  for line in infile:
    time.sleep(1)
    if line.startswith("#"):
      outfile.write(line)
    else:
      translated = transl_yandex(line, from_lang, to_lang)
      full_form = line.strip() + " --- " + translated.strip() +'\n'
      outfile.write(full_form.encode("utf-8"))

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
