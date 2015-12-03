#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include <stack>

using namespace std;

vector<vector<char>> land;
set<pair<int,int>> explored;
stack<pair<int,int>> test;
int W, H;
int totalTests = 0;
int explore(int y, int x) {
  test.push(make_pair(y,x));
  explored.insert(make_pair(y,x));
  int size = 0;
  while (!test.empty()) {
    x = test.top().second;
    y = test.top().first;
    test.pop();
    cerr << "exploring " << x << " " << y << endl;
    totalTests++;
    if (land[y][x] == 'O') {
      size += 1;
      pair<int,int> yx;
      yx = make_pair(y,x+1);
      if (x+1 < W && explored.find(yx) == explored.end()) {
        test.push(yx);
        explored.insert(yx);
      }
      yx = make_pair(y,x-1);
      if (x-1 >= 0 && explored.find(yx) == explored.end()) {
        test.push(yx);
        explored.insert(yx);
      }
      yx = make_pair(y+1,x);
      if (y+1 < H && explored.find(yx) == explored.end()) {
        test.push(yx);
        explored.insert(yx);
      }
      yx = make_pair(y-1,x);
      if (y-1 >= 0 && explored.find(yx) == explored.end()) {
        test.push(yx);
        explored.insert(yx);
      }
    }
  }
  return size;
}



int main()
{
  cin >> W; cin.ignore();
  cin >> H; cin.ignore();
  int totalLake = 0;
  for (int i = 0; i < H; i++) {
    string row;
    cin >> row; cin.ignore();
    vector<char> tempRow;
    vector<bool> boolean;
    for (int i = 0; i < W; i++) {
      tempRow.push_back(row[i]);
      if (row[i] == 'O') totalLake++;
    }
    land.push_back(tempRow);

  }

  int N;
  cin >> N; cin.ignore();
  for (int i = 0; i < N; i++) {
    if (totalLake > W*H*.9) cout << totalLake << endl;
    else {
      explored.clear();
      int X;
      int Y;
      cin >> X >> Y; cin.ignore();
      int size = explore(Y,X);
      cerr << "DONE EXPLORING:" << size <<  endl;
      cout << size << endl;
    }
  }
  cerr << totalTests << endl;
}
