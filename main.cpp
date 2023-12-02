#include <iostream>
#include "Student.h"
#include "LinkedList.h"

int main(int argc, char** argv) {
	Student* student1 = new Student("name1", 11);
	Student* student2 = new Student("name2", 22);
	Student* student3= new Student("name3", 33);
	Student* student4 = new Student("name4", 44);
	Student* student5 = new Student("name5", 55);
	LinkedList<Student>* l = new LinkedList<Student>();
	l->addFirst(student1);
	l->addLast(student5);
	l->add(student2, 1);
	l->add(student3, 2);
	l->add(student4, 0);

	cout << "THE NUMBER OF ELEMENTS IS : "<< l->getLength() << endl;
	l->display();
	cout << endl;
	cout << "----->List after deleting FIRST element :" << endl;
	l->removeFirst();
	cout << "THE NUMBER OF ELEMENTS IS : " << l->getLength() << endl;
	l->display();
	cout << endl;
	cout << "----->List after deleting LAST element :" << endl;
	l->removeLast();
	cout << "THE NUMBER OF ELEMENTS IS : " << l->getLength() << endl;
	l->display();
	cout << endl;
	cout << "----->List after deleting THE 2 element :" << endl;
	l->remove(1);
	cout << "THE NUMBER OF ELEMENTS IS : " << l->getLength() << endl;
	l->display();
	cout << endl;
	cout << "----->searching if the student1 existes :" << endl;
	l->contains(student1);
	cout << endl;
	cout << "----->searching if the student2 existes :" << endl;
	l->contains(student2);
	cout << endl;
	cout << "----->List after adding some  elements :" << endl;
	student2 = new Student("name2", 22);
	l->add(student2, 1);
	student4 = new Student("name4", 44);
	l->add(student4, 3);
	cout << "THE NUMBER OF ELEMENTS IS : " << l->getLength() << endl;
	l->display();
	cout << endl;
	cout << "----->deleting by entity some elements" << endl;
	cout << "THE NUMBER OF ELEMENTS BEFORE DELETING IS : " << l->getLength() << endl;
	l->remove(student1);
	l->remove(student3);
	l->remove(student4);
	l->remove(student5);
	cout << "THE NUMBER OF ELEMENTS AFTER DELETING IS : " << l->getLength() << endl;
	l->display();
	return 0;
}