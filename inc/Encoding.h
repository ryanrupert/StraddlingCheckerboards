/**
* Created By Ryan Rupert on 2/13/2017.
*/
#pragma once
#include "pugixml.hpp"
#include <unordered_map>
#include <iostream>   //REVIEW: See if iostream is needed
#include <string>
#include <stdlib.h>
#include <ctype.h>

class Crypto
{
//members
public:
  //constructors
  Crypto ();
  Crypto (std::string file);
  Crypto (const char *language);
  Crypto (std::string file, const char *language);
  
  std::string decode(std::string tableid,std::string encoded); //changing this for the get table by xml
  std::string encode(std::string tableid,std::string plain); //same here
  void setLang(const char *language);
  char* getLang();

private:
  pugi::xml_document doc;
  pugi::xml_node current;

  char lang[3];
  void getTable(std::string tableid);

  std::unordered_map<std::string, std::string> table;
  std::unordered_map<std::string, std::string> code;

  //below are the modular encoding functions
  std::string findDigit(int &index, std::string plain, std::string encoded, std::string figvalue);
  std::string findCode(int &index, std::string plain, std::string encoded, bool &codefound, std::string codevalue);
  std::string findLetter(int &index, std::string plain, std::string encoded);
  //below are the modular decoding functions
  //bool findFig(int index);
  //void findCode(int index);
};
