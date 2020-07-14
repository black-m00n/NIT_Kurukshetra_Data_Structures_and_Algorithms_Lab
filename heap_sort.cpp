#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void swap(ll &x, ll &y){
	ll temp = x;
	x = y;
	y = temp;
}
void max_heapify(ll arr[], ll index, ll n){
	ll largest = index;
	ll left  =  2 * index + 1;
	ll right  =  2 * index + 2;
	if(left <= n  &&  arr[left] > arr[largest])
		largest = left;
	if(right <= n  &&  arr[right] > arr[largest])
		largest = right;
	if(largest != index){
		swap(arr[index], arr[largest]);
		max_heapify(arr, largest, n);
	}
}
void heap_sort(ll arr[], ll n){
	ll i;
	for(i = n/2 ;  i >= 0;  i--)
		max_heapify(arr, i, n);
	for(i = n;  i > 0;  i--){
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i-1);
	}
}
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll arr[n];
		for(ll i = 0;  i < n;  i++)
			cin >> arr[i];
		for(ll i = 0;  i < n;  i++)
			cout << arr[i] << " ";
		cout << endl;
		heap_sort(arr, n);
		for(ll i = 0;  i < n;  i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	return 0;
}