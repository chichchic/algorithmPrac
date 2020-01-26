#include <iostream>
#include <queue>

using namespace std;

struct point
{
  int x;
  int y;
  long long day;
};

struct sPoint
{
  int x;
  int y;
};

bool ice[1503][1503] = {};
long long iceDay[1503][1503];
bool iceCheck[1503][1503];

int r, c;
int swan[2][2];
int mx[4] = {-1, 1, 0, 0};
int my[4] = {0, 0, -1, 1};
long long ans = 2551234;
void swanMove(long long start, long long end)
{
  long long mid = (start + end) / 2;
  queue<sPoint> que;
  sPoint fSwan = {swan[0][0], swan[0][1]};
  bool check[1503][1503] = {};
  bool arrive = false;
  check[fSwan.x][fSwan.y] = true;
  que.push(fSwan);

  while (!que.empty())
  {
    sPoint cur = que.front();
    que.pop();
    if (cur.x == swan[1][0] && cur.y == swan[1][1])
    {
      arrive = true;
      break;
    }
    for (int i = 0; i < 4; i++)
    {
      sPoint next = {cur.x + mx[i], cur.y + my[i]};
      if (next.x >= 0 && next.y >= 0 && next.x < r && next.y < c && !check[next.x][next.y] && iceDay[next.x][next.y] <= mid)
      {
        check[next.x][next.y] = true;
        que.push(next);
      }
    }
  }

  if (arrive)
  {
    if (ans > mid)
      ans = mid;
    if (start >= end)
      return;
    swanMove(start, mid - 1);
  }
  else
  {
    if (start >= end)
      return;
    swanMove(mid + 1, end);
  }
}

int main()
{
  cin >> r >> c;
  char temp;
  bool firstSwan = true;
  queue<point> que;
  int lastDay = 0;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> temp;
      if (temp == 'X')
      {
        ice[i][j] = true;
      }
      else
      {
        point temp = {i, j, 0};
        que.push(temp);
        iceDay[i][j] = 0;
        iceCheck[i][j] = true;
      }

      if (temp == 'L')
      {
        if (firstSwan)
        {
          swan[0][0] = i;
          swan[0][1] = j;
          firstSwan = false;
        }
        else
        {
          swan[1][0] = i;
          swan[1][1] = j;
        }
      }
    }
  }
  while (!que.empty())
  {
    point cur = que.front();
    que.pop();

    for (int i = 0; i < 4; i++)
    {
      point next = {cur.x + mx[i],
                    cur.y + my[i],
                    cur.day + 1};
      if (next.x >= 0 && next.y >= 0 && next.x < r && next.y < c && !iceCheck[next.x][next.y] && ice[next.x][next.y])
      {
        iceDay[next.x][next.y] = next.day;
        if (lastDay < next.day)
          lastDay = next.day;
        que.push(next);
        ice[next.x][next.y] = false;
        iceCheck[next.x][next.y] = true;
      }
    }
  }
  swanMove(0, lastDay);
  cout << ans;
  return 0;
}