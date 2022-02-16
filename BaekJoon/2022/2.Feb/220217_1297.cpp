#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  double d, h, w;
  cin >> d >> h >> w;
  double m = (d * d) / (h * h + w * w);
  cout << (int)floor(h * sqrt(m)) << ' ' << (int)floor(w * sqrt(m));

  return 0;
}