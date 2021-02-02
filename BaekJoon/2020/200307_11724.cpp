#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, m, temp1, temp2;
  int ans = 0;
  scanf(" %d %d", &n, &m);
  vector<vi> element(n + 1);
  vector<bool> check(n + 1, false);
  while (m--)
  {
    scanf(" %d %d", &temp1, &temp2);
    element[temp1].push_back(temp2);
    element[temp2].push_back(temp1);
  }
  queue<int> que;
  for (int i = 1; i <= n; i++)
  {
    if (!check[i])
    {
      que.push(i);
      check[i] = true;
      ans++;
    }
    while (!que.empty())
    {
      int cur = que.front();
      que.pop();
      for (int j = 0; j < element[cur].size(); j++)
      {
        int next = element[cur][j];
        if (!check[next])
        {
          que.push(next);
          check[next] = true;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    if (!check[i])
      ans++;
  }
  cout << ans;
  return 0;
}