ll sum_of_diference(ll arr[], ll n) {
	sort(arr, arr+n);

	ll sum = 0;

	for(ll i = 0; i < n; i++){
		sum += i*arr[i] - (n-1-i)*arr[i];
	}
		
	return sum;
}
