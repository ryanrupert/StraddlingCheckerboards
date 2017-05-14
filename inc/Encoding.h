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
  void setLang(char language[3]);
  char* getLang();

private:
  pugi::xml_document doc;
  pugi::xml_node current;
  char lang[3];
  void getTable(std::string tableid);
  std::unordered_map<std::string, std::string> table;
  std::unordered_map<std::string, std::string> code;
};
