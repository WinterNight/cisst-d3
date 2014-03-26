#include "Component.h"

Component::Component()
{
}

Component::Component(string cName, string isInternal)
{
  name = cName;
  internal = isInternal;
}

string Component::ToString() 
{
  string res;
  res += WriteIndent() + "\"" + name + "\" : {\n";
  // indentation should be increased
  IncreaseIndent();
  res += WriteIndent() + "\"" + "internal" + "\"" +  " : " + internal + ",\n";
  res += WriteIndent() + "\"" + "data"     + "\"" +  " : {\n";

  res += InnersToString();

  // indentation should be decreased
  res += "\n" + WriteIndent() + "}";
  DecreaseIndent();
  res += "\n" + WriteIndent() + "}";
  return res;
}

void Component::SetIndent(int i)
{
  indent = i + 2;
  
  for (map<string, Layer*>::iterator it = inners.begin(); it != inners.end(); it++) {
    it->second->SetIndent(indent);
  }
}

