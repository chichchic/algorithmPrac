#include <iostream>
#include <vector>

using namespace std;

int main()
{
  freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> positive;
  vector<int> negative;
  vector<int> liquid;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    if (temp > 0)
    {
      positive.push_back(temp);
    }
    else
    {
      negative.push_back(temp);
    }
  }
  int posIdx = 0, negIdx = negative.size() - 1;
  while (posIdx < positive.size() && negIdx >= 0)
  {
    if (positive[posIdx] < -negative[negIdx])
    {
      liquid.push_back(positive[posIdx]);
      posIdx++;
    }
    else
    {
      liquid.push_back(negative[negIdx]);
      negIdx--;
    }
  }
  for (; posIdx < positive.size(); posIdx++)
  {
    liquid.push_back(positive[posIdx]);
  }
  for (; negIdx >= 0; negIdx--)
  {
    liquid.push_back(negative[negIdx]);
  }
  int answer1, answer2;
  int gap = 2000000001;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int mixed = abs(liquid[i] + liquid[j]);
      if (abs(liquid[j]) - abs(liquid[i]) > gap)
      {
        break;
      }
      if (mixed < gap)
      {
        gap = mixed;
        answer1 = i;
        answer2 = j;
      }
    }
  }
  if (liquid[answer1] < liquid[answer2])
  {
    cout << liquid[answer1] << ' ' << liquid[answer2];
  }
  else
  {
    cout << liquid[answer2] << ' ' << liquid[answer1];
  }
  return 0;
}