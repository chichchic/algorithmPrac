#include <iostream>
#include <vector>

using namespace std;

int find(int x, vector<int> &parent)
{
  if (x == parent[x])
    return x;
  return parent[x] = find(parent[x], parent);
}

void bind(int x, int y, vector<int> &parent)
{
  x = find(x, parent);
  y = find(y, parent);
  if (x < y)
  {
    parent[y] = x;
  }
  else
  {
    parent[x] = y;
  }
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int frank_count;
  cin >> frank_count;
  vector<int> parent(n + 1);
  for (int i = 0; i <= n; i++)
  {
    parent[i] = i;
  }
  while (frank_count--)
  {
    int number;
    cin >> number;
    bind(0, number, parent);
  }
  vector<vector<int>> party(m);
  for (int i = 0; i < m; i++)
  {
    int count;
    cin >> count;
    int number;
    cin >> number;
    party[i].push_back(number);
    for (int j = 1; j < count; j++)
    {
      cin >> number;
      bind(party[i][j - 1], number, parent);
      party[i].push_back(number);
    }
  }
  int answer = 0;
  for (int i = 0; i < m; i++)
  {
    if (find(party[i][0], parent) != 0)
    {
      answer++;
    }
  }
  cout << answer;

  return 0;
}