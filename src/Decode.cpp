/**
* Created By Ryan Rupert on 2/13/2017.
*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <stdlib.h>
#include "Encoding.h"
//const std::unordered_map<std::string, std::string> code = {{"ABORT","000"},{"ACCEPT","019"},{"ACCESS","028"},{"ADDRESS","037"},{"AGENT","046"}};
std::string Crypto::decode(const std::unordered_map<std::string, std::string> & mymap, std::string encoded)
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
  std::string figvalue; //this will hold the value of fig
  int figvalueint = 0;  //this will hold the int value of fig
  bool figfound = false;  //this will hold the fig was found
  int tempcomp[3];  //this will hold the temps
  bool codedo = false;  //this will hold weather or not to do the code if
  bool parinthdo = false; // this will hold weather or not to do the parinth if
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

  //find the fig values
  got = mymap.find("FIG");
  //if it does then
  if (got != mymap.end())
  {
    //put the value if fig in figvalue
    figvalue = got->second;
    //put the intiger value of fig in figvalueint
    figvalueint = atoi(got->second.c_str());
  }


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
    //this will loop till it has gone through all the numbers
    while(index < length)
    {
      //put the string at index in temp
      temp = encoded.substr(index, 2);
      tempint = atoi(temp.c_str());
      //if tempint equals figvalue then
      if (tempint == figvalueint)
      {
        //add 2 to int
        index+=2;
        //while tempint is not equal figvalueint
        do
        {
          //put encoded string at index in temp
          temp = encoded.substr(index, 3);
          tempcomp[0] = temp.at(0);
          tempcomp[1] = temp.at(1);
          tempcomp[2] = temp.at(2);
          //if temp at 1 equals temp at 2 and temp at 2 equals temp at 3 and temp at 1 equals temp at 3 then
          if ( (tempcomp[0] == tempcomp[1]) && (tempcomp[1] == tempcomp[2]) && (tempcomp[0] == tempcomp[2]) )
          {
            //std::cout << "MADE FIG" << std::endl;
            //add temp at 1 to decoded and put in decoded
            decoded = decoded + temp[1];
            //turn figfound to true
            figfound = true;
            index += 3;
          }
          else
            //std::cout << "error string decoded" << decoded << std::endl;
            throw 5;
          //index += 3;
          //put encoded string at index in temp
          temp = encoded.substr(index, 2);
          //turn temp to an intiger then put in tempint
          tempint = atoi(temp.c_str());
        }while (!(tempint == figvalueint));
        index += 2;
      }

      if (index > encoded.length()-1)
        break;

      //put the value at the index position in temp dependent on if the code
      //value is double
      (codedouble == true) ? temp = encoded.substr(index, 2) : temp = encoded.at(index);
      codedo = ((codevalue.compare(temp) == 0) && (codefound == true)) ? true : false;
      (parinthfound == true) ? temp = encoded.substr(index, 2) : temp = encoded.at(index);
      parinthdo = ((parinthfound == true) && (parinthvalueint == tempint)) ? true : false;

      //if any of the special cases is true then do what is in the if
      if((codedo || parinthdo) && (figfound != true))
      {
        (codedouble == true) ? temp = encoded.substr(index, 2) : temp = encoded.at(index);
        if((codevalue.compare(temp) == 0) && (codefound == true))
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
        if (index > encoded.length()-1)
          break;
        (parinthfound == true) ? temp = encoded.substr(index, 2) : temp = encoded.at(index);
        if((parinthfound == true) && (parinthvalueint == tempint))
        {
          decoded = (parinthIsOpen == false) ? decoded + "(" : decoded + ")";
          parinthIsOpen = (parinthIsOpen == false) ? true : false;
          index+=2;
        }
      }
      else if (figfound != true)
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
      figfound = false;
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
