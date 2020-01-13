#ifndef Class_hpp
#define Class_hpp

#include "Student.hpp"
#include <iostream>
#include <string>

using namespace std;

class Student;

class Cls{
public:
    Cls();
    Cls(string name, string instructor, int limit);
    void Register(Student* student);
    void Withdraw(Student* student);
    void Display();
	string getName();
	string getInstr();
	bool checkfull();
	bool checkcls(Student* student);

private:
    string name;
    string instructor;
    Student** list;
	int limit;
	int end;
};

#endif
