#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef queue<pii> qpii;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, l, r;
  cin >> n >> l >> r;
  vvi country(50, vi(50));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> country[i][j];
    }
  }

  int ans = 0;
  int mx[4] = {0, 0, 1, -1};
  int my[4] = {1, -1, 0, 0};
  while (true)
  {
    bool movementEnd = true;
    vvi check(50, vi(50, false));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (check[i][j])
        {
          continue;
        }
        check[i][j] = true;
        qpii que;
        que.push(make_pair(i, j));
        int total = 0;
        vector<pii> linkedCountry;
        while (!que.empty())
        {
          int curX = que.front().first;
          int curY = que.front().second;
          linkedCountry.push_back(que.front());
          total += country[curX][curY];
          que.pop();
          for (int k = 0; k < 4; k++)
          {
            int nextX = curX + mx[k];
            int nextY = curY + my[k];
            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n || check[nextX][nextY])
            {
              continue;
            }
            int dif = abs(country[curX][curY] - country[nextX][nextY]);
            if (dif < l || dif > r)
            {
              continue;
            }
            check[nextX][nextY] = true;
            que.push(make_pair(nextX, nextY));
          }
        }
        if (linkedCountry.size() > 1)
        {
          movementEnd = false;
          total /= linkedCountry.size();
          for (int i = 0; i < linkedCountry.size(); i++)
          {
            country[linkedCountry[i].first][linkedCountry[i].second] = total;
          }
        }
      }
    }

    if (movementEnd)
    {
      break;
    }
    else
    {
      ans++;
    }
  }
  cout << ans;
  return 0;
}