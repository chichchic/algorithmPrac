#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int ans = 100001;
  long long n, s;
  cin >> n >> s;
  vector<int> input(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> input[i];
  }

  int b = 0, e = 0;
  long long sum = input[0];
  while (true)
  {
    if (sum >= s)
    {
      ans = min(e - b + 1, ans);
      sum -= input[b++];
    }
    else if (e == n - 1)
      break;
    else
    {
      sum += input[++e];
    }
  }
  if (ans == 100001)
    cout << 0;
  else
    cout << ans;
  return 0;
}