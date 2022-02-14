#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int y, m;
  cin >> y >> m;
  cout << m + m - y;

  return 0;
}