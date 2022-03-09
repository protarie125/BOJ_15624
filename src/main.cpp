#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

constexpr auto divi = int{ 1'000'000'007 };

vi memo;

int fibo(int n) {
	if (memo[n] < 0) {
		memo[n] = (fibo(n - 1) + fibo(n - 2)) % divi;
	}

	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	if (0 == n) {
		cout << 0;
		return 0;
	}

	if (1 == n) {
		cout << 1;
		return 0;
	}

	memo = vi(n + 1, -1);
	memo[0] = 0;
	memo[1] = 1;

	cout << fibo(n);

	return 0;
}