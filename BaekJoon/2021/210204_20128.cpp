#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const ll INF = 1e18;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vl> dist(100001, vl(2, INF));
  vpll adj[100001];

  for (int i = 0; i < m; i++)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }

  dist[1][0] = 0;

  queue<pll> que;
  que.push(make_pair(1LL, 0LL));
  while (!que.empty())
  {
    ll cur = que.front().first;
    ll cur_cost = que.front().second;
    que.pop();
    for (int i = 0; i < adj[cur].size(); i++)
    {
      long long next = adj[cur][i].first;
      long long next_cost = cur_cost + adj[cur][i].second;
      if (dist[next][next_cost % 2] > next_cost)
      {
        que.push(make_pair(next, next_cost));
        dist[next][next_cost % 2] = next_cost;
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << (dist[i][1] != INF ? dist[i][1] : -1) << ' ';
    cout << (dist[i][0] != INF ? dist[i][0] : -1) << '\n';
  }
  return 0;
}