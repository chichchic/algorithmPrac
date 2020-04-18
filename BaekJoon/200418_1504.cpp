#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define MAX 9987654321

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int n, e;
vector<vpii> v(803);

void Dijkstra(vector<int> &dist, int start)
{
  priority_queue<pii> pq;
  pq.push(make_pair(0, start));
  while (!pq.empty())
  {
    int len = -pq.top().first;
    int cur = pq.top().second;
    // cout << cur << ' ' << len << '\n';
    pq.pop();
    if (dist[cur] != -1)
      continue;
    dist[cur] = len;
    for (int i = 0; i < v[cur].size(); i++)
    {
      int next = v[cur][i].first;
      if (dist[next] == -1)
        pq.push(make_pair(-(len + v[cur][i].second), next));
    }
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  //굳이 1a 1b로 나눌필요 없음.. 1에서 시작하는 dist를 통해 둘다 알 수 있음
  //ab와 an도 동일
  vector<int> dist_1a(803, -1);
  vector<int> dist_1b(803, -1);
  vector<int> dist_ab(803, -1);
  vector<int> dist_aN(803, -1);
  vector<int> dist_bN(803, -1);
  cin >> n >> e;
  for (int i = 0; i < e; i++)
  {
    int a, b, c;
    scanf(" %d %d %d", &a, &b, &c);
    v[a].push_back(make_pair(b, c));
    v[b].push_back(make_pair(a, c));
  }
  int a, b;
  cin >> a >> b;
  Dijkstra(dist_1a, 1);
  Dijkstra(dist_1b, 1);
  Dijkstra(dist_ab, a);
  Dijkstra(dist_aN, a);
  Dijkstra(dist_bN, b);
  int ans;

  // cout << dist_1a[a] << '\n';
  // cout << dist_1b[b] << '\n';
  // cout << dist_ab[b] << '\n';
  // cout << dist_aN[n] << '\n';
  // cout << dist_bN[n] << '\n';

  if (dist_1a[a] == -1 || dist_ab[b] == -1 || dist_bN[n] == -1)
  {
    ans = -1;
  }
  else
    ans = dist_1a[a] + dist_ab[b] + dist_bN[n];
  if (dist_1b[b] != -1 && dist_ab[b] != -1 && dist_aN[n] != -1)
  {
    int temp = dist_1b[b] + dist_ab[b] + dist_aN[n];
    if (ans == -1)
      ans = temp;
    else
    {
      ans = (ans > temp) ? temp : ans;
    }
  }
  cout << ans;
  return 0;
}