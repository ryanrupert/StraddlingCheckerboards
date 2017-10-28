/**
* Created By Ryan Rupert on 2/13/2017.
*/
#include "Encoding.h"
std::string Crypto::encode(std::string tableid, std::string plain)
{
  this->getTable(tableid);
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
  got = table.find("CODE");
  //if code was found and got is not table.end() then put the code value in codevalue
  if(got != table.end())
    codevalue = got->second;

  //this searchs the map to see if fig is in there and puts the result in got
  got = table.find("FIG");
  //if fig was found and got is nat table.end() then put the fig value in figvalue
  if(got != table.end())
    figvalue = got->second;

  //get the plain length
  length = plain.length();

  //this try is for a guard against not finding the letter
  try{
    //this will loop till it has gone through all the letters
    while (index < length)
    {
      //if the char at plain index in a digit then
      if (std::isdigit(plain.at(index)))
      {
        //add the figure value to encoded
        encoded = encoded + figvalue;
        //while the char at plain index in a digit loop
        while (std::isdigit(plain.at(index)))
        {
          //add the number at plain index to encoded 3 times
          encoded = encoded + plain.at(index) + plain.at(index) + plain.at(index);
          //add one to index
          index++;
          //if the index is bigger than plain length then break
          if (index > plain.length()-1)   //REVIEW: What would be the best fix for this
            break;
        }
        //add figvalue to encoded
        encoded = encoded + figvalue;
        //set figfound to true
        figfound = true;
        //index++;
      }
      //if code was found in the map then
      //this will find if it is a code word
      //TODO: I think the for loop can be changed at a find in unordered_map
      //instead of a for loop of code
      else if(codevalue != "null" && figfound != true)
      {
        //loop till codevalue is found
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

      //if a code word was found and a figure was found skip this
      if(codefound == false && figfound == false)
      {
        //get the letter at the index position
        temp = plain.at(index);
        //find the letter in temp and put in got
        got = table.find (temp);

        //if end is not found meaning that the search did not reach the end of the
        //map then
        if(got != table.end())
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
      //set codefound to false
      codefound = false;
      //set figfound to false
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
