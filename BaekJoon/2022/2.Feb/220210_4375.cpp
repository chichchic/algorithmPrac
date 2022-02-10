#include <iostream>

using namespace std;

int findAnswer(int n)
{
  int ret = 1;
  int mod = 1;
  while (true)
  {
    mod %= n;
    if (!mod)
    {
      break;
    }
    ret++;
    mod *= 10;
    mod += 1;
  }
  return ret;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n)
  {
    cout << findAnswer(n) << '\n';
  }

  return 0;
}