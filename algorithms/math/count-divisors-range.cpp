vl divisors(MAX, 0);
void count_divisors_range() {
    for (ll i = 1; i <= MAX; i++) {
        for (ll j = 1; j * i <= MAX; j++)
            divisors[i * j]++;
    }
}