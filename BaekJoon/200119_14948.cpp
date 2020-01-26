#include <iostream>
#include <queue>

using namespace std;

long long base[101][101];
int n, m;
short dx[4] = {1, -1, 0, 0};
short dy[4] = {0, 0, 1, -1};

struct mRec
{
  int x;
  int y;
  int jump;
};

void check(long long start, long long end)
{
  bool visit[101][101] = {};
  bool arrive = false;
  long long bound = (start + end) / 2;
  visit[0][0] = true;
  if (start == end)
  {
    cout << start;
    return;
  }
  queue<mRec> que;

  mRec temp = {0, 0, 1};
  que.push(temp);

  while (!que.empty())
  {
    mRec cur = que.front();

    que.pop();

    if (cur.x == n - 1 && cur.y == m - 1)
    {
      cout << bound << " b\n";
      arrive = true;
      break;
    }
    for (int i = 0; i < 4; i++)
    {
      mRec noUse = {cur.x + dx[i], cur.y + dy[i], cur.jump};
      mRec use = {cur.x + (dx[i] * 2), cur.y + (dy[i] * 2), 0};
      if (!(noUse.x >= 0 && noUse.x < n && noUse.y >= 0 && noUse.y < m && !visit[noUse.x][noUse.y]))
        continue;
      if (base[noUse.x][noUse.y] <= bound)
      {
        // cout << noUse.x << " " << noUse.y << '\n';
        visit[noUse.x][noUse.y] = true;
        que.push(noUse);
      }
      else if (cur.jump)
      {
        if (use.x >= 0 && use.x < n && use.y >= 0 && use.y < m && !visit[use.x][use.y])
        {
          // cout << use.x << " " << use.y << " Jump\n";
          visit[use.x][use.y] = true;
          que.push(use);
        }
      }
    }
  }
  if (arrive)
    check(start, bound - 1);
  else
    check(bound + 1, end);
}

int main()
{
  long long min = 1234567890;
  long long max = 0;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> base[i][j];
      if (min > base[i][j])
        min = base[i][j];
      if (max < base[i][j])
        max = base[i][j];
    }
  }

  check(min, max);
  return 0;
}