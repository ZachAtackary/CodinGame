#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

list<int> budgets;
list<int> contribution;

int main()
{
    int N;
    cin >> N; cin.ignore();
    int cost;
    cin >> cost; cin.ignore();
    for (int i = 0; i < N; i++) {
        int B;
        cin >> B; cin.ignore();
        budgets.push_back(B);
    }
    budgets.sort();
    budgets.reverse();
    int amountContributed = 0;
    for (auto budget: budgets) {
      amountContributed += budget;
    }
    int extra = amountContributed - cost;
    int amountRemove = 0;
    int numRemoved = 0;
    vector<int> removed;
    int theSame = 0;
    while (true) {
      cerr << "amount removed:" << amountRemove << endl;
      numRemoved++;
      int contributed, nextContributed;
      int value = 0;
      if (budgets.size() > 1) {
        bool nextSame = false;
        auto begin = budgets.begin();
        contributed = *(begin);
        nextContributed = *(++begin);
        if (contributed == nextContributed) nextSame = true;
        removed.push_back(*budgets.begin());
        budgets.pop_front();
        if (budgets.size() > 1 || nextSame) value = contributed - nextContributed;
        else value = contributed;
        //cerr << "value: " << value << endl;
        if (value == 0) theSame++;
        else {theSame++; value *= theSame;}
        //cerr << "theSame: " << theSame << endl;
      } else if (budgets.size() == 1){
        auto begin = budgets.begin();
        contributed = *(begin);
        removed.push_back(*budgets.begin());
        budgets.pop_front();
        value = contributed;
      } else break;
      //cerr << "value: " << value << endl;
      amountRemove += value;
      if (amountRemove >= extra) break;
    }
    budgets.reverse();
    int totalRemoved = 0;
    for (int& val : removed) {totalRemoved += val; val = 0;}
    cerr << "totalRemoved: " << totalRemoved << endl;
    int totalPutBack = totalRemoved - extra;
    //cerr << "totalPutBack: " << totalPutBack << endl;
    int amountPutBack, amountExtra;
    while (removed.size()) {
      int numberOfAdditions = removed.size();
      //cerr << "adding back" << endl;
      //cerr << "amount still removed: " << removed.size() << endl;
      amountPutBack = totalPutBack/numberOfAdditions;
      //cerr << "amountPutBack: " << amountPutBack << endl;
      amountExtra = totalPutBack%numberOfAdditions;
      for (int& val : removed) {
        val += amountPutBack;
      }
      totalPutBack = amountExtra;
      //cerr << "totalPutBack: " << totalPutBack << endl;
      budgets.push_back(removed[removed.size()-1]);

      removed.pop_back();
    }
    if (amountContributed < cost) {cout << "IMPOSSIBLE" << endl; return 0;}
    for (auto budget :budgets) {
      cout << budget << endl;
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

}
