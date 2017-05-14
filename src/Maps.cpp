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
  for (int i = 0; i < 3; ++i)
  {
    lang[i] = language[i];
  }
  this->getTable("CODE");
}

void Crypto::getTable(std::string tableid)
{
  std::string name;
  std::string num;
  current = doc.child("TABLES").find_child_by_attribute(tableid.c_str(), "Lang", lang);
  (tableid == "CODE") ? code.clear() : table.clear();
  for(pugi::xml_node item = current.first_child(); item; item = item.next_sibling())
  {
    (tableid == "CODE") ? code.insert(std::make_pair(item.text().as_string(), item.attribute("Num").value())) : table.insert(std::make_pair(item.text().as_string(), item.attribute("Num").value()));
  }
}

char* Crypto::getLang()
{
  return lang;
}
