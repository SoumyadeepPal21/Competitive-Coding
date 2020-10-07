#include<bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265358979323846264338;
template<typename T> T gcd(T a, T b) { if (a < b) swap(a, b); return b ? gcd(b, a % b) : a; }
template <class T> inline T lcm(T a, T b) { return a / gcd(a, b) * b;}
template <typename T> inline T sqr(const T& x) { return x * x;}
bool isPerfectSquare(long double x) {long double sr = sqrt(x); return ((sr - floor(sr)) == 0);}
bool ispow2(int i) { return i && (i & -i) == i;}
int ceil(int a, int b) { return (a + b - 1) / b;}

int isprime(int n)
{
	if (n <= 1)  return 0; if (n <= 3)  return 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0) return 0;
	return 1;
}

// returns all distict factors
vector<int> factors(int x)
{
	vector<int> a, b;
	for (int i = 1; i * i <= x; ++i) if (x % i == 0) {
			a.push_back(i); if (i * i < x) b.push_back(x / i);
		}
	reverse(b.begin(), b.end()); a.insert(a.end(), b.begin(), b.end());
	return a;
}

// returns all distict prime factors
vector<int> primefactors(int n) {
	vector<int> primes;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			primes.emplace_back(i);
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) primes.emplace_back(n);
	return primes;
}

// returns all prime factors and how many times it divides x
vector<pair<long long, int>> factor(long long x) {
	vector<pair<long long, int>> ans;
	for (long long i = 2; i * i <= x; i++)
		if (x % i == 0) {
			ans.push_back({i, 1});
			while ((x /= i) % i == 0) ans.back().second++;
		}
	if (x != 1) ans.push_back({x, 1});
	return ans;
}



const int maxN = 1e6 + 10;
bool isprm[maxN];
vector<int> primes;
void seive()
{
	for (int i = 0; i < maxN; i++) isprm[i] = true;
	isprm[0] = isprm[1] = false;
	for (int i = 2; i < maxN; i++)
		if (isprm[i])
			for (int j = 2 * i; j < maxN; j += i) isprm[j] = false;
	for (int i = 2; i < maxN; i++) if (isprm[i]) primes.push_back(i);
}









const int maxN = 1e6 + 10;
int spf[maxN]; //spf[i] = smallest prime factor of iN
void SPF()
{
	for (int i = 1; i < maxN; i++) spf[i] = i;
	for (int i = 4; i < maxN; i += 2) spf[i] = 2;
	for (long long i = 3; i * i < maxN; i++)
		if (spf[i] == i)
			for (long long j = i * i; j < maxN; j += i)
				if (spf[j] == j) spf[j] = i;
}
map<int, int> getfactors(int x)
{
	map<int, int> ret;
	while (x != 1)
	{
		ret[spf[x]]++;
		x /= spf[x];
	}
	return ret;
}





template<class T> inline T bit(T x, int i) { return (x >> i) & 1;}
int digits(int n, int base) { return (int)(floor( log(n) / log(base)) + 1); }  // no of digits in n base "base"
int pct(int x) { return __builtin_popcountll(x);} //number of set bits
template<class T> inline int msb(T x) { return (int)floor(log2(x)); } //index(0 based) of msb bit


