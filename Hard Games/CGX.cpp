#pragma once
#include <string>
#include <iostream>

using namespace std;
string value;

void parse(string str) {
  string letter;
  char c;
  string indent;
  bool shtuffBeforeBlock = false;
  bool newBlock = false;
  bool inString = false;

  for(int i = 0; i < str.size(); i++) {
    c = str[i];
    letter = str[i];

    if (c == '\'') inString = !inString;
    if (inString) {
      value += letter;
      continue;
    }

    switch(c) {
    case '(':
      newBlock = true;
      if (shtuffBeforeBlock) {value += "\n" + indent;}
      indent += "    ";
    case ';':
      value += letter + '\n' + indent;
      shtuffBeforeBlock = false;
      break;
    case ')':
      value += '\n';
      if (newBlock) for (int i = 0; i < indent.size()+1; i++) value.pop_back();
      for (int i = 0; i < 4; i++) if (indent != "") indent.pop_back();
      value += indent + letter;
      newBlock = false;
      break;
    default:
      if (!isspace(c)) {
        newBlock = false;
        shtuffBeforeBlock = true;
        value += letter;
      }
    }
  }
}

int main() {
  string str;
  int N;
  cin >> N; cin.ignore();
  for (int i = 0; i < N; i++) {
    string CGXLine;
    getline(cin, CGXLine);
    str += CGXLine + '\n';
  }
  parse(str);
  cout << value;
}
