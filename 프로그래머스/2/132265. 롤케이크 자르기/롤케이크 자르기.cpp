#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int arr_to[1000001], arr_from[1000001];

int solution(vector<int> topping) {
    int answer = 0;
    
    vector<int> v_to, v_from;
    for(int i=0; i<topping.size(); i++) {
        if(find(v_to.begin(), v_to.end(), topping[i]) == v_to.end()) {
            v_to.push_back(topping[i]);
        }
        arr_to[i] = v_to.size();
    }
    for(int i=topping.size()-1; i>=0; i--) {
        if(find(v_from.begin(), v_from.end(), topping[i]) == v_from.end()) {
            v_from.push_back(topping[i]);
        }
        arr_from[i] = v_from.size();
    }
    
    for(int i=0; i<topping.size()-1; i++) {
        if(arr_to[i] == arr_from[i+1]) answer++;
    }
    
    return answer;
}