#include "Interface.h"

Interface::Interface()
{
}

Interface::Interface(string iName, string isInternal, int interfaceID) 
{
  name = iName;
  internal = isInternal;
  id = interfaceID;
}

string Interface::ToString() 
{
  string res; 
  res += WriteIndent() + "\"" + name + "\"" + " : {\n";
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

void Interface::AddConnection(int interfaceID) 
{
  cout << "success" << endl;
  connections.push_back(interfaceID);
}

int Interface::GetInterfaceID() 
{
  return id;
}

