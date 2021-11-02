#include <iostream>

using namespace std;

int mem[101][101][101] = {};

int w(int a, int b, int c)
{
  if (mem[a + 50][b + 50][c + 50])
  {
    return mem[a + 50][b + 50][c + 50];
  }
  if (a > 20 || b > 20 || c > 20)
  {
    mem[a + 50][b + 50][c + 50] = w(20, 20, 20);
    return mem[a + 50][b + 50][c + 50];
  }

  if (a < b && b < c)
  {
    mem[a + 50][b + 50][c + 50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return mem[a + 50][b + 50][c + 50];
  }
  mem[a + 50][b + 50][c + 50] =
      w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
  return mem[a + 50][b + 50][c + 50];
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 101; i++)
  {
    for (int j = 0; j < 101; j++)
    {
      for (int k = 0; k < 101; k++)
      {
        if (i <= 50 || j <= 50 || k <= 50)
        {
          mem[i][j][k] = 1;
        }
      }
    }
  }
  while (true)
  {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == -1 && b == -1 && c == -1)
    {
      break;
    }
    printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
  }
  return 0;
}