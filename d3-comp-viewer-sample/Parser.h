// #ifndef _Parser_h
// #define _Parser_h

#include <fstream>
#include <map>
#include "Process.h"

using namespace std;
class Parser : virtual public Layer
{
private:
    int interfaceID = 0;
    ofstream outputFile;
public:
    Parser(string s);
    string ProcessToString();
    string MatrixToString();
    virtual string ToString();
    string WriteIndent();
    void CloseFile(void);
    void Write();
    int GetInterfaceID();
    void ParseConnection(string clientProcess, string clientComponent, string clientInterface, 
                         string serverProcess, string serverComponent, string serverInterface);

    virtual void SetIndent(int it);
};
