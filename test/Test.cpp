#include <iostream>
#include <unordered_map>
#include <string>
#include <stdlib.h>

const std::unordered_map<std::string, std::string> ct1 = {
  {"CONTROL","6"},
  {"COE","0"},
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
  {" ","99"}};

int main()
{
  int singlelimit = 0;
  std::string temp;
  std::unordered_map<std::string, std::string>::const_iterator got;
  got = ct1.find("CONTROL");
  if(got != ct1.end())
  {
    temp = got->second;
    singlelimit = atoi(temp.c_str());
  }
  else
    std::cout << "error" << std::endl;

  std::cout << "singlelimit is: " << singlelimit << std::endl;
  std::cin.get();
  return 0;
}
