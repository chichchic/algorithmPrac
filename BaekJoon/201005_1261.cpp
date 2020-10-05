#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};

typedef pair<int, int> pii;
typedef pair<int, pii> ipii;
typedef vector<ipii> vipii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
  // freopen("input.txt", "r", stdin);
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);

  int n, m;
  cin >> n >> m;
  priority_queue<ipii, vipii> pq;
  vvi maze(m, vi(n));
  vvi check(m, vi(n, 0));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf(" %1d", &maze[i][j]);
    }
  }

  pq.push(ipii(-0, pii(0, 0)));
  while (!pq.empty())
  {
    int curCol = pq.top().second.second;
    int curRow = pq.top().second.first;
    int curWall = pq.top().first;
    if (curCol == n - 1 && curRow == m - 1)
    {
      cout << -curWall;
      return 0;
    }
    pq.pop();
    for (int i = 0; i < 4; i++)
    {
      int nextCol = curCol + mx[i];
      int nextRow = curRow + my[i];
      if (nextCol < n && nextCol >= 0 && nextRow < m && nextRow >= 0 && !check[nextRow][nextCol])
      {
        check[nextRow][nextCol] = 1;
        if (maze[nextRow][nextCol] == 1)
        {
          pq.push(ipii(curWall - 1, pii(nextRow, nextCol)));
        }
        else
        {
          pq.push(ipii(curWall, pii(nextRow, nextCol)));
        }
      }
    }
  }
  return 0;
}