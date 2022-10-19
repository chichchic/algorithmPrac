#include <iostream>

using namespace std;

const int INF = 41;
int connections[10][5] = {{0, 1, 2, -1, -1}, {3, 7, 9, 11, -1}, {4, 10, 14, 15, -1}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15, -1}, {3, 14, 15, -1, -1}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}};

int getShortesCnt(int clock[16], int cur)
{
  if (cur == 10)
  {
    for (int i = 0; i < 16; i++)
    {
      if (clock[i] != 0)
        return INF;
    }
    return 0;
  }
  int ret = INF;
  for (int i = 0; i < 4; i++)
  {
    ret = min(ret, i + getShortesCnt(clock, cur + 1));
    for (int j = 0; j < 5; j++)
    {
      int num = connections[cur][j];
      if (num == -1)
      {
        break;
      }
      clock[num] = (clock[num] + 1) % 4;
    }
  }
  return ret;
}

int main()
{
  // freopen("./input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int c;
  cin >> c;
  while (c--)
  {
    int clock[16];
    for (int i = 0; i < 16; i++)
    {
      int clockPos;
      cin >> clockPos;
      clock[i] = clockPos / 3 % 4;
    }
    int ans = getShortesCnt(clock, 0);
    cout << (ans >= INF ? -1 : ans) << '\n';
  }

  return 0;
}