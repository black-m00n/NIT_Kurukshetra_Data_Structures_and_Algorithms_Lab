#include<bits/stdc++.h>
using namespace std;
#define ll long long
void swap(ll &a, ll &b){
	ll temp = a;
	a = b;
	b = temp;
}
void selection_sort(ll arr[], ll n){
	for(ll i = 0;  i < n;  i++){
		ll min = i;
		for(ll j = i+1;  j < n;  j++)
			if(arr[j] < arr[min])
				min = j;
		if(min != i)
			swap(arr[i], arr[min]);
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
		selection_sort(arr, n);
		for(int i = 0;  i < n;  i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	return 0;
}