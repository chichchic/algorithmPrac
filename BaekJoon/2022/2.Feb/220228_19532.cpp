#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  cout << ((c * e) - (f * b)) / ((a * e) - (d * b)) << ' ' << ((c * d) - (f * a)) / ((b * d) - (e * a));

  return 0;
}