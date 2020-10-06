#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ipii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, x;
  cin >> n >> m >> x;

  vvpii city(n + 1);
  priority_queue<pii, vpii> pq;
  for (int i = 0; i < m + 1; i++)
  {
    int s, e, t;
    cin >> s >> e >> t;
    city[s].push_back(pii(t, e));
  }

  vector<int> result(n + 1, -1);
  pq.push(pii(-0, x));
  int ans = 0;
  while (!pq.empty())
  {
    int cur = pq.top().second;
    int curTime = pq.top().first;
    pq.pop();
    if (result[cur] != -1)
      continue;
    result[cur] = -curTime;
    for (int i = 0; i < city[cur].size(); i++)
    {
      int nextV = city[cur][i].second;
      if (result[nextV] == -1)
      {
        pq.push(pii(-city[cur][i].first + curTime, nextV));
      }
    }
  }

  for (int i = 1; i < n + 1; i++)
  {
    priority_queue<pii, vpii> pq2;
    pq2.push(pii(0, i));
    vector<int> result2(n + 1, -1);
    while (!pq2.empty())
    {
      int cur = pq2.top().second;
      int curTime = pq2.top().first;
      if (cur == x)
      {
        ans = max(result[i] + (-curTime), ans);
        break;
      }
      pq2.pop();
      if (result2[cur] != -1)
        continue;
      result2[cur] = -curTime;
      for (int i = 0; i < city[cur].size(); i++)
      {
        int nextV = city[cur][i].second;
        if (result2[nextV] == -1)
        {
          pq2.push(pii(-city[cur][i].first + curTime, nextV));
        }
      }
    }
  }
  cout << ans;
  return 0;
}