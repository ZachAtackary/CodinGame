#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int tx, ty, goal;
bool map[40][18];
bool emptySpot[40][18];
int rand1, randd2;
int avgGiantX = 0;
int avgGiantY = 0;

int findGiants() {
  cerr << "finding giants" << endl;
  int count = 0;
  for (int x = tx-4; x <= tx+4; x++) {
    for (int y = ty-4; y <= ty+4; y++) {
      //cerr << "looping: " << x << " " << y << endl;
      if (map[x][y] == true) count++;
    }
  }
  return count;
}

void falseMap( bool map[40][18]) {
  for (int x = 0; x < 40; x++) {
    for (int y = 0; y < 18; y++) {
      map[x][y] = false;
    }
  }
}

void findEmptySpots() {
  for (int x = 1; x < 39; x++) {
    for (int y = 1; y < 17; y++) {
      if(map[x][y] == false &&
         map[x-1][y-1] == false &&
         map[x-1][y] == false &&
         map[x-1][y+1] == false &&
         map[x][y-1] == false &&
         map[x][y] == false &&
         map[x][y+1] == false &&
         map[x+1][y-1] == false &&
         map[x+1][y] == false &&
         map[x+1][y+1] == false) emptySpot[x][y] = true;
    }
  }
}

bool inDanger() {
  if(map[tx][ty] == false &&
         map[tx-1][ty-1] == false &&
         map[tx-1][ty] == false &&
         map[tx-1][ty+1] == false &&
         map[tx][ty-1] == false &&
         map[tx][ty] == false &&
         map[tx][ty+1] == false &&
         map[tx+1][ty-1] == false &&
         map[tx+1][ty] == false &&
         map[tx+1][ty+1] == false) return false;
  cerr << "in danger!" << endl;
  return true;
}

string findEscape() {
  if(emptySpot[tx-1][ty-1] && tx-1 > 0 && ty-1 > 0) {tx -= 1; ty -= 1; return "NW";}
  else if(emptySpot[tx+1][ty-1] && tx+1 < 40 && ty-1 > 0) {tx += 1; ty -= 1; return "NE";}
  else if(emptySpot[tx][ty-1] && ty-1 > 0) {ty -= 1; return "N";}

  else if(emptySpot[tx+1][ty] && tx+1 < 40) {tx += 1; return "E";}
  else if(emptySpot[tx-1][ty] && tx-1 > 0) {tx -= 1; return "W";}

  else if(emptySpot[tx-1][ty+1] && tx-1 > 0 && ty+1 < 19) {tx -= 1; ty += 1; return "SW";}
  else if(emptySpot[tx][ty+1] && ty+1 < 19) {ty += 1; return "S";}
  else if(emptySpot[tx+1][ty+1] && tx+1 < 40 && ty+1 < 19) {tx += 1; ty += 1; return "SE";}
  else {cerr << "CANT RUN, STRIKE!" << endl; return "STRIKE";}
}

void printMap(bool map[40][18]) {
  for (int y = 0; y < 18; y++) {
    for (int x = 0; x < 40; x++) {
      if (x == tx && y == ty) cerr << "T";
      else cerr << map[x][y];
    }
    cerr << endl;
  }
}

void goTowardsCenter() {
  string first = "";
  string second = "";
  cerr << "tx: " << tx << endl;
  cerr << "AVGGIANT: " << avgGiantX << ", " << avgGiantY << endl;
  if (tx < avgGiantX) {second = "E"; tx++;}
  else if (tx > avgGiantX) {second = "W"; tx--;}
  if (ty < avgGiantY && ty > 0) {first = "N"; ty--;}
  else if (ty > avgGiantY && ty < 17) {first = "S"; ty++;}
  if ((first+second).size()) {
    //checkSafe(first+second);
    cout << first << second << endl;
  }
  else cout << "WAIT" << endl;
}

int main()
{
  cin >> tx >> ty; cin.ignore();
  //cout << "N" << endl;
  // game loop
  while (1) {
    cerr << "TEST" << endl;
    falseMap(map);
    falseMap(emptySpot);
    cerr << "FALSED" << endl;
    int H; // the remaining number of hammer strikes.
    int N; // the number of giants which are still present on the map.
    cin >> H >> N; cin.ignore();
    cerr << "GOT DATA" << endl;
    goal = N/H;
    int avgX = 0;
    int avgY = 0;
    for (int i = 0; i < N; i++) {
      int X;
      int Y;
      cin >> X >> Y; cin.ignore();
      cerr << "giant: " << X << " " << Y << endl;
      avgX += X;
      avgY += Y;
      map[X][Y] = true;
    }
    avgX /= N;
    avgY /= N;
    if (N > 40) avgGiantX = avgX;
    else avgGiantX = avgX+1;
    avgGiantY = avgY;
    cerr << "THOR: " << tx << " ," << ty << endl;
    cerr << "AVGGIANT" << avgGiantX << ", " << avgGiantY << endl;
    findEmptySpots();
    cerr << "AVGGIANT" << avgGiantX << ", " << avgGiantY << endl;
    printMap(emptySpot);
    cerr << "AVGGIANT" << avgGiantX << ", " << avgGiantY << endl;
    int giantsAroundThor = findGiants();
    cerr << "AVGGIANT" << avgGiantX << ", " << avgGiantY << endl;
    cerr << "goal: " << goal << endl;
    cerr << "giantsAroundThor: " << giantsAroundThor << endl;
    if (inDanger()) cout << findEscape() << endl;
    else if (giantsAroundThor < goal) {cerr << "AVGGIANT" << avgGiantX << ", " << avgGiantY << endl;goTowardsCenter();}
    else cout << "STRIKE" << endl;
  }
}
