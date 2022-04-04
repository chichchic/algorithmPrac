#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int s, m, l;
  cin >> s >> m >> l;
  cout << (1 * s + 2 * m + 3 * l >= 10 ? "happy" : "sad");

  return 0;
}