#include <map>
#include "Component.h"
#include <iostream>
#include <string>

#ifndef _Process_h
#define _Process_h

using namespace std;
class Process : virtual public Layer
{
  public:
    Process();
    Process(string pName);
    virtual string ToString();
    virtual void SetIndent(int it);
};
#endif
