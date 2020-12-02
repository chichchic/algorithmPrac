#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> seq(n);
  for (int i = 0; i < n; i++)
  {
    cin >> seq[i];
  }

  sort(seq.begin(), seq.end());
  int ans = 2e9 + 1;

  int s = 0, e = 0;
  while (s < n)
  {
    int dif = seq[e] - seq[s];
    if (dif < ans && dif >= m)
    {
      ans = dif;
    }
    if (dif > ans || e == n - 1)
    {
      s++;
    }
    else
    {
      e++;
    }
  }

  cout << ans;
  return 0;
}