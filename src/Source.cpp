#include <iostream>
#include <unordered_map>
#include <string>

std::string encode(const std::unordered_map<std::string, std::string> & mymap,std::string plain);
std::string decode(const std::unordered_map<std::string, std::string> & mymap,std::string plain);
const std::unordered_map<std::string, std::string> ct1 = {{"A","1"},{"B","2"},{"C","3"},{"D","4"},{"E","5"}};
const std::unordered_map<std::string, std::string> ct37 = {{"B","1"},{"D","2"},{"A","3"},{"E","4"},{"C","5"}};

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
  std::string decoded;
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

  //get user input
  std::cout << "Enter a string to decode" << std::endl;
  std::cin >> encoded;
  std::cin.get();

  //decode encoded text
  decoded = decode(ct1, encoded);

  //output the decoded text
  std::cout << "Decoded: " << decoded << std::endl;
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

  //this try is for a guard against not finding the letter
  try{
    //this will loop till it has gone through all the letters
    while (index < length)
    {
      //get the letter at the index position
      temp = plain.at(index);
      //find the letter in temp and put in got
      got = mymap.find (temp);
      //if end is not found meaning that the search did not reach the end of the
      //map then
      if(got != mymap.end())
      {
        //add the number at the second position of got to encoded and place the
        //result in encoded
        encoded = encoded + got->second;
        //add one to index
        index++;
      }
      //if end was found then throw 5 to protect against issues
      else
        throw 5;
    }
  }
  catch(int e)
  {
    //put null in encoded to indicate that a letter was not found in the map
    encoded = "null";
  }
  //return the encoded string
  return encoded;
}

std::string decode(const std::unordered_map<std::string, std::string> & mymap,std::string encoded)
{
  //declare vars
  std::string decoded;
  std::string temp;
  int index = 0;
  int length = 0;
  bool notfound = true;

  //get the plain length
  length = encoded.length();

  //this is the try statement to get the errors
  try{
    //this will loop till it has gone through all the numbers
    while(index < length)
    {
      //put the number at index into temp
      temp = encoded.at(index);
      //loop through the map looking for the number
      for (const auto& foo : mymap)
      {
        //if the map number equals temp
        if(foo.second == temp)
        {
          temp = foo.first;
          //put the letter at the location of the map into decoded
          decoded = decoded + temp;
          notfound = false;
          //then break because no need to loop again the number was found
          break;
        }
        notfound = true;
      }
      if(notfound == true)
        throw 5;
      notfound = false;
      index++;
    }
  }
  catch(int e)
  {
    decoded = "null";
  }
  return decoded;
}
