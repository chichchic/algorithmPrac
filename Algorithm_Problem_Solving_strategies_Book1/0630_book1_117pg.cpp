#include <iostream>
#include <vector>

#define MAX(x, y) ((x > y) ? (x) : (y))

using namespace std;

int index_i, index_j, answer;

//O(N^3)
void bruteMaxSum(vector<int> input, int input_size)
{
    for(int i = 1; i <= input_size; i++)
    {
        for(int j = 0; j < input_size - i + 1; j++)
        {
            int total = 0;
            for(int k = 0; k < i; k++)
            {
                total += input[j+k];
            }
                if(answer < total)
                {
                    answer = total;
                    index_i = j;
                    index_j = i;
                }
        }
    }
}

//O(N^2)
void betterMaxSum(vector<int> input, int input_size)
{
    for(int i = 0; i < input_size; i++)
    {
        int total = 0;
        for(int j = 0; j < input_size-i; j++)
        {
            total += input[i+j];
            if(answer < total) 
            {
                answer = total;
                index_i = i;
                index_j = j+1;
            }
        }
    }
}

//Divide and Conquer && Greedy
//O(NlogN)
int fastMaxSum(vector<int> input, int low, int high, int min)
{
    if(low >= high) return input[low];

    int mid = (low + high) / 2, sum = 0, left = min, right = min;

    for(int i = mid; i >= low; i--)
    {
        sum += input[i];
        if(sum > left) left = sum;
    }

    sum = 0;

    for(int i = mid+1; i <= high; i++)
    {
        sum += input[i];
        if(sum > right) right = sum;
    }

    int result = MAX(fastMaxSum(input, low, mid, min), 
                    fastMaxSum(input, mid+1, high, min));

    return MAX(result, right+left);
}

// Dynamic Programing
//O(N)
int fastestMaxSum(vector<int> input, int input_size, int min)
{
    int result = min, ans = min;
    for(int i = 0; i < input_size; i++)
    {
        result = MAX(result, 0) + input[i];
        if(ans < result) ans = result;
    }

    return ans;
}

int main(){

    vector<int> input;
    int input_size, input_val;

    cin >> input_size;

    for(int i = 0; i < input_size; i++)
    {
        cin >> input_val;
        input.push_back(input_val);
        if (answer > input_val) answer = input_val;
    }
    
    /* 
    //bruteMaxSum(input, input_size);
    // betterMaxSum(input, input_size);
    for(int i = index_i; i < index_j+index_i; i++)
        cout << input[i] << " ";
    cout << endl;
    cout << answer << endl;
    */

   //cout << fastMaxSum(input, 0, input_size-1, answer) << endl;

    cout << fastestMaxSum(input, input_size, answer) << endl;

    return 0;
}