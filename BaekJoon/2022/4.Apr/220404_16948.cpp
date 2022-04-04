#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  visited[r1][c1] = true;
  queue<pair<int, int>> que;
  que.push({r1, c1});
  que.push({-1, -1});
  int mr[6] = {-2, -2, 0, 0, 2, 2};
  int mc[6] = {-1, 1, -2, 2, -1, 1};
  int answer = 0;
  bool find = false;
  while (!que.empty())
  {
    int cr = que.front().first;
    int cc = que.front().second;
    if (cr == r2 && cc == c2)
    {
      find = true;
      break;
    }
    que.pop();
    if (cr == -1)
    {
      if (que.empty())
      {
        break;
      }
      answer++;
      que.push({-1, -1});
      continue;
    }
    for (int i = 0; i < 6; i++)
    {
      int nr = mr[i] + cr;
      int nc = mc[i] + cc;
      if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc])
      {
        continue;
      }
      visited[nr][nc] = true;
      que.push({nr, nc});
    }
  }
  if (find)
  {
    cout << answer;
  }
  else
  {
    cout << -1;
  }

  return 0;
}