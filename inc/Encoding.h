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

//member tables
private:
  pugi::xml_document doc;
  pugi::xml_node current;
  char lang[3];
  void getTable(std::string tableid);
  std::unordered_map<std::string, std::string> table;
  std::unordered_map<std::string, std::string> code;
  /*const std::unordered_map<std::string, std::string> code = {
    {"ABORT","000"},
    {"ACCEPT","019"},
    {"ACCESS","028"},
    {"ADDRESS","037"},
    {"AGENT","046"}};*/

public:
  /*const std::unordered_map<std::string, std::string> ct1 = {
    {"CONTROL","6"},
    {"CODE","0"},
    {"A","1"},
    {"E","2"},
    {"I","3"},
    {"N","4"},
    {"O","5"},
    {"T","6"},
    {"B","70"},
    {"C","71"},
    {"D","72"},
    {"F","73"},
    {"G","74"},
    {"H","75"},
    {"J","76"},
    {"K","77"},
    {"L","78"},
    {"M","79"},
    {"P","80"},
    {"Q","81"},
    {"R","82"},
    {"S","83"},
    {"U","84"},
    {"V","85"},
    {"W","86"},
    {"X","87"},
    {"Y","88"},
    {"Z","89"},
    {"FIG","90"},
    {".","91"},
    {":","92"},
    {"'","93"},
    {"(","94"},
    {")","94"},
    {"+","95"},
    {"-","96"},
    {"=","97"},
    {"REQ","98"},
    {" ","99"}};*/
  /*const std::unordered_map<std::string, std::string> ct37 = {
    {"CONTROL","6"},
    {"E","0"},
    {"S","1"},
    {"T","2"},
    {"O","3"},
    {"N","4"},
    {"I","5"},
    {"A","6"},
    {"B","70"},
    {"C","71"},
    {"D","72"},
    {"F","73"},
    {"G","74"},
    {"H","75"},
    {"J","76"},
    {"K","77"},
    {"L","78"},
    {"M","79"},
    {"P","80"},
    {"Q","81"},
    {"R","82"},
    {"U","83"},
    {"V","84"},
    {"W","85"},
    {"X","86"},
    {"Y","87"},
    {"Z","88"},
    {"FIG","89"},
    {" ","90"},
    {".","91"},
    {",","92"},
    {"'","93"},
    {"?","94"},
    {"/","95"},
    {"+","96"},
    {"-","97"},
    {"=","98"},
    {"CODE","99"}};*/
};
