#include "Student.hpp"

Student::Student(){
	// default constructor
	end = 0;
}

Student::Student(string name, string id, int limit){
	// constructor
	this->name = name;
	this->id = id;
	this->limit = limit;

	end = 0;

	// making a dynamic array of list
	list = new Cls* [limit];
}

void Student::Register(Cls* cls){
	// check if student could this class (whether student's available seat is full)
	if (end == limit) {
		cout << "[Failed] " << this->name << " can't take more class" << endl;
		return;
	}

	// check if the student already registered this class
	for (int i = 0; i < end; i++) {
		if (list[i] == cls) {
			cout << "[Failed] " << this->name << " has already registered " << cls->getName() << endl;
			return;
		}
	}

	// When object.Class call this student
	if (!(cls->checkcls(this)) && (end < limit)) {
		list[end] = cls;
		end++;
		return;
	}

	// When this student call the class to register
	else if ((cls->checkcls(this)) && (!(cls->checkfull()))) {
		list[end] = cls;
		end++;
		cls->Register(this);
		return;
	}

	// call class because there's no empty seat at the class
	else if ((cls->checkcls(this)) && (cls->checkfull())) {
		cls->Register(this);
		return;
	}
	
}

void Student::Withdraw(Cls* cls){

	int index;
	bool flag = false;

	// check student registered this class
	for (int i = 0; i < end; i++) {
		if (list[i] == cls) flag = true;
	}

	// when student didn't register
	if (!flag) {
		cout << "[Failed] " << this->name << "didn't registered " << cls->getName() << endl;
	}

	// withdraw the class at the student
	else {
		for (int i = 0; i < end; i++) {
			if (list[i] == cls) {
				index = i;
				break;
			}
		}
		for (int j = index; j < end - 1; j++) {
			list[j] = list[j + 1];
		}
		end--;

		if (cls->checkcls(this)) return;
		else {
			cls->Withdraw(this);
		}
	}
}

void Student::Display(){
    cout << "-----------------------------------------------" << endl;
    cout << "Name : " << this->name << "\t" <<"Student# : " << this->id << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Total number of lectures : " << this->end << endl << endl;
    for(int i=0; i<end; i++){
        cout << list[i]->getName()
        << "\t" << list[i]->getInstr()
        << endl;
    }
    cout << endl << endl;
}

string Student::getName() {
	return name;
}

string Student::getId() {
	return id;
}

bool Student::checkstu(Cls* cls) {
	// check this student include the class

	bool flag = true;

	for (int i = 0; i < end; i++) {
		if (list[i] == cls) flag = false;
	}

	return flag;
}

bool Student::checkfull() {
	// check end is same to limit

	if (end == limit) return true;
	else return false;
}