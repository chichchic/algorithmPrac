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
  int a[100001], b[100001];
  int dp[100001] = {};
  int size = 0;
  for (int i = 1; i <= n; i++)
  {
    int id;
    cin >> id;
    a[id] = i;
  }
  for (int i = 0; i < n; i++)
  {
    int id;
    cin >> id;
    b[i] = a[id];
    if (dp[size] < b[i])
    {
      dp[++size] = b[i];
    }
    else if (dp[size] > b[i])
    {
      int longest = FindLongest(dp, size, b[i]);
      if (dp[longest + 1] > b[i])
      {
        dp[longest + 1] = b[i];
      }
    }
  }

  cout << size;
  return 0;
}