/**
* Created By Ryan Rupert on 2/13/2017.
*/
#include "Encoding.h"
Crypto::Crypto()
{
  pugi::xml_parse_result result;
  result = doc.load_file("table.xml");
}

void Crypto::setLang(char language[3])
{
  //read language into lang
  for (int i = 0; i < 3; ++i)
  {
    lang[i] = language[i];
  }
  //reload the table code for the appropriate lang
  this->getTable("CODE");
}

void Crypto::getTable(std::string tableid)
{
  //get the child note with the correct table id and lang
  current = doc.child("TABLES").find_child_by_attribute(tableid.c_str(), "Lang", lang);
  //depending on the table id clear the correct map
  (tableid == "CODE") ? code.clear() : table.clear();
  //set item to the first child
  //while you are still in the child elements loop
  //before looping again set item to the next child
  for(pugi::xml_node item = current.first_child(); item; item = item.next_sibling())
  {
    //put the character and the num value in the correct map depending on the table id
    (tableid == "CODE") ? code.insert(std::make_pair(item.text().as_string(), item.attribute("Num").value())) : table.insert(std::make_pair(item.text().as_string(), item.attribute("Num").value()));
  }
}

char* Crypto::getLang()
{
  //return the language current language
  return lang;
}


std::string Crypto::findDigit(int &index, std::string plain, std::string encoded, std::string figvalue)
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
        //figfound = true;
        //index++;
	return encoded;
}

