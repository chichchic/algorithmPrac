#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = n / 5; i >= 0; i--)
  {
    int remain = (n - 5 * i);
    if (remain % 2 == 0)
    {
      cout << i + remain / 2;
      return 0;
    }
  }
  cout << -1;
  return 0;
}