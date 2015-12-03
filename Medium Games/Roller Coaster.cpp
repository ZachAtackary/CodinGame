#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
  set<int> lineStarts;
  map<int,int> lineStartTimes;
  list<pair<int,long long int>> peopleInRoller;
    int sizeRoller;
    int timesRun;
    int numOfGroups;
    cin >> sizeRoller >> timesRun >> numOfGroups; cin.ignore();
    //timesRun *= 15;
    int groups[numOfGroups];
    for (int i = 0; i < numOfGroups; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        groups[i] = Pi;
    }
    int riders, i, lineStart, looping;
    i = 0;
    looping = 0;
    long long int money = 0;
    long long int lastMoney = 0;
    int loopTotal = 0;
    for (int times = 0; times < timesRun; times++) {
      riders = 0;
      lineStart = i;
      if (lineStarts.find(lineStart) != lineStarts.end() && looping == 0) {
        cerr << "looped" << endl;
        looping = times - lineStartTimes[i];
        auto iter = peopleInRoller.begin();
        for(;iter->first != i; iter++);
        cerr << iter->first << iter->second << endl;
        for(;iter != peopleInRoller.end(); iter++) {
          cerr << "adding to loop total" << endl;
          loopTotal += iter->second;
        }
      }
      lineStartTimes[i] = times;
      lineStarts.insert(lineStart);
      //
      //cerr << looping << endl;
      if (looping != 0 && ((times + looping-1) < timesRun)) {
        //cerr << "loopTotal: " << loopTotal << endl;
        //cerr << "LOOPING!!!" << endl;
        times += looping - 1;
        money += loopTotal;
        //cerr << "money: " << money << endl;
      }
      else {
        //int startingIndex = i;
        do {
          riders += groups[i];
          //cerr << groups[i] << endl;

          if (riders > sizeRoller) {
            //cerr << "full roller" << endl;
            riders -= groups[i];
            break;
          }
          //cerr << "i: " << i << endl;
          money += groups[i];
          i = (i + 1)%numOfGroups;
        } while (lineStart != i);
        //cerr << "sending roller" << endl;
        if (times%10000 == 0) cerr << times << endl;
        //cerr << "peopleInRoller" << money-lastMoney << " Index: " << lineStart << endl;
        peopleInRoller.push_back(make_pair(lineStart,money-lastMoney));
        lastMoney = money;
      }
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << money << endl;
}
