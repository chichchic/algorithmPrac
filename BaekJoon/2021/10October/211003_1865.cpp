#include <iostream>
#include <vector>
#include <utility>
#include <queue>

const int INF = 2e9;
using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, m, w;
    cin >> n >> m >> w;
    vector<pair<pair<int, int>, int>> edges(n + 1);
    for (int i = 0; i < m; i++)
    {
      int s, e, t;
      cin >> s >> e >> t;
      edges.push_back({{s, e}, t});
      edges.push_back({{e, s}, t});
    }
    for (int i = 0; i < w; i++)
    {
      int s, e, t;
      cin >> s >> e >> t;
      edges.push_back({{s, e}, -t});
    }
    string answer = "NO\n";
    vector<int> nodes_info(n + 1, INF);
    nodes_info[1] = 0;
    for (int c = 0; c < n - 1; c++)
    {
      for (int i = 0; i < edges.size(); i++)
      {
        int from = edges[i].first.first;
        int to = edges[i].first.second;
        int weight = edges[i].second;

        if (nodes_info[to] > nodes_info[from] + weight)
          nodes_info[to] = nodes_info[from] + weight;
      }
    }
    for (int i = 0; i < edges.size(); i++)
    {
      int from = edges[i].first.first;
      int to = edges[i].first.second;
      int weight = edges[i].second;

      if (nodes_info[to] > nodes_info[from] + weight)
      {
        answer = "YES\n";
        break;
      }
    }
    cout << answer;
  }

  return 0;
}