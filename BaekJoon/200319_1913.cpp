#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main()
{
  // freopen("input.txt", "r", stdin);

  int n, input;
  cin >> n >> input;

  int ansx, ansy;
  vi temp(n, -1);
  vector<vi> ans_table(n, temp);

  int x = n / 2, y = n / 2;
  ans_table[x][y] = 1;
  y--;

  int mx[4] = {1, 0, -1, 0};
  int my[4] = {0, 1, 0, -1};

  int move = 2;
  int rot = 0;
  int rotcnt = n / 2;
  int cur = 2;
  int cnt = 0;
  while (rotcnt)
  {
    ans_table[y][x] = cur++;
    cnt++;
    if (cnt >= move)
    {
      rot++;
      cnt = 0;
    }
    if (rot >= 4)
    {
      move += 2;
      rotcnt--;
      rot = 0;
      y--;
      continue;
    }
    x += mx[rot];
    y += my[rot];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << ans_table[i][j] << ' ';
      if (input == ans_table[i][j])
      {
        ansy = i + 1;
        ansx = j + 1;
      }
    }
    cout << '\n';
  }
  cout << ansy << ' ' << ansx;
  return 0;
}