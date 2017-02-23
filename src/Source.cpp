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
  std::getline(std::cin, plain);
  //encode plain text
  encoded = encode(ct1, plain);
  //output the encoded text
  std::cout << "Encoded: " << encoded << std::endl;
  std::cin.get();

  //get user input
  std::cout << "Enter a string to decode" << std::endl;
  std::getline(std::cin, encoded);
  //decode encoded text
  decoded = decode(ct1, encoded);
  //output the decoded text
  std::cout << "Decoded: " << decoded << std::endl;
  std::cin.get();

  //show the user that this is using a ct37 map
  std::cout << "CT37:" << std::endl;

  //get user input
  std::cout << "Enter a string to encoded" << std::endl;
  std::getline(std::cin, plain);
  //encode plain text
  encoded = encode(ct37, plain);
  //output the encoded text
  std::cout << "Encoded: " << encoded << std::endl;
  std::cin.get();

  //get user input
  std::cout << "Enter a string to decode" << std::endl;
  std::getline(std::cin, encoded);
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
  std::string codevalue = "null";  //this will hold the num code value
  int codelength = 0; //this will hold the length of the current codeword
  std::string figvalue = "null"; //this will hold the value of fig
  bool figfound = false;  //this will hold if a figure was found
  //this declares the iterator for the map
  std::unordered_map<std::string, std::string>::const_iterator got;

  //this searchs the map to see if code is in there and puts the result in got
  got = mymap.find("CODE");
  if(got != mymap.end())
    codevalue = got->second;

  got = mymap.find("FIG");
  if(got != mymap.end())
    figvalue = got->second;

  //get the plain length
  length = plain.length();

  //this try is for a guard against not finding the letter
  try{
    //this will loop till it has gone through all the letters
    while (index < length)
    {
      if (plain.at(index) >= 0 || plain.at(index) <= 9)
      {
        encoded = encoded + figvalue;
        while (plain.at(index) >= 0 || plain.at(index) <= 9)
        {
          encoded = encoded + plain.at(index) + plain.at(index) + plain.at(index);
          index++;
        }
        encoded = encoded + figvalue;
        figfound = true;
      }
      //if code was found in the map then
      //this will find if it is a code word
      else if(codevalue != "null" && figfound != true)
      {
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
      else if(codefound == false && figfound == false)
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
      codefound = false;
      figfound = false;
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
  int singlelimitmod = 0; //this is the modified singlelimit
  int tempint = 0;  //this will hold the current num of the index from the string
  bool notfound = true; //this will hold if a value was notfound
  std::string codevalue;  //this will hold the code value
  bool codefound = false; //this will hold if code was found in the encode map
  int codevalueint = 0; //this will hold he code value as an int
  bool codedouble = false;  //this will hold if code is a double digit
  bool parinthfound = false;  //this will hold if a parinthase was found
  int parinthvalueint = 0;  //this will hold the value of a parithase in int
  std::string parinthasevalue; //this will hold the value of papinthase
  bool parinthIsOpen = false; //this will hold if the parinthase is open or not
  //this declares the iterator
  std::unordered_map<std::string, std::string>::const_iterator got;

  //get the plain length
  length = encoded.length();

  //this finds the control key for the number at wich single digits stop
  got = mymap.find("CONTROL");
  //if control is found then
  if(got != mymap.end())
  {
    //the value at got is turned to a c string then turned to a number and put
    //in singlelimit
    singlelimit = atoi(got->second.c_str());
    //add one to singlelimit then place it in singlelimitmod
    singlelimitmod = singlelimit + 1;
  }
  //if control is not found then throw an error
  else
    throw 5;

  //find if this encode map uses code
  got = mymap.find("CODE");
  //if it does then
  if (got != mymap.end())
  {
    //put the value of code in codevalue
    codevalue = got->second;
    //put the intiger value of code in codevalueint
    codevalueint = atoi(got->second.c_str());
    //set code found to true
    codefound = true;
  }
  //if code was not found then set codefound to false
  else
    codefound = false;

  //if the codevalueint is a double digit number then set codedouble to true else false
  codedouble = ((codevalueint >= 0) && (codevalueint <= 9)) ? false : (codevalueint > 9) ? true : false;

  //find if the encoded map has parinthasis
  got = mymap.find("(");
  //if it does then
  if (got != mymap.end())
  {
    //put the value of code in codevalue
    parinthasevalue = got->second;
    //put the intiger value of code in codevalueint
    parinthvalueint = atoi(got->second.c_str());
    //set code found to true
    parinthfound = true;
  }
  //if code was not found then set codefound to false
  else
    parinthfound = false;

  //this is the try statement to get the errors
  try{
    //TODO: add in the code section here
    //this will loop till it has gone through all the numbers
    while(index < length)
    {
      //put the value at the index position in temp dependent on if the code
      //value is double
      (codedouble == true) ? temp = encoded.substr(index, 2) : temp = encoded.at(index);
      (parinthfound == true) ? temp = encoded.substr(index, 2) : temp = encoded.at(index);
      //turn temp to c string then turn to a number and place in tempint
      tempint = atoi(temp.c_str());

      //if any of the special cases is true then do what is in the if
      if(((codevalueint == tempint) && (codefound == true)) || ((parinthfound == true) && (parinthvalueint == tempint)))
      {
        if((codevalueint == tempint) && (codefound == true))
        {
          //add one to index if code is a single digit
          if(codedouble == false)
            index++;
          //add two to index if code is a double digit
          else if(codedouble ==true)
            index+=2;

          //put the values in encoded at index with range of three to temp
          temp = encoded.substr(index, 3);

          //loop through the map looking for the number
          for (const auto& foo : code)
          {
            //if the map number equals temp
            if(foo.second == temp)
            {
              //put the letter at the location of the map into decoded
              decoded = decoded + foo.first;

              //set notfound to false because a letter was found
              notfound = false;

              //then break because no need to loop again the number was found
              break;
            }
          }
          //if notfound is true then throw an error
          if(notfound == true)
            throw 5;

          //reset notfound
          notfound = false;

          //add three to index
          index+=3;
        }
        else if((parinthfound == true) && (parinthvalueint == tempint))
        {
          decoded = (parinthIsOpen == false) ? decoded + "(" : decoded + ")";
          parinthIsOpen = (parinthIsOpen == false) ? true : false;
          index+=2;
        }
      }
      else
      {
        //put the value in encoed at indek in temp
        temp = encoded.at(index);
        //turn temp to a c string then turn to a intager and put in tempint
        tempint = atoi(temp.c_str());

        //if tempint is a single digit then
        if((tempint >= 0) && (tempint <= singlelimit))
        {
          //put the value at index in temp
          temp = encoded.at(index);

          //loop through the map looking for the number
          for (const auto& foo : mymap)
          {
            //if the map number equals temp
            if(foo.second == temp)
            {
              //put the letter at the location of the map into decoded
              decoded = decoded + foo.first;

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
        else if((tempint >= singlelimitmod) && (tempint <= 99))
        {
          //put the value at index in temp
          temp = encoded.substr(index,2);

          //loop through the map looking for the number
          for (const auto& foo : mymap)
          {
            //if the map number equals temp
            if(foo.second == temp)
            {
              //put the letter at the location of the map into decoded
              decoded = decoded + foo.first;

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

          //add two to index
          index+=2;
        }
        else
          throw 5;
      }
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
