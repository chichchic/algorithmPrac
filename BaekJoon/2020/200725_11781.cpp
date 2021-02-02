//TODO: 아직 안품

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef long long ll;
class loadInfo
{
public:
  ll arrive, curTime;
  double len;
  bool isJam;
  loadInfo(ll a, double l, ll c, bool i)
  {
    arrive = a;
    len = l;
    curTime = c;
    isJam = i;
  }
};

bool operator<(loadInfo l, loadInfo r)
{
  return l.len > r.len;
}

typedef vector<loadInfo> vli;
typedef vector<vli> vvli;

int main()
{
  freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n, m, jamS, jamE;
  cin >> n >> m >> jamS >> jamE;

  vvli load(n + 1);
  for (int i = 0; i < m; i++)
  {
    ll a, b, l, t1, t2;
    cin >> a >> b >> l >> t1 >> t1;
    load[a].push_back(loadInfo(b, l, 0, t1));
    load[b].push_back(loadInfo(a, l, 0, t2));
  }

  priority_queue<loadInfo, vli> pq;
  vector<ll> dist(n + 1, -1);
  pq.push(loadInfo(1, 0, 0, 0));

  double ans = 0;

  while (!pq.empty())
  {
    loadInfo li = pq.top();
    pq.pop();
    ll cur = li.arrive;
    double curLen = li.len;
    bool curJam = li.isJam;

    if (dist[cur] != -1)
      continue;

    double plusLen = 0;
  }
  return 0;
}