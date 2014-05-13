#include "Process.h"

Process::Process()
{
}

Process::Process(std::string pName) 
{
  name = pName;
  internal = "false";
}

std::string Process::ToString()
{
  std::string res;
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
  for (std::map<std::string, Component*>::iterator it = inners.begin(); it != inners.end(); it++) {
    it->second->SetIndent(indent);
  }
}

Component* Process::FindInnerElement(std::string key) 
{
  std::map<std::string, Component*>::iterator it = inners.find(key);
  if (it != inners.end()) {
    return it->second; 
  } else {
    return NULL;
  }
}

void Process::Insert(std::string name, Component *inner) 
{
  this->inners.insert(std::pair<std::string, Component*>(name, inner));
}

std::string Process::InnersToString() 
{
  std::string ret;
  std::map<std::string, Component*>::iterator it = inners.begin();
  ret += it->second->ToString();
  it++;
  for (; it != inners.end(); it++) {
    ret += ",\n";
    ret += it->second->ToString();
  }
  return ret;
}

