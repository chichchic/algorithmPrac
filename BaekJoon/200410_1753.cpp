#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

vector<vpii> vec(20005);
int dist[20005];

int main()
{
  // freopen("input.txt", "r", stdin);

  int n, m, start;
  cin >> n >> m >> start;
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    scanf(" %d %d %d", &u, &v, &w);
    vec[u].push_back(make_pair(v, w));
  }

  memset(dist, -1, sizeof(dist));
  priority_queue<pii> pq;
  pq.push(make_pair(0, start));

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
      int next = vec[island][i].first;
      if (dist[next] == -1)
        pq.push(make_pair(-(len + vec[island][i].second), next));
    }
  }
  for (int i = 1; i <= n; i++)
  {
    if (dist[i] == -1)
      printf("INF\n");
    else
    {
      printf("%d\n", dist[i]);
    }
  }
  return 0;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <utility>

// using namespace std;

// typedef vector<int> vi;
// typedef pair<int, int> pii;
// typedef vector<pii> vpii;

// vector<vpii> v(20005);
// int dist[20005];

// // visted 배열이 없게 푸는 방법

// int main()
// {
//   freopen("input.txt", "r", stdin);
//   int n, m, start;
//   cin >> n >> m >> start;
//   for (int i = 0; i < m; i++)
//   {
//     int s, e, cost;
//     scanf(" %d %d %d", &s, &e, &cost);
//     v[s].push_back(make_pair(e, cost));
//   }
//   memset(dist, -1, sizeof(dist));

//   priority_queue<pii> pq;
//   pq.push(make_pair(0, start));

//   while (!pq.empty())
//   {
//     int cost = -pq.top().first;
//     int vtx = pq.top().second;
//     pq.pop();
//     if (dist[vtx] != -1)
//       continue;
//     dist[vtx] = cost;
//     for (int i = 0; i < v[vtx].size(); i++)
//     {
//       int next = v[vtx][i].first;
//       if (dist[next] == -1)
//         pq.push(make_pair(-(cost + v[vtx][i].second), next));
//     }
//   }
//   for (int i = 1; i <= n; i++)
//   {
//     if (dist[i] == -1)
//       printf("INF\n");
//     else
//       printf("%d\n", dist[i]);
//   }
//   return 0;
// }