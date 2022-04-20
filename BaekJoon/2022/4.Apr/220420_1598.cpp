#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int nx = (n - 1) % 4;
  int mx = (m - 1) % 4;
  int ny = (n - 1) / 4;
  int my = (m - 1) / 4;
  int x = mx - nx;
  int y = my - ny;
  if (x < 0)
  {
    x *= -1;
  }
  if (y < 0)
  {
    y *= -1;
  }
  cout << x + y;

  return 0;
}