#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int ax, ay, az;
  cin >> ax >> ay >> az;
  int cx, cy, cz;
  cin >> cx >> cy >> cz;
  cout << cx - az << ' ' << cy / ay << ' ' << cz - ax;

  return 0;
}