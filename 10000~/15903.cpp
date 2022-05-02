#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, m, num, min1, min2, sum;
    priority_queue <long long, vector<long long>, greater<long long> > pq;
    
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> num;
        pq.push(num);
    }

    while (m--){
        min1 = pq.top();
        pq.pop();
        min2 = pq.top();
        pq.pop();

        pq.push(min1+min2);
        pq.push(min1+min2);
    }

    sum = 0;

    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }

    cout << sum;
}