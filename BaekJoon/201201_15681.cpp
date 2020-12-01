#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int dfs(vvi &tree, int cur, vi &nodeNumber, int prev)
{
  for (int i = 0; i < tree[cur].size(); i++)
  {
    if (tree[cur][i] == prev)
      continue;
    nodeNumber[cur] += dfs(tree, tree[cur][i], nodeNumber, cur);
  }
  return nodeNumber[cur];
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, r, q;
  cin >> n >> r >> q;
  vvi tree(n + 1);
  for (int i = 1; i < n; i++)
  {
    int v1, v2;
    cin >> v1 >> v2;
    tree[v1].push_back(v2);
    tree[v2].push_back(v1);
  }

  vi nodeNumber(n + 1, 1);
  dfs(tree, r, nodeNumber, -1);
  for (int i = 0; i < q; i++)
  {
    int subRoot;
    cin >> subRoot;
    cout << nodeNumber[subRoot] << '\n';
  }
  return 0;
}