#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int y = 0, m = 0;
  for (int i = 0; i < n; i++)
  {
    int time;
    cin >> time;
    y += time / 30;
    m += time / 60;
    y += (time + 1) % 30 ? 1 : 0;
    m += (time + 1) % 60 ? 1 : 0;
  }
  y *= 10;
  m *= 15;
  if (y == m)
  {
    cout << "Y M " << m;
  }
  else
  {
    cout << (y > m ? "M " : "Y ");
    cout << (y > m ? m : y);
  }
  return 0;
}