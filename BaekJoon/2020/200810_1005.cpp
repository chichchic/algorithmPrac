#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;

int main()
{
  // freopen("input.txt", "r", stdin);
  int test_case;
  cin >> test_case;
  while (test_case--)
  {
    int n, k, w;
    cin >> n >> k;
    vi linkCnt(n + 1, 0);
    vi takeTime(n + 1);
    vector<vi> buildMap(n + 1);
    vi totalTime(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
      cin >> takeTime[i];
      totalTime[i] = takeTime[i];
    }
    for (int i = 0; i < k; i++)
    {
      int a, b;
      cin >> a >> b;
      buildMap[a].push_back(b);
      linkCnt[b]++;
    }
    cin >> w;
    queue<int> que;
    for (int i = 1; i <= n; i++)
    {
      if (!linkCnt[i])
        que.push(i);
    }
    while (!que.empty())
    {
      int cur = que.front();
      if (cur == w)
      {
        cout << totalTime[w] << '\n';
        break;
      }
      que.pop();
      for (int i = 0; i < buildMap[cur].size(); i++)
      {
        int next = buildMap[cur][i];
        totalTime[next] = max(totalTime[next], takeTime[next] + totalTime[cur]);
        if (--linkCnt[next] == 0)
          que.push(next);
      }
    }
  }
  return 0;
}