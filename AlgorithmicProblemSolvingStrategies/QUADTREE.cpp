#include <iostream>

using namespace std;

string inversion(string zip, int cur)
{
  if (zip[cur] != 'x')
  {
    return zip.substr(cur, 1);
  }
  string block[4];
  cur++;
  block[0] = inversion(zip, cur);
  cur += block[0].length();
  for (int i = 1; i < 4; i++)
  {
    block[i] = inversion(zip, cur);
    cur += block[i].length();
  }
  return "x" + block[2] + block[3] + block[0] + block[1];
}

int main()
{
  // freopen("./input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c;
  cin >> c;
  while (c--)
  {
    string zip;
    cin >> zip;
    cout << inversion(zip, 0) << '\n';
  }

  return 0;
}