#!/usr/bin/env python3


try:
	import os
	import sys
	import httplib2
	import json
	import re
except ImportError:
	print("missing module..")



def get_phonetics(path):
	infile = open(os.path.abspath(path), mode='r',encoding='ascii')
	outfile = open(os.path.abspath(path)+"_phonetics",mode='w',encoding='utf8')

	h = httplib2.Http(".cache")

	reg_fon = re.compile(r'"type":"phonetic","text":"([^"]*)"')

	
	for line in infile:
		try:
			eng, slovak, fon = '','',''
			reg = re.search(r"([^-]*)-(.*)",line)
			if reg:
				eng = reg.group(1).strip()
				slovak = reg.group(2).strip()
				#print("eng: " + eng)
				#print("slovak: "+slovak)
				# GET fonetics from web
				resp, content = h.request("http://www.google.com/dictionary/json?callback=dict_api.callbacks.id100&q="+eng+"&sl=en&tl=en", "GET")
				content = content.decode('utf-8')
				fon = reg_fon.search(content).group(1)
				# fon.group(1)
				full_form = eng+" - "+slovak+" - "+fon+'\n'
				outfile.write(full_form)
		except AttributeError:
			print("Chyba! Zrejme chybne anglicke slovicko: "+eng)
	

	infile.close()
	outfile.close()



# spustenie modulu ako skriptu
# 1 parameter - cesta + nazov k slovniku
if __name__ == '__main__':
	get_phonetics(sys.argv[1])


