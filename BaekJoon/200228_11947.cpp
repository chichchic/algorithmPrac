#include <iostream>

using namespace std;

long long lovely(long long n)
{
  long long nCopy = n;
  long long ten = 1;
  long long rev = 0;
  while (nCopy)
  {
    rev += (9 - (nCopy % 10)) * ten;
    nCopy /= 10;
    ten *= 10;
  }
  return n * rev;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  long long t, n;
  cin >> t;
  while (t--)
  {
    cin >> n;
    long long nCopy = n;
    long long ten = 1;
    long long ans = 0;
    while (ten <= n)
    {
      ten *= 10;
    }
    ten /= 2;
    if (ten <= n)
      cout << lovely(ten) << '\n';
    else
      cout << lovely(n) << '\n';
  }
  return 0;
}