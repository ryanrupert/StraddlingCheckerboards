/**
* Created By Ryan Rupert on 2/13/2017.
*/
#include "Encoding.h"
Crypto::Crypto()
{
  doc.load_file("table.xml");
}

bool Crypto::setLang(char language[3])
{
  for (int i = 0; i < 3; ++i)
  {
    lang[i] = language[i];
  }
  return getTable("CODE");
}

bool Crypto::getTable(std::string tableid)
{
  std::string num;
  std::string str;
  current = doc.child("TABLES").child(tableid.c_str()).find_child_by_attribute("Lang", lang);
  (tableid == "CODE") ? codes.clear() : table.clear();
  for(pugi::xml_node item = current.first_child(); item; item = item.next_sibling())
  {
    (tableid == "CODE") ? codes.insert({item.value(), item.name()}) : table.insert({item.value(), item.name()});
  }
}
