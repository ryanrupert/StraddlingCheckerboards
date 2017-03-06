#pragma once
#include <unordered_map>

class Crypto
{
private:
  const std::unordered_map<std::string, std::string> code;


public:
  const std::unordered_map<std::string, std::string> ct1;
  const std::unordered_map<std::string, std::string> ct37;
  Crypto ();
  std::string decode(const std::unordered_map<std::string, std::string> & mymap,std::string encoded);
  std::string encode(const std::unordered_map<std::string, std::string> & mymap,std::string plain);
};
