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
  Crypto crypto;
  //declare vars
  std::string encoded;
  std::string decoded;
  std::string plain;

  //Show the user that this is using the ct1 map
  std::cout << "CT1:" << std::endl;

  //get user input
  std::cout << "Enter a string to encoded" << std::endl;
  std::getline(std::cin, plain);
  //encode plain text
  encoded = crypto.encode(ct1, plain);
  //output the encoded text
  std::cout << "Encoded: " << encoded << std::endl;
  std::cin.get();

  //get user input
  std::cout << "Enter a string to decode" << std::endl;
  std::getline(std::cin, encoded);
  //decode encoded text
  decoded = crypto.decode(ct1, encoded);
  //output the decoded text
  std::cout << "Decoded: " << decoded << std::endl;
  std::cin.get();

  //show the user that this is using a ct37 map
  std::cout << "CT37:" << std::endl;

  //get user input
  std::cout << "Enter a string to encoded" << std::endl;
  std::getline(std::cin, plain);
  //encode plain text
  encoded = crypto.encode(ct37, plain);
  //output the encoded text
  std::cout << "Encoded: " << encoded << std::endl;
  std::cin.get();

  //get user input
  std::cout << "Enter a string to decode" << std::endl;
  std::getline(std::cin, encoded);
  //decode encoded text
  decoded = crypto.decode(ct37, encoded);
  //output the decoded text
  std::cout << "Decoded: " << decoded << std::endl;
  std::cin.get();
  return 0;
}
