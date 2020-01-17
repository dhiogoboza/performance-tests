#include <string>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>
#include <list>

using namespace std;

#define EXECUTIONS 1000000
#define ITEMS_IN_LIST 20

string mode1_name = "pop during iteration";
string mode2_name = "    clear in the end";

class RandomObject {
public:
    RandomObject() {
    }

    ~RandomObject() {
    }
};

void fillOutList(std::list<RandomObject *> &listOfItems) {
    for (int i = 0; i < ITEMS_IN_LIST; i++) {
        listOfItems.push_front(new RandomObject());
    }
}

int clearListDuringIteration() {
    std::list<RandomObject *> listOfItems;
    fillOutList(listOfItems);

    while (listOfItems.size() > 0) {
        delete listOfItems.front();
        listOfItems.pop_front();
    }
}

int clearListInTheEnd() {
    std::list<RandomObject *> listOfItems;
    fillOutList(listOfItems);

    std::list<RandomObject *>::iterator it = listOfItems.begin();
    while(it != listOfItems.end()) {
        delete (*it);
        it++;
    }
    listOfItems.clear();
}

int main() {
    double elapsed_secs = 0;
    string result = "";

    for (int mode = 0; mode < 2; mode++) {
        for (int i = 0; i < EXECUTIONS; i++) {
            if (mode == 0) {
                clock_t begin = clock();
                
                result += clearListDuringIteration();
                
	            clock_t end = clock();
                elapsed_secs += double(end - begin) / CLOCKS_PER_SEC;
            } else {
                clock_t begin = clock();
                
	            result += clearListInTheEnd();
	            
	            clock_t end = clock();
                elapsed_secs += double(end - begin) / CLOCKS_PER_SEC;
            }
        }
        
        cout << (mode == 0 ? mode1_name : mode2_name ) << ": " << (elapsed_secs / EXECUTIONS) << endl;
    }
	
	return 0;
}
