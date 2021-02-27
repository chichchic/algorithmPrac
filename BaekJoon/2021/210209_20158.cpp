#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 999999999

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;

typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef pair<pii, pic> piiic;

int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
int md[4] = {'d', 'r', 'u', 'l'};

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vvi controlTime(n, vi(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> controlTime[i][j];
    }
  }
  vvvvi check(14, vvvi(4, vvi(n, vi(n, 0))));

  check[1][0][0][0] = 1;
  check[1][1][0][0] = 1;
  check[1][2][0][0] = 1;
  check[1][3][0][0] = 1;

  queue<piiic> que;
  que.push(make_pair(make_pair(0, 0), make_pair(1, '-')));
  que.push(make_pair(make_pair(-1, -1), make_pair(0, '-')));
  int ans = 0;
  while (!que.empty())
  {
    int curX = que.front().first.first;
    int curY = que.front().first.second;
    int curStep = que.front().second.first;
    char curDir = que.front().second.second;
    if (curX == n - 1 && curY == n - 1)
    {
      cout << ans;
      return 0;
    }
    que.pop();
    if (curX == -1)
    {
      if (que.empty())
      {
        break;
      }
      que.push(make_pair(make_pair(-1, -1), make_pair(0, '-')));
      ans++;
      continue;
    }
    for (int i = 0; i < 4; i++)
    {
      int stepCnt = 1;
      char nextDir = md[i];
      if (nextDir == curDir)
      {
        stepCnt = curStep + 1;
      }
      bool canGo = true;
      int nextX = curX;
      int nextY = curY;
      for (int j = 1; j <= stepCnt; j++)
      {
        nextX += mx[i];
        nextY += my[i];
        if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
        {
          canGo = false;
          break;
        }
        if (controlTime[nextX][nextY] == 0)
        {
          continue;
        }
        if (controlTime[nextX][nextY] <= ans)
        {
          canGo = false;
          break;
        }
        if (j == stepCnt && controlTime[nextX][nextY] <= ans + 1)
        {
          canGo = false;
          break;
        }
      }
      if (canGo && check[stepCnt][i][nextX][nextY] == 0)
      {
        check[stepCnt][i][nextX][nextY] = 1;
        que.push(make_pair(make_pair(nextX, nextY), make_pair(stepCnt, nextDir)));
      }
    }
  }
  cout << "Fired";
  return 0;
}