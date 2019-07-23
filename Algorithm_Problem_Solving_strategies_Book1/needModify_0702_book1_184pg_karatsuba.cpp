//아직 덜함

#include <iostream>
#include <vector>

using namespace std;

void usd(vector<int>& input) //vector 내부 숫자 뒤집기
{
    for(int i = 0; i < input.size() / 2; i++)
    {
        int temp = input[i];
        input[i] = input[input.size() - i];
        input[input.size() - i] = i;
    }
}

void nomalize(vector<int>& input) // 자릿수 계산 및 뒤집기
{
    int carry = 0;

    for(int i = 0; i < input.size(); i++)
    {
        input[i] += carry;

        if(input[i] > 9)
        {
            carry = input[i] / 10;
            input[i] %= 10;
        }
        else
        {
            carry = 0;
        }
    }

    usd(input);
}

//곱하는게 각 자리수별이 아닌, 모든 자리수와 곱해야함 (이중 반복문을 사용해야함)
// 수정 필요
vector<int> multypVec(vector<int> input1, vector<int> input2)
{
    usd(input1);
    usd(input2);

    vector<int> output;

    bool small1 = (input1.size() < input2.size());
    int i = 0;

    if(small1)
    {
        for(; i < input1.size(); i++)
            output.push_back(input1[i] * input2[i]);
        for(; i < input2.size(); i++)
            output.push_back(input2[i]);
    }
    else
    {
        {
            for(; i < input2.size(); i++)
                output.push_back(input1[i] * input2[i]);
            for(; i < input1.size(); i++)
                output.push_back(input1[i]);
        }
    }
    
    nomalize(output);
    
    return output;
}

int main()
{
    int input1_size, input2_size, temp;
    vector<int> input1, input2, output;
    
    cin >> input1_size;

    for(int i = 0; i < input1_size; i++)
    {
        cin >> temp;
        input1.push_back(temp);
    }

    cin >> input2_size;

    for(int i = 0; i < input2_size; i++)
    {
        cin >> temp;
        input2.push_back(temp);
    }

    output = multypVec(input1, input2);

    for(int i = 0; i < output.size(); i++)
    {
        cout << output[i];
    }
    cout << endl;

    return 0;
}