#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string str;
  cin >> str;
  int t;
  cin >> t;
  while (t--)
  {
    int a;
    int b;
    cin >> a >> b;
    char c = str[a];
    str[a] = str[b];
    str[b] = c;
  }
  cout << str;

  return 0;
}