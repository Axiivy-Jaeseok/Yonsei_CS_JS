#ifndef Student_hpp
#define Student_hpp

#include "Cls.hpp"
#include <iostream>
#include <string>

class Cls;

using namespace std;

class Student{
public:
    Student();
    Student(string name, string id, int limit);
    void Display();
    void Register(Cls* cls);
    void Withdraw(Cls* cls);
	string getName();
	string getId();
	bool checkfull();
	bool checkstu(Cls* cls);
    
private:
    string name;
    string id;
    Cls** list;
	int limit;
	int end;
};

#endif
