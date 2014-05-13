/**
 * Indentation is hard coded.
 */
#include "Layer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#ifndef _Interface_h
#define _Interface_h

class Interface : virtual public Layer
{
  public:
    int id;
    Interface();
    Interface(std::string iName, std::string isInternal, int interfaceID);
    virtual std::string ToString();
    virtual void SetIndent(int it);
    int GetInterfaceID();
};
#endif // Interface_h
