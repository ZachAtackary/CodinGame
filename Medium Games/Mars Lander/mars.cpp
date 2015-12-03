#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
struct pos {
  int x,y;
  pos(int x, int y) : x(x), y(y) {}
};

vector<pos*> land;

int main()
{
    int surfaceN; // the number of points used to draw the surface of Mars.
    cin >> surfaceN; cin.ignore();

    for (int i = 0; i < surfaceN; i++) {
      int landX; // X coordinate of a surface point. (0 to 6999)
      int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
      cin >> landX >> landY; cin.ignore();
      land.push_back(new pos(landX, landY));
    }
    //find flat spot
    pair<pos*,pos*> flat;
    for (int i = 0; i < land.size()-1; i++) {
      if (land[i]->y == land[i+1]->y) flat = make_pair(land[i], land[i+1]);
    }

    cerr << "flat area from " << flat.first->x << " to " << flat.second->x << endl;

    // game loop
    while (1) {
        int X;
        int Y;
        int hSpeed; // the horizontal speed (in m/s), can be negative.
        int vSpeed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int inpower; // the thrust power (0 to 4).
        int rotation;
        cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> inpower; cin.ignore();
        int power = 4;
        if (X > flat.second->x) {
          rotation = 23;
          if (hSpeed > 20) rotation = 23;
          if (hSpeed > 40) rotation = 30;
          if (hSpeed < -20) rotation = -23;
          if (hSpeed < -40) rotation = -30;
        }
        else if (X < flat.first->x) {
          rotation = -23;
          if (hSpeed > 20) rotation = 23;
          if (hSpeed > 40) rotation = 30;
          if (hSpeed < -20) rotation = -23;
          if (hSpeed < -40) rotation = -30;
        }
        else {
          if (hSpeed > 10) rotation = 23;
          else if (hSpeed < -10) rotation = -23;
          else rotation = 0;

          power = 0;
          if (vSpeed <= -37 || hSpeed < -20 || hSpeed > 20) power = 4;
          if (vSpeed > 10) power = 0;
        }
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << rotation << " " << power << endl; // rotate power. rotate is the desired rotation angle. power is the desired thrust power.
    }
}
