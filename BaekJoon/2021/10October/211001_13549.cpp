#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> visited(100001, 100002);
  visited[n] = true;
  queue<pair<int, int>> que;
  que.push({0, n});
  int mx[2] = {1, -1};
  int answer = 100002;
  while (!que.empty())
  {
    int time = que.front().first;
    int curPos = que.front().second;
    que.pop();
    if (curPos == k)
    {
      answer = min(answer, time);
      continue;
    }
    for (int i = 0; i < 2; i++)
    {
      int nextPos = curPos + mx[i];
      if (nextPos < 0 || nextPos > 100000 || visited[nextPos] < time + 1)
        continue;
      visited[nextPos] = time + 1;
      que.push({time + 1, nextPos});
    }
    int nextPos = curPos * 2;
    if (nextPos <= 100000 && visited[nextPos] > time)
    {
      visited[nextPos] = time;
      que.push({time, nextPos});
    }
  }
  cout << answer;
  return 0;
}