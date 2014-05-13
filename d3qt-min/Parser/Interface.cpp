#include "Interface.h"

Interface::Interface()
{
}

Interface::Interface(std::string iName, std::string isInternal, int interfaceID) 
{
  name = iName;
  internal = isInternal;
  id = interfaceID;
}

std::string Interface::ToString() 
{
  std::string res; 
  res += WriteIndent() + "\"" + ReplaceDotInName(name) + "\"" + " : {\n";
  // indentation should be increased
  IncreaseIndent();
  res += WriteIndent() + "\"" + "internal" + "\"" + " : " + internal + "\n";
  // indentation should be decreased
  DecreaseIndent();
  res += WriteIndent() + "}";
  return res;
}

void Interface::SetIndent(int i) 
{
  indent = i + 2;
}

int Interface::GetInterfaceID() 
{
  return id;
}

