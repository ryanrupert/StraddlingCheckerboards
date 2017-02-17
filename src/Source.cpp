#include <iostream>
#include <unordered_map>
#include <string>
#include <stdlib.h>
#include "Header.h"

std::string encode(const std::unordered_map<std::string, std::string> & mymap,std::string plain);
std::string decode(const std::unordered_map<std::string, std::string> & mymap,std::string plain);
const std::unordered_map<std::string, std::string> code = {{"ABORT","000"},{"ACCEPT","019"},{"ACCESS","028"},{"ADDRESS","037"},{"AGENT","046"}};
//const std::unordered_map<std::string, std::string> ct1 = {{"A","1"},{"B","2"},{"C","3"},{"D","4"},{"E","5"}};
//const std::unordered_map<std::string, std::string> ct37 = {{"B","1"},{"D","2"},{"A","3"},{"E","4"},{"C","5"}};

int main()
{
  //declare vars
  std::string encoded;
  std::string decoded;
  std::string plain;

  //Show the user that this is using the ct1 map
  std::cout << "CT1:" << std::endl;
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

  //show the user that this is using a ct37 map
  std::cout << "CT37:" << std::endl;
  //get user input
  std::cout << "Enter a string to encoded" << std::endl;
  std::cin >> plain;
  std::cin.get();

  //encode plain text
  encoded = encode(ct37, plain);

  //output the encoded text
  std::cout << "Encoded: " << encoded << std::endl;
  std::cin.get();

  //get user input
  std::cout << "Enter a string to decode" << std::endl;
  std::cin >> encoded;
  std::cin.get();

  //decode encoded text
  decoded = decode(ct37, encoded);

  //output the decoded text
  std::cout << "Decoded: " << decoded << std::endl;
  std::cin.get();
  return 0;
}

std::string encode(const std::unordered_map<std::string, std::string> & mymap,std::string plain)
{
  //declare vars
  std::string encoded;  //this will hold the encoded text
  std::string temp; //this will hold a temp string
  int index = 0;  //this holds the index position
  int length = 0; //this will hold the plain text length
  bool codefound = false; //this holds if a code value was found
  std::string codevalue;  //this will hold the num code value
  int codelength = 0; //this will hold the length of the current codeword
  //this declares the iterator for the map
  std::unordered_map<std::string, std::string>::const_iterator got;
  //this searchs the map to see if code is in there and puts the result in got
  got = mymap.find("CODE");

  //get the plain length
  length = plain.length();

  //this try is for a guard against not finding the letter
  try{
    //this will loop till it has gone through all the letters
    while (index < length)
    {
      //TODO: check to see if the loop works
      //if code was found in the map then
      if(got != mymap.end())
      {
        //set codevalue to the value of code
        codevalue = got->second;

        //this will find if it is a code word
        for(const auto& foo : code)
        {
          //put the length of the current code word in codelength
          codelength = foo.first.length();
          //put the string from plain starting at index wih a length of
          //codelength in temp
          temp = plain.substr(index, codelength);
          //if the selected range is equal to the codeword then
          if(foo.first == temp)
          {
            //add codevalue and the value of the codeword te encoded
            encoded = encoded + codevalue + foo.second;
            //then set cod found to true
            codefound = true;
            //change the index to reflect the new index position
            index+=codelength;
            //break out of the loop
            break;
          }
        }
      }

      //if a code word was found skip this
      if(codefound == false)
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
  std::string decoded;  //this will hold the decoded string
  std::string temp; //this will hold a temp string
  int index = 0;  //this will hold the index position
  int length = 0; //this will hold the length of the encoded text
  int singlelimit = 0;  //this will hold the single digit limit for the map values
  int tempint = 0;  //this will hold the current num of the index from the string
  bool notfound = true; //this will hold if a value was notfound
  //this declares the iterator
  std::unordered_map<std::string, std::string>::const_iterator got;

  //get the plain length
  length = encoded.length();

  got = ct1.find("CONTROL");
  if(got != ct1.end())
  {
    temp = got->second;
    singlelimit = atoi(temp.c_str());
  }
  else
    throw 5;

  //this is the try statement to get the errors
  try{
    //TODO: add in the code section here
    //this will loop till it has gone through all the numbers
    while(index < length)
    {
      temp = encoded.at(index);
      tempint = atoi(temp.c_str());
      //TODO: test to see if double digits work
      //put the number at index into temp
      if(tempint >= 0 && tempint <= singlelimit)
      {
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
            //set notfound to false because a letter was found
            notfound = false;
            //then break because no need to loop again the number was found
            break;
          }
          //if the letter was not found notfound is true
          notfound = true;
          index+=2;
        }
      }
      else if(tempint >= singlelimit++ && tempint <= 99)
      {
        temp = encoded.substr(index,2);
        //loop through the map looking for the number
        for (const auto& foo : mymap)
        {
          //if the map number equals temp
          if(foo.second == temp)
          {
            temp = foo.first;
            //put the letter at the location of the map into decoded
            decoded = decoded + temp;
            //set notfound to false because a letter was found
            notfound = false;
            //then break because no need to loop again the number was found
            break;
          }
          //if the letter was not found notfound is true
          notfound = true;
        }
        //if notfound is true then throw an error
        if(notfound == true)
          throw 5;
        //reset notfound
        notfound = false;
        //add one to index
        index++;
      }
      else
        throw 5;
    }
  }
  catch(int e)
  {
    //put null in encoded to indicate that a letter was not found in the map
    decoded = "null";
  }
  //return the encode string
  return decoded;
}
