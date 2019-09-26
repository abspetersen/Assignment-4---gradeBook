#include <iostream>
#include "studentType.h"
#include "studentType.cpp"

int main(){

    //new student object test
    student test; 
    student test2;

    //values being passed in are 
    test.initialize("John", "Doe", 1010, 2, 2, 1, 20, 40, 40);
    //test2.initialize("Jane", "Doe", 1011, 2, 2, 1, 20, 40, 40);
    test.addAllValue();

    //outputs student name, id and current grade
    test.printStudent();
    system("pause");


    //changing grade for each section
    test.addProgAssignments();
    test.addTests();
    test.addFinal();
       
    test.printStudent();

    if(test.compareId(test2)==LESS){
        cout << "test should be inserted before test2." << endl;
    }else if(test.compareId(test2)==GREATER){
        cout << "test2 should be inserted before test." << endl;
    }else{
        cout << "Error, IDS have been reused." << endl;
    }
    
    return 0;
}