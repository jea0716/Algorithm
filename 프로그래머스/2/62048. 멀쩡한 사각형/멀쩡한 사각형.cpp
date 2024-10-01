using namespace std;

typedef long long ll;

long long solution(int w,int h) {
    ll answer = (ll)w * (ll)h - (w + h);
    
    int tmp;
    while(h != 0) {
        tmp = w % h;
        w = h;
        h = tmp;
    }
    
    answer += w;
    
    return answer;
}