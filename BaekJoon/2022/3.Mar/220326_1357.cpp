#include <iostream>

using namespace std;
int rev(int number)
{
  int ret = 0;
  while (number)
  {
    ret *= 10;
    ret += number % 10;
    number /= 10;
  }
  return ret;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  cout << rev(rev(a) + rev(b));

  return 0;
}