#include <iostream>
#include <queue>

using namespace std;

struct pos
{
  int h;
  int n;
  int m;
};

int m, n, h;
int total, cur = 0;
int box[101][101][101]; // h, n, m;

queue<pos> que1;

int ans = 0;

void ripe()
{
  while (!que1.empty())
  {
    pos temp = que1.front();
    que1.pop();

    if (temp.h == -1)
    {
      if (que1.empty())
        break;
      que1.push(temp);
      ans++;
      continue;
    }

    if (temp.h + 1 < h)
    {
      pos input = {temp.h + 1, temp.n, temp.m};
      if (box[input.h][input.n][input.m] == 0)
      {
        box[input.h][input.n][input.m] = 1;
        cur++;
        que1.push(input);
      }
    }
    if (temp.n + 1 < n)
    {
      pos input = {temp.h, temp.n + 1, temp.m};
      if (box[input.h][input.n][input.m] == 0)
      {
        box[input.h][input.n][input.m] = 1;
        cur++;
        que1.push(input);
      }
    }
    if (temp.m + 1 < m)
    {
      pos input = {temp.h, temp.n, temp.m + 1};
      if (box[input.h][input.n][input.m] == 0)
      {
        box[input.h][input.n][input.m] = 1;
        cur++;
        que1.push(input);
      }
    }
    if (temp.h - 1 >= 0)
    {
      pos input = {temp.h - 1, temp.n, temp.m};
      if (box[input.h][input.n][input.m] == 0)
      {
        box[input.h][input.n][input.m] = 1;
        cur++;
        que1.push(input);
      }
    }
    if (temp.n - 1 >= 0)
    {
      pos input = {temp.h, temp.n - 1, temp.m};
      if (box[input.h][input.n][input.m] == 0)
      {
        box[input.h][input.n][input.m] = 1;
        cur++;
        que1.push(input);
      }
    }
    if (temp.m - 1 >= 0)
    {
      pos input = {temp.h, temp.n, temp.m - 1};
      if (box[input.h][input.n][input.m] == 0)
      {
        box[input.h][input.n][input.m] = 1;
        cur++;
        que1.push(input);
      }
    }
  }
}

int main()
{
  cin >> m >> n >> h;

  total = m * n * h;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < m; k++)
      {
        cin >> box[i][j][k];
        if (box[i][j][k] == 1)
        {
          cur++;
          pos temp = {i, j, k};
          que1.push(temp);
        }
        else if (box[i][j][k] == -1)
        {
          total--;
        }
      }
    }
  }

  pos temp = {-1, -1, -1};
  que1.push(temp);

  ripe();
  if (total == cur)
    cout << ans;
  else
    cout << -1;

  return 0;
}
