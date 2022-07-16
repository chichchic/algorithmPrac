#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 102;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  queue<pair<int, int>> cloudes;
  vector<vector<int>> answer(h, vector<int>(w, INF));
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      char cloud;
      cin >> cloud;
      if (cloud == 'c')
      {
        cloudes.push({i, j});
      }
    }
  }
  cloudes.push({-1, -1});
  int minute = 0;
  while (!cloudes.empty())
  {
    int x = cloudes.front().first;
    int y = cloudes.front().second;
    cloudes.pop();
    if (x == -1)
    {
      minute++;
      if (cloudes.empty())
      {
        break;
      }
      cloudes.push({-1, -1});
      continue;
    }
    answer[x][y] = min(minute, answer[x][y]);
    if (y + 1 < w)
    {
      cloudes.push({x, y + 1});
    }
  }
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (answer[i][j] == INF)
      {
        cout << -1 << ' ';
        continue;
      }
      cout << answer[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}