#include <map>
#include "Component.h"
#include <iostream>
#include <string>

#ifndef _Process_h
#define _Process_h

class Process : virtual public Layer
{
  std::map<std::string, Component*> inners;
  public:
    Process();
    Process(std::string pName);
    virtual std::string ToString();
    virtual void SetIndent(int it);
    Component* FindInnerElement(std::string key);

    void Insert(std::string name, Component *inner);
    std::string InnersToString();
};
#endif
