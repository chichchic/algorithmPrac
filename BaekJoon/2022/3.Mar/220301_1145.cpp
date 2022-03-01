#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int input[5];
  cin >> input[0] >> input[1] >> input[2] >> input[3] >> input[4];
  int s = min(input[0], min(input[1], min(input[2], min(input[3], input[4]))));
  for (int i = s;; i++)
  {
    int cnt = 0;
    for (int j = 0; j < 5; j++)
    {
      if (i % input[j] == 0)
      {
        cnt++;
      }
    }
    if (cnt >= 3)
    {
      cout << i;
      break;
    }
  }
  return 0;
}