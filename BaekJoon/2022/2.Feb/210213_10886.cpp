#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int notCute = 0, cute = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int vote;
    cin >> vote;
    if (vote == 0)
    {
      notCute++;
    }
    else
    {
      cute++;
    }
  }
  cout << (notCute > cute ? "Junhee is not cute!" : "Junhee is cute!");
  return 0;
}