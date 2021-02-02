#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int g;
  cin >> g;

  int max = g / 2 + 1;
  int s = 1, e = 2;
  int sum = 3;
  vector<int> ans;
  while (s < max)
  {
    if (sum == g)
    {
      ans.push_back(e);
    }
    if (sum > g || e == max)
    {
      sum -= s * 2 + 1;
      s++;
    }
    else
    {
      sum += e * 2 + 1;
      e++;
    }
  }
  if (ans.size() == 0)
  {
    cout << -1;
  }
  else
  {
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
      cout << ans[i] << '\n';
    }
  }

  return 0;
}