#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  cout << (b - c) / a;

  return 0;
}