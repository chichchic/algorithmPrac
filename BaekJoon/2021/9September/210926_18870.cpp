#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> coordinates(n);
  set<int> s;
  unordered_map<int, int> hash;
  for (int i = 0; i < n; i++)
  {
    cin >> coordinates[i];
    s.insert(coordinates[i]);
  }
  int size = 0;
  ;
  for (auto iter = s.begin(); iter != s.end(); ++iter)
  {
    hash.insert({*iter, size++});
  }
  for (int i = 0; i < n; i++)
  {
    cout << hash.find(coordinates[i])->second << ' ';
  }
  return 0;
}