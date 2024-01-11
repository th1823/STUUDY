#include <iostream>
using namespace std;

#define MAXN 100
int K; //폭탄 받은 사람 번호
int T; //개수
int N[MAXN+10];
char C[MAXN+10];

void Inputdata(){
    cin >> K;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N[i] >> C[i]; 
    }
}

int Solve(){
    
}

int main(){
    int ans=-1;

    Inputdata();
    ans = Solve();

    return ans;
}
