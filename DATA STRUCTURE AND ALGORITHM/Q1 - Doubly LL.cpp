#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int ID;
    string Name;
    float Marks;

    Student(int id = 0, string name = "", float marks = 0.0) {
        ID = id;
        Name = name;
        Marks = marks;
    }
};

class Node {
public:
    Student student;
    Node* next;
    Node* prev;

    Node(Student s) : student(s), next(nullptr), prev(nullptr) {}
};

class DoublyLL {
private:
    Node* head;

public:
    DoublyLL() : head(nullptr) {}

    void display();
    void insertAtFront(Student student);
    void insertMiddle(Student student, int position);
    void deleteLast();
    void calculateAverageAndCount();
};

void DoublyLL::display() {
    // Task 1: Complete this function to display the list of students.
}

void DoublyLL::insertAtFront(Student student) {
    // Task 2: Complete this function to insert a student at the front.
}

void DoublyLL::insertMiddle(Student student, int position) {
    // Task 3: Complete this function to insert a student at a specific position.
}

void DoublyLL::deleteLast() {
    // Task 4: Complete this function to delete the last student.
}

void DoublyLL::calculateAverageAndCount() {
    // Task 5: Complete this function to calculate the average marks and count of students.
}

int main() {
    DoublyLL list;

    // Initializing 3 students
    Student s1(1, "Samad", 85.5);
    Student s2(2, "Baba", 90.0);
    Student s3(3, "Harlina", 78.0);

    // Inserting students into the list
    list.insertAtFront(s3);
    list.insertAtFront(s2);
    list.insertAtFront(s1);

    // Tasks to be implemented
    cout << "Initial list of students:" << endl;
    list.display();

    cout << "\nInserting a student in the middle:" << endl;
    Student s4(4, "Diana", 88.0);
    list.insertMiddle(s4, 2); // Insert at position 2
    list.display();

    cout << "\nDeleting the last student:" << endl;
    list.deleteLast();
    list.display();

    cout << "\nCalculating average marks and total number of students:" << endl;
    list.calculateAverageAndCount();

    return 0;
}

