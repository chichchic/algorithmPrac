#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int l, c;

bool isVowel(char c)
{
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return true;
  return false;
}

void backTracking(vector<char> &keySet, int point, vector<char> &charSet, int consonant, int vowel)
{
  if (keySet.size() == l)
  {
    for (int i = 0; i < keySet.size(); i++)
      cout << keySet[i];
    cout << '\n';
    return;
  }
  for (int i = point; i < c - l + keySet.size() + 1; i++)
  {
    keySet.push_back(charSet[i]);
    int hasVoewl = 0, hasConsonant = 0;
    if (isVowel(charSet[i]))
    {
      hasVoewl = vowel > 0 ? 1 : 0;
    }
    else
    {
      hasConsonant = consonant > 0 ? 1 : 0;
    }
    if (l >= keySet.size() + consonant + vowel - hasVoewl - hasConsonant)
    {
      backTracking(keySet, i + 1, charSet, consonant - hasConsonant, vowel - hasVoewl);
    }
    keySet.pop_back();
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> l >> c;
  vector<char> charSet(c);

  for (int i = 0; i < c; i++)
  {
    cin >> charSet[i];
  }

  sort(charSet.begin(), charSet.end());
  vector<char> keySet;
  backTracking(keySet, 0, charSet, 2, 1);
  return 0;
}