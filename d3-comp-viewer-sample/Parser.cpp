#include <iostream>
#include "Parser.h"
#include <string>

using namespace std;

Parser::Parser(string s)
{
    level = 0;
    outputFile.open(s.c_str());
    ParseProcess("root");
}

void Parser::Push(string elem)
{
    level ++; // XXX not all the push increase level
    outputStack.push(elem);
}

string Parser::Pop(void)
{
    try
    {
        if (outputStack.empty())
            throw "Cann't pop from empty stack.";
        else
        {
            level --;
            string temp_top = PeekStackTop();
            outputStack.pop();
            return temp_top;
        }
    }
    catch (string e)
    {
        cout << e << endl;
    }
}

void Parser::Write(string s)
{
    // First, write indentation.
    outputFile << GetIndentation();
    outputFile << s ;
}

string Parser::GetIndentation()
{
    int temp_level = level;
    string indent = "";
    while (temp_level > 0)
    {
        indent += "\t";
        temp_level --;
    }
    return indent;
}

void Parser::CloseFile(void)
{
    std::cout << "Closing ..." << std::endl;
    // FlushStack
    while (!outputStack.empty())
    {
        Write(Pop());
    }
    outputFile.close();
}

void Parser::ParseProcess(string s)
{
    std::cout << "within parsing process ..." << std::endl;
    // if (!outputStack.empty() && level > 2)
    // {
    //     FlushStack();
    //     Write(",\n");
    // }
    if (level > 2)
    {
        while (!outputStack.empty() && level > 3) 
        {
            Write(Pop());
        }
        Write(Pop() + ",\n");
    }
    // outputFile << "level: " << level << endl;
    Write("{\n");
    Push("}");
    Write("\"name\": \"" + s + "\",\n");
    Write("\"children\": [\n");
    Push("\n" + GetIndentation() + "]\n"); // XXX fake
}

void Parser::ParseComponent(string s)
{
    if (PeekStackTop() == "}") 
    { 
        // meaning this is not the first component, and a comma is need
        Write(Pop() + ",\n");
    }
    Write("{\n");
    Push("}"); 
    Write("\"name\": \"" + s + "\",\n");
    Write("\"size\": 1006\n");
}

void Parser::ParseInterface(string s)
{
}
// a square bracket and a curly bracket left on the stack.
// void Parser::FlushStack()
// {
//     while (!outputStack.empty())
//     {
//         Write(Pop());
//     }
// }

string Parser::PeekStackTop()
{
    return outputStack.top();
}
