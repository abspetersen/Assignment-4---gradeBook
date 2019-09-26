#include <iostream>
#include "studentType.h"

using namespace std;

student::student(){
    //initialize all values as 0s
    for(int i = 0; i < prog_Limit; i++)     { progAssignments[i]       = 0;}
    for(int i = 0; i < tests_Limit; i++)    { tests[i]                 = 0;}
    for(int i = 0; i < final_Limit; i++)    { finals[i]                = 0;}
};

//relationType used for sort according to studentID
//enum student::RelationType  {LESS, GREATER, EQUAL};
RelationType student::compareId(student otherStudent) const{
    if (studentId < otherStudent.studentId)
        return LESS;
    else if (studentId > otherStudent.studentId)
        return GREATER;
    else return EQUAL;
};

//Student is initialized here with appropriate values
void student::initialize(string nameF, string nameL, int Id, int numPrograms, int numTests, int numFinals){
    fName = nameF;
    lName = nameL;
    studentId = Id;
    prog_Limit = numPrograms;
    tests_Limit = numTests;
    final_Limit = numFinals;
};

//TODO
//console outputs the student data
//need to output result to a txt or whatever
void student::printStudent() const{
    cout << "*****************************************************" << endl;
    cout << "Student name is " <<fName<< " " << lName << "."<< endl;
    cout << "\tID: " << studentId << endl;
    cout << endl;
        
    for (int i = 0; i < prog_Limit; i++){
        cout << "\t\tProgram Assignment #" << i+1 << " - \t" << progAssignments[i]<< endl;
    }
    cout << endl;
    for (int i = 0; i < tests_Limit; i++){
        cout << "\t\tTest #" << i+1 << " - \t" << tests[i]<< endl;
    }
    cout << endl;
    for (int i = 0; i < final_Limit; i++){
        cout << "\t\tFinal #" << i+1 << " - \t" << finals[i]<< endl;
    }
    cout << "*****************************************************" << endl;
    cout << endl;
};

    //Add grades for programming assignments
void student::addProgAssignments(){
    if (prog_Limit <= 0 || prog_Limit > 6){
        //input was an unacceptable value, 
        //implement an error check before passing values on to student
    }else{
        for(int i = 0; i < prog_Limit; i++) { 
            double val;
            cout << "Enter Grade in percentage for Programming assignment #" << i+1 << endl; 
            cin >> val;
            progAssignments[i] = val;
        }
    }
};

//Add values for tests
void student::addTests(){
    if(tests_Limit <= 0 || tests_Limit > 4){
        //input was an unacceptable value, 
        //implement an error check before passing values on to student
    }else{
        for(int i = 0; i < tests_Limit; i++) { 
            double val;
            cout << "Enter Grade in percentage for Test #" << i+1 << endl; 
            cin >> val;
            tests[i] = val;
        }
    }
};

void student::addFinal(){
    cout << "addFinal is called" << endl;
    if(final_Limit<0 || final_Limit > 1){
        //input was an unacceptable value, 
        //implement an error check before passing values on to student
    }else{
        for(int i = 0; i < final_Limit; i++) { 
            double val;
            cout << "Enter Grade in percentage for Final #" << i+1 << endl; 
            cin >> val;
            finals[i] = val;
        }
    }    
};

    //calculate grade 
int student::calculateGrade(){
        //outputs grade
        return 0;
}

student::~student(){};