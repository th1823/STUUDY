#include <iostream>
#include <cstring>
using namespace std;
 
int N, P;
void InputData(){
    cin >> N >> P;
}
int remainder[97];

int count_parent(int k){
    int t = 1;
    int beg = k;
    int index = k;
    while(remainder[index] != beg){
        index = remainder[index];
        t+=1;
    }
 
    return t;
 
}
 
int sol(){
    // initialize remainder array
    memset(remainder, -1, sizeof(remainder));
    int k = N;
    while(1){
        int new_k = (k*N) % P;
         
        if (remainder[new_k] == k){
            // found common part
            return count_parent(new_k);
        }
        else{
            remainder[new_k] = k;
            k = new_k;
        }
 
    }
 
}
 
 
 
int main(){
    int ans = -1;
    InputData();

    ans = sol();
    cout << ans << endl;
    return 0;
}