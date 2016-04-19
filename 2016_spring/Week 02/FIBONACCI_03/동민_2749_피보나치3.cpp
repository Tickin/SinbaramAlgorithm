//Ç®¾úÀ½



#include <iostream>
#include <cstring>
using namespace std;

long long mod = 1000000;

void array_gob(long long a[2][2], long long b[2][2], long long c[2][2]){

	a[0][0] = (b[0][0] * c[0][0] + b[0][1] * c[1][0])%mod;
	a[0][1] = (b[0][0] * c[0][1] + b[0][1] * c[1][1])%mod;
	a[1][0] = (b[1][0] * c[0][0] + b[1][1] * c[1][0])%mod;
	a[1][1] = (b[1][0] * c[0][1] + b[1][1] * c[1][1])%mod;
	
	
}

int main(){
	long long num;
	cin >> num;

	long long ans[2][2] = { { 1, 0 }, { 0, 1 } };
	long long a[2][2] = { { 1, 1 }, { 1, 0 } };

	while (num > 0){
		if (num % 2 == 1){
			//ans = ans * a
			long long temp[2][2];
			memset(temp, 0, sizeof(temp));
			
			array_gob(temp, ans, a);
			
			ans[0][0] = temp[0][0];
			ans[0][1] = temp[0][1];
			ans[1][0] = temp[1][0];
			ans[1][1] = temp[1][1];

		}

		long long temp2[2][2];
		memset(temp2, 0, sizeof(temp2));
		/*for (int i = 0; i < 2; i++){
			for (int k = 0; k < 2; k++){
				for (int j = 0; j < 2; j++){
					temp[i][k] += a[i][j] * a[j][k];
				}
				temp[i][k] %= mod;
			}
		}*/
		array_gob(temp2, a, a);

		a[0][0] = temp2[0][0];
		a[0][1] = temp2[0][1];
		a[1][0] = temp2[1][0];
		a[1][1] = temp2[1][1];

		num /= 2;
	}

	//cout << ans[0][0] << "  ";
	cout << ans[0][1] << endl;
	//cout << ans[1][0] << "  ";
	//cout << ans[1][1] << endl;
	return 0;

}