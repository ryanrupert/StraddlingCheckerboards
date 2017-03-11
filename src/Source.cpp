/**
* Created By Ryan Rupert on 2/13/2017.
*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <stdlib.h>
#include "Encoding.h"

int main()
{
  Crypto crypt1;
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
