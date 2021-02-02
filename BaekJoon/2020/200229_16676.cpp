#include <iostream>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  long long n;
  cin >> n;
  int ans = 1;
  long long temp = 100;
  long long limit = 11;
  while (limit <= n)
  {
    ans++;
    limit += temp;
    temp *= 10;
  }
  cout << ans;
  return 0;
}