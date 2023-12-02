#include "Student.h"

Student::Student(string n, int a) :name(n), age(a) {}
Student::Student() :name(""), age(18) {}
string Student::getName() {
	return name;
}
int Student::getAge() {
	return age;
}
void Student::setName(string name) {
	this->name = name;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::display() {
	cout << "----------------" << endl;
	cout << "name : " << name << endl;
	cout << "age : " << age << endl;
}
