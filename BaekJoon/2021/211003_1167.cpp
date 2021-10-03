#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int answer = 0;

void getNodeInfo(vector<vector<pair<int, int>>> &tree_info, vector<int> &node_info, const int parent, const int cur_node)
{
  for (int i = 0; i < tree_info[cur_node].size(); ++i)
  {
    int child_node = tree_info[cur_node][i].first;
    if (child_node == parent)
      continue;
    getNodeInfo(tree_info, node_info, cur_node, child_node);
  }
  int first = 0, second = 0;
  for (int i = 0; i < tree_info[cur_node].size(); ++i)
  {
    int child_node = tree_info[cur_node][i].first;
    if (child_node == parent)
      continue;
    int child_weight = tree_info[cur_node][i].second + node_info[child_node];
    if (first < child_weight)
    {
      second = max(first, second);
      first = child_weight;
      continue;
    }
    second = max(second, child_weight);
  }
  answer = max(answer, first + second);
  node_info[cur_node] = first;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int v;
  cin >> v;
  vector<vector<pair<int, int>>> tree_info(v + 1);
  vector<int> node_info(v + 1, 0);
  for (int i = 0; i < v; i++)
  {
    int cur_node, child_node, weight;
    cin >> cur_node;
    while (true)
    {
      cin >> child_node;
      if (child_node == -1)
        break;
      cin >> weight;
      tree_info[cur_node].push_back({child_node, weight});
    }
  }
  getNodeInfo(tree_info, node_info, -1, 1);
  cout << answer;

  return 0;
}