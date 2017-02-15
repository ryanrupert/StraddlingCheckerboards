#include <iostream>
#include <unordered_map>
#include <string>

std::string encode(const std::unordered_map<std::string, std::string> & mymap,std::string plain);
const std::unordered_map<std::string, std::string> ct1 = {{"A","1"},{"B","2"},{"C","3"},{"D","4"},{"E","5"}};

int main()
{
  /*std::unordered_map<std::string, std::string> mymap = {{"A","1"},{"B","2"},{"C","3"},{"D","4"},{"E","5"}};
  std::string encoded;
  std::string temp;
  std::string plain;
  std::unordered_map<std::string, std::string>::const_iterator got;
  int index = 0;
  int length = 0;

  std::cout << "Enter a string to encoded" << std::endl;
  std::cin >> plain;
  std::cin.get();
  length = plain.length();
  std::cout << "length" << length << std::endl;
  while (index < length)
  {
    temp = plain[index];
    got = mymap.find (temp);
    temp = got->second;
    encoded = encoded + temp;
    std::cout << "telem:" << std::endl;
    std::cout << "encoded: " << encoded << std::endl;
    std::cout << "temp: " << temp << std::endl;
    index++;
  }
  std::cout << "Is this correct " << encoded << std::endl;
  std::cin.get();*/

  //declare vars
  std::string encoded;
  std::string plain;

  //get user input
  std::cout << "Enter a string to encoded" << std::endl;
  std::cin >> plain;
  std::cin.get();

  //encode plain text
  encoded = encode(ct1, plain);

  //output the encoded text
  std::cout << "Encoded: " << encoded << std::endl;
  std::cin.get();
  return 0;
}

std::string encode(const std::unordered_map<std::string, std::string> & mymap,std::string plain)
{
  //declare vars
  std::string encoded;
  std::string temp;
  int index = 0;
  int length = 0;
  //this declares the iterator for the map
  std::unordered_map<std::string, std::string>::const_iterator got;

  //get the plain length
  length = plain.length();

  while (index < length)
  {
    temp = plain[index];
    got = mymap.find (temp);
    temp = got->second;
    encoded = encoded + temp;
    //std::cout << "telem:" << std::endl;
    //std::cout << "encoded: " << encoded << std::endl;
    //std::cout << "temp: " << temp << std::endl;
    index++;
  }
  return encoded;
}
