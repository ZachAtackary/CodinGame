#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int sizeRoller;
    int timesRun;
    int numOfGroups;
    cin >> sizeRoller >> timesRun >> numOfGroups; cin.ignore();
    int groups[numOfGroups];
    for (int i = 0; i < numOfGroups; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        groups[i] = Pi;
    }
    int riders, i, lineStart, looping;
    i = 0;
    long long int money = 0;
    for (int times = 0; times < timesRun; times++) {
      riders = 0;
      lineStart = i;
      if (false/*lineStart == 0*/) looping = times;
      if (false/*looping != 0 && (times + looping) == */) {

      }
      else {
        do {
          if (riders + groups[i] <= sizeRoller) {
            riders += groups[i];

          money += groups[i];
          i = (i + 1)%numOfGroups;
            }
          else break;
        } while (lineStart != i);
        //cerr << "sending roller" << endl;
        if (times%10000 == 0) cerr << times << endl;
      }
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << money << endl;
}
