#include <iostream>
#include "studentType.h"
#include "studentType.cpp"

int main(){

    student test; 

    test.initialize("John", "Doe", 1010, 6, 4, 1);
    test.addProgAssignments();
    test.addTests();
    test.addFinal();

    test.printStudent();
    
    return 0;
}