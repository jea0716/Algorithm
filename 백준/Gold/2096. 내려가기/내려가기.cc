#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    int t1, t2, t3;
    int m1=0, m2=0, m3=0, n1=0, n2=0, n3=0;
    int m4, m5, m6, n4, n5, n6;
    int min, max;
    for(int i=0; i<n; i++){
        cin >> t1 >> t2 >> t3;
        m4=m1; m5=m2; m6=m3;
        n4=n1; n5=n2; n6=n3;
        if(m4+t1 > m5+t1) m1 = m4+t1;
        else m1 = m5+t1;
        if(m4+t2 >= m5+t2 && m4+t2 >= m6+t2) m2 = m4+t2;
        else if(m5+t2 >= m4+t2 && m5+t2 >= m6+t2) m2 = m5+t2;
        else m2 = m6+t2;
        if(m5+t3 > m6+t3) m3 = m5+t3;
        else m3 = m6+t3;

        if(n4+t1 < n5+t1) n1 = n4+t1;
        else n1 = n5+t1;
        if(n4+t2 <= n5+t2 && n4+t2 <= n6+t2) n2 = n4+t2;
        else if(n5+t2 <= n4+t2 && n5+t2 <= n6+t2) n2 = n5+t2;
        else n2 = n6+t2;
        if(n5+t3 < n6+t3) n3 = n5+t3;
        else n3 = n6+t3;
    }
    if(m1 >= m2 && m1 >= m3) max = m1;
    else if(m2 >= m1 && m2 >= m3) max = m2;
    else max = m3;
    if(n1 <= n2 && n1 <= n3) min = n1;
    else if(n2 <= n3 && n2 <= n1) min = n2;
    else min = n3;
    cout << max << " " << min << endl;
    return 0;
}