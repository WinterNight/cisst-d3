#include <string>
#include <map>

#ifndef _Layer_h
#define _Layer_h

using namespace std;
class Layer
{
  protected:
    int indent;
    string name;
    string internal = "false";
    map<string, Layer*> inners;
  public:
    void IncreaseIndent() {
      indent++;
    };

    void DecreaseIndent() {
      indent--;
    };

    string WriteIndent() {
      string res = "";
      for (int i = 0; i < indent; i++) {
        res += "  ";
      }
      return res;
    };

    virtual void SetIndent(int it) = 0;
    virtual string ToString() = 0;

    string GetName() {
      return name;
    };

    void Insert(string name, Layer *inner) {
      inners.insert(pair<string, Layer*>(name, inner));
    };

    string InnersToString() {
      string ret;
      map<string, Layer*>::iterator it = inners.begin();
      ret += it->second->ToString();
      it++;
      for (; it != inners.end(); it++) {
        ret += ",\n";
        ret += it->second->ToString();
      }
      return ret;
    };

    virtual Layer* FindInnerElement(string key) {
      map<string, Layer*>::iterator it = inners.find(key);
      if (it != inners.end()) {
        return it->second; 
      } else {
        return NULL;
      }
    };

    void AddConnection(int interfaceID);
};
#endif
