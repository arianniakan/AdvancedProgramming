#include <iostream>

using namespace std;

string coding(string str, int left, int right){
    if (left >= right) return str;
    else {
        string previous_ans = coding(str, left+2, right-1);
        swap( previous_ans[left], previous_ans[right]);
        return previous_ans;
    }
    return 0;

}

int main()
{
    string abc;
    cin >> abc;
    abc = coding(abc,0,abc.length()-1);
    cout<<abc<<endl;
}