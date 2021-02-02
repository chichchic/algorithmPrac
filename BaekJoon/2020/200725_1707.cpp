#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
  // freopen("input.txt", "r", stdin);
  int k, v, e;
  cin >> k;
  while (k--)
  {
    cin >> v >> e;
    vi check(v + 1, 0);
    vvi map(v + 1);
    for (int i = 0; i < e; i++)
    {
      int f, s;
      cin >> f >> s;
      map[f].push_back(s);
      map[s].push_back(f);
    }
    bool yes = true;

    for (int i = 1; i <= v; i++)
    {
      if (check[i] != 0)
        continue;
      queue<int> que;
      que.push(i);
      check[i] = 1;
      while (!que.empty())
      {
        int cur = que.front();
        que.pop();
        int curFlag = check[cur];
        for (int i = 0; i < map[cur].size(); i++)
        {
          int next = map[cur][i];
          if (check[next] == 0)
          {
            check[next] = curFlag % 2 + 1;
            que.push(next);
          }
          else if (check[next] == curFlag)
          {
            yes = false;
            break;
          }
        }
        if (!yes)
          break;
      }
      if (!yes)
        break;
    }
    if (yes)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}