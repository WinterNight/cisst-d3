#include <iostream>
#include <sstream>
#include "Parser.h"
#include <string>

Parser::Parser(std::string s)
{
    indent = 0;
    outputFile.open(s.c_str());
}

std::string Parser::ProcessToString()
{
  std::string ret = "";
  ret += WriteIndent() + "\"" + "processes" + "\"" + ": {\n";

  // indentation should be incresed
  ret += InnersToString();

  // indentation should be decresed
  ret += "\n" + WriteIndent() + "}";
  return ret;
}

void Parser::SetupConnections() 
{
  connections = new int*[interfaceSize];
  for (int i = 0; i < interfaceSize; i++) {
    connections[i] = new int[interfaceSize];
    for (int j = 0; j < interfaceSize; j++) {
      connections[i][j] = 0;
    }
  }
}

std::string Parser::MatrixToString()
{
  std::string ret;

  ret += WriteIndent() + "\"" + "matrix" + "\"" + ": [\n";
  IncreaseIndent();

  ret += ConnectionToString();

  DecreaseIndent();
  ret += "\n" + WriteIndent() + "]";
  return ret;
}

std::string Parser::ConnectionToString()
{
  std::string ret;

  for (int i = 0; i < interfaceSize; i++) {
    if (i != 0) {
      ret += ",\n" + WriteIndent() + "[";
    } else {
      ret += WriteIndent() + "[";
    }

    int flag = 0; // 0: an interface has no connection with others
                  // 1: have at least one conneciton
    for (int k = 0; k < interfaceSize; k++) {
      if (connections[i][k] != 0) {
        flag = 1;
      }
    }
    if (flag == 0) {
      connections[i][i] = 50;
    }

    for (int j = 0; j < interfaceSize; j++) {
      if (j != 0) {
        ret += ", ";
      }
      ret += NumberToString(connections[i][j]); 
    }

    ret += "]";
  }

  return ret;
}

std::string Parser::ToString()
{
  std::string ret;
  ret += WriteIndent() + "{\n";
  // indentation should be increased
  IncreaseIndent();
  ret += MatrixToString();
  ret += ",\n";

  SetIndent(indent);
  ret += ProcessToString(); 
  // indentation should be decreased
  DecreaseIndent();
  ret += "\n" + WriteIndent() + "}\n";

  return ret;
}

void Parser::SetIndent(int i) {
  for (std::map<std::string, Process*>::iterator it = inners.begin(); it != inners.end(); it++) {
    it->second->SetIndent(indent);
  }
}

std::string Parser::WriteIndent()
{
  std::string ret = "";
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
  // Write to file
  std::cout << ToString();
  outputFile << ToString() << std::endl;
}

int Parser::GetInterfaceID() 
{
  interfaceSize++;
  return interfaceSize - 1; // size - 1 is the ID
}

void Parser::ParseConnection(std::string clientProcess, 
                            std::string clientComponent, 
                            std::string clientInterface,
                            std::string serverProcess, 
                            std::string serverComponent, 
                            std::string serverInterface)
{

  if (connections == NULL) {
    SetupConnections();
  }

  Process *p1, *p2;
  Component *c1, *c2;
  Interface *i1, *i2;

  p1 = FindInnerElement(clientProcess);
  if (p1 != NULL) {
    c1 = p1->FindInnerElement(clientComponent);
  } else {
    std::cout << "missing process....." << clientProcess << std::endl;
  }
  if (c1 != NULL) {
    i1 = c1->FindInnerElement(clientInterface);
  } else {
    std::cout << "missing component....." << clientComponent << std::endl;
  }

  p2 = FindInnerElement(serverProcess);
  if (p2 != NULL) {
    c2 = p2->FindInnerElement(serverComponent);
  } else {
    std::cout << "missing process....." << serverProcess << std::endl;
  }
  if (c2 != NULL) {
    i2 = c2->FindInnerElement(serverInterface);
  } else {
    std::cout << "missing component....." << serverComponent << std::endl;
  }

  
  connections[i1->GetInterfaceID()][i2->GetInterfaceID()] = amount;
  connections[i2->GetInterfaceID()][i1->GetInterfaceID()] = amount;
}

Process* Parser::FindInnerElement(std::string key) 
{
  std::map<std::string, Process*>::iterator it = inners.find(key);
  if (it != inners.end()) {
    return it->second; 
  } else {
    return NULL;
  }
}

void Parser::Insert(std::string name, Process *inner) 
{
  inners.insert(std::pair<std::string, Process*>(name, inner));
}

std::string Parser::InnersToString() 
{
  std::string ret;
  std::map<std::string, Process*>::iterator it = inners.begin();
  ret += it->second->ToString();
  it++;
  for (; it != inners.end(); it++) {
    ret += ",\n";
    ret += it->second->ToString();
  }
  return ret;
}

std::string Parser::NumberToString(int number)
{
  std::ostringstream ss;
  ss << number;
  return ss.str();
}
