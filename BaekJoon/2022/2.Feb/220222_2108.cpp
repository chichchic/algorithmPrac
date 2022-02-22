#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int max_v = -4000, min_v = 4000;
  long long a = 0;
  vector<pair<int, int>> amount;
  vector<int> seq;
  for (int i = 4000; i >= 0; i--)
  {
    amount.push_back({0, -i});
  }
  for (int i = 1; i <= 4000; i++)
  {
    amount.push_back({0, i});
  }
  int num;
  for (int i = 1; i <= n; i++)
  {
    cin >> num;
    amount[num + 4000].first--;
    max_v = max(max_v, num);
    min_v = min(min_v, num);
    a += num;
    seq.push_back(num);
  }

  cout << (int)round(a / (float)n) << '\n';

  sort(seq.begin(), seq.end());
  cout << seq[n / 2] << '\n';

  sort(amount.begin(), amount.end());
  if (amount[0].first == amount[1].first)
  {
    cout << amount[1].second << '\n';
  }
  else
  {
    cout << amount[0].second << '\n';
  }

  cout << max_v - min_v;
  return 0;
}