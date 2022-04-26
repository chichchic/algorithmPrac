#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int answer[6] = {0, 2, 4, 8, 16, 32};
  cout << answer[n];

  return 0;
}