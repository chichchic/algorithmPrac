#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int input[4];
    cin >> input[0] >> input[1] >> input[2] >> input[3];

    sort(input, input+4);

    cout << input[0] * input[2] << endl;



    return 0;
}