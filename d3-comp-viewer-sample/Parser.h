// #ifndef _Parser_h
// #define _Parser_h

// #include <iostream>
#include <fstream>
#include <stack>
using namespace std;

class Parser
{
private:
    ofstream outputFile;
    stack<string> outputStack; // close parenthesis are pushed onto stack
    int level;
public:
    Parser(string s);
    void Push(string elem);
    string Pop(void);
    void Write(string s);
    string GetIndentation();
    void CloseFile(void);
    void ParseProcess(string s);
    void ParseComponent(string s);
    void ParseInterface(string s);
    void ParseConnection(string s);
    // void FlushStack(); // write close parentheses 
    string PeekStackTop();
};
