#include <string>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>
#include <list>

using namespace std;

#define EXECUTIONS 10000000

string mode1_name = " switch";
string mode2_name = "if-else";

#define STR1 "STR1"
static const string str1 = "STR1";

int a = 20;

int usingSwitch() {
    int b = 0;

    switch (a) {
        case 20:
            b = a + 1;
        default:
            b = a - 1;
    }

    return b;
}

int usingIfElse() {
    int b = 0;

    if (a == 20) {
        b = a + 1;
    } else {
        b = a - 1;
    }

    return b;
}

int main() {
    double elapsed_secs = 0;
    string result = "";

    for (int mode = 0; mode < 2; mode++) {
        for (int i = 0; i < EXECUTIONS; i++) {
            if (mode == 0) {
                clock_t begin = clock();

                result += usingIfElse();

	            clock_t end = clock();
                elapsed_secs += double(end - begin) / CLOCKS_PER_SEC;
            } else {
                clock_t begin = clock();

	            result += usingSwitch();

	            clock_t end = clock();
                elapsed_secs += double(end - begin) / CLOCKS_PER_SEC;
            }
        }

        cout << (mode == 0 ? mode1_name : mode2_name ) << ": " << (elapsed_secs / EXECUTIONS) << endl;
    }
	
	return 0;
}
