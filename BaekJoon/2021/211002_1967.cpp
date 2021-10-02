#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int answer = 0;

void setNodeInfo(vector<int> &node_info, vector<vector<pair<int, int>>> &weights, int cur_node)
{
  for (int i = 0; i < weights[cur_node].size(); i++)
  {
    setNodeInfo(node_info, weights, weights[cur_node][i].first);
  }
  int first = 0, second = 0;
  for (int i = 0; i < weights[cur_node].size(); i++)
  {
    int child_node = weights[cur_node][i].first;
    int child_weight = weights[cur_node][i].second;
    int child_node_info = node_info[child_node];
    if (first <= child_weight + child_node_info)
    {
      second = max(second, first);
      first = child_weight + child_node_info;
      continue;
    }
    second = max(second, child_weight + child_node_info);
  }
  answer = max(answer, first + second);
  node_info[cur_node] = first;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> node_info(n + 1, 0);
  vector<vector<pair<int, int>>> weights(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    int p, c, w;
    cin >> p >> c >> w;
    weights[p].push_back({c, w});
  }
  setNodeInfo(node_info, weights, 1);
  cout << answer;
  return 0;
}