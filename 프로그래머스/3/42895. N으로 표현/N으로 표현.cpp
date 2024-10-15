#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int setting(int n, int k)
{
    int num = n;
    for(int i=0; i<k; i++) 
    {
        num = num * 10 + n;
    }
    
    return num;
}

int solution(int N, int number) {
    if (number == N) return 1;
    
    vector<unordered_set<int>> DP(8);
    
    DP[0].insert(N);
    
    for(int i=1; i<8; i++) 
    {
        DP[i].insert(setting(N, i));
        
        for(int j=0; j<i; j++)
        {
            for(int k=0; k<i; k++) 
            {
                if(j + k + 1 != i) continue;
                
                for(int a: DP[j]) 
                {
                    for(int b: DP[k])
                    {
                        DP[i].insert(a + b);
                        DP[i].insert(a * b);
                        
                        if(a - b > 0) DP[i].insert(a - b);
                        if(a / b > 0) DP[i].insert(a / b);
                    }
                }
            }
        }
        if(DP[i].find(number) != DP[i].end())
        {
            return i + 1;
        }
    }
    
    return -1;
}