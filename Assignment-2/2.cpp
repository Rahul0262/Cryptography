#include <bits/stdc++.h>
using namespace std;

int getBinaryToDecimal(int n) 
{
    int ans = 0; 
    int base_val = 1;
    int unitDigit;
    while(n){
        unitDigit = n % 10;
        n = n/10; 
        ans += unitDigit * base_val; 
        base_val = base_val * 2; 
    }
    return ans; 
}

void getDecinmalToBinary(int n) 
{
    int ans[1000];   
    int i = 0; 
    while(n > 0) {
        ans[i] = n % 2; 
        n = n / 2; 
        i++;
    }
    for (int j = i - 1; j >= 0; j--){ 
       	cout << ans[j];
    }   
}

int main()
{
	int F,G,M;
	cin >> F;
	cin >> G;
	cin >> M;

	int q=1;
	int ans=0;

	int binaryOfF = getBinaryToDecimal(F);
	int binaryOfG = getBinaryToDecimal(G);
	int binaryOfM = getBinaryToDecimal(M);
	
	while (binaryOfF && binaryOfG) {
        if (binaryOfG & 1)
            ans ^= binaryOfF; 
        binaryOfG >>= 1;
        binaryOfF <<= 1;
	}

	if(ans > binaryOfM){
		while(q > 0){
			int n = 1, k = 0, i = -1, j = -1;
			while(i <= 0){
				n = n*2;
				if(ans <= n)	i = k;
				k++;
			}
			k=0;
			n=1;
			while(j <= 0){
				n = n*2;
				if(binaryOfM <= n)	j = k;
				k++;
			}
			q = i - j;
			if(q >= 0)	ans = ans ^ (binaryOfM << q);
		}
	}

	if(ans!=0)	getDecinmalToBinary(ans);
	else	cout << "0";

}