#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

// SOOOOOO UGLY NEVER LOOK AT THIS ONE AGAIN!!!!!!!!
int main()
{
    int R;
    cin >> R; cin.ignore();
    int L;
    cin >> L; cin.ignore();
    stringstream line;
    stringstream nextLine;
    line << R << ' ';
    for (int i = 1; i < L; i++) {
      cerr << "test" << endl;
      char c;
      string lastInput = " ";
      int count = 0;
      cerr << "line: " << line.str() << endl;
      line.clear();
      while (line.get(c)) {
        string in ;
        in += c;
        cerr << "line: " << line.str() << endl;
        int j = 0;
        while (line.str()[j] != ' ') {
          line.get(c);
          in += c;
          cerr << in << endl;
          j++;
        }

        //line.ignore();
        cerr << "input: " << in << endl;
        if (in == lastInput || lastInput == " ") {
          //cerr << "inc count" << endl;
          count ++;
          lastInput = in;
        } else {
          cerr << "building nextline" << endl;
          nextLine << count << ' ' << lastInput;
          count = 0;
          lastInput = " ";
          line.unget();
          line.unget();
          line.clear();
        }
      }
      if (count != 0) {
        cerr << "building nextline outside" << lastInput << endl;
        nextLine << count << ' ' << lastInput;
      }
      string strIn = nextLine.str();
      nextLine.str("");
      line.str(strIn);
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    char input;
    line.clear();
    stringstream out;
    while (line.get(input)) {
      out << input;
    }
    string finalOut = out.str();
    if (finalOut[finalOut.length()-1] == ' ') finalOut.pop_back();
    cout << finalOut << endl;
}
