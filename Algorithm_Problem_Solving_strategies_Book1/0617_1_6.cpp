#include <iostream>
using namespace std;

int main() {
	float c, n, l, input[1001];
	float result = 0.0f, ans;
	cin >> c;
	while(c){
		cin >> n >> l;
		
		for(int i = 0; i < n; i++)
			cin >> input[i];
		ans = 100.0f;
		for(int i = l; i <= n; i++)
		{
			for(int j = 0; j < n-i; j++)
			{
				result = 0.0f;
				for(int k = 0; k < i; k++)
				{
					result += input[j+k];
				}
				if(ans > result/(float)i) ans = result/(float)i;
			}
		}
		
		cout << ans << endl;
		c--;
	}
	return 0;
}