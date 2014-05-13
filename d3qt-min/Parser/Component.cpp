#include "Component.h"

Component::Component()
{
}

Component::Component(std::string cName, std::string isInternal)
{
  name = cName;
  internal = isInternal;
}

std::string Component::ToString() 
{
  std::string res;
  res += WriteIndent() + "\"" + ReplaceDotInName(name) + "\" : {\n";
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
  
  for (std::map<std::string, Interface*>::iterator it = inners.begin(); it != inners.end(); it++) {
    it->second->SetIndent(indent);
  }
}

Interface* Component::FindInnerElement(std::string key) 
{
  std::map<std::string, Interface*>::iterator it = inners.find(key);
  if (it != inners.end()) {
    return it->second; 
  } else {
    return NULL;
  }
}

void Component::Insert(std::string name, Interface *inner) {
  this->inners.insert(std::pair<std::string, Interface*>(name, inner));
}

std::string Component::InnersToString() {
  std::string ret;
  std::map<std::string, Interface*>::iterator it = inners.begin();
  ret += it->second->ToString();
  it++;
  for (; it != inners.end(); it++) {
    ret += ",\n";
    ret += it->second->ToString();
  }
  return ret;
}

