#include <iostream>
#include <queue>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int f, s, g, u, d;
  cin >> f >> s >> g >> u >> d;

  queue<int> que;
  bool visited[1000001] = {};

  visited[s] = true;
  que.push(s);
  int count = 0;
  que.push(-1);
  while (true)
  {
    int cur = que.front();
    que.pop();
    if (cur == g)
    {
      cout << count;
      return 0;
    }
    if (que.empty())
      break;
    if (cur == -1)
    {
      count++;
      que.push(-1);
      continue;
    }
    int nextUp = cur + u;
    int nextDown = cur - d;
    if (nextUp <= f && !visited[nextUp])
    {
      visited[nextUp] = true;
      que.push(nextUp);
    }
    if (nextDown > 0 && !visited[nextDown])
    {
      visited[nextDown] = true;
      que.push(nextDown);
    }
  }
  cout << "use the stairs";
  return 0;
}