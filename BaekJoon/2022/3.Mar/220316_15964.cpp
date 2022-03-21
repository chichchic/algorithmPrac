#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  cout << (a + b) * (a - b);

  return 0;
}