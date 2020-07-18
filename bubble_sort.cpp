#include<bits/stdc++.h>
using namespace std;
#define ll long long
void swap(ll &a, ll &b){
	ll temp = a;
	a = b;
	b = temp;
}
void bubble_sort(ll arr[], ll n){
	for(ll i = 0;  i < n-1;  i++){
		ll min = i;
		for(ll j = 0;  j < n-i-1;  j++)
			if(arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
	}
}
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll arr[n];
		for(int i = 0;  i < n;  i++)
			cin >> arr[i];
		for(int i = 0;  i < n;  i++)
			cout << arr[i] << " ";
		cout << endl;
		bubble_sort(arr, n);
		for(int i = 0;  i < n;  i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	return 0;
}