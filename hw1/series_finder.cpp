
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(){
    int m;
    int s;
    int n;
    cin >> s >> m;
    cin >> n;
    int min;
    int max;

    int hi;
    int ri = s;
    int guess;
    int N;
    cin>>hi;
    while (n>1){
        cin>>hi;

        min = ((ri + 97) * s)/m;
        max = ((ri + 122) * s)/m;
        N = min;
        guess = (N*m) + hi;
        while (guess%s!=0)
        {
            N++;
            guess = (N*m) + hi;
        }
        if (N<=max)
        {
            guess = (guess/s)-ri;
        }
        else {
            cout<<"no such char"<<endl;
            return 0;
        }

        cout << char(guess);
        n--;
        ri = hi;
    }

    cout<<endl;
    return 0;
}
