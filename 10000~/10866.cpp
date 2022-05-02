#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    deque <int> dq;

    int n;
    cin >> n;

    string c;

    while(n--){
        cin >> c;

        if (c == "push_front"){
            int X;
            cin >> X;
            dq.push_front(X);
        } else if (c == "push_back"){
            int X;
            cin >> X;
            dq.push_back(X);
        } else if (c == "pop_front"){
            if (dq.empty()){
                cout << -1 << '\n';
            } else{
                cout << dq.front() << '\n';
                dq.pop_front();
            } 
        } else if (c == "pop_back"){
            if (dq.empty()){
                cout << -1 << '\n';
            } else{
                cout << dq.back() << '\n';
                dq.pop_back();
            } 
        } else if (c == "size"){
            cout << dq.size() << '\n';
        } else if (c == "empty"){
            cout << dq.empty() << '\n';
        } else if (c == "front"){
            if (dq.empty()){
                cout << -1 << '\n';
            } else{
                cout << dq.front() << '\n';
            }
        } else if (c == "back"){
            if (dq.empty()){
                cout << -1 << '\n';
            } else{
                cout << dq.back() << '\n';
            }
        }

    }
}