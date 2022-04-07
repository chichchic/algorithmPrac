#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> prices(n + 1, 0);
  vector<int> minCosts(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    cin >> prices[i];
    minCosts[i] = prices[i];
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; i - j >= 1; j++)
    {
      minCosts[i] = min(minCosts[i], minCosts[i - j] + minCosts[j]);
    }
  }
  cout << minCosts[n];
  return 0;
}