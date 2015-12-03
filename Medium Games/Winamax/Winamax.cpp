#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

list<int> cardsP1;
list<int> cardsP2;
int gameRounds = 0;

void printList(list<int> inList) {
  for (auto iter = inList.begin(); iter != inList.end(); iter++) {
    cerr << *iter << endl;
  }
}

int cardToInt(string &card) {
  card.pop_back();
  int intCard;
  if      (card == "J") intCard = 11;
  else if (card == "Q") intCard = 12;
  else if (card == "K") intCard = 13;
  else if (card == "A") intCard = 14;
  else intCard = stoi(card);
  return intCard;
}

void duel() {

}

string fight() {
  while (cardsP1.size() != 0 && cardsP2.size() != 0) {
    cerr << "new round" << endl;
    auto cardP1 = cardsP1.begin();
    auto cardP2 = cardsP2.begin();
    while (true) {
      cerr << "testing card values" << endl;
      if (*cardP1 > *cardP2) {
        cerr << *cardP1 << " is greater than " << *cardP2 << endl;
        cardP1++;
        for(auto iter = cardsP1.begin(); iter != cardP1;) {
          cerr << "iter val" << *iter << endl;
          cardsP1.push_back(*iter);
          iter++;
          cardsP1.pop_front();
        }
        cardP2++;
        for(auto iter = cardsP2.begin(); iter != cardP2;) {
          cardsP1.push_back(*iter);
          iter++;
          cardsP2.pop_front();
        }
        gameRounds++;
        break;
      }
      else if (*cardP1 < *cardP2) {
        cerr << *cardP1 << " is less than " << *cardP2 << endl;
        cardP1++;
        for(auto iter = cardsP1.begin(); iter != cardP1;) {
          cardsP2.push_back(*iter);
          iter++;
          cardsP1.pop_front();
        }
        cardP2++;
        for(auto iter = cardsP2.begin(); iter != cardP2;) {
          cardsP2.push_back(*iter);
          iter++;
          cardsP2.pop_front();
        }
        gameRounds++;
        break;
      }
      else {
        cerr << "CARDS VALUE ARE THE SAME" << endl;
        for(int i = 0; i < 4; i++) {
          if (++cardP1 == cardsP1.end()) return "PAT";
          if (++cardP2 == cardsP2.end()) return "PAT";
        }
      }
    }
  }
  stringstream output;
  if (cardsP1.size() == 0) output << "2 " << gameRounds;
  else output << "1 " << gameRounds;
  return output.str();
}

int main()
{
    int n; // the number of cards for player 1
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string cardp1; // the n cards of player 1
        cin >> cardp1; cin.ignore();
        int card = cardToInt(cardp1);
        cardsP1.push_back(card);
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp2; // the m cards of player 2
        cin >> cardp2; cin.ignore();
        int card = cardToInt(cardp2);
        cardsP2.push_back(card);
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    cerr << "player 1 cards:" << endl;
    printList(cardsP1);

    cerr << "player 2 cards:" << endl;
    printList(cardsP2);

    cout << fight() << endl;

    //cout << "PAT" << endl;
}
