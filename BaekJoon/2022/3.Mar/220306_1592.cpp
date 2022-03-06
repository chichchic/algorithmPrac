#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, l;
  cin >> n >> m >> l;
  vector<int> cnt(n, 0);
  int answer = 0;
  int idx = 0;
  while (true)
  {
    cnt[idx]++;
    if (cnt[idx] == m)
    {
      break;
    }
    if (cnt[idx] % 2 == 1)
    {
      idx = (idx + l) % n;
    }
    else
    {
      idx = (n + idx - l) % n;
    }
    answer++;
  }
  cout << answer;
  return 0;
}