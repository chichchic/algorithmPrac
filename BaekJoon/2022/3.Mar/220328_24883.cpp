#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  char c;
  cin >> c;
  if (c == 'N' || c == 'n')
  {
    cout << "Naver D2";
  }
  else
  {
    cout << "Naver Whale";
  }

  return 0;
}