// #ifndef _Parser_h
// #define _Parser_h

#include <fstream>
#include <map>
#include "Process.h"

class Parser : virtual public Layer
{
private:
    int interfaceSize = 0; // also be used as ID
    std::ofstream outputFile;
    std::map<std::string, Process*> inners;
    int ** connections;
    int amount = 500;
    
public:
    Parser(std::string s);

    void Write();
    std::string WriteIndent();
    virtual std::string ToString();
    std::string ProcessToString();
    std::string MatrixToString();

    void CloseFile(void);
    int GetInterfaceID();
    void ParseConnection(std::string clientProcess, 
                        std::string clientComponent, 
                        std::string clientInterface, 
                        std::string serverProcess, 
                        std::string serverComponent, 
                        std::string serverInterface);

    virtual void SetIndent(int it);
    Process* FindInnerElement(std::string key);

    void Insert(std::string name, Process *inner);
    std::string InnersToString();
    std::string ConnectionToString();
    void SetupConnections();
    std::string NumberToString(int number);
};
