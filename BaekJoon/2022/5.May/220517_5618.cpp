#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int a = 1, b = 1;
  cin >> a >> b;
  int c = a;
  if (n == 3)
  {
    cin >> c;
  }
  for (int i = 1; i <= min(a, min(b, c)); i++)
  {
    if (a % i == 0 && b % i == 0 && c % i == 0)
    {
      cout << i << '\n';
    }
  }

  return 0;
}