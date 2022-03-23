#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int ur, tr, uo, to;
  cin >> ur >> tr >> uo >> to;
  cout << 56 * ur + 24 * tr + 14 * uo + 6 * to;

  return 0;
}