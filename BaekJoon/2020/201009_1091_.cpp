//TODO: 아직 안품
#include <iostream>
#include <vector>

using namespace std;
vector<int> init_cards;
vector<int> shuffleRule;
int n;

int shuffle(const vector<int> &cards, const int step)
{
  vector<int> shuffledCards(n);
  while (true)
  {
    bool impossible = true;
    bool isSorted = true;
    for (int i = 0; i < n; i++)
    {
      shuffledCards[shuffleRule[i]] = cards[i];
      if (shuffledCards[i] != init_cards[i])
        impossible = false;
      if (shuffledCards[i] != i % 3)
        isSorted = false;
    }
    if (impossible)
      return -1;
    if (isSorted)
      return step;
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<int> cards(n);
  bool isSorted = true;
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    init_cards.push_back(num);
    if (num != i % 3)
      isSorted = false;
    cards[i] = num;
  }
  if (isSorted)
  {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    shuffleRule.push_back(num);
  }
  cout << shuffle(cards, 1);
  return 0;
}