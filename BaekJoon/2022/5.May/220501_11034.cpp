#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  int a, b, c;
  while (scanf("%d", &a) != EOF)
  {
    scanf("%d %d", &b, &c);
    int ans = 0;
    while (b - a != 1 || c - b != 1)
    {
      if (b - a < c - b)
      {
        a = b;
        b++;
      }
      else
      {
        c = b;
        b--;
      }
      ans++;
    }
    printf("%d\n", ans);
  }

  return 0;
}