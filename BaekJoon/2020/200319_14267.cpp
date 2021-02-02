/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<long long> vll;

int main()
{
  // freopen("input.txt", "r", stdin);
  long long n, m, temp;
  scanf(" %lld %lld", &n, &m);
  vector<vll> low(n + 1);
  vector<long long> stress(n + 1, 0);

  for (long long i = 1; i <= n; i++)
  {
    scanf(" %lld", &temp);
    if (temp == -1)
      continue;
    low[temp].push_back(i);
  }
  queue<long long> q;
  while (m--)
  {
    long long cur, point;
    scanf("%lld %lld", &cur, &point);
    stress[cur] += point;
  }
  q.push(1);
  long long point;
  while (!q.empty())
  {
    long long qcur = q.front();
    q.pop();
    point = stress[qcur];
    for (long long i = 0; i < low[qcur].size(); i++)
    {
      stress[low[qcur][i]] += point;
      q.push(low[qcur][i]);
    }
  }
  for (long long i = 1; i <= n; i++)
    printf("%lld ", stress[i]);
  return 0;
}
*/

#include <iostream>
#include <vector>

using namespace std;

typedef vector<long long> vll;

void dfs(vector<vll> &low, vector<long long> &stress, long long cur, long long boss)
{
  long long boss_stress = 0;
  if (boss != -1)
  {
    boss_stress = stress[boss];
  }
  stress[cur] += boss_stress;
  for (long long i = 0; i < low[cur].size(); i++)
  {
    dfs(low, stress, low[cur][i], cur);
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  long long n, m, temp;
  scanf(" %lld %lld", &n, &m);
  vector<vll> low(n + 1);
  vector<long long> stress(n + 1, 0);

  for (long long i = 1; i <= n; i++)
  {
    scanf(" %lld", &temp);
    if (temp == -1)
      continue;
    low[temp].push_back(i);
  }
  while (m--)
  {
    long long cur, point;
    scanf("%lld %lld", &cur, &point);
    stress[cur] += point;
  }
  dfs(low, stress, 1, -1);
  for (long long i = 1; i <= n; i++)
    printf("%lld ", stress[i]);
  return 0;
}