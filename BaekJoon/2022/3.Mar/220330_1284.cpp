#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int size[10] = {4, 2, 3, 3, 3, 3, 3, 3, 3, 3};
  while (true)
  {
    string str;
    cin >> str;
    if (str == "0")
    {
      break;
    }
    int width = 1;
    for (int i = 0; i < str.length(); i++)
    {
      width += size[str[i] - '0'] + 1;
    }
    cout << width << '\n';
  }

  return 0;
}