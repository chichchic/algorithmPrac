#include <iostream>
#include <vector>
using namespace std;

vector<int> bit_count(65536);

void setInitCount()
{
  bit_count[0] = 0;
  bit_count[1] = 1;
  bit_count[2] = 1;
  bit_count[3] = 2;
  int idx = 4;
  int step = 2;
  while (step < 16)
  {
    int loopCount = 1 << (step - 1);
    for (int i = 0; i < loopCount; i++)
    {
      bit_count[idx] = bit_count[idx - loopCount];
      idx++;
    }
    for (int i = 0; i < loopCount; i++)
    {
      bit_count[idx] = bit_count[idx - loopCount] + 1;
      idx++;
    }
    step++;
  }
}

int findCoFriend(int relationship1[], int relationship2[], int cursor)
{
  int result = 0;
  for (int i = 0; i <= cursor; i++)
  {
    int cofriend = relationship1[i] & relationship2[i];
    result += bit_count[cofriend];
  }
  return result;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  setInitCount();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int relationship[2001][126] = {};
  int cursor;
  for (int i = 1; i <= n; i++)
  {
    string relate;
    cin >> relate;
    cursor = 0;
    int idx = 0;
    for (int j = 0; j < n; j++)
    {
      if (relate[j] == '1')
      {
        relationship[i][cursor] |= (1 << idx);
      }
      idx++;
      if (idx > 15)
      {
        cursor++;
        idx = 0;
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    cout << findCoFriend(relationship[a], relationship[b], cursor) << '\n';
  }
  return 0;
}