#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100001;
const int MAX_HEIGHT = 17;

vector<int> tree[MAX_SIZE];
int node_depth[MAX_SIZE];
int **dp;

void dfs(int current, int parent, int depth)
{
  dp[current][0] = parent;
  node_depth[current] = depth;
  for (auto child : tree[current])
  {
    if (child == parent)
    {
      continue;
    }
    dfs(child, current, depth + 1);
  }
}

int lca(int node_a, int node_b)
{
  //node_a가 무조건 더 깊은 노드
  int dif = node_depth[node_a] - node_depth[node_b];
  for (int i = MAX_HEIGHT - 1; i >= 0; --i)
  {
    if (dif & (1 << i))
    {
      node_a = dp[node_a][i];
    }
  }

  if (node_a != node_b)
  {
    for (int i = MAX_HEIGHT - 1; i >= 0; --i)
    {
      if (dp[node_a][i] != 0 && dp[node_a][i] != dp[node_b][i])
      {
        node_a = dp[node_a][i];
        node_b = dp[node_b][i];
      }
    }
    node_a = dp[node_a][0];
  }
  return node_a;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  dp = (int **)malloc(MAX_SIZE * sizeof(int *));
  for (int i = 0; i < MAX_SIZE; ++i)
  {
    dp[i] = (int *)malloc(MAX_HEIGHT * sizeof(int));
    fill(dp[i], dp[i] + MAX_HEIGHT, 0);
  }
  for (int i = 0; i < N - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  dfs(1, 0, 0);

  for (int j = 1; j < MAX_HEIGHT; ++j)
  {
    for (int i = 1; i <= N; i++)
    {
      if (dp[i][j - 1] != 0)
      {
        dp[i][j] = dp[dp[i][j - 1]][j - 1];
      }
    }
  }

  int M;
  cin >> M;
  while (M--)
  {
    int a, b;
    cin >> a >> b;
    if (node_depth[a] > node_depth[b])
    {
      cout << lca(a, b) << '\n';
    }
    else
    {
      cout << lca(b, a) << '\n';
    }
  }

  return 0;
}