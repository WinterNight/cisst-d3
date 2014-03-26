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

using namespace std;
class Interface : virtual public Layer
{
  private:
    int id;
    vector<int> connections;
  public:
    Interface();
    Interface(string iName, string isInternal, int interfaceID);
    virtual string ToString();
    virtual void SetIndent(int it);
    void AddConnection(int interfaceID);
    int GetInterfaceID();
};
#endif // Interface_h
