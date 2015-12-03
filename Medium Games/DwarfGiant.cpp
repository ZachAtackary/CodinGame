#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

map<int, vector<int>> relationMap;

int explore(int node, int parent = -1) {
  cerr << "exploring " << node << " from node " << parent << endl;
  vector<int>& relations = relationMap[node];
  multiset<int> vals;
  for (auto iter = relations.begin(); iter != relations.end(); iter++) {
    if (*iter != parent) {
      int val = explore(*iter, node);
      vals.insert(val);
    }
  }
  int length;
  if (vals.size() > 0) {
    auto greatest = --vals.end();
    length = *greatest + 1;
  }else length = 1;
  cerr << "length at node " << node << ": " << length << endl;
  return length;
}

int main()
{
    int n; // the number of adjacency relations
    cin >> n; cin.ignore();

    for (int i = 0; i < n; i++) {
        int xi; // the ID of a person which is adjacent to yi
        int yi; // the ID of a person which is adjacent to xi
        cin >> xi >> yi; cin.ignore();
        relationMap[xi].push_back(yi);
    }
    for(auto elem : relationMap)
    {
      cerr << elem.first << ": ";
      for (auto element : elem.second) {
        cerr << element << " ";
      }
      cerr << endl;
    }
    vector<int> testThese;
    for (auto relation : relationMap) {
      int person = relation.first;
      bool mentored = false;
      for (auto relation : relationMap) {
        for (auto student : relation.second) {
          if (student == person) {
            mentored = true;
            cerr << "student: " << person << endl;
          }
        }
      }
      if (mentored == false) {
        cerr << "mentor: " << relation.first << endl;
        testThese.push_back(relation.first);
      }
    }
    int nodesNum = relationMap.size();
    cerr << "nodesNum: " << nodesNum << endl;
    int maxSteps = 0;
    for (int i = 0; i < testThese.size(); i++) {
      int steps = explore(testThese[i]);
      if (steps > maxSteps) maxSteps = steps;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << maxSteps<< endl;
}
