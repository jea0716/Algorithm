#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    vector <int> prev(arr.size(), 0);
    vector <int> now = arr;
    while(prev != now) {
        for(int i=0; i<arr.size(); i++) {
            prev[i] = now[i];
            if(now[i] % 2 == 0 && now[i] >= 50) now[i] /= 2;
            else if(now[i] % 2 == 1 && now[i] < 50) now[i] = now[i] * 2 + 1;
        }
        answer++;
    }
    return answer-1;
}