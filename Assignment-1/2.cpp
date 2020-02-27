#include<bits/stdc++.h>
using namespace std;

int inversemodulo(int x,int mod){
	int i=1;
	while((x*i)%26 != mod){
		i++;
	}
	return i;
}

int reality(int x){
	return (x % 26 < 0)? (x%26)+26: (x%26);
}

int main(){
	string ct,first,second,v;
	cin >> ct;
	cin >> first >> second;
	int ct_len = ct.length();
	if (ct_len%2 != 0)
	{
		ct.append("Z");
		ct_len+=1;
	}
	int F[2] = {(first[0]-'A'),(first[1]-'A')};
	int S[2] = {(second[0]-'A'),(second[1]-'A')};
	v = ct;
	int K[2][2]={{0,0},{0,0}};
	K[1][0] = inversemodulo(11, (F[0]+S[0])%26);
	K[0][0] = inversemodulo(7, reality(S[0]-4*K[1][0]));
	K[1][1] = inversemodulo(11, (F[1]+S[1])%26);
	K[0][1] = inversemodulo(7, reality(S[1]-4*K[1][1]));
	int det = K[0][0]*K[1][1] - K[0][1]*K[1][0];
	int det_inv = inversemodulo(det,1);

	int k_1[2][2];
	k_1[0][0] = (K[1][1]*det_inv)%26;
	k_1[1][1] = (K[0][0]*det_inv)%26;
	k_1[0][1] = (reality(-K[0][1])*det_inv)%26;
	k_1[1][0] = (reality(-K[1][0])*det_inv)%26;

	for (int i = 0; i < ct.length(); i+=2)
	{
		v[i] = reality((int(ct[i]) - 65)*k_1[0][0] + (int(ct[i+1]) - 65)*k_1[1][0]) + 'A';
		v[i+1] = reality((int(ct[i]) - 65)*k_1[0][1] + (int(ct[i+1]) - 65)*k_1[1][1]) + 'A';
	}
	cout << v;
}