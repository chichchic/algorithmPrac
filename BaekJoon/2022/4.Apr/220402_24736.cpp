#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int scoreTable[5] = {6, 3, 2, 1, 2};
  int aScore = 0;
  int bScore = 0;
  int count;
  for (int i = 0; i < 5; i++)
  {
    cin >> count;
    aScore += scoreTable[i] * count;
  }
  for (int i = 0; i < 5; i++)
  {
    cin >> count;
    bScore += scoreTable[i] * count;
  }
  cout << aScore << ' ' << bScore;
  return 0;
}