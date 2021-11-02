#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAX_ROOM = 100001;
const int MAX_DEPTH = 18;
vector<pair<int, int>> room_tree[MAX_ROOM];
int path_weight[MAX_ROOM][MAX_DEPTH];
int path_parent[MAX_ROOM][MAX_DEPTH];
int enery[MAX_ROOM];

void dfs(int current, int parent, int weight)
{
  path_weight[current][0] = weight;
  path_parent[current][0] = parent;
  for (auto next : room_tree[current])
  {
    if (next.first == parent)
      continue;
    dfs(next.first, current, next.second);
  }
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    cin >> enery[i];
  }

  for (int i = 0; i < N - 1; ++i)
  {
    int a, b, c;
    cin >> a >> b >> c;
    room_tree[a].push_back(make_pair(b, c));
    room_tree[b].push_back(make_pair(a, c));
  }

  dfs(1, 0, 0);
  for (int j = 1; j < MAX_DEPTH; ++j)
  {
    for (int i = 1; i <= N; ++i)
    {
      path_parent[i][j] = path_parent[path_parent[i][j - 1]][j - 1];
      path_weight[i][j] = path_weight[i][j - 1] + path_weight[path_parent[i][j - 1]][j - 1];
    }
  }

  for (int i = 1; i <= N; ++i)
  {
    int room = i;
    for (int j = MAX_DEPTH - 1; j >= 0; j--)
    {
      if (enery[i] >= path_weight[room][j] && path_parent[room][j] != 0)
      {
        enery[i] -= path_weight[room][j];
        room = path_parent[room][j];
      }
    }
    cout << room << ' ';
  }

  return 0;
}