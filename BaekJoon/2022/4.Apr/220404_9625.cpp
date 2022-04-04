#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  int a[46] = {1, 0, 1};
  int b[46] = {0, 1, 1};
  for (int i = 3; i <= 45; i++)
  {
    a[i] = b[i - 1];
    b[i] = b[i - 1] + a[i - 1];
  }
  cout << a[k] << ' ' << b[k];

  return 0;
}