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
pair<int,int> types[14] {
  make_pair(0,0),
  make_pair(0,1),
  make_pair(2,0),
  make_pair(0,1),
  make_pair(4,0),
  make_pair(5,0),
  make_pair(2,0),
  make_pair(0,1),
  make_pair(0,1),
  make_pair(0,1),
  make_pair(-1,0),
  make_pair(1,0),
  make_pair(0,1),
  make_pair(0,1)
    };

int main()
{
    int W; // number of columns.
    int H; // number of rows.
    cin >> W >> H; cin.ignore();
    int tunnel[W][H];
    for (int y = 0; y < H; y++) {
        string LINE; // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
        getline(cin, LINE);
        stringstream line(LINE);
        for (int x = 0; x < W; x++) {
          line >> tunnel[x][y];
        }
    }
    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX; cin.ignore();
    int prevX;
    // game loop
    while (1) {
      int XI;
      int YI;
      string POS;
      cin >> XI >> YI >> POS; cin.ignore();
      pair<int,int> type = types[tunnel[XI][YI]];
      int outX = XI;
      int outY = YI;

      if (type.first == 2) {
        if (POS == "LEFT") outX += 1;
        else outX -= 1;
        outY += type.second;
      }
      else if (type.first == 4) {
        if (POS == "TOP") outX -= 1;
        else outY += 1;
      }
      else if (type.first == 5) {
        if (POS == "TOP") outX += 1;
        else outY += 1;
      }
      else {
        outX += type.first;
        outY += type.second;
      }
      //if (type.first == 2) outX = XI-1;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

      cout << outX << " " << outY << endl; // One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
}
}
