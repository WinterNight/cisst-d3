#include "Interface.h"
#include <iostream>
#include <string>
#include <map>

#ifndef _Component_h
#define _Component_h

class Component : virtual public Layer
{
  std::map<std::string, Interface*> inners;
  public:
    Component();
    Component(std::string cName, std::string isInternal);
    virtual std::string ToString();
    virtual void SetIndent(int it);
    Interface* FindInnerElement(std::string key);

    void Insert(std::string name, Interface *inner);
    std::string InnersToString();
};
#endif
