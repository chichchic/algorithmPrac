#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> pos(k);
  for (int i = 0; i < k; i++)
  {
    cin >> pos[i];
  }
  int start = 0, end = pos[k - 1] - pos[0] + 1;
  string ans = "";
  int cnt;
  while (end - start > 1)
  {
    cnt = 1;
    int mid = (start + end) / 2;
    int cur = pos[0];
    string ansCandi = "1";
    for (int i = 1; i < k; i++)
    {
      if (cnt < m && pos[i] - cur >= mid)
      {
        cur = pos[i];
        ansCandi += '1';
        cnt++;
      }
      else
      {
        ansCandi += '0';
      }
    }
    // cout << cnt << ' ' << ansCandi << ' ' << mid << '\n';
    if (cnt < m)
      end = mid;
    else if (cnt == m)
    {
      start = mid;
      ans = ansCandi;
    }
    else
    {
      start = mid;
    }
  }
  cout << ans;
  return 0;
}