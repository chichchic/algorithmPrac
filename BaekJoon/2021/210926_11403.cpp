#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> answer(n, vector<int>(n, 0));
  vector<vector<int>> tree(n);
  int state;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> state;
      if (state)
      {
        tree[i].push_back(j);
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    queue<int> que;
    que.push(i);
    while (!que.empty())
    {
      int current = que.front();
      que.pop();
      for (int j = 0; j < tree[current].size(); j++)
      {
        int next = tree[current][j];
        if (answer[i][next])
          continue;
        answer[i][next] = 1;
        que.push(next);
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << answer[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}