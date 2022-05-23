#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int ch = 100, sa = 100;
  for (int i = 0; i < n; i++)
  {
    int c, s;
    cin >> c >> s;
    if (c > s)
    {
      sa -= c;
    }
    if (s > c)
    {
      ch -= s;
    }
  }
  cout << ch << '\n'
       << sa;

  return 0;
}