#include <iostream>
#include "studentType.h"

using namespace std;

//constructor
student::student(){
    //initialize all values as non empty
    fName           = "";
    lName           = "";
    studentId       = 0 ;
    postedGrade     = 0 ;
    letterGrade     = 'f';
    for(int i = 0; i < prog_Limit ; i++){progAssignments[i]= 0;}
    for(int i = 0; i < tests_Limit; i++){tests[i]          = 0;}
    for(int i = 0; i < final_Limit; i++){finals[i]         = 0;}
};

//relationType used for sort according to studentID
RelationType student::compareId(student otherStudent) const{
    if (studentId < otherStudent.studentId)
        return LESS;
    else if (studentId > otherStudent.studentId)
        return GREATER;
    else return EQUAL;
};

//Student is initialized here with values that are passed in
void student::initialize(string nameF, string nameL, int Id,
                            int numPrograms, int numTests, int numFinals,
                            double progWeight, double testWeight, double finalWeight
                        ){
    fName = nameF;
    lName = nameL;
    studentId = Id;
    prog_Limit = numPrograms;
    tests_Limit = numTests;
    final_Limit = numFinals;
    progWei = progWeight;
    testWei = testWeight;
    finalWei = finalWeight;
};

//inputs all values and calculates total grade and letter grade
void student::addAllValue(){
    addProgAssignments();        
    addTests();
    addFinal();
    system("cls");
}

//TODO
//console outputs the student data
//need to output result to a txt or whatever
void student::printStudent() const{
    cout << "*****************************************************" << endl;
    cout << "Student name is " <<fName<< " " << lName << "."<< endl;
    cout << "\tID: " << studentId << endl;
        
    // for (int i = 0; i < prog_Limit; i++){
    //     cout << "\t\tProgram Assignment #" << i+1 << " - \t" << progAssignments[i]<< endl;
    // }
    // cout << endl;
    // for (int i = 0; i < tests_Limit; i++){
    //     cout << "\t\tTest #" << i+1 << " - \t" << tests[i]<< endl;
    // }
    // cout << endl;
    // for (int i = 0; i < final_Limit; i++){
    //     cout << "\t\tFinal #" << i+1 << " - \t" << finals[i]<< endl;
    // }
    cout << endl;
    cout << "\t\tFinal grade -\t" << postedGrade << "%"<< endl;
    cout << "\t\tLetter grade -\t" << letterGrade<< endl;
    cout << "*****************************************************" << endl;
    cout << endl;
};

//Add grades for programming assignments
void student::addProgAssignments(){
    //clears console
    system("CLS");

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

    calculateGrade();
    //clears console
    system("CLS");
};

//Add values for tests
void student::addTests(){
    //clears console
    system("CLS");
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
        
        calculateGrade();
    }
    //clears console
    system("CLS");
};

//Add values for final
void student::addFinal(){
    //clears console
    system("CLS");

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
    calculateGrade();
    //clears console
    system("CLS");
};

//sum Of an array
double student::sumOFArr(double arr[], int size){
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}

//calculate grade 
void student::calculateGrade(){
    double programGrade = (sumOFArr(progAssignments, prog_Limit)/(prog_Limit * 100)) * progWei;
    double testGrade = (sumOFArr(tests, tests_Limit)/(tests_Limit * 100)) * testWei;
    double finalsGrade= (sumOFArr(finals, final_Limit)/(final_Limit * 100)) * finalWei;

    //cout << "Program grade\t" << (programGrade*100.00)/100.00 << ", out of " << progWei << endl;
    //cout << "Test grade\t" << (testGrade*100.00)/100.00 << ", out of " << testWei << endl;
    //cout << "Finals grade\t" << (finalsGrade*100.00)/100.00 << ", out of " << finalWei << endl;

    postedGrade = programGrade + testGrade + finalsGrade;

    if(postedGrade >= 90){
        letterGrade = 'A';
    }else if(postedGrade >= 80){
        letterGrade = 'B';
    }else if(postedGrade >= 70){
        letterGrade = 'C';
    }else if(postedGrade >= 60){
        letterGrade = 'D';
    }else{
        letterGrade = 'F';
    }
}

student::~student(){};