#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
  std::unordered_map<std::string, int> mymap = {{"test", 1}, {"test3", 2}};
  std::string input;
  int key = 0;
  std::cout << "This program is a test of maps currently this is" << std::endl;
  std::cout << "going to be a test of unordered maps" << std::endl;
  std::cout << "Please enter a string that will be entered into the map." << std::endl;
  std::cin >> input;
  std::cin.get();
  std::cout << "Please enter a intager for the key id." << std::endl;
  std::cin >> key;
  std::cin.get();
  mymap.insert (std::make_pair(input, key));
  std::cout << "This is the output of the map." << std::endl;
  for (const auto& foo : mymap) {
    std::cout << foo.first << ":" << foo.second << std::endl;
  }
  std::cout << "Is this correct?" << std::endl;
  std::cin.get();
  return 0;
}
