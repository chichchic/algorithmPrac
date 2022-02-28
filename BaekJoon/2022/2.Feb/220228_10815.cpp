#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findCards(vector<int> &cards, int num)
{
  int s = 0, e = cards.size() - 1;
  while (s <= e)
  {
    int mid = (s + e) / 2;
    if (cards[mid] == num)
    {
      return 1;
    }
    else if (cards[mid] < num)
    {
      s = mid + 1;
    }
    else
    {
      e = mid - 1;
    }
  }
  return 0;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> cards(n);
  for (int i = 0; i < n; i++)
  {
    cin >> cards[i];
  }
  sort(cards.begin(), cards.end());
  int m, num;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> num;
    cout << findCards(cards, num) << ' ';
  }

  return 0;
}