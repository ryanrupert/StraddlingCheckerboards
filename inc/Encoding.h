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
  Crypto ();
  std::string decode(std::string tableid,std::string encoded); //changing this for the get table by xml
  std::string encode(std::string tableid,std::string plain); //same here
  void setLang(char *language);
  char* getLang();

private:
  //declare variables
  pugi::xml_document doc; //this holds the whole XML document
  pugi::xml_node current; //this holds the current XML document being used
  std::unordered_map<std::string, std::string> table; //this holds the table with the id that is set
  std::unordered_map<std::string, std::string> code; //this holds the code table for the current language
  char lang[3]; //this holds the current language

  //prototype private functions
  //this will load the table
  void getTable(std::string tableid);
  //below are the modular encoding functions
  std::string findDigit(int &index, std::string plain, std::string encoded, std::string figvalue);
  std::string findCode(int &index, std::string plain, std::string encoded, bool &codefound, std::string codevalue);
  std::string findLetter(int &index, std::string plain, std::string encoded);
  //below are the modular decoding functions
  //bool findFig(int index);
  //void findCode(int index);
};
