#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int tmp = n;
    int i = 2;
    while(tmp > 1) {
        if(tmp % i == 0) {
            answer.push_back(i);
            while(tmp % i == 0) tmp /= i;
        }
        
        i++;
    }
    return answer;
}