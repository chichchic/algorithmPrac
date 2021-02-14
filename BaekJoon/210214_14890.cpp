#include <iostream>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, l;
  cin >> n >> l;

  int map[100][100];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> map[i][j];
    }
  }

  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    int cnt = 1;
    int curHeight = map[i][0];
    bool canGo = true;
    for (int j = 1; j < n && canGo; j++)
    {
      if (curHeight == map[i][j])
      {
        cnt++;
        continue;
      }
      int dif = map[i][j] - curHeight;
      if (dif == 1)
      {
        if (cnt >= l)
        {
          cnt = 1;
          curHeight = map[i][j];
          continue;
        }
        canGo = false;
      }
      else if (dif == -1)
      {
        int temp = l - 1;
        int tempHeight = map[i][j];
        while (temp-- > 0)
        {
          if (tempHeight != map[i][++j])
          {
            canGo = false;
            break;
          }
        }
        cnt = 0;
        curHeight = map[i][j];
      }
      else
      {
        canGo = false;
      }
    }
    if (canGo)
    {
      ans++;
    }
  }
  for (int i = 0; i < n; i++)
  {
    int cnt = 1;
    int curHeight = map[0][i];
    bool canGo = true;
    for (int j = 1; j < n && canGo; j++)
    {
      if (curHeight == map[j][i])
      {
        cnt++;
        continue;
      }
      int dif = map[j][i] - curHeight;
      if (dif == 1)
      {
        if (cnt >= l)
        {
          cnt = 1;
          curHeight = map[j][i];
          continue;
        }
        canGo = false;
      }
      else if (dif == -1)
      {
        int temp = l - 1;
        int tempHeight = map[j][i];
        while (temp-- > 0)
        {
          if (tempHeight != map[++j][i])
          {
            canGo = false;
            break;
          }
        }
        cnt = 0;
        curHeight = map[j][i];
      }
      else
      {
        canGo = false;
      }
    }

    if (canGo)
    {
      ans++;
    }
  }

  cout << ans;

  return 0;
}