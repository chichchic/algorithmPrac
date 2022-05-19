#include <iostream>

using namespace std;

int getGCD(int a, int b)
{
  if (a < b)
  {
    return getGCD(b, a);
  }
  if (b == 0)
  {
    return a;
  }
  return getGCD(b, a % b);
}

int getLCM(int a, int b)
{
  int GCD = getGCD(a, b);
  return a * b / GCD;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int a, b;
    cin >> a >> b;
    cout << getLCM(a, b) << ' ' << getGCD(a, b) << '\n';
  }

  return 0;
}