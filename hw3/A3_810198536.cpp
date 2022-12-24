#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

bool is_all_digit(string str){
    for (int i = 0; i<str.length(); i++){
        if (!isdigit(str[i])) return false;
    }
    return true;
}


class Student
{
    private: 

        string ID;
        string StudentName;
    public: 
        Student(){};
        Student(string inName, string inID){
            set_name(inName);
            set_ID(inID);
        };

        void set_name(string inName){
            if (inName.length()==0) abort();
            StudentName = inName;
        }
        void set_ID(string inID){
            if (!is_all_digit(inID)) abort();
            if (inID.length()<6) abort();
            ID = inID;
        }

        string get_name() {return StudentName;}
        string get_ID() {return ID;}
        void show_student(){
            cout<<"\n"<<StudentName<<" -- "<< ID<<endl;
        }


};

class Course{
    private: 
        string class_code;
        string class_title;
        string capacity;
        vector<Student*> attending_students;
        vector<Student*> waiting_students;

    public:
        Course(){};
        Course(string ClassCode, string ClassTitle, string Capacity){
            set_class_code(ClassCode);
            set_class_title(ClassTitle);
            set_capacity(Capacity);
        }
        void set_class_code(string ClassCode){
            if (ClassCode.length() != 2) abort();
            if (!is_all_digit(ClassCode)) abort();
            class_code = ClassCode;
        }

        void set_class_title(string ClassTitle){
            if(ClassTitle.length()==0) abort();\
            class_title = ClassTitle;
        }

        void set_capacity(string Capacity){
            if (!is_all_digit(Capacity)) abort();
            if (stoi(Capacity)<0) abort();
            capacity = Capacity;
        }
        string get_class_code() {return class_code;}
        string get_class_title() {return class_title;}
        int find_student_class_list(string ID){
            for (int i = 0; i<attending_students.size(); i++){
                if (attending_students[i]->get_ID() == ID) return i;
            }
            return -1;
        }
        int find_student_wait_list(string ID){
            for (int i = 0; i<waiting_students.size(); i++){
                if (waiting_students[i]->get_ID() == ID) return i;
            }
            return -1;
        }
        int number_of_attenders(){return attending_students.size();}
        int number_of_waiters(){return waiting_students.size();}

        bool is_class_full(){
            return attending_students.size() == stoi(capacity);
        }

        void fill_class(){
            int diff = stoi(capacity) - attending_students.size();
            if (diff<=0) {return;} 
            for (int i = 0; i < diff; i++){
                if (waiting_students.size()==0) return;
                attending_students.push_back(waiting_students[0]);
                waiting_students.erase(waiting_students.begin()+0);
            }
        }

        void add_student(Student* student){
            if (find_student_class_list(student->get_ID())==-1 and find_student_wait_list(student->get_ID())==-1){
                if (is_class_full()){
                    waiting_students.push_back(student);
                }
                else { attending_students.push_back(student);}
            }
        }

        void remove_student(Student* student){
            int student_index = find_student_class_list(student->get_ID());
            int wstudent_index = find_student_wait_list(student->get_ID());
            if (wstudent_index!=-1){
                waiting_students.erase(waiting_students.begin() + wstudent_index);
            }
            if (student_index!=-1){
                attending_students.erase(attending_students.begin() + student_index);
                fill_class();
            }
        }        
        void show_class(){
            cout<<"\n"<<class_title<<": "<< number_of_attenders() << "("<< number_of_waiters() << ")" <<"\n"<<endl;
        }

        



};

class University{
    private:
        vector<Student> students;
        vector<Course> courses; 
    public:
        void add_student(string name, string ID){
            students.push_back(Student(name, ID));
        }
        void add_course(string ClassCode, string ClassTitle, string Capacity){
            courses.push_back(Course(ClassCode, ClassTitle, Capacity));
        }
        void show_class(){
            courses[0].show_class();
        }
        void show_student(){
            students[0].show_student();
        }
        int find_student(string ID){
            for (int i = 0; i<students.size(); i++){
                if (students[i].get_ID() == ID) return i;
            }
            return -1;
        }
        int find_course(string class_code){
            for (int i = 0; i<courses.size(); i++){
                if (courses[i].get_class_code() == class_code) return i;
            }
            return -1;
        }
        void add_to_course(string student_id, string class_code){
            int student_index = find_student(student_id);
            int course_index = find_course(class_code);

            if ( student_index != -1 and course_index != -1 ){
                courses[course_index].add_student(&students[student_index]);
            }
        }

        void remove_from_course(string student_id, string class_code){
            int student_index = find_student(student_id);
            int course_index = find_course(class_code);

            if ( student_index != -1 and course_index != -1 ){
                courses[course_index].remove_student(&students[student_index]);
            }
        }

        void set_cap(string class_code, string capacity){
            int course_index = find_course(class_code);
            courses[course_index].set_capacity(capacity);
            courses[course_index].fill_class();
        }

        void report(){
            for (int i = 0; i < courses.size(); i++){
                courses[i].show_class();
            }
        }

        void student_report(string student_id){
            int student_index;
            int wstudent_index;
            int i;
            int student = find_student(student_id);
            if (student == -1) return;
            cout<<students[student].get_name()<<":\n"<<endl;

            for (i = 0; i < courses.size(); i++)
            {
                student_index = courses[i].find_student_class_list(student_id);
                wstudent_index = courses[i].find_student_wait_list(student_id);
                if (student_index!=-1) { cout << courses[i].get_class_title() << "\n" << endl;}
                if (wstudent_index!=-1) { cout << courses[i].get_class_title() << "(w)" << "\n"<<endl;}
            }
        }
};

int main(){
    // Student JonDoe;
    // string ID;
    // string Name;
    // cin >> ID;
    // cin >> Name;
    


    // University UT;
    // string ClassCode;
    // string ClassTitle;
    // string Capacity;

    // cin >> ClassCode;
    // cin >> ClassTitle;
    // cin >> Capacity; 
    // UT.add_course(ClassCode, ClassTitle, "1");
    // UT.report();
    // UT.add_student(Name, ID);
    // UT.add_student("Borna", "810198531");
    // UT.add_to_course(ID, ClassCode);
    // UT.add_to_course("810198531", ClassCode);
    // UT.report();
    // UT.student_report(ID);
    // UT.student_report("810198531");
    // UT.set_cap(ClassCode,"2");
    // UT.report();
    // UT.student_report(ID);
    // UT.student_report("810198531");
    // UT.set_cap(ClassCode,"0");
    // UT.report();
    // UT.student_report(ID);
    // UT.student_report("810198531");
    int n;
    int m;
    cin>>n;
    string name;
    string ID;
    University UT;

    for (int i = 0; i<n; i++){
        cin>>ID;
        cin>>name;
        UT.add_student(name, ID);
    }
    string ClassCode;
    string ClassTitle;
    string Capacity;

    cin>>m;
    for (int i = 0; i<m; i++){
        cin>>ClassCode;
        cin>>ClassTitle;
        cin>>Capacity;
        UT.add_course(ClassCode, ClassTitle, Capacity);
    }
    string command;
    while(1){
        cin>>command;
        if (command == "add"){
            cin>>ID;
            cin>>ClassCode;
            UT.add_to_course(ID, ClassCode);
        }
        if (command == "report"){UT.report();}
        if (command == "student"){
            cin>>ID;
            UT.student_report(ID);
        }
        if(command == "drop"){
            cin>>ID;
            cin>>ClassCode;
            UT.remove_from_course(ID, ClassCode);
        }
        if(command == "setcap"){
            cin>>ClassCode;
            cin>>Capacity;
            UT.set_cap(ClassCode, Capacity);
        }
    }
    return 0;
} 