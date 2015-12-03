#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <list>
#include <climits>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
list<int> data;
int main()
{
    int n;
    cin >> n; cin.ignore();
    string vs;
    getline(cin, vs);
    stringstream sData(vs);
    int datapoint;
    for (int i = 0; i < n; i++) {
      sData >> datapoint;
      data.push_back(datapoint);
    }
    cerr << vs << endl;
    int loss = 0;
    bool lookingForHigh = true;
    int high = 0;
    int low = INT_MAX;
    for (auto iter = data.begin(); iter != data.end(); iter++) {
      if (lookingForHigh) {
        if (*iter > high) high = *iter;
        else {
          lookingForHigh = false;
          iter--;
          cerr << "found high: " << high << endl;
        }
      }else {
        if (*iter < low) low = *iter;
        else {
          cerr << "found low: " << low << endl;
          lookingForHigh = true;
          if (low-high < loss) loss = low-high;
          low = INT_MAX;
          iter--;
        }
      }
    }
    if (low-high < loss) loss = low-high;
    //int loss = 0;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << loss << endl;
}
