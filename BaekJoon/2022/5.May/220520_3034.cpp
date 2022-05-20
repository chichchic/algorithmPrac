#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, w, h;
  cin >> n >> w >> h;
  int d = w * w + h * h;
  for (int i = 0; i < n; i++)
  {
    int l;
    cin >> l;
    if (l <= w || l <= h || l * l <= d)
    {
      cout << "DA\n";
    }
    else
    {
      cout << "NE\n";
    }
  }

  return 0;
}