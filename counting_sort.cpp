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
void counting_sort(ll A[], ll n){
	ll B[n+1];
	ll i;
	ll max = get_max(A, n);
	ll C[max+1];
	for(i = 0;  i <= max;  i++)
		C[i] = 0;
	for(i = 1;  i <= n;  i++)
		C[A[i]] = C[A[i]] + 1;
	for(i = 1;  i <= max;  i++)
		C[i] = C[i] + C[i-1];
	for(i = n;  i >= 1;  i--){
		B[C[A[i]]] = A[i];
		C[A[i]] = C[A[i]] - 1;
	}
	for(i = 1;  i <= n;  i++)
		A[i] = B[i];
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
		counting_sort(arr, n);
		for(ll i = 1;  i <= n;  i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	return 0;
}