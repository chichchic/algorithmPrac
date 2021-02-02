#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vvi family(n + 1);
  bool visited[101] = {};
  int x, y;
  cin >> x >> y;
  int m;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int temp1, temp2;
    cin >> temp1 >> temp2;
    family[temp1].push_back(temp2);
    family[temp2].push_back(temp1);
  }

  queue<int> que;
  que.push(x);
  visited[x] = true;
  que.push(-1);
  int ans = 0;
  bool isRelation = true;
  while (true)
  {
    int cur = que.front();
    que.pop();
    if (cur == y)
      break;
    if (cur == -1)
    {
      if (que.empty())
      {
        isRelation = false;
        break;
      }
      que.push(-1);
      ans++;
      continue;
    }
    for (int i = 0; i < family[cur].size(); i++)
    {
      int next = family[cur][i];
      if (!visited[next])
      {
        que.push(next);
        visited[next] = true;
      }
    }
  }
  if (isRelation)
    cout << ans;
  else
    cout << -1;

  return 0;
}