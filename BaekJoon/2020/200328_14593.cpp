#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> ppii;

bool comp(ppii a, ppii b)
{
  if (a.first.first == b.first.first)
  {
    if (a.first.second == b.first.second)
    {
      return a.second.first < b.second.first;
    }
    return a.first.second < b.first.second;
  }
  return a.first.first > b.first.first;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  vector<ppii> input(n);
  for (int i = 0; i < n; i++)
  {
    cin >> input[i].first.first >> input[i].first.second >> input[i].second.first;
    input[i].second.second = i + 1;
  }
  sort(input.begin(), input.end(), comp);
  cout << input[0].second.second;
  return 0;
}