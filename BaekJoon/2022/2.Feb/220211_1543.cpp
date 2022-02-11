#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string doc;
  string key;
  getline(cin, doc);
  getline(cin, key);
  string::size_type idx = doc.find(key, 0);
  int ans = 0;
  while (idx != string::npos)
  {
    ans++;
    idx = doc.find(key, idx + key.length());
  }
  cout << ans;
  return 0;
}