#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int l, p, v;
  int i = 1;
  while (true)
  {
    cin >> l >> p >> v;
    if (l == 0 && p == 0 && v == 0)
    {
      break;
    }
    int full = v / p * l;
    int remain = v % p;
    if (remain > l)
    {
      remain = l;
    }
    cout << "Case " << i << ": " << full + remain << '\n';
    i++;
  }

  return 0;
}