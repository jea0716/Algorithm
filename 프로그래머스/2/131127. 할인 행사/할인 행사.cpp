#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    vector<int> basket(number.size(), 0);
    for(int i=0; i<=discount.size()-10; i++) {
        for(int j=0; j<basket.size(); j++) basket[j] = 0;
        for(int j=i; j<i+10; j++) {
            for(int k=0; k<want.size(); k++) {
                if(want[k] == discount[j]) basket[k]++;
            }
        }
        bool check = true;
        for(int j=0; j<basket.size(); j++) {
            if(basket[j] != number[j]) check = false;
        }
        if(check) answer++;
    }
    return answer;
}