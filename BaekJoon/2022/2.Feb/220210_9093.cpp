#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string str;
  getline(cin, str);
  while (n--)
  {
    getline(cin, str);
    istringstream ss(str);
    string strBuff;
    while (getline(ss, strBuff, ' '))
    {
      for (int i = strBuff.length() - 1; i >= 0; i--)
      {
        cout << strBuff[i];
      }
      cout << ' ';
    }
    cout << '\n';
  }

  return 0;
}