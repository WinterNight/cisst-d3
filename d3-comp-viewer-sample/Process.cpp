#include "Process.h"

Process::Process()
{
}

Process::Process(string pName) 
{
  name = pName;
  internal = "false";
}

string Process::ToString()
{
  string res;
  res += WriteIndent() + "\"" + name + "\" : {\n";
  // indentation should be increased
  IncreaseIndent();
  res += WriteIndent() + "\"" + "internal" + "\"" + " : " + internal + ",\n";
  res += WriteIndent() + "\"" + "data"     + "\"" + " : {\n"; 

  res += InnersToString();
  // indentation should be decreased
  res += "\n" + WriteIndent() + "}";
  DecreaseIndent();
  res += "\n" + WriteIndent() + "}";
  return res;
}

void Process::SetIndent(int i)
{
  indent = i + 1;
  for (map<string, Layer*>::iterator it = inners.begin(); it != inners.end(); it++) {
    it->second->SetIndent(indent);
  }
}

