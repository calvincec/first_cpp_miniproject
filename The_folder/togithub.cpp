#include <iostream>
#include <string>
using namespace std;
 

class Node {

public:

    string surName, firstName, lastName;
    int subject1, subject2, subject3, subject4, subject5;
    double average;
    char grade;
    Node* prev;
    Node* next;
    Node( string& surName, string& firstName,  string& lastName, int sub1, int sub2, int sub3, int sub4, int sub5) {

        this->surName = surName;

        this->firstName = firstName;

        this->lastName = lastName;

        subject1 = sub1;

        subject2 = sub2;

        subject3 = sub3;

        subject4 = sub4;

        subject5 = sub5;

        average = this->calculateAverage();

        grade = this->calculateGrade();

        prev = NULL;

        next = NULL;

    }

 

    double calculateAverage() {

        return (subject1 + subject2 + subject3 + subject4 + subject5) / 5.0;

    }

 

    char calculateGrade() {

        double avg = calculateAverage();

        if (avg >= 90) {

            return 'A';

        } else if (avg >= 80) {

            return 'B';

        } else if (avg >= 70) {

            return 'C';

        } else if (avg >= 60) {

            return 'D';

        } else {

            return 'F';

        }

    }

};

 

class StudentList {

private:

    Node* head;

public:

    StudentList() : head(NULL) {}

 

    void addStudent( string& surName, string& firstName,

                      string& lastName, int sub1, int sub2,

                       int sub3, int sub4, int sub5) {

        Node* newStudent = new Node(surName, firstName, lastName, sub1, sub2, sub3, sub4, sub5);

 

        if (head == NULL) {

            head = newStudent;

        } else {

            Node* current = head;

            while (current->next != NULL) {

                current = current->next;

            }

            current->next = newStudent;

            newStudent->prev = current;

        }

    }

 

    void rankStudents() {

        Node* current = head;

 

        // Perform a bubble sort based on the average scores of students

        while (current != NULL) {

            Node* innerCurrent = current->next;

            while (innerCurrent != NULL) {

                double currentAvg = current->average;

                double innerCurrentAvg = innerCurrent->average;

                if (innerCurrentAvg > currentAvg) {

                    // Swap the students' positions

                    swapNodes(innerCurrent, current);

                }

                innerCurrent = innerCurrent->next;

            }

            current = current->next;

        }

    }

 

    void swapNodes(Node* node1, Node* node2) {

        if (node1 == NULL || node2 == NULL) {

            return;

        }

 

        // Swap the previous pointers

        if (node1->prev != NULL) {

            node1->prev->next = node2;

        } else {

            head = node2;

        }

 

        if (node2->prev != NULL) {

            node2->prev->next = node1;

        } else {

            head = node1;

        }

 

        // Swap the next pointers

        if (node1->next != NULL) {

            node1->next->prev = node2;

        }

 

        if (node2->next != NULL) {

            node2->next->prev = node1;

        }

 

        // Swap the previous and next pointers of the nodes

        Node* tempPrev = node1->prev;

        Node* tempNext = node1->next;
        
        node1->prev = node2->prev;

        node1->next = node2->next;

        node2->prev = tempPrev;

        node2->next = tempNext;

    }

 

    void displayRanking() {

        Node* current = head;

        int rank = 1;

        cout<<"\tFull name\t\t"<<"Average score\t\t"<<"Grade\n";

        while (current != NULL) {

            cout << rank << "\t"<< current->surName << " " << current->firstName << " " << current->lastName <<"\t\t";

            cout << current->average <<"\t\t";

            cout << current->grade << endl << endl;

            current = current->next;

            rank++;

        }

    }

};

 

int main() {

    StudentList students;

 

    int numStudents;

    cout << "Enter the number of students: ";

    cin >> numStudents;

 

    for (int i = 0; i < numStudents; i++) {

        string surName, firstName, lastName;

        int sub1, sub2, sub3, sub4, sub5;

 

        cout << "Enter details for student " << i + 1 << ":" << endl;

        cout << "Surname: ";

        cin >> surName;

       cout << "First Name: ";

        cin >> firstName;

        cout << "Last Name: ";

        cin >> lastName;

        cout << "Subject 1 Score: ";

        cin >> sub1;

        cout << "Subject 2 Score: ";

        cin >> sub2;

        cout << "Subject 3 Score: ";

        cin >> sub3;

        cout << "Subject 4 Score: ";

        cin >> sub4;

        cout << "Subject 5 Score: ";

        cin >> sub5;

 

        students.addStudent(surName, firstName, lastName, sub1, sub2, sub3, sub4, sub5);

    }

 

    cout << "Before ranking:" << endl;

    students.displayRanking();

 

    cout << endl;

 

    cout << "After ranking:" << endl;

    students.rankStudents();

    students.displayRanking();

 

    return 0;

}