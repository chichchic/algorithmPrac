#include <iostream>
#include <utility>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int ans = 0;

  pair<int, int> schedule[15];
  int profits[16] = {};

  for (int i = 0; i < n; i++)
  {
    cin >> schedule[i].first >> schedule[i].second;
  }

  for (int i = 0; i < n; i++)
  {
    int t = schedule[i].first;
    int p = schedule[i].second;

    if (i + t > n)
    {
      continue;
    }
    if (i != 0)
    {
      profits[i] = max(profits[i], profits[i - 1]);
    }
    profits[i + t] = max(profits[i + t], profits[i] + p);
    ans = max(ans, profits[i + t]);
  }

  cout << ans;

  return 0;
}