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
  if (parent == -1 && vals.size() > 1) {
    auto greatest = --vals.end();
    length = *greatest + *(--greatest) + 1;
  }else if (vals.size() > 0) {
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
        relationMap[yi].push_back(xi);
    }
    for(auto elem : relationMap)
    {
      cerr << elem.first << ": ";
      for (auto element : elem.second) {
        cerr << element << " ";
      }
      cerr << endl;
    }
    int nodesNum = relationMap.size();
    cerr << "nodesNum: " << nodesNum << endl;
    float minSteps = explore((relationMap.begin())->first)/2;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << minSteps << endl; // The minimal amount of steps required to completely propagate the advertisement
}
