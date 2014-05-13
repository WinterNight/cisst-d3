#include <iostream>
#include <string>
#include <map>

#ifndef _Layer_h
#define _Layer_h

class Layer
{
  protected:
    int indent;
    std::string internal = "false";
  public:
    std::string name;

    std::string ReplaceDotInName(std::string aName) {
      std::string res(aName);
      for (int i = 0; i < res.size(); i++) {
        if (res[i] == '.') {
          res[i] = '-';
        }
      }
      return res;
    }

    void IncreaseIndent() {
      indent++;
    };

    void DecreaseIndent() {
      indent--;
    };

    std::string WriteIndent() {
      std::string res = "";
      for (int i = 0; i < indent; i++) {
        res += "  ";
      }
      return res;
    };

    virtual void SetIndent(int it) = 0;
    virtual std::string ToString() = 0;

    std::string GetName() {
      return name;
    };

};
#endif
