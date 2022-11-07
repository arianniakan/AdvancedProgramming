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
    // vector <int> V1;
    int temp;
    int result = s;
    while (n>0){
        cin>>temp;
        cout << s << " "<< m << " "<< temp<< " " << n <<"\n";

        result = (s*(result+temp))%m;

        n--;
    }
    // for (int i = 0; i<V1.capacity()-1; i++)
    // {
    //     s = (s*(s+V1[i]))%m;
    //     cout << s << " "<< m << " "<< i <<"\n"<<;

    // }
    cout<<result<<endl;
    return 0;
}
