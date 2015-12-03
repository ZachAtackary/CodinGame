#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <utility>
#include <climits>
#include <set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


multiset<int> Xs;
multiset<int> Ys;
int main()
{
  //cerr << "max size: " << houses.max_size() << endl;
  long long int N;
  cin >> N; cin.ignore();
  for (int i = 0; i < N; i++) {
    long long int X;
    long long int Y;
    cin >> X >> Y; cin.ignore();
    Xs.insert(X);
    Ys.insert(Y);
  }
  auto iter = Ys.begin();
  for (int i = 0; i < Ys.size()/2; i++) {
    iter++;
  }
  long long int mainWire = *iter;
  cerr << "mainWire: " << mainWire << endl;
  long long int totalLength = *(--Xs.end()) - *Xs.begin();
  //if (minX < 1) totalLength++;
  cerr << "totalLength: " << totalLength << endl;
  long long int lastOutput = 0;
  for (auto iter = Ys.begin(); iter != Ys.end(); iter++) {
    if (abs(*iter - mainWire) != lastOutput) cerr << abs(*iter - mainWire) << " ";
    totalLength += abs(*iter - mainWire);
    lastOutput = abs(*iter - mainWire);
  }
  cerr << endl;
  // }

  // Write an action using cout. DON'T FORGET THE "<< endl"
  // To debug: cerr << "Debug messages..." << endl;

  cout << totalLength << endl;
}
