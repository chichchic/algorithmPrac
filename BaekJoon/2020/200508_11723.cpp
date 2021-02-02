#include <iostream>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int state = 0;
  int m;
  cin >> m;
  while (m--)
  {
    char tmp[10];
    scanf("%s", tmp);
    string a = tmp;

    if (a == "all")
      state = (1 << 21) - 1;
    else if (a == "empty")
      state = 0;
    else
    {
      int x;
      scanf("%d", &x);
      if (a == "add")
        state |= (1 << x);
      else if (a == "remove" && state & (1 << x))
        state -= (1 << x);
      else if (a == "check")
        if (state & (1 << x))
          printf("1\n");
        else
          printf("0\n");
      else if (a == "toggle")
        state ^= (1 << x);
    }
  }
  return 0;
}