#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int odd = 0, even = 0;
    int answer = 0;
    for(int i=0; i<num_list.size(); i++) {
        if(num_list[i] % 2 == 0) {
            if(even == 0) even += num_list[i];
            else even *= 10, even += num_list[i];
        }
        else {
            if(odd == 0) odd += num_list[i];
            else odd *= 10, odd += num_list[i];
        }
    }
    answer = odd + even;
    return answer;
}