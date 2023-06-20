/*
This code employs these concepts:
- Data structures (doubly linked list) and algorithms
- Sorting algorithm (bubble sort)
- C++ coding
- Class concept in OOP
- Pointers concept

The code:
-creates a node class that will be used to get 10 objects rep 10 students
-allows input of surname, midname and last name of 10 students
-inputs marks for each students in the 14 subjects
-computes the total marks and grade for each student
-ranks the students depending on their average grades
-ranks the student using bubble sort algorithm
-uses doubly linked list to get the next and prevous students


*/

#include<iostream>
#include<string>
using namespace std;

class Node
{
public:
    Node(string surname, string firstname, string lastname,
        int sub1, int sub2, int sub3, int sub4, int sub5,
        int sub6, int sub7, int sub8, int sub9, int sub10,
        int sub11, int sub12, int sub13, int sub14);
    Node* next;
    Node* prev;

    string surname, firstname, lastname;
    int sub1, sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9, sub10,
        sub11, sub12, sub13, sub14;
    char grader();
    int average();

};
//costructor
Node::Node(string surname, string firstname, string lastname,
    int sub1, int sub2, int sub3, int sub4, int sub5,
    int sub6, int sub7, int sub8, int sub9, int sub10,
    int sub11, int sub12, int sub13, int sub14)
{
    this->surname = surname;
    this->firstname = firstname;
    this->lastname = lastname;
    this->sub1 = sub1;  this->sub2 = sub2;  this->sub3 = sub3;
    this->sub4 = sub4; this->sub5 = sub5;  this->sub6 = sub6;
    this->sub7 = sub7;  this->sub8 = sub8; this->sub9 = sub9;
    this->sub10 = sub10;  this->sub11 = sub11;  this->sub12 = sub12;
    this->sub13 = sub13;  this->sub14 = sub14;
    this->next = NULL;
    this->prev = NULL;
}
//to obtain grade
char Node::grader()
{
    int marks = this->average();
    if (marks < 40) { return 'E'; }
    else if (marks >= 40 && marks < 50) { return 'D'; }
    else if (marks >= 50 && marks < 60) { return 'C'; }
    else if (marks >= 60 && marks < 70) { return 'B'; }
    else { return 'A'; }
}
//to obtain average
int Node::average()
{
    int a = sub1 + sub2 + sub3 + sub4 + sub5 + sub6 + sub7 + sub8 + sub9 + sub10
        + sub11 + sub12 + sub13 + sub14;
    return (a / 14);
}

// Function to display the ranking
void displayRanking(string names[], int averages[], char grades[]) {
    int size = 10;
    system("cls");

    // Display list before ranking
    cout << "Here is the list containing them before being ranked\n";
    cout << "\tFull name\t\t" << "Average score\t\t" << "Grade\n";
    for (int i = 0; i < size; i++) {
        cout << names[i] << "\t\t" << averages[i] << "\t\t" << grades[i] << "\n";
    }

    // Rank them using bubble sort
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (averages[j] < averages[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = averages[j];
                string temp2 = names[j];
                char temp3 = grades[j];
                averages[j] = averages[j + 1];
                names[j] = names[j + 1];
                grades[j] = grades[j + 1];
                averages[j + 1] = temp;
                names[j + 1] = temp2;
                grades[j + 1] = temp3;
            }
        }
    }

    // Display list after ranking
    cout << "Here is the list containing them ranked\n";
    cout << "\tFull name\t\t" << "Average score\t\t" << "Grade\n";
    for (int i = 0; i < size; i++) {
        cout << names[i] << "\t\t" << averages[i] << "\t\t" << grades[i] << "\n";
    }

    // Display top 5 students
    cout << "The top 5 students are:\n";
    for (int p = 0; p < 5; p++) {
        cout << names[p] << endl;
    }
}

int main() {
    //create 10 objects for 10 students
    Node* student1; Node* student2; Node* student3; Node* student4; Node* student5;
    Node* student6; Node* student7; Node* student8; Node* student9; Node* student10;
    //make arrays to store the averages, full names and grades to ease ranking
    int averages[10]; string names[10]; char grades[10];

    int i = 0;
    //entering details for 10 students
    while (i < 10) {
        string surname, firstname, lastname;
        int sub1, sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9, sub10,
            sub11, sub12, sub13, sub14;
        //
        cout << "Enter details for student " << i + 1 << ":" << endl;
        cout << "Surname: "; cin >> surname; cout << "First Name: "; cin >> firstname;
        cout << "Last Name: "; cin >> lastname;
        names[i] = surname + " " + firstname + " " + lastname;
        cout << "Subject 1 Score: "; cin >> sub1; cout << "Subject 2 Score: "; cin >> sub2;
        cout << "Subject 3 Score: "; cin >> sub3; cout << "Subject 4 Score: "; cin >> sub4;
        cout << "Subject 5 Score: "; cin >> sub5; cout << "Subject 6 Score: "; cin >> sub6;
        cout << "Subject 7 Score: "; cin >> sub7; cout << "Subject 8 Score: "; cin >> sub8;
        cout << "Subject 9 Score: "; cin >> sub9; cout << "Subject 10 Score: "; cin >> sub10;
        cout << "Subject 11 Score: "; cin >> sub11; cout << "Subject 12 Score: "; cin >> sub12;
        cout << "Subject 13 Score: "; cin >> sub13; cout << "Subject 14 Score: "; cin >> sub14;

        //asign the input variables to respective students
        if (i == 0) {
            student1 = new Node(surname, firstname, lastname, sub1,
                sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9, sub10, sub11, sub12, sub13,
                sub14); averages[i] = student1->average(); grades[i] = student1->grader();
        }

        if (i == 1) {
            student2 = new Node(surname, firstname, lastname, sub1,
                sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9, sub10, sub11, sub12, sub13,
                sub14); averages[i] = student2->average(); grades[i] = student2->grader();
        }

        if (i == 2) {
            student3 = new Node(surname, firstname, lastname, sub1,
                sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9, sub10, sub11, sub12, sub13,
                sub14); averages[i] = student3->average(); grades[i] = student3->grader();
        }

        if (i == 3) {
            student4 = new Node(surname, firstname, lastname, sub1,
                sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9, sub10, sub11, sub12, sub13,
                sub14); averages[i] = student4->average(); grades[i] = student4->grader();
        }

        if (i == 4) {
            student5 = new Node(surname, firstname, lastname, sub1,
                sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9, sub10, sub11, sub12, sub13,
                sub14); averages[i] = student5->average(); grades[i] = student5->grader();
        }

        if (i == 5) {
            student6 = new Node(surname, firstname, lastname, sub1,
                sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9, sub10, sub11, sub12, sub13,
                sub14); averages[i] = student6->average(); grades[i] = student6->grader();
        }

        if (i == 6) {
            student7 = new Node(surname, firstname, lastname, sub1,
                sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9, sub10, sub11, sub12, sub13,
                sub14); averages[i] = student7->average(); grades[i] = student7->grader();
        }

        if (i == 7) {
            student8 = new Node(surname, firstname, lastname, sub1,
                sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9, sub10, sub11, sub12, sub13,
                sub14); averages[i] = student8->average(); grades[i] = student8->grader();
        }

        if (i == 8) {
            student9 = new Node(surname, firstname, lastname, sub1,
                sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9, sub10, sub11, sub12, sub13,
                sub14); averages[i] = student9->average(); grades[i] = student9->grader();
        }

        if (i == 9) {
            student10 = new Node(surname, firstname, lastname, sub1,
                sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9, sub10, sub11, sub12, sub13,
                sub14); averages[i] = student10->average(); grades[i] = student10->grader();
        }

        i++;
    }
//to print the ranked output
    displayRanking(names, averages, grades);

    // Freeing memory
    delete student1; delete student2; delete student3; delete student4; delete student5;
    delete student6; delete student7; delete student8; delete student9; delete student10;

    return 0;
}
