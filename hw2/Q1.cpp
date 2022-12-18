#include <iostream>

using namespace std;


string find_realese_type(int year){
    int mod3 = year%3;
    if (mod3 == 0) return "core i7";
    if (mod3 == 1) return "core i3";
    if (mod3 == 2) return "core i5";
    return "";
}
int find_generation(int year){
    return ((year-1)/3) +1;
}

float ProcessingPowerOfYear(int generation, string Processor_type){
    if (Processor_type == "core i3"){
        if (generation == 1) return 1;
        else return 1.5 * ProcessingPowerOfYear(generation-1, Processor_type);
    }
    else if (Processor_type == "core i5"){
        if (generation == 1) return 1.4;
        else  return (1.2 * ProcessingPowerOfYear(generation-1, Processor_type))+
                     (0.2 * ProcessingPowerOfYear(generation, "core i3"));
    }
    else if (Processor_type == "core i7"){
        if (generation == 1) return 1.7;
        else return (1.3 * ProcessingPowerOfYear(generation-1, Processor_type))+
                    (0.3 * ProcessingPowerOfYear(generation, "core i5"))+
                    (0.2 * ProcessingPowerOfYear(generation, "core i3"));
    }
    return -1;
}


int main(){
    int year;
    cin >> year;
    if (year<1) return -1;
    string Processor_type = find_realese_type(year);
    int generation = find_generation(year);
    float PP = ProcessingPowerOfYear(generation, Processor_type);
    cout << Processor_type << endl;
    cout << PP << endl;
    return 0;
}