#include <iostream>
#include <vector>

using namespace std;

const double INF = 1e6;

int getMinCost(vector<int> &lentCost, int size)
{
  int ret = INF;
  int sum = 0;
  for (int i = 0; i < lentCost.size(); i++)
  {
    if (i < size)
    {
      sum += lentCost[i];
      continue;
    }
    ret = min(ret, sum);
    sum += (lentCost[i] - lentCost[i - size]);
  }
  ret = min(ret, sum);
  return ret;
}

int main()
{
  // freopen("./input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c;
  cin >> c;
  while (c--)
  {
    int n, l;
    cin >> n >> l;
    vector<int> lentCost(n);
    for (int i = 0; i < n; i++)
    {
      cin >> lentCost[i];
    }
    double minTotal = INF;
    for (int i = l; i <= n; i++)
    {
      minTotal = min(minTotal, getMinCost(lentCost, i) / (double)i);
    }
    printf("%.10lf\n", minTotal);
  }

  return 0;
}