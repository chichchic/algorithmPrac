#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

struct unit
{
  int a, b, c;
  unit(int x, int y, int z) : a(x), b(y), c(z){};

  bool operator<(const unit &b) const
  {
    return this->a < b.a;
  }
};

typedef pair<int, int> pii;
typedef vector<unit> vu;

int n, m;
vector<vu> vec(1003);
int dist[1003];
int p[1003] = {};

int arrive_time(int b)
{
  memset(dist, -1, sizeof(dist));
  priority_queue<pii> pq;
  pq.push(make_pair(0, 1));
  vector<int> pre_path;
  while (!pq.empty())
  {
    int len = -pq.top().first;
    int island = pq.top().second;
    pq.pop();
    if (dist[island] != -1)
      continue;
    dist[island] = len;
    for (int i = 0; i < vec[island].size(); i++)
    {
      if (vec[island][i].c == b)
        continue;
      int next = vec[island][i].a;
      if (dist[next] == -1)
        pq.push(make_pair(-(len + vec[island][i].b), next));
    }
  }
  return dist[n];
}

int main()
{
  // freopen("input.txt", "r", stdin);

  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    scanf(" %d %d %d", &u, &v, &w);
    vec[u].push_back(unit(v, w, i));
    vec[v].push_back(unit(u, w, i));
  }
  int first = arrive_time(-1);
  memset(dist, -1, sizeof(dist));
  priority_queue<unit> pq;
  pq.push(unit(0, 1, -1));
  while (!pq.empty())
  {
    int len = -pq.top().a;
    int island = pq.top().b;
    int pre = pq.top().c;
    pq.pop();
    if (dist[island] != -1)
      continue;
    dist[island] = len;
    p[island] = pre;
    for (int i = 0; i < vec[island].size(); i++)
    {
      int next = vec[island][i].a;
      if (dist[next] == -1)
        pq.push(unit(-(len + vec[island][i].b), next, island));
    }
  }
  first = dist[n];
  int cur = n;
  vector<int> idx;
  int ans = 0;
  while (cur != -1)
  {
    int next = p[cur];
    for (int i = 0; i < vec[cur].size(); i++)
    {
      if (vec[cur][i].a == next)
      {
        idx.push_back(vec[cur][i].c);
        break;
      }
    }
    cur = next;
  }
  for (int i = 0; i < idx.size(); i++)
  {
    int candi = arrive_time(idx[i]);
    if (candi == -1)
    {
      cout << -1;
      return 0;
    }
    if (ans < candi - first)
      ans = candi - first;
  }
  cout << ans;
  return 0;
}