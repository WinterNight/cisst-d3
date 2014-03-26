#include "Interface.h"
#include <iostream>
#include <string>
#include <map>

#ifndef _Component_h
#define _Component_h

using namespace std;
class Component : virtual public Layer
{
  public:
    Component();
    Component(string cName, string isInternal);
    virtual string ToString();
    virtual void SetIndent(int it);
};
#endif
