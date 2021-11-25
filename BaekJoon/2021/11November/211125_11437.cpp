#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> ancestorMatrix(n + 1, vector<int>(17, 0));
  vector<vector<int>> children(n + 1);
  vector<int> height(n + 1);
  vector<bool> visited(n + 1, false);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    children[a].push_back(b);
    children[b].push_back(a);
  }
  queue<int> que;
  que.push(1);
  height[1] = 0;
  visited[1] = true;
  while (!que.empty())
  {
    int cur = que.front();
    que.pop();
    for (int i = 0; i < children[cur].size(); i++)
    {
      int child = children[cur][i];
      if (visited[child])
      {
        continue;
      }
      visited[child] = true;
      que.push(child);
      height[child] = height[cur] + 1;
      ancestorMatrix[child][0] = cur;
    }
    if (ancestorMatrix[cur][0] == 0)
    {
      continue;
    }
    int point = ancestorMatrix[cur][0];
    int index = 1;
    for (int i = 0; i < n; i++)
    {
      int ancestor = ancestorMatrix[point][i];
      if (ancestor == 0)
      {
        break;
      }
      ancestorMatrix[cur][index] = ancestor;
      point = ancestor;
      index++;
    }
  }
  int m;
  cin >> m;
  while (m--)
  {
    int a, b;
    cin >> a >> b;
    if (height[a] > height[b])
    {
      int dif = height[a] - height[b];
      int idx = 0;
      while (dif != 0)
      {
        if (dif & (1 << idx))
        {
          dif ^= (1 << idx);
          a = ancestorMatrix[a][idx];
        }
        idx++;
      }
    }
    else if (height[a] < height[b])
    {
      int dif = height[b] - height[a];
      int idx = 0;
      while (dif != 0)
      {
        if (dif & (1 << idx))
        {
          dif ^= (1 << idx);
          b = ancestorMatrix[b][idx];
        }
        idx++;
      }
    }
    if (a == b)
    {
      cout << a << '\n';
      continue;
    }
    int prev = 0;
    while (ancestorMatrix[a][prev + 1] != ancestorMatrix[b][prev + 1])
    {
      prev++;
    }
    a = ancestorMatrix[a][prev];
    b = ancestorMatrix[b][prev];
    while (a != b)
    {
      a = ancestorMatrix[a][0];
      b = ancestorMatrix[b][0];
    }
    if (a == 0)
    {
      cout << 1 << '\n';
    }
    else
    {
      cout << a << '\n';
    }
  }
  return 0;
}