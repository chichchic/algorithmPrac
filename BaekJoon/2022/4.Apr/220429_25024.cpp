#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  int date[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  while (t--)
  {
    int x, y;
    cin >> x >> y;
    if (x >= 0 && x <= 23 && y >= 0 && y <= 59)
    {
      cout << "Yes ";
    }
    else
    {
      cout << "No ";
    }
    if (x >= 1 && x <= 12 && y >= 1 && y <= date[x])
    {
      cout << "Yes\n";
    }
    else
    {
      cout << "No\n";
    }
  }

  return 0;
}