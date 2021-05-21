#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 1000001;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int *a = (int *)malloc(MAX_SIZE * sizeof(int));
  int *dp = (int *)malloc(MAX_SIZE * sizeof(int));
  int *order = (int *)malloc(MAX_SIZE * sizeof(int));
  int size = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
    if (i == 0)
    {
      dp[0] = a[0];
    }
    if (dp[size] < a[i])
    {

      dp[++size] = a[i];
      order[i] = size;
    }
    else
    {
      int longest = lower_bound(dp, dp + size, a[i]) - dp;
      order[i] = longest;
      dp[longest] = a[i];
    }
  }
  cout << size + 1 << '\n';
  int cursor = n - 1;
  stack<int> s;
  while (size >= 0)
  {
    if (order[cursor] == size)
    {
      s.push(a[cursor]);
      size--;
    }
    cursor--;
  }
  while (!s.empty())
  {
    cout << s.top() << ' ';
    s.pop();
  }
  return 0;
}
