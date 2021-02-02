#include <iostream>

using namespace std;
int val[31][2];
int main()
{
  // freopen("input.txt", "r", stdin);
  int d, k;
  cin >> d >> k;
  val[0][0] = 1;
  val[1][1] = 1;
  for (int i = 2; i < d; i++)
  {
    val[i][0] = val[i - 1][0] + val[i - 2][0];
    val[i][1] = val[i - 1][1] + val[i - 2][1];
  }
  int a = val[d - 1][0], b = val[d - 1][1];
  int ansA, ansB = (k / b) + 1;
  while (ansB)
  {
    if ((k - b * ansB) % a == 0)
    {
      ansA = (k - b * ansB) / a;
      if (ansA > 0)
        break;
    }
    ansB--;
  }
  cout << ansA << '\n'
       << ansB;
  return 0;
}