#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct circle
{
  int x, y, r;
  circle() {}
  circle(int x, int y, int r) : x(x), y(y), r(r) {}
};

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
  // freopen("input.txt", "r", stdin);
  int testCase;
  cin >> testCase;
  while (testCase--)
  {
    int enemyNum;
    cin >> enemyNum;
    vector<circle> inputPoint(enemyNum);
    vvi connect(enemyNum);
    for (int i = 0; i < enemyNum; i++)
    {
      int x, y, r;
      cin >> x >> y >> r;
      inputPoint[i] = circle(x, y, r);
    }
    for (int i = 0; i < enemyNum - 1; i++)
    {
      circle f = inputPoint[i];
      for (int j = i + 1; j < enemyNum; j++)
      {
        circle s = inputPoint[j];
        if ((f.x - s.x) * (f.x - s.x) + (f.y - s.y) * (f.y - s.y) <= (f.r + s.r) * (f.r + s.r))
        {
          connect[i].push_back(j);
          connect[j].push_back(i);
        }
      }
    }
    vector<bool> check(enemyNum, false);
    int ans = 0;
    for (int i = 0; i < enemyNum; i++)
    {
      if (check[i])
        continue;
      ans++;
      queue<int> que;
      que.push(i);
      while (!que.empty())
      {
        int curPoint = que.front();
        que.pop();
        for (int j = 0; j < connect[curPoint].size(); j++)
        {
          if (check[connect[curPoint][j]])
            continue;
          check[connect[curPoint][j]] = true;
          que.push(connect[curPoint][j]);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}