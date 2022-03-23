#include <iostream>
using namespace std;

long long fibonacci(int n){
    // 재귀함수로 구현
    // if (n<=1){
    //     return n;
    // } else{
    //     return fibonacci(n-1)+fibonacci(n-2);
    // }
    
    // 반복문으로 구현
    long long n0 = 0;
    long long n1 = 1;
    long long result;

    if (n<=1){
        return n;
    } else {
        for (int i=0; i<(n-1); i++){
            result = n0 + n1;
            n0 = n1;
            n1 = result;
        }
        return result;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    cout << fibonacci(n);

    return 0;
}