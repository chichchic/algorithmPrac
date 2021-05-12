#include <iostream>

using namespace std;

int FindLongest(int dp[], int size, int threshold)
{
  int begin = 0;
  int end = size;
  while (end - begin > 1)
  {
    int mid = (begin + end) / 2;
    if (dp[mid] < threshold)
    {
      begin = mid;
    }
    else
    {
      end = mid;
    }
  }
  return begin;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int a[1000000];
  int dp[1000001] = {-1000000001};
  int size = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
    if (dp[size] < a[i])
    {
      dp[++size] = a[i];
    }
    else if (dp[size] > a[i])
    {
      int longest = FindLongest(dp, size, a[i]);
      if (dp[longest + 1] > a[i])
      {
        dp[longest + 1] = a[i];
      }
    }
  }
  cout << size;
  return 0;
}
