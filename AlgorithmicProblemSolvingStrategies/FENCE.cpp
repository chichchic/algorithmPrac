#include <iostream>
#include <vector>

using namespace std;

int getMaxSize(vector<int> &fence, int s, int e)
{
  if (s == e)
  {
    return fence[s];
  }
  int mid = (s + e) / 2;
  int l = mid, r = mid + 1;
  int ret = max(getMaxSize(fence, s, l), getMaxSize(fence, r, e));
  int height = min(fence[l], fence[r]);
  ret = max(ret, height * (r - l + 1));
  while (l > s || r < e)
  {
    if (l == s || (r != e && fence[l - 1] < fence[r + 1]))
    {
      r++;
      height = min(height, fence[r]);
      ret = max(ret, height * (r - l + 1));
    }
    else
    {
      l--;
      height = min(height, fence[l]);
      ret = max(ret, height * (r - l + 1));
    }
  }
  return ret;
}

int main()
{
  // freopen("./input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c;
  cin >> c;
  while (c--)
  {
    int n;
    cin >> n;
    vector<int> fence(n);
    for (int i = 0; i < n; i++)
    {
      cin >> fence[i];
    }
    cout << getMaxSize(fence, 0, n - 1) << '\n';
  }

  return 0;
}