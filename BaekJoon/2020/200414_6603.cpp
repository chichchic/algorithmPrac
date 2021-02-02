#include <iostream>
#include <vector>

using namespace std;

void print_lotto_candi(vector<int> &s, int cur, vector<int> candi)
{
  if (candi.size() >= 6)
  {
    for (int i = 0; i < candi.size(); i++)
    {
      cout << candi[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = cur; i < s.size(); i++)
  {
    candi.push_back(s[i]);
    print_lotto_candi(s, i + 1, candi);
    candi.pop_back();
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int k;
  cin >> k;
  while (k)
  {
    vector<int> s(k);
    for (int i = 0; i < k; i++)
    {
      scanf(" %d", &s[i]);
    }
    vector<int> temp;
    print_lotto_candi(s, 0, temp);
    printf("\n");
    cin >> k;
  }
  return 0;
}