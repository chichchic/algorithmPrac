#include <iostream>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);

  int a, prev;
  scanf("%d", &prev);
  bool isGood = true;
  while (scanf("%d", &a) != EOF)
  {
    if (a < prev)
    {
      isGood = false;
      break;
    }
    prev = a;
  }
  if (isGood)
    cout << "Good";
  else
    cout << "Bad";
  return 0;
}