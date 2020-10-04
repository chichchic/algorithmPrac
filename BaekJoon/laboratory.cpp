#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<int> temp;
  temp.push_back(1);
  temp.push_back(2);
  temp.push_back(3);
  temp.push_back(4);
  for (auto itr = temp.end() - 1; itr != temp.begin() - 1; itr--)
  {
    cout << *itr << ' ';
  }
  return 0;
}