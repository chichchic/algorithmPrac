#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << (int)(n * 0.78) << ' ' << (int)(n * 0.8 + n * 0.2 * 0.78);

  return 0;
}