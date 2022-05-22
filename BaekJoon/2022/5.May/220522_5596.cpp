#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int s = 0, t = 0;
  for (int i = 0; i < 4; i++)
  {
    int score;
    cin >> score;
    s += score;
  }
  for (int i = 0; i < 4; i++)
  {
    int score;
    cin >> score;
    t += score;
  }
  cout << (s >= t ? s : t);

  return 0;
}