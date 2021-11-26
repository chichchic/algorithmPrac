#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> cardPacks(n + 1);
  vector<pair<double, int>> cost(n);
  vector<vector<int>> costMatrix(n + 1, (vector<int>(n + 1, 0)));
  for (int i = 1; i <= n; i++)
  {
    cin >> cardPacks[i];
    cost[i - 1].first = cardPacks[i] / (double)i;
    cost[i - 1].second = i;
  }
  sort(cost.begin(), cost.end());
  for (int num = 1; num <= n; num++)
  {
    int cardCnt = cost[num - 1].second;
    for (int cnt = 1; cnt <= n; cnt++)
    {
      if (cnt < cardCnt)
      {
        costMatrix[num][cnt] = costMatrix[num - 1][cnt];
      }
      else
      {
        costMatrix[num][cnt] = max(max(costMatrix[num][cnt - cardCnt] + cardPacks[cardCnt], costMatrix[num - 1][cnt]), costMatrix[num - 1][cnt - cardCnt] + cardPacks[cardCnt]);
      }
    }
  }
  cout << costMatrix[n][n];
  return 0;
}