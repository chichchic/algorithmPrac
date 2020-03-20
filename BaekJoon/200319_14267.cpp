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
    // q.push(cur);
    // while (!q.empty())
    // {
    //   long long qcur = q.front();
    //   q.pop();
    //   stress[qcur] += point;
    //   for (long long i = 0; i < low[qcur].size(); i++)
    //   {
    //     q.push(low[qcur][i]);
    //   }
    // }
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