#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  cin >> a >> b;
  cout << a / b << ".";
  a %= b;
  for (int i = 0; i <= 1000; i++)
  {
    a *= 10;
    cout << a / b;
    a = a - (a / b) * b;
  }
  return 0;
}