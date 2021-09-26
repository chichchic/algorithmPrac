#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
vector<int> board(101);

int findEnd(int x)
{
  if (x == board[x])
  {
    return x;
  }
  else
  {
    int y = findEnd(board[x]);
    board[x] = y;
    return y;
  }
}

void setEnd(int start, int end)
{
  start = findEnd(start);
  end = findEnd(end);
  if (start != end)
    board[start] = end;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> dp(101, 1e9);
  vector<bool> visited(101, false);
  for (int i = 1; i <= 100; i++)
  {
    board[i] = i;
  }
  for (int i = 0; i < n + m; ++i)
  {
    int s, e;
    cin >> s >> e;
    setEnd(s, e);
  }
  visited[1] = true;
  queue<int> que;
  que.push(1);
  que.push(-1);
  int answer = 0;
  while (!que.empty())
  {
    int cur = que.front();
    que.pop();

    if (cur == -1)
    {
      answer++;
      que.push(-1);
      continue;
    }
    for (int i = 1; i <= 6 && cur + i <= 100; i++)
    {
      int next = findEnd(cur + i);
      if (visited[next])
        continue;
      visited[cur + i] = true;
      visited[next] = true;
      if (next == 100)
      {
        cout << answer + 1;
        return 0;
      }
      que.push(next);
    }
  }
  cout << answer;
  return 0;
}