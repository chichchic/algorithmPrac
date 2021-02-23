class Solution
{
public:
  void reverseString(vector<char> &s)
  {
    int vecSize = s.size();
    for (int i = 0; i < vecSize / 2; i++)
    {
      s[i] += s[vecSize - i - 1];
      s[vecSize - i - 1] = s[i] - s[vecSize - i - 1];
      s[i] -= s[vecSize - i - 1];
    }
  }
};