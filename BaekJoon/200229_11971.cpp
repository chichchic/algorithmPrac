#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef pair<long long, long long> pll;
int main()
{
  // freopen("input.txt", "r", stdin);
  long long n, m, ans = 0, idx = 0;
  cin >> n >> m;
  vector<pll> limit(n);
  for (int i = 0; i < n; i++)
    cin >> limit[i].first >> limit[i].second;
  long long cur = 0, lim = 0;
  long long move, speed;
  for (int i = 0; i < m; i++)
  {
    cin >> move >> speed;
    cur += move;
    while (true)
    {
      lim += limit[idx].first;
      long long over = speed - limit[idx].second;
      if (ans < over)
        ans = over;
      if (lim == cur)
      {
        idx++;
        break;
      }
      else if (lim > cur)
      {
        lim -= limit[idx].first;
        break;
      }
      idx++;
    }
  }
  cout << ans;
  return 0;
}