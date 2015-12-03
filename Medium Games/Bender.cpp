#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct xyPair {
  int y,x;
  xyPair(int x = 0, int y = 0) : x(x), y(y) {}
};


vector<vector<char>> map;
xyPair velocity(0,1);
xyPair pos;
xyPair goal;
vector<xyPair*> teleporters;
bool breakerMode = false;

void printMap() {
  for (int y= 0; y < map.size(); y++) {
    for (int x = 0; x < map[y].size(); x++) {
      if (pos.y == y && pos.x == x) cerr << '@';
      else cerr << map[y][x];
    }
    cerr << endl;
  }
}

int priorities[] = {0,1,2,3};
string direction[] = {"SOUTH","EAST","NORTH","WEST"};
xyPair* velocities[] = {
  new xyPair(0,1),
  new xyPair(1,0),
  new xyPair(0,-1),
  new xyPair(-1,0)
};

int findIndex(xyPair vel) {
  if (vel.y == 1) return 0;
  if (vel.x == 1) return 1;
  if (vel.y == -1) return 2;
  if (vel.x == -1) return 3;
}

void changeVel() {
  cerr << "changing velocity" << endl;
  for (int i = 0; i < 4; i++) {
    xyPair vel = *velocities[priorities[i]];
    if (map[pos.y+vel.y][pos.x+vel.x] != 'X' && map[pos.y+vel.y][pos.x+vel.x] != '#' ) {velocity = vel; return;}
  }
}

void reversePriorities() {
  cerr << "reversing priorities" << endl;
  int temp, i;
  int size = 4;
  for (i = 0; i < size/2; ++i) {
    temp = priorities[size-i-1];
    priorities[size-i-1] = priorities[i];
    priorities[i] = temp;
  }
  for (i = 0; i < 4; i++) {
    cerr << priorities[i];
  }
  cerr << endl;
}

void teleport() {
  cerr << "teleporting" << endl;
  if (pos.x == teleporters[0]->x && pos.y == teleporters[0]->y) pos = *teleporters[1];
  else pos = *teleporters[0];
}

int main()
{
  int L;
  int C;
  cin >> L >> C; cin.ignore();
  for (int Y = 0; Y < L; Y++) {
    string input;
    getline(cin, input);
    vector<char> row;
    for (int X = 0; X < input.size(); X++) {
      row.push_back(input[X]);
      if (input[X] == '@') {
        pos.y = Y;
        pos.x = X;
        row[row.size()-1] = ' ';
      }
      if (input[X] == '$') {
        goal.y = Y;
        goal.x = X;
      }
      if (input[X] == 'T') {
        teleporters.push_back(new xyPair(X,Y));
      }
    }
    map.push_back(row);
  }
  int moveCount = 0;
  string output;

  while (true) {
    moveCount++;
    printMap();
    cerr << "location: " << pos.x << ", " << pos.y << endl;

    if (pos.x == goal.x && pos.y == goal.y) {
      break;
    }
    if (moveCount > 5000) {output = "LOOP"; break;}
    char loc = map[pos.y][pos.x];
    switch(loc) {
    case 'S': velocity = *velocities[0]; break;
    case 'E': velocity = *velocities[1]; break;
    case 'N': velocity = *velocities[2]; break;
    case 'W': velocity = *velocities[3]; break;
    case 'B': breakerMode = !breakerMode; break;
    case 'I': reversePriorities(); break;
    case 'T': teleport(); break;
    }
    char& obstical = map[pos.y+velocity.y][pos.x+velocity.x];
    if (obstical == '#' || (obstical == 'X' && !breakerMode)) {
      changeVel();
    }
    else if (obstical == 'X' && breakerMode) {
      obstical = ' ';
    }

    pos.y += velocity.y;
    pos.x += velocity.x;
    output += direction[findIndex(velocity)] + "\n";
    cerr << direction[findIndex(velocity)] << endl;

  }
  cout << output << endl;
}
