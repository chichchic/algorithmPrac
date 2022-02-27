#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int a, b;
    scanf("%d,%d", &a, &b);
    cout << a + b << '\n';
  }

  return 0;
}