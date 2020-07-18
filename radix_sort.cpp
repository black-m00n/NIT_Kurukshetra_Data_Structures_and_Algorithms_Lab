#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll get_max(ll A[], ll n){
	ll i, max = A[1];
	for(i = 2;  i <= n;  i++)
		if(A[i] > max)
			max = A[i];
	return max;
}
ll get_digits(ll n){
	ll count = 0;
	while(n != 0){
		count++;
		n = n / 10;
	}
	return count;
}
void counting_sort(ll A[], ll n, ll range){
	ll B[n+1];
	ll i;
	ll C[10];
	for(i = 0;  i < 10;  i++)
		C[i] = 0;
	for(i = 1;  i <= n;  i++)
		C[(A[i] / range) % 10]++;
	for(i = 1;  i < 10;  i++)
		C[i] = C[i] + C[i-1];
	for(i = n;  i >= 1;  i--){
		B[C[(A[i] / range) % 10]] = A[i];
		C[(A[i] / range) % 10]--;
	}
	for(i = 1;  i <= n;  i++)
		A[i] = B[i];
}
void radix_sort(ll arr[], ll n){
	ll j, i = 1, max = get_max(arr, n);
	ll digits = get_digits(max);
	for(j = 1, i = 1;  j <= digits;  j++, i *= 10){
		counting_sort(arr, n, i);
	}		
}
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll arr[n+1];
		for(ll i = 1;  i <= n;  i++)
			cin >> arr[i];
		for(ll i = 1;  i <= n;  i++)
			cout << arr[i] << " ";
		cout << endl;
		radix_sort(arr, n);
		for(ll i = 1;  i <= n;  i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	return 0;
}