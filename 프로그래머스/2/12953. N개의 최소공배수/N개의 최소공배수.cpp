#include <string>
#include <vector>

using namespace std;

int GCD(int n, int m) {
    int min = m > n ? n : m;
    int max = m > n ? m : n;
    
    while(max % min != 0) {
        int tmp = max % min;
        max = min;
        min = tmp;
    } 
    
    return min;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i=1; i<arr.size(); i++) {
        int g = GCD(answer, arr[i]);
        int tmp = answer * arr[i] / g;
        answer = tmp;
    }
    return answer;
}