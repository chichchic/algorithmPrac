#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, m;
  cin >> n >> m;
  vector<vpii> busMap(n + 1);
  vi cityCnt(n + 1, 0);
  vector<bool> inQue(n + 1, false);
  vector<long long> dist(n + 1, 1e9);
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    busMap[a].push_back(make_pair(b, c));
  }

  queue<int> que;
  que.push(1);
  cityCnt[1]++;
  inQue[1] = true;
  dist[1] = 0;

  while (!que.empty())
  {
    int cur = que.front();
    que.pop();
    inQue[cur] = false;

    for (int i = 0; i < busMap[cur].size(); i++)
    {
      int next = busMap[cur][i].first;
      int cost = busMap[cur][i].second;
      if (dist[next] > dist[cur] + cost)
      {
        dist[next] = dist[cur] + cost;
        if (inQue[next])
          continue;
        inQue[next] = true;
        if (++cityCnt[next] >= n)
          return cout << -1, 0;
        que.push(next);
      }
    }
  }
  for (int i = 2; i <= n; i++)
    cout << (dist[i] == 1e9 ? -1 : dist[i]) << '\n';
  return 0;
}