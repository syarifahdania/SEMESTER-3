#include <iostream>
#include <string>
// Group 6 : Vaccine Queue System for Elderly
using namespace std;

class Patient {
public:
    string name, patientNo, vaccineType;
    Patient* next;
    Patient* current;

	Patient(string name, string patientNo, string vaccineType) {		//Constructor
    	this->name = name;
    	this->patientNo = patientNo;
    	this->vaccineType = vaccineType;
    	this->next = nullptr;
	}

};

class Queue {
	private: 
    		Patient* head;
    		Patient* tail;
    		Patient* current;
    
    public:
    	Queue() : head(nullptr), tail(nullptr) {}	 //Constructor
    	
   	// Task 1: Insert new patient in the list (Chew)
    	void push(Patient p) {
        		Patient* newNode = new Patient(p);
        		if (head == nullptr) {
            		head = tail = newNode;
        		} else {
           			tail->next = newNode;
			tail = tail->next;
        		}
    	}
    
    	// Task 2: Delete the patient who has received the vaccine (Mohamad Ali)
    	void pop() {
        		if (head == nullptr) {
            		cout << "No patients in the list." << endl << endl;
            		return;
        		} else {
        			if (head == tail) {
        				cout << "Patient name : " << head->name << endl;
				cout << "Patient Number : " << head->patientNo << endl << endl;
            			delete head;
            			head = tail = nullptr;
        			} else {
            			Patient* temp = head;
            			head = head->next;
            			cout << "Patient name : " << temp->name << endl;
				cout << "Patient Number : " << temp->patientNo << endl << endl;
            			delete temp;
        			}
		}
    	}
    
    	// Task 3 : Display the list (Syarifah)
		    void displayList() {
		    current = head;
		    int index = 0;
		    
		    if (current == nullptr) { // If the list is empty, display this message
		        cout << "No patients in the list." << endl << endl;
		        return;
		    }
		    
		    while (current != nullptr) {
		        index++;
		        cout << "Patient " << index << ": " << endl;
		        cout << "Patient name : " << current->name << endl;
		        cout << "Patient Number : " << current->patientNo << endl;
		        cout << "Vaccine type to be received : " << current->vaccineType << endl;
		        cout << endl;
		        current = current->next;
		    }
		}

    	//Task 4 : Search Patient Details (Harini)
    	void searchPatientInfo (string patientNo) {
    		current = head;
    		while (current != nullptr && current->patientNo != patientNo) {
        			current = current->next;
    		}
		if (current != nullptr) {
        			cout << "Patient name : " << current->name << endl;
        			cout << "Patient Number : " << current->patientNo << endl;
        			cout << "Vaccine type to be received : " << current->vaccineType << endl; 
cout << endl;
    		} else {
    			cout << "Patient details do not exist in the list." << endl << endl;
    		}
    }

};

int main() {
int choice;
Queue q;
    
//Display program title
    	cout << "=====Vaccine Queue System for Elderly=====" << endl;	    
do {		//Display menu
        		cout << endl << "Menu :" << endl;
        		cout << "1. Insert New Patient Details" << endl;
        		cout << "2. Delete Patient Details Who Have Received Vaccine" << endl;
        		cout << "3. Display All Records" << endl;
        		cout << "4. Search Patient Details" << endl;
        		cout << "5. Exit" << endl;
        		cout << endl << "Enter your choice: ";
        		cin >> choice;

        		switch (choice) {
        		case 1: {	//Input patient info into the system
            		string name, patientNo, vaccineType;

           			cout << "Enter Patient Name: ";
					cin.ignore(); // Clear the input buffer
					getline(cin, name); // Read the full name
					
					cout << "Enter Patient Number: ";
					cin >> patientNo;
					cin.ignore(); // Clear the input buffer again
					
					cout << "Enter Vaccine Type: ";
					getline(cin, vaccineType); // Use getline to avoid input issues


            		Patient p(name, patientNo, vaccineType);
            		q.push(p);
            		break;
        		}

        		case 2: {	//Delete patient info from system
        			cout << "Delete Record for Patient Who Have Received Vaccine : ";
			cout << endl;
        			q.pop();
            		break;
       		}


        		case 3:		//Display list of patients
            		q.displayList();
            		break;

        		case 4:{		//Search patient info
        			string patientNo;

        			cout << "Enter Patient Number : ";
        			cin >> patientNo;

        			q.searchPatientInfo(patientNo);
			break;
		}
        		case 5:		//Exit system
            		cout << "Exiting program." << endl;
            		break;

        		default:
            		cout << "Invalid choice! Please try again." << endl;
        		}
} while (choice != 5);
}
