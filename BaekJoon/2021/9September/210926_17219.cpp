#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  unordered_map<string, string> input(n);

  while (n--)
  {
    string s1, s2;
    cin >> s1 >> s2;
    input.insert({s1, s2});
  }

  while (m--)
  {
    string target;
    cin >> target;
    cout << input.find(target)->second << '\n';
  }

  return 0;
}