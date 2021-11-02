#include <iostream>
#include <vector>

using namespace std;

int findMaxRectangle(int s, int e, vector<int> &histogram)
{
  if (s == e)
  {
    return 0;
  }
  if (s + 1 == e)
  {
    return histogram[s];
  }
  int mid = (s + e) / 2;
  int answer = max(findMaxRectangle(s, mid, histogram), findMaxRectangle(mid, e, histogram));

  int l = mid;
  int r = mid;
  int width = 1;
  int height = histogram[mid];
  while (r - l + 1 < e - s)
  {
    int p = l > s ? min(height, histogram[l - 1]) : -1;
    int q = r < e - 1 ? min(height, histogram[r + 1]) : -1;

    if (p >= q)
    {
      height = p;
      l--;
    }
    else
    {
      height = q;
      r++;
    }
    width++;
    answer = max(answer, width * height);
  }
  return answer;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> histogram(n);
  for (int i = 0; i < n; i++)
  {
    cin >> histogram[i];
  }

  cout << findMaxRectangle(0, n, histogram);
  return 0;
}