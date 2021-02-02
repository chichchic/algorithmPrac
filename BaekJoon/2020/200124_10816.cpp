#include <iostream>

using namespace std;

int card[20000003] = {};

int main()
{
  int n, m, temp;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    scanf(" %d", &temp);
    card[temp + 10000000]++;
  }

  cin >> m;
  for (int i = 0; i < m; i++)
  {
    scanf(" %d", &temp);
    printf("%d ", card[temp + 10000000]);
  }

  return 0;
}