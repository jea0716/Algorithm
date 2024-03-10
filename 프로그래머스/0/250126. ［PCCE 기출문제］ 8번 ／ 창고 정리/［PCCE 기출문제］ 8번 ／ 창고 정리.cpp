#include <string>
#include <vector>

using namespace std;

string solution(vector<string> storage, vector<int> num) {
    int num_item = 0;
    vector<string> clean_storage(storage.size());
    vector<int> clean_num(num.size());
    
    for(int i=0; i<storage.size(); i++){
        int clean_idx = -1;
        for(int j=0; j<num_item; j++){
            if(storage[i] == clean_storage[j]){
                clean_idx = j;
                break;
            }
        }
        if(clean_idx == -1){
            clean_storage[num_item] = storage[i];
            clean_num[num_item] = num[i];
            num_item += 1;
        }
        else{
            clean_num[clean_idx] += num[i];
        }
    }
    
    // 아래 코드에는 틀린 부분이 없습니다.
    
    int num_max = -1;
    string answer = "";
    for(int i=0; i<num_item; i++){
        if(clean_num[i] > num_max){
            num_max = clean_num[i];
            answer = clean_storage[i];
        }
    }
    return answer;
}