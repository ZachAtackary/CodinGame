#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
struct Elevator {
  int floor, pos;
  Elevator(int floor, int pos):floor(floor), pos(pos) {}
};

vector<Elevator*>elevators;



int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    for (int i = 0; i < nbElevators; i++) {
      int elevatorFloor; // floor on which this elevator is found
      int elevatorPos; // position of the elevator on its floor
      cin >> elevatorFloor >> elevatorPos; cin.ignore();
      elevators.push_back(new Elevator(elevatorFloor, elevatorPos));
    }

    // game loop
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();
        cerr << "clone pos: " << clonePos << endl << "exit pos: " << exitPos << endl << "direction: " << direction << endl;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        if (direction == "NONE") {cout << "WAIT" << endl; continue;}
        int goal;
        if (cloneFloor == exitFloor) goal = exitPos;
        else {
          for (auto iter = elevators.begin(); iter != elevators.end(); iter++) {
            auto elevator = **iter;
            if (elevator.floor == cloneFloor) goal = elevator.pos;
          }
        }
        cerr << "goal pos: " << goal << endl;
        if (clonePos < goal) {
          if (direction == "RIGHT") cout << "WAIT" << endl;
          else cout << "BLOCK" << endl;
        }
        else if (clonePos > goal) {
          cerr << "test" << endl;
          if (direction == "LEFT") cout << "WAIT" << endl;
          else cout << "BLOCK" << endl;
        }
        else cout << "WAIT" << endl;
        //cout << "WAIT" << endl; // action: WAIT or BLOCK
    }
}
