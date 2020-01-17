#include <string>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>
#include <list>

using namespace std;

#define EXECUTIONS 10000000

string mode1_name = "      define";
string mode2_name = "static const";

#define STR1 "STR1"
static const string str1 = "STR1";

int a = 20;

string defineString() {
    return STR1;
}

string staticConstString() {
    return str1;
}

int main() {
    double elapsed_secs = 0;
    string result = "";

    for (int mode = 0; mode < 2; mode++) {
        for (int i = 0; i < EXECUTIONS; i++) {
            if (mode == 0) {
                clock_t begin = clock();
                
                result += defineString();
                
	            clock_t end = clock();
                elapsed_secs += double(end - begin) / CLOCKS_PER_SEC;
            } else {
                clock_t begin = clock();
                
	            result += staticConstString();
	            
	            clock_t end = clock();
                elapsed_secs += double(end - begin) / CLOCKS_PER_SEC;
            }
        }
        
        cout << (mode == 0 ? mode1_name : mode2_name ) << ": " << (elapsed_secs / EXECUTIONS) << endl;
    }

	return 0;
}
