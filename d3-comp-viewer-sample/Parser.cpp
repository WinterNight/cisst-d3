#include <iostream>
#include "Parser.h"
#include <string>

Parser::Parser(string s)
{
    indent = 0;
    outputFile.open(s.c_str());
}

string Parser::ProcessToString()
{
  string ret = "";
  ret += WriteIndent() + "\"" + "processes" + "\"" + ": {\n";

  // indentation should be incresed
  ret += InnersToString();

  // indentation should be decresed
  ret += "\n" + WriteIndent() + "}";
  return ret;
}

string Parser::MatrixToString()
{
}

string Parser::ToString()
{
  string ret;
  ret += WriteIndent() + "{\n";
  // indentation should be increased
  IncreaseIndent();
  // ret += MatrixToString();
  ret += ",\n";

  SetIndent(indent);
  ret += ProcessToString(); 
  // indentation should be decreased
  DecreaseIndent();
  ret += "\n" + WriteIndent() + "}";

  return ret;
}

void Parser::SetIndent(int i) {
  for (map<string, Layer*>::iterator it = inners.begin(); it != inners.end(); it++) {
    it->second->SetIndent(indent);
  }
}

string Parser::WriteIndent()
{
  string ret = "";
  for (int i = 0; i < indent; i++) {
    ret += "  ";
  }
  return ret;
}

void Parser::CloseFile(void)
{
    std::cout << "Closing ..." << std::endl;
    outputFile.close();
}

void Parser::Write()
{
  std::cout << ToString();
}

int Parser::GetInterfaceID() {
  interfaceID++;
  return interfaceID - 1;
}

void Parser::ParseConnection(string clientProcess, string clientComponent, string clientInterface,
                             string serverProcess, string serverComponent, string serverInterface) {

  cout << "test core dump ......." << endl;
  Layer *p1, *c1, *i1;
  Layer *p2, *c2, *i2;
  // Layer *p1 =     FindInnerElement(clientProcess);
  // Layer *c1 = p1->FindInnerElement(clientComponent);
  // Layer *i1 = c1->FindInnerElement(clientInterface);
  p1 = FindInnerElement(clientProcess);
  if (p1 != NULL) {
    c1 = p1->FindInnerElement(clientComponent);
  } else {
    cout << "missing process....." << clientProcess << endl;
  }
  if (c1 != NULL) {
    i1 = c1->FindInnerElement(clientInterface);
  } else {
    cout << "missing component....." << clientComponent << endl;
  }

  // Layer *p2 =     FindInnerElement(serverProcess);
  // Layer *c2 = p2->FindInnerElement(serverComponent);
  // Layer *i2 = c2->FindInnerElement(serverInterface);
  p2 = FindInnerElement(serverProcess);
  if (p2 != NULL) {
    c2 = p2->FindInnerElement(serverComponent);
  } else {
    cout << "missing process....." << serverProcess << endl;
  }
  if (c2 != NULL) {
    i2 = c2->FindInnerElement(serverInterface);
  } else {
    cout << "missing component....." << serverComponent << endl;
  }

  // i1->AddConnection(i2->GetInterfaceID());
  // i2->AddConnection(i1->GetInterfaceID());
}

