#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map <long long, long long> m;
long long MOD = 1000000007;

long long answer(long long n)
{
    if(n <= 0) return 0;
    else if(n == 1) return 1;
    else if(n == 2) return 1;
    else if(m.count(n) > 0) return m[n];
    else
    {
        if(n % 2 == 0)
        {
            long long a = answer(n / 2 - 1) % MOD;
            long long b = answer(n / 2) % MOD;
            m[n] = b * ((2 * a + b) % MOD) % MOD;
            return m[n];
        }
        else
        {
            long long a = answer(n / 2 + 1) % MOD;
            long long b = answer(n / 2) % MOD;
            m[n] = ((b * b) % MOD + (a * a) % MOD) % MOD;
            return m[n];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    long long n; cin >> n;
    m[0] = 0; m[1] = m[2] = 1;
    cout << answer(n) << "\n";
    return  0;
}