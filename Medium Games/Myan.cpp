#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define FillNumArray(numArray, H, Size)                      \
  for (int h = 0; h < H; h++) {                              \
    string numeral;                                          \
    cin >> numeral; cin.ignore();                            \
    for (int num = 0; num < Size; num++) {                   \
      for (int l = 0; l < L; l++) {                          \
        numArray[num][h][l] = numeral[num*L+l];              \
      }                                                      \
    }                                                        \
  };
#define FillNumVector(numArray, numbers, Size)               \
  for (int num = 0; num < Size; num++) {                     \
    vector<vector<char>> rows;                               \
    for (int l = 0; l < L; l++) {                            \
      vector<char> column;                                   \
      for (int h = 0; h < H; h++) {                          \
        column.push_back(numArray[num][h][l]);               \
      }                                                      \
      rows.push_back(column);                                \
    }                                                        \
    numbers.push_back(rows);                                 \
  };
#define MyanStandardConversion(Num, numbersList)             \
  long long int Num[numbersList.size()];                     \
  for (int i = 0; i < numbersList.size(); i++) {             \
    for (int j = 0; j < numbers.size(); j++) {               \
      if (numbers[j] == numbersList[i]){                     \
        cerr << "EQUAL" << j << endl;                        \
        Num[i] = j;                                          \
      }                                                      \
    }                                                        \
    cerr << "number" << Num[i] << endl;                      \
  };
#define CalcTotals(Number)                                   \
  long long int total ## Number = 0;                         \
  for (int i=0; i<numbers ## Number.size(); i++) {           \
    total ## Number += standardNum ## Number[i] * pow(20,i); \
  };

vector<vector<vector<char>>> numbers, numbers1, numbers2;
int L, H;

void printNumbers(vector<vector<vector<char>>> numbers) {
  for (auto number: numbers) {
    for (int y = 0; y < H; y++) {
      for (int x = 0; x < L; x++) {
        cerr << number[x][y];
      }
      cerr << endl;
    }
    cerr << endl;
  }
}

void coutNumber(vector<vector<char>> number) {
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < L; x++) {
      cout << number[x][y];
    }
    cout << endl;
  }
}

int main()
{
    cin >> L >> H; cin.ignore();
    char numArray[20][L][H];
    FillNumArray(numArray, H, 20);
    FillNumVector(numArray, numbers, 20);

    int S1;
    cin >> S1; cin.ignore();
    char numArray1[S1/H][L][H];
    FillNumArray(numArray1, S1, S1/H);
    FillNumVector(numArray1, numbers1, S1/H);
    printNumbers(numbers1);

    int S2;
    cin >> S2; cin.ignore();
    char numArray2[S2/H][L][H];
    FillNumArray(numArray2, S2, S2/H);
    FillNumVector(numArray2, numbers2, S2/H);
    printNumbers(numbers2);

    reverse(numbers1.begin(), numbers1.end());
    reverse(numbers2.begin(), numbers2.end());

    MyanStandardConversion(standardNum1, numbers1); //creates variable standardNum1
    MyanStandardConversion(standardNum2, numbers2); //creates variable standardNum2

    CalcTotals(1); //creates variable total1
    CalcTotals(2); //creates variable total1

    string operation;
    cin >> operation; cin.ignore();

    long long int total;
    if      (operation == "+") total = total1 + total2;
    else if (operation == "-") total = total1 - total2;
    else if (operation == "*") total = total1 * total2;
    else if (operation == "/") total = total1 / total2;
    cerr << total1 << " " << operation << " " << total2 << " = " << total << endl;

    vector<long long int> total20Base;
    do {
      total20Base.push_back(total%20);
      total = total/20;
    } while (total != 0);

    reverse(total20Base.begin(), total20Base.end());

    for (int i=0; i<total20Base.size(); i++) { cerr << total20Base[i] << endl; }
    for (int i=0; i<total20Base.size(); i++) { coutNumber(numbers[total20Base[i]]); }
}
