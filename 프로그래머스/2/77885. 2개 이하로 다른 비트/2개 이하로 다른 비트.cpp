#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i=0; i<numbers.size(); i++) {
        if(numbers[i] % 2 == 0) answer.push_back(numbers[i] + 1);
        else {
            long long tmp = 1;
            while(numbers[i] & tmp) {
                tmp *= 2;
            }
            answer.push_back(numbers[i] + (tmp / 2));
        }
    }
    
    return answer;
}