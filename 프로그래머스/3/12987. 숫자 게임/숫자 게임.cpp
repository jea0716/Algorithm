#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int cnt = 0;
    
    for(int i=0; i<B.size(); i++)
    {
        if(A[cnt] < B[i])
        {
            cnt++;
        }
    }
    
    return cnt;
}