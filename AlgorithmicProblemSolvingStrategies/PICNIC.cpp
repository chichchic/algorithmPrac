#include <iostream>

using namespace std;

int getCombCnt(int pair, int n, int cur, bool (*friends)[10], bool isPair[10])
{
  if (pair == n / 2)
  {
    return 1;
  }

  int ret = 0;

  for (int i = cur; i < n; i++)
  {
    if (isPair[i])
    {
      continue;
    }
    for (int j = i + 1; j < n; j++)
    {
      if (isPair[j])
      {
        continue;
      }

      if (friends[i][j])
      {
        isPair[i] = true;
        isPair[j] = true;
        ret += getCombCnt(pair + 1, n, i + 1, friends, isPair);
        isPair[i] = false;
        isPair[j] = false;
      }
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
    int n, m;
    cin >> n >> m;
    bool friends[10][10] = {};
    for (int i = 0; i < m; i++)
    {
      int a, b;
      cin >> a >> b;
      friends[a][b] = true;
      friends[b][a] = true;
    }
    bool isPair[10] = {};
    cout << getCombCnt(0, n, 0, friends, isPair) << '\n';
  }

  return 0;
}