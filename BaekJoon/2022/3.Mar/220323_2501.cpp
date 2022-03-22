#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int p, q;
  cin >> p >> q;
  vector<int> v;

  for (int i = 1; i <= p; i++)
  {
    if (p % i == 0)
    {
      q--;
    }
    if (q == 0)
    {
      cout << i;
      break;
    }
  }
  if (q > 0)
  {
    cout << 0;
  }
  return 0;
}