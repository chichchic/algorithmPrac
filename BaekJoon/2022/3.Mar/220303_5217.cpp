#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test_case;
  cin >> test_case;
  while (test_case--)
  {
    int n;
    cin >> n;
    cout << "Pairs for " << n << ':';
    for (int i = 1; n - i > i; i++)
    {
      cout << ' ' << i << ' ' << n - i;
      if (n - i - 2 > i)
        cout << ',';
    }
    cout << '\n';
  }

  return 0;
}