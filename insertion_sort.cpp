#include<bits/stdc++.h>
using namespace std;
#define ll long long
void insertion_sort(ll arr[], ll n){
	for(ll j = 1;  j < n;  j++){
		ll key = arr[j];
		ll i = j-1;
		while(i >= 0  &&  key < arr[i]){
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = key;
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
		insertion_sort(arr, n);
		for(int i = 0;  i < n;  i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	return 0;
}