#include <iostream>
#include <unordered_map>
#include <string>
#include <stdlib.h>
#include "Header.h"

//std::string encode(const std::unordered_map<std::string, std::string> & mymap,std::string plain);
//std::string decode(const std::unordered_map<std::string, std::string> & mymap,std::string plain);
//const std::unordered_map<std::string, std::string> code = {{"ABORT","000"},{"ACCEPT","019"},{"ACCESS","028"},{"ADDRESS","037"},{"AGENT","046"}};
//const std::unordered_map<std::string, std::string> ct1 = {{"A","1"},{"B","2"},{"C","3"},{"D","4"},{"E","5"}};
//const std::unordered_map<std::string, std::string> ct37 = {{"B","1"},{"D","2"},{"A","3"},{"E","4"},{"C","5"}};

int main()
{
  Crypto crypt1;
  //declare vars
  std::string encoded;
  std::string decoded;
  std::string plain;
  //added this to see if there is any data in the map but there isn't
  std::cout << "test" << std::endl;
  std::unordered_map<std::string, std::string>::const_iterator got;
  got = crypt1.ct1.find("T");
  if(got != crypt1.ct1.end())
    std::cout << "T was found as" << got->second << std::endl;
  //Show the user that this is using the ct1 map
  std::cout << "CT1:" << std::endl;

  //get user input
  std::cout << "Enter a string to encoded" << std::endl;
  std::getline(std::cin, plain);
  //encode plain text
  encoded = crypt1.encode(crypt1.ct1, plain);
  //output the encoded text
  std::cout << "Encoded: " << encoded << std::endl;
  std::cin.get();

  //get user input
  std::cout << "Enter a string to decode" << std::endl;
  std::getline(std::cin, encoded);
  //decode encoded text
  decoded = crypt1.decode(crypt1.ct1, encoded);
  //output the decoded text
  std::cout << "Decoded: " << decoded << std::endl;
  std::cin.get();

  //show the user that this is using a ct37 map
  std::cout << "CT37:" << std::endl;

  //get user input
  std::cout << "Enter a string to encoded" << std::endl;
  std::getline(std::cin, plain);
  //encode plain text
  encoded = crypt1.encode(crypt1.ct37, plain);
  //output the encoded text
  std::cout << "Encoded: " << encoded << std::endl;
  std::cin.get();

  //get user input
  std::cout << "Enter a string to decode" << std::endl;
  std::getline(std::cin, encoded);
  //decode encoded text
  decoded = crypt1.decode(crypt1.ct37, encoded);
  //output the decoded text
  std::cout << "Decoded: " << decoded << std::endl;
  std::cin.get();
  return 0;
}
