#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void merge(ll arr[], ll start, ll mid, ll end){
	ll temp[end-start+1];
	ll i = start, j = mid+1, k = 0;
	while(i <= mid  &&  j <= end)
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	while(i <= mid)
		temp[k++] = arr[i++];
	while(j <= end)
		temp[k++] = arr[j++];
	for(i = start;  i <= end;  i++)
		arr[i] = temp[i-start];
}
void merge_sort(ll arr[], ll start, ll end){
	if(start < end){
		ll mid = start + (end-start)/2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid+1, end);
		merge(arr, start, mid, end);
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
		merge_sort(arr, 0, n-1);
		for(int i = 0;  i < n;  i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	return 0;
}