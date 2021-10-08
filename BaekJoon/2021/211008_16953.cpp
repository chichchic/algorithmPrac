#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  queue<pair<long long, long long>> que;
  que.push({a, 1});
  while (!que.empty())
  {
    long long curNum = que.front().first;
    long long curCnt = que.front().second;
    que.pop();
    if (curNum == b)
    {
      cout << curCnt;
      return 0;
    }
    if (curNum * 2 <= b)
      que.push({curNum * 2, curCnt + 1});
    if (curNum * 10 + 1 <= b)
      que.push({curNum * 10 + 1, curCnt + 1});
  }
  cout << -1;

  return 0;
}