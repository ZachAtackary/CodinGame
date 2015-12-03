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
multiset<char> hand;
vector<string> words;

map<char,int> values {
  {'e',1},
  {'a',1},
  {'i',1},
  {'o',1},
  {'n',1},
  {'r',1},
  {'t',1},
  {'l',1},
  {'s',1},
  {'u',1},
  {'d',2},
  {'g',2},
  {'b',3},
  {'c',3},
  {'m',3},
  {'p',3},
  {'f',4},
  {'h',4},
  {'v',4},
  {'w',4},
  {'y',4},
  {'k',5},
  {'j',8},
  {'x',8},
  {'q',10},
  {'z',10}
};

int main()
{
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string W;
        getline(cin, W);
        words.push_back(W);
    }
    string LETTERS;
    getline(cin, LETTERS);
    for (int i = 0; i < LETTERS.size(); i++) {
      hand.insert(LETTERS[i]);
    }
    int maxScore = 0;
    string maxWord;
    for (auto& word: words) {
      auto handCopy = hand;
      bool canMakeWord = true;
      int score = 0;
      for (int i = 0; i < word.size(); i++) {
        auto iter = handCopy.find(word[i]);
        if (iter == handCopy.end()) {canMakeWord = false; break;}
        handCopy.erase(iter);
        score += values[word[i]];
      }
      if (canMakeWord && score > maxScore) {
          maxScore = score;
          maxWord = word;
      }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << maxWord << endl;
}
