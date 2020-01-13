#include "Cls.hpp"

Cls::Cls(){
	// default constructor
	end = 0;
}

Cls::Cls(string name, string instructor, int limit){
	// constructor

	this->name = name;
	this->instructor = instructor;
	this->limit = limit;

	end = 0;

	// making a dynamic array of list
	list = new Student* [limit];
}

void Cls::Register(Student* student){
	// check if student could this class (whether the class is full)
	if (end == limit) {
		cout << "[Failed] " << this->name << " has already been full!" << endl;
		return;
	}

	// check if the student already registered this class
	for (int i = 0; i < end; i++) {
		if (list[i] == student) {
			cout << "[Failed] " << student->getName() << " has already registered " << this->name << endl;
			return;
		}
	}

	// When object.Student call this class
	if (!(student->checkstu(this)) && (end < limit)) {
		list[end] = student;
		end++;
		return;
	}

	// When this class call the student to register
	else if ((student->checkstu(this)) && (!(student->checkfull()))) {
		list[end] = student;
		end++;
		student->Register(this);
		return;
	}

	// call student because there's no empty seat at the student
	else if ((student->checkstu(this)) && (student->checkfull())) {
		student->Register(this);
		return;
	}
}

void Cls::Withdraw(Student* student){

	int index;
	bool flag = false;

	// check student registered this class
	for (int i = 0; i < end; i++) {
		if (list[i] == student) flag = true;
	}

	// when student didn't register
	if (!flag) {
		cout << "[Failed] " << student->getName() << "didn't registered " << this->name << endl;
	}

	// withdraw the class
	else {
		for (int i = 0; i < end; i++) {
			if (list[i] == student) {
				index = i;
				break;
			}
		}
		for (int j = index; j < end - 1; j++) {
			list[j] = list[j + 1];
		}

		end--;

		if (student->checkstu(this)) return;
		else {
			student->Withdraw(this);
		}
	}
}

void Cls::Display(){
    cout << "-----------------------------------------------" << endl;
    cout << "Prof. : " << this->instructor << "\t" <<"Class Name : " << this->name << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Total number of students : " << this->end << endl << endl;
    for(int i=0; i<end; i++){
        cout <<  list[i]->getName()
    	<< "\t" << list[i]->getId()
    	<< endl;
    }
    cout << endl << endl;
}

string Cls::getName() {
	return name;
}

string Cls::getInstr() {
	return instructor;
}


bool Cls::checkcls(Student* student) {
	// check this class include the student

	bool flag = true;

	for (int i = 0; i < end; i++) {
		if (list[i] == student) flag = false;
	}

	return flag;
}

bool Cls::checkfull() {
	// check end is same to limit
	if (end == limit) return true;
	else return false;
}