#include <iostream>
#include <vector>

using namespace std;

const double INF = 1e6;

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
    for (int i = 0; i < n; i++)
    {
      int sum = 0;
      for (int j = i; j < n; j++)
      {
        sum += lentCost[j];
        int len = (j - i + 1);
        if (len >= l)
          minTotal = min(minTotal, sum / (double)len);
      }
    }

    printf("%.10lf\n", minTotal);
  }

  return 0;
}