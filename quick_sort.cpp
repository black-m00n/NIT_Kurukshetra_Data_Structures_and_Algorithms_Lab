#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void swap(ll &a, ll &b){
	ll temp = a;
	a = b;
	b = temp;
}
// This is Lomuto partioning
ll partition(ll arr[], ll start, ll end){
	ll i = start, j; // or i = start-1
	ll pivot = arr[end];
	for(j = start;  j < end;  j++){
		if(arr[j] <= pivot){
			swap(arr[i], arr[j]);
			i++;
			/*
				or
				i++;
				swap(arr[i], arr[j]);
			*/
		}
	}
	swap(arr[i], arr[end]); // or swap(arr[++i], arr[end]);
	return i;
}
void quick_sort(ll arr[], ll start, ll end){
	if(start < end){
		ll pivot_index = partition(arr, start, end);
		quick_sort(arr, start, pivot_index-1);
		quick_sort(arr, pivot_index+1, end);
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
		quick_sort(arr, 0, n-1);
		for(int i = 0;  i < n;  i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	return 0;
}
