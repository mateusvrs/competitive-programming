ll sum_of_diference(vl& arr, ll n) {
	sort(all(arr));

	ll sum = 0;
	for(ll i = 0; i < n; i++){
		sum += i*arr[i] - (n-1-i)*arr[i];
	}
		
	return sum;
}
