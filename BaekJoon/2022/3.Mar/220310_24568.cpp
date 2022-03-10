#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int r, s;
  cin >> r >> s;
  int total = (r * 8 + s * 3);

  cout << (total > 28 ? total - 28 : 0);

  return 0;
}