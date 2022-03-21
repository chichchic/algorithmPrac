#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int win = 0;
  for (int i = 0; i < 6; i++)
  {
    char c;
    cin >> c;
    if (c == 'W')
    {
      win++;
    }
  }

  switch (win)
  {
  case 1:
  case 2:
    cout << 3;
    break;
  case 3:
  case 4:
    cout << 2;
    break;
  case 5:
  case 6:
    cout << 1;
    break;
  default:
    cout << -1;
  }

  return 0;
}