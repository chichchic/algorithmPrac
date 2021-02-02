#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int d, n;
  cin >> d >> n;
  vector<int> oven(d + 1);

  cin >> oven[1];
  for (int i = 2; i <= d; i++)
  {
    cin >> oven[i];
    if (oven[i] > oven[i - 1])
    {
      oven[i] = oven[i - 1];
    }
  }
  int pizza;
  int inoven = 0;
  while (inoven < n)
  {
    if (d <= 0)
    {
      cout << 0;
      return 0;
    }
    cin >> pizza;
    for (; d > 0; d--)
    {
      if (oven[d] >= pizza)
      {
        d--;
        inoven++;
        break;
      }
    }
  }
  cout << d + 1;
  return 0;
}