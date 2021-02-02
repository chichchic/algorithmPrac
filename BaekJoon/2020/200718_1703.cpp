#include <iostream>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int a;
  cin >> a;
  while (a)
  {
    int branch, cut, leaf = 1;

    for (int i = 0; i < a; i++)
    {
      cin >> branch >> cut;
      leaf = leaf * branch - cut;
    }
    cout << leaf << '\n';
    cin >> a;
  }
  return 0;
}