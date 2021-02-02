#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

#define MAX_D 9987654321

using namespace std;

typedef pair<long long, long long> pii;
typedef pair<long long, pii> ppii;
typedef pair<long long, bool> pib;
typedef pair<long long, pib> pdpib;
typedef vector<pii> vpii;

vector<vpii> vec(4003);
long long f_dist[4003];
long long r_dist1[4003];
long long r_dist2[4003];

int main()
{
  // freopen("input.txt", "r", stdin);
  long long n, m;
  cin >> n >> m;

  for (long long i = 0; i < m; i++)
  {
    long long u, v, w;
    scanf(" %lld %lld %lld", &u, &v, &w);
    vec[u].push_back(make_pair(v, w * 2));
    vec[v].push_back(make_pair(u, w * 2));
  }

  fill_n(f_dist, n + 1, -1);
  fill_n(r_dist1, n + 1, -1);
  fill_n(r_dist2, n + 1, -1);
  priority_queue<pii> f_pq;
  priority_queue<pdpib> r_pq;
  f_pq.push(make_pair(0, 1));
  while (!f_pq.empty())
  {
    long long len = -f_pq.top().first;
    long long island = f_pq.top().second;
    f_pq.pop();
    if (f_dist[island] != -1)
      continue;
    f_dist[island] = len;
    for (long long i = 0; i < vec[island].size(); i++)
    {
      long long next = vec[island][i].first;
      if (f_dist[next] == -1)
        f_pq.push(make_pair(-(len + vec[island][i].second), next));
    }
  }
  r_pq.push(make_pair(0.0, make_pair(1, false)));
  bool first = true;
  while (!r_pq.empty())
  {
    long long len = -r_pq.top().first;
    long long island = r_pq.top().second.first;
    bool step = r_pq.top().second.second;
    long long *r_dist;
    long long *next_dist;
    if (step)
    {
      r_dist = r_dist1;
      next_dist = r_dist2;
    }
    else
    {
      r_dist = r_dist2;
      next_dist = r_dist1;
    }

    r_pq.pop();
    if (r_dist[island] != -1)
      continue;
    if (!first)
      r_dist[island] = len;
    else
    {
      first = false;
    }

    for (long long i = 0; i < vec[island].size(); i++)
    {
      long long next = vec[island][i].first;
      long long next_len;
      if (step)
        next_len = vec[island][i].second * 2;
      else
        next_len = vec[island][i].second / 2;
      // cout << next << ": " << vec[island][i].second << ' ' << fast << ' ';
      // cout << vec[island][i].second * fast << '\n';
      if (next_dist[next] == -1)
        r_pq.push(make_pair(-(len + next_len), make_pair(next, !step)));
    }
  }
  long long cnt = 0;
  for (long long i = 2; i <= n; i++)
  {
    // printf("%lld %lld %lld %lld\n", i, r_dist1[i], r_dist2[i], f_dist[i]);
    if (f_dist[i] == -1)
      f_dist[i] = MAX_D;
    if (r_dist1[i] == -1)
    {
      r_dist1[i] = MAX_D;
    }
    if (r_dist2[i] == -1)
    {
      r_dist2[i] = MAX_D;
    }
    if (r_dist1[i] > f_dist[i] && r_dist2[i] > f_dist[i])
    {
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}