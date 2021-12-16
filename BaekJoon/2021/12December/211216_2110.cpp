#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canSetRouter(vector<int> &position, const int target_cnt, int min_distance)
{
  int cnt = 1;
  int prev = position[0];
  for (int i = 1; i < position.size(); i++)
  {
    if (position[i] - prev >= min_distance)
    {
      cnt++;
      prev = position[i];
    }
  }
  if (cnt >= target_cnt)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, c;
  cin >> n >> c;
  vector<int> position(n);
  for (int i = 0; i < n; i++)
  {
    cin >> position[i];
  }
  sort(position.begin(), position.end());
  int s = 0, e = 1e9 + 1;
  while (s + 1 < e)
  {
    int mid = (e + s) / 2;
    if (canSetRouter(position, c, mid))
    {
      s = mid;
    }
    else
    {
      e = mid;
    }
  }
  cout << s;
  return 0;
}