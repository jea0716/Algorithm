#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

ll solution(int k, int d) {
    ll answer = 0;
    for(int i=0; i<=d; i+=k)
    {
        answer += (ll)(sqrt(pow(d, 2) - pow(i, 2)) / k + 1);
    }
    return answer;
}