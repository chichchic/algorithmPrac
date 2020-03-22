#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
long long n;

long long seg_init(vector<long long> &data, vector<long long> &seg_T, long long begin, long long end, long long cur)
{
  if (begin == end)
  {
    return seg_T[cur] = begin;
  }
  long long mid = (begin + end) / 2;
  long long candi1 = seg_init(data, seg_T, begin, mid, cur * 2 + 1);
  long long candi2 = seg_init(data, seg_T, mid + 1, end, cur * 2 + 2);
  return seg_T[cur] = (data[candi1] < data[candi2]) ? candi1 : candi2;
}

long long find_min(vector<long long> &data, vector<long long> &seg_T, long long begin, long long end, const long long find_s, const long long find_e, long long cur)
{
  if (end < find_s || begin > find_e)
    return -1;
  if (find_s <= begin && end <= find_e)
    return seg_T[cur];
  long long mid = (begin + end) / 2;
  long long candi1 = find_min(data, seg_T, begin, mid, find_s, find_e, cur * 2 + 1);
  long long candi2 = find_min(data, seg_T, mid + 1, end, find_s, find_e, cur * 2 + 2);
  if (candi1 == -1)
    return candi2;
  else if (candi2 == -1)
    return candi1;
  else
    return (data[candi1] < data[candi2]) ? candi1 : candi2;
}

long long max_area(vector<long long> &data, vector<long long> &seg_T, long long start, long long end)
{
  long long input_size = data.size();
  long long min_idx = find_min(data, seg_T, 0, input_size - 1, start, end, 0);
  long long result = (end - start + 1) * data[min_idx];
  if (start < min_idx)
  {
    result = max(result, max_area(data, seg_T, start, min_idx - 1));
  }
  if (end > min_idx)
  {
    result = max(result, max_area(data, seg_T, min_idx + 1, end));
  }
  return result;
}

int main()
{
  // freopen("input.txt", "w", stdout);
  // cout << "100000 ";
  // srand((unsigned long long)time(NULL));

  // for (int i = 0; i < 100000; i++)
  // {
  //   long long num = rand();
  //   cout << num % 1000000001 << ' ';
  // }
  // cout << '\n'
  //      << 0;
  // freopen("input.txt", "r", stdin);
  scanf(" %lld", &n);
  while (n)
  {
    long long h = ceil(log2(n));
    vector<long long> data(n);
    vector<long long> seg_T(1 << (h + 1), 0);
    for (long long i = 0; i < n; i++)
      scanf(" %lld", &data[i]);
    seg_init(data, seg_T, 0, n - 1, 0);
    printf("%lld\n", max_area(data, seg_T, 0, n - 1));
    scanf(" %lld", &n);
  }

  return 0;
}