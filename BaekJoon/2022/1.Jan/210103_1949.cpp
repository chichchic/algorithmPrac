#include <iostream>
#include <vector>
using namespace std;

int population[10001] = {};
int dp[10001][2] = {};
bool visited[10001] = {};
vector<vector<int>> link(10001);

void setMaxPopulation(int cur)
{
  if (visited[cur])
  {
    return;
  }
  visited[cur] = true;
  dp[cur][0] = 0;
  dp[cur][1] = population[cur];
  for (int i = 0; i < link[cur].size(); i++)
  {
    int next = link[cur][i];
    if (visited[next])
    {
      continue;
    }
    setMaxPopulation(next);
    dp[cur][0] += max(dp[next][0], dp[next][1]);
    dp[cur][1] += dp[next][0];
  }
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> population[i];
  }
  for (int i = 1; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    link[a].push_back(b);
    link[b].push_back(a);
  }
  setMaxPopulation(1);
  cout << max(dp[1][0], dp[1][1]);
  return 0;
}