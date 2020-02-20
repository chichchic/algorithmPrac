#include <iostream>
#include <algorithm>

using namespace std;

int l, k, c;
int cutPoint[10003];
int ans;

int cutCheck(int limit)
{
  int curPoint = 0;
  int cutCnt = 0;
  for (int i = 1; i <= k + 1; i++)
  {
    if (cutPoint[i] - cutPoint[i - 1] > limit)
      return false;
    if (cutPoint[i] - curPoint > limit)
    {
      cutCnt++;
      if (cutCnt > c)
        return false;
      curPoint = cutPoint[i - 1];
    }
  }
  return cutCnt <= c;
}

int main()
{
  freopen("input.txt", "r", stdin);
  cin >> l >> k >> c;

  for (int i = 1; i <= k; i++)
    cin >> cutPoint[i];
  sort(cutPoint, cutPoint + k + 1);
  cutPoint[k + 1] = l;

  int s = 0, e = (1 << 31) - 1;
  while (s <= e)
  {
    int m = (s + e) / 2;
    if (cutCheck(m))
    {
      ans = m;
      e = m - 1;
    }
    else
      s = m + 1;
  }

  int curPoint = l;
  int cutCnt = 0;
  int idx = 0;
  for (int i = k; i >= 0; i--)
  {
    if (curPoint - cutPoint[i] > ans)
    {
      cutCnt++;
      curPoint = cutPoint[i + 1];
      idx = i + 1;
    }
  }
  if (cutCnt < c)
    idx = 1;

  cout << ans << ' ' << cutPoint[idx];
  return 0;
}