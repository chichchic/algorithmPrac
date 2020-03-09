#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char input[100000][31];     //24 == number;
char input_str[100000][31]; //24 == number;

int comp(const void *a, const void *b)
{
  return strcmp((char *)a, (char *)b);
}

int cstr_to_int(char *a, int size)
{
  int output = 0;
  for (int i = 0; i < size; i++)
  {
    output = output * 10 + (a[i] - '0');
  }
  return output;
}

void seek(char *a, int end)
{
  int start = 0;
  int mid;
  while (start <= end)
  {
    int mid = (start + end) / 2;
    int result = strcmp(input_str[mid], a);
    if (result == 0)
    {
      int output = 0;
      for (int i = 5; i >= 0; i--)
      {
        output = output * 10 + (int)(input_str[mid][30 - i] - '0');
      }
      printf("%d\n", output + 1);
      return;
    }
    else if (result < 0)
      start = mid + 1;
    else
      end = mid - 1;
  }
  // cout << "s: " << start << "e: " << end << '\n';
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, m;
  scanf(" %d %d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    scanf(" %s", input[i]);
  }
  for (int i = 0; i < n; i++)
  {
    memcpy(input_str[i], input[i], sizeof(input_str[0]));
    int temp = i;
    for (int j = 0; j < 6; j++)
    {
      input_str[i][30 - j] = temp % 10 + '0';
      temp /= 10;
    }
  }

  qsort(input_str, n, sizeof(input_str[0]), comp);

  for (int i = 0; i < m; i++)
  {
    char temp[25];
    scanf(" %s", temp);
    if (temp[0] <= '9' && temp[0] >= '0')
      printf("%s\n", input[cstr_to_int(temp, strlen(temp)) - 1]);
    else
      seek(temp, n - 1);
  }

  return 0;
}