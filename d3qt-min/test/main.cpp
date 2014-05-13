#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
  std::string name = "hel.lo";
  for (int i = 0; i < name.size(); i++) {
    if (name[i] == '.') {
      name[i] = '-';
    }
  }
  std::cout << name << std::endl;
  return 0;
}
