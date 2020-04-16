#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

struct unit
{
  int a, b, c;
  unit(int x, int y, int z) : a(x), b(y), c(z){};
};

typedef pair<int, int> pii;
typedef vector<unit> vu;

vector<vu> vec(1003);
int dist[1003];

int main()
{
  freopen("input.txt", "r", stdin);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    scanf(" %d %d %d", &u, &v, &w);
    vec[u].push_back(unit(v, w, i));
    vec[v].push_back(unit(u, w, i));
  }
  int first;
  int ans = 0;
  for (int b = -1; b < m; b++)
  {
    memset(dist, -1, sizeof(dist));
    priority_queue<pii> pq;
    pq.push(make_pair(0, 1));
    cout << b << ": ";
    while (!pq.empty())
    {
      int len = -pq.top().first;
      int island = pq.top().second;

      pq.pop();
      if (dist[island] != -1)
        continue;
      cout << island << ' ';
      dist[island] = len;
      for (int i = 0; i < vec[island].size(); i++)
      {
        if (b != -1 && vec[island][i].c == b)
          continue;
        int next = vec[island][i].a;
        if (dist[next] == -1)
          pq.push(make_pair(-(len + vec[island][i].b), next));
      }
    }
    cout << '\n';
    if (b == -1)
      first = dist[n];
    else
    {
      if (dist[n] == -1)
      {
        cout << -1;
        return 0;
      }
      int candi = dist[n] - first;
      if (ans < candi)
        ans = candi;
    }
  }
  cout << ans;
  return 0;
}