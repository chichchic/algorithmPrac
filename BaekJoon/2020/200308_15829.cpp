#include <iostream>
#include <string>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  long long l;
  string st;
  cin >> l >> st;
  long long ans = 0;
  long long temp = 1;
  for (int i = 0; i < l; i++)
  {
    ans += (st[i] - 'a' + 1) * temp;
    ans %= 1234567891;
    temp *= 31;
    temp %= 1234567891;
  }
  cout << ans;
  return 0;
}