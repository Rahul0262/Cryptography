#include<iostream>
#include <string.h>
using namespace std;
int main(){
	int l,key[100000];
	char encr_key[100000],pt[100000],vig_key[100000],ct[100000];
	cin >> l;
	for(int i=0;i<l;i++){
	    cin>>key[i];
	}
	cin>> encr_key;
	cin>> pt;
	int height = strlen(encr_key)/l;
	/*
	Vigenere Decryption
	*/
	for(int i=0;i<l;i++){
		for (int j = 0,k = 0; j < height; j++,k+=l){
			vig_key[i+k] = encr_key[((key[i] - 1) * height) + j];
		}
	}
	for (int i = 0; i < strlen(pt); ++i){
		ct[i] = 'a' + (vig_key[i%strlen(vig_key)] + pt[i] - 'a' - 'a')%26;
	}
	printf("%s\n", vig_key);
	printf("%s\n", ct);
	return 0;
}