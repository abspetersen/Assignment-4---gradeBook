#ifndef STUDENTTYPE_H
#define STUDNETTYPE_H
#pragma once

#include <iostream>
#include <fstream>
#include <string>

//#include "studentType.cpp"    

using namespace std;

enum RelationType  {LESS, GREATER, EQUAL};

class student{
    string fName, lName;
    int studentId;

    double progAssignments[6], tests[4], finals[1];

    //TODO
    //need to write functions to calculate grades 
    double grade;
    char letterGrade;

    //This will act like ceilings for the arrays declared above.
    int prog_Limit, tests_Limit, final_Limit;

    public:
        //TODO
        //just inserts dummy data in the arrays, change later.
        student();
    
        //relationType used for sort according to studentID
        RelationType compareId(student) const;

        //Student is initialized here with appropriate values
        void initialize(string, string, int, int, int, int);

        //TODO
        //console outputs the student data
        //need to output result to a txt or whatever
        void printStudent() const;

        //Add grades for progAssignments[]
        void addProgAssignments();

        //Add values to tests[]
        void addTests();

        ////Add values to finals[]
        void addFinal();

        //calculate grade using weights
        int calculateGrade();

        ~student();
};

#endif