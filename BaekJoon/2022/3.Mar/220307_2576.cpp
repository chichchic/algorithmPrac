#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int answer1 = 0;
  int answer2 = 9999;
  for (int i = 0; i < 7; i++)
  {
    int num;
    cin >> num;
    if (num % 2 == 1)
    {
      answer1 += num;
      answer2 = min(answer2, num);
    }
  }
  if (answer1 == 0)
  {
    cout << -1;
  }
  else
  {
    cout << answer1 << endl
         << answer2;
  }

  return 0;
}