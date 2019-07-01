#include <iostream>
using namespace std;

int main() {
	double c, n, l, input[1001];
	double result = 0.0f, ans;
	cin >> c;
	while(c){
		cin >> n >> l;
		
		for(int i = 0; i < n; i++)
			cin >> input[i];
		
		ans = 100.0f;
		
		for(int i = l; i <= n; i++)
		{
			for(int j = 0; j <= n-i; j++)
			{
				result = 0.0;
				for(int k = 0; k < i; k++)
				{
					result += input[j+k];
				}
				result /= (double)i;
				if(ans > result) ans = result;
			}
		}
		
		cout << fixed;
		cout.precision(10);
		cout << ans << endl;
		c--;
	}
	return 0;
}