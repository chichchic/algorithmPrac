#include <iostream>

using namespace std;

int main()
{
  freopen("input.txt", "r", stdin);
  int _case;
  long long n, m;
  cin >> _case;
  while (_case--)
  {
    cin >> n >> m;
    cout << 1 + (n - m) * m << '\n';
  }
  return 0;
}