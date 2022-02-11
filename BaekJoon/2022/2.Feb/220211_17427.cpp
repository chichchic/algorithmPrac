#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans += (n / i) * i;
  }
  cout << ans;

  return 0;
}