#include <iostream>
#include <vector>

using namespace std;


bool IsLettersAndDigits(string str){
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") !=
        string::npos;
}

bool IsDomainCorrect(string str){
    if (str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.") != string::npos) {
        return false;
        }
    if (str.find("..")!=string::npos ){
        return false;
    }
    if (str[0]=='.' and str[str.length() - 1]=='.') {
        return false;
    }
    return true;
}


// class Contacts{
//     private:
//     string firstName;
//     string lastName;
//     string phone;
//     string email; 
//     public:
//     void addFirstName(string input){
//         firstName = input;
//         return;
//     }
//     void addLastName(string input){
//         lastName = input;
//         return;
//     }
//     void addPhone(string input){
//         if (input.length()!=11 or input.substr(0,2)!="09"){
//             cout<<"Command Failed"<<endl;
//             return;
//         }
//         phone = input;
//         return;
//     }
//     void addEmail(string input){
//         string domain;
//         string name;
//         size_t seprationPos = input.find("@");
//         if (seprationPos == string::npos){
//             cout<<"Command Failed"<<endl;
//             return;
//         }
//         domain = input.substr(seprationPos+1);
//         name = input.substr(0, seprationPos+1);
//         if (name.length()==0 or !IsLettersAndDigits(name))
//         {
//             cout<<"Command Failed"<<endl;
//             return; 
//         }
//         if (!IsDomainCorrect(domain))
//         {
//             cout<<"Command Failed"<<endl;
//             return; 
//         }
//         email = input;
//     }
// };

bool CheckPhone(string input){
    if (input.length()!=11 or input.substr(0,2)!="09"){
        cout<<"Command Failed phone"<<endl;
        return false;
    }
    return true;
}

bool CheckEmail(string input){
        string domain;
        string name;
        size_t seprationPos = input.find("@");
        if (seprationPos == string::npos){
            cout<<"Command Failed email"<<endl;
            return false;
        }
        domain = input.substr(seprationPos+1);
        name = input.substr(0, seprationPos+1);
        if (name.length()==0 or !IsLettersAndDigits(name))
        {
            cout<<"Command Failed email"<<endl;
            return false; 
        }
        if (!IsDomainCorrect(domain))
        {
            cout<<"Command Failed email"<<endl;
            return false; 
        }
        return true;
    }
void print_contacts(vector <string> firstNames,
                    vector <string> lastNames,
                    vector <string> emails,
                    vector <string> phones)
{
        for (int i = 0; i<firstNames.size(); i++){
            if (firstNames[i] == "-1") continue;
            cout << i << " " << firstNames[i] << " " << lastNames[i] << " " << emails[i] << " " << phones[i] <<endl;
        }
        return;
    
}

void add_contacts(  string temp,
                    vector <string> &firstNames,
                    vector <string> &lastNames,
                    vector <string> &emails,
                    vector <string> &phones)
{
    string tag;
        for (int i = 0 ; i < 4 ; i++)
        {
            cin >> tag;
            if (tag == "-f"){
                cin>>temp;
                firstNames.push_back(temp);
                continue;
            }
            if (tag == "-l"){
                cin>>temp;
                lastNames.push_back(temp);
                continue;
            }
            if (tag == "-p"){
                cin>>temp;
                if (CheckPhone(temp)){phones.push_back(temp);}
                else {break;}
                continue;
            }
            if (tag == "-e"){
                cin>>temp;
                if (CheckEmail(temp)){emails.push_back(temp);}
                else {break;}
                continue;
            }
        }
    return;
    
}

void search_for_string (
                        vector <string> firstNames,
                        vector <string> lastNames,
                        vector <string> emails,
                        vector <string> phones)

{
    string target;
    cin >> target;
        for (int i = 0; i<firstNames.size(); i++){
            if (firstNames[i].find(target)!=string::npos or 
                lastNames[i].find(target)!=string::npos or 
                emails[i].find(target)!=string::npos or 
                phones[i].find(target)!=string::npos )
                {cout << i << " " << firstNames[i] << " " << lastNames[i] << " " << emails[i] << " " << phones[i] <<endl;}        
                }
        return;
}

void delete_contact(
                        vector <string> &firstNames,
                        vector <string> &lastNames,
                        vector <string> &emails,
                        vector <string> &phones)
{
    int i;
    cin >> i;
    firstNames[i] = "-1";
    lastNames[i] = "-1";
    emails[i] = "-1";
    phones[i] = "-1";
    return;
    
}

int main(){
string command;
vector <string> firstNames;
vector <string> lastNames;
vector <string> emails;
vector <string> phones;
string tag;
string temp;
while (1){
    cin >> command;
    if (command == "add"){
        // cout << "add command run initiated" << "\n";
        add_contacts(temp, firstNames, lastNames, emails, phones);
    }
    else if (command == "search"){
        // cout << "search command run initiated" << "\n"; 
        search_for_string(firstNames, lastNames, emails, phones);

    }
    else if (command == "delete"){
        delete_contact(firstNames, lastNames, emails, phones);
    }
    else { cout << "invalid command" << "\n"; }
    // print_contacts(firstNames, lastNames, emails, phones);

}

}
