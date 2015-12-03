#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int totalCount = 0;

struct node {
  char value;
  list<node*> children;
  node(char value = ' ') : value(value) {}

  void addNum(list<char> number) {
    for (auto iter = children.begin(); iter != children.end(); iter++) {
      auto& childNode = **iter;
      if(childNode.value ==  *number.begin()) {
        number.pop_front();
        if (number.size() != 0) childNode.addNum(number);
        return;
      }
    }
    cerr << "adding new child: " << *number.begin() << endl;
    node* newChild = new node(*number.begin());
    children.push_back(newChild);
    number.pop_front();
    totalCount++;
    if(number.size() != 0) newChild->addNum(number);
  }
};
node base;
int main()
{
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string telephone;
        cin >> telephone;cin.ignore();
        list<char> num;
        for (int i = 0; i < telephone.size(); i++) {
          num.push_back(telephone[i]);
        }
        cerr << "adding num: " << telephone << endl;
        base.addNum(num);
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << totalCount << endl; // The number of elements (referencing a number) stored in the structure.
}
