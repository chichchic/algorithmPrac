#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int answer = 1;
int n;
vector<vector<int>> placeHeight(101, vector<int>(101));
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};
int getSafePlaceCnt(int rainHeight)
{
  int ret = 0;
  vector<vector<bool>> checked(n, vector<bool>(n, false));
  queue<pair<int, int>> que;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (checked[i][j] || placeHeight[i][j] <= rainHeight)
        continue;
      ret++;
      que.push({i, j});
      checked[i][j] = true;
      while (!que.empty())
      {
        int curx = que.front().first;
        int cury = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++)
        {
          int nextx = curx + mx[i];
          int nexty = cury + my[i];
          if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= n || checked[nextx][nexty] || placeHeight[nextx][nexty] <= rainHeight)
          {
            continue;
          }
          checked[nextx][nexty] = true;
          que.push({nextx, nexty});
        }
      }
    }
  }
  return ret;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> placeHeight[i][j];
    }
  }
  for (int i = 1; i <= 100; i++)
  {
    answer = max(answer, getSafePlaceCnt(i));
  }
  cout << answer;
  return 0;
}