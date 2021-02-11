#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int countSafeRoom(vvi map, vpii gasPoints, int zeroCnt)
{
  queue<pii> que;
  int maxX = map.size();
  int maxY = map[0].size();
  vvi check(maxX, vi(maxY, false));
  int mx[4] = {0, 0, 1, -1};
  int my[4] = {1, -1, 0, 0};
  for (pii gasPoint : gasPoints)
  {
    que.push(gasPoint);
    check[gasPoint.first][gasPoint.second] = true;
  }

  while (!que.empty())
  {
    int curX = que.front().first;
    int curY = que.front().second;

    que.pop();
    for (int i = 0; i < 4; i++)
    {
      int nextX = curX + mx[i];
      int nextY = curY + my[i];
      if (nextX < 0 || nextX >= maxX || nextY < 0 || nextY >= maxY || check[nextX][nextY] || map[nextX][nextY] != 0)
      {
        continue;
      }
      check[nextX][nextY] = true;
      que.push(make_pair(nextX, nextY));
      zeroCnt--;
    }
  }
  return zeroCnt;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int ans = 0;

  vvi map(n, vi(m));

  int zeroCnt = 0;
  vpii gasPoints;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
      if (map[i][j] == 0)
      {
        zeroCnt++;
      }
      if (map[i][j] == 2)
      {
        gasPoints.push_back(make_pair(i, j));
      }
    }
  }
  for (int i = 0; i < n * m - 2; i++)
  {
    int firstX = i / m;
    int firstY = i % m;
    if (map[firstX][firstY] != 0)
    {
      continue;
    }
    map[firstX][firstY] = 1;
    for (int j = i + 1; j < n * m - 1; j++)
    {
      int secondX = j / m;
      int secondY = j % m;
      if (map[secondX][secondY] != 0)
      {
        continue;
      }
      map[secondX][secondY] = 1;
      for (int k = j + 1; k < n * m; k++)
      {
        int thirdX = k / m;
        int thirdY = k % m;
        if (map[thirdX][thirdY] != 0)
        {
          continue;
        }
        map[thirdX][thirdY] = 1;
        int cur = countSafeRoom(map, gasPoints, zeroCnt - 3);
        if (ans < cur)
        {
          ans = cur;
        }
        map[thirdX][thirdY] = 0;
      }
      map[secondX][secondY] = 0;
    }
    map[firstX][firstY] = 0;
  }

  cout << ans;

  return 0;
}