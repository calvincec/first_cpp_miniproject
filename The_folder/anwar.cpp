#include<iostream>
#include <string>
#include<vector>
#include<stdlib.h>
//#include <algorithm>
using namespace std;

//function prototypes
void rankstudents(vector<int>& all_marks, vector<string>& majina);
void quicksort(vector<int>& all_marks, vector<string>& majina, int low, int high);
int partition(vector<int>& all_marks, vector<string>& majina, int low, int high);
string grader(int marks);

//rankstudent displays the final student details and marks with resp ranks
void rankstudents(vector<int>& all_marks, vector<string>& majina) {
    quicksort(all_marks, majina, 0, all_marks.size()-1);
    system("CLS");
    cout << "\n**************************************\n";
    cout << "Here is the list of all the ranked students and their marks\n";
    cout << "Full names\t\t\t" << "total marks\t\t\t" << "position\n";
    int position = 1;
    int prev_marks = all_marks[0];
    for (int i = 0; i < majina.size(); i++) {
        cout << majina[i] << "\t\t\t" << all_marks[i] << "\t\t\t" << position << "\n";
        if (i != majina.size() - 1) {
            if (all_marks[i] != all_marks[i + 1]) {
                position++;
            }
        }
    }
    cout<<"-----------------------------------\n";
    cout<<"Concequently, the top 5 students are: \n";
    for(int i=0;i<5;i++){
        cout<<majina[i]<<"\n";
    }
}
//to help generate grades
string grader(int marks){
    if (marks<40){return "E";}
    else if (marks>=40&&marks<50){return "D";}
    else if (marks>=50&&marks<60){return "C";}
    else if (marks>=60&&marks<70){return "B";}
    else if (marks>=70){return "A";}
    else{throw "Invalid marks";}
}
//the linked list class to contain the student details
class Node
{
public:
    Node(vector<string>& name, vector<int>& subjects);
    Node * next;
    Node* previous;
    string first_name,middle_name,last_name, full_name;
    int applied_math, data_structure, ect, physics, workshop;
    int total_marks = applied_math + data_structure + ect + physics + workshop;
    string grade = grader(total_marks);
    //int marks();
    /* int total_marks();
    int grade(); */
    int position();
};
vector<int> get_marks(Node* student);
//constructor
Node::Node(vector<string>& name, vector<int>& subjects){
    this->next = NULL;
    this->previous = NULL;
    first_name = name[0];
    middle_name = name[1];
    last_name = name[2];
    full_name = name[0] + " "+ name[1] + " " + name[2];
    applied_math = subjects[0];
    data_structure = subjects[1];
    ect = subjects[2];
    physics = subjects[3];
    workshop = subjects[4];
    total_marks = applied_math + data_structure + ect + physics + workshop;
}



vector<int> get_marks(Node* student){
        Node* ptr = student;
        vector<int> all_marks2;
        while(ptr->next != NULL){
            all_marks2.push_back(ptr->total_marks);
            ptr = ptr->next;
        }
        return all_marks2;
    }

int main(){
    //applied_math, data_structure, ect, physics, workshop
     string a; int b;
    Node* student1; Node* student2; Node* student3;
    Node* student4; Node* student5; Node* student6;
    Node* student7; Node* student8; Node* student9; Node* student10;

    for(int i=0;i<10;i++){
        vector<string> name; vector<int> subjects;
        cout<<"lets enter details for student "<<i+1<<endl;
        cout<<"first name: ";cin>>a;name.push_back(a);
        cout<<"middle name: ";cin>>a;name.push_back(a);
        cout<<"last name: ";cin>>a;name.push_back(a);
        cout<<"marks in applied maths: ";cin>>b;subjects.push_back(b);
        cout<<"marks in data structures: ";cin>>b;subjects.push_back(b);
        cout<<"marks in ect: ";cin>>b;subjects.push_back(b);
        cout<<"marks in physics: ";cin>>b;subjects.push_back(b);
        cout<<"marks in worshop: ";cin>>b;subjects.push_back(b);

        if (i==0){student1 = new Node(name,subjects);}
        if (i==1){student2 = new Node(name,subjects);}
        if (i==2){student3 = new Node(name,subjects);}
        if (i==3){student4 = new Node(name,subjects);}
        if (i==4){student5 = new Node(name,subjects);}
        if (i==5){student6 = new Node(name,subjects);}
        if (i==6){student7 = new Node(name,subjects);}
        if (i==7){student8 = new Node(name,subjects);}
        if (i==8){student9 = new Node(name,subjects);}
        if (i==9){student10 = new Node(name,subjects);}
    }
    student1->next = student2;  student2->next = student3; student3->next = student4;
    student4->next = student5; student5->next = student6; student6->next = student7;
    student7->next = student8; student8->next = student9; student9->next = student10;
    cout<<student1->total_marks<<endl;
     student2->previous = student1;  student3->previous = student2; student4->previous = student3;
    student5->previous = student4; student6->previous = student5; student7->previous = student6;
    student8->previous = student7; student9->previous = student8; student10->previous = student9;
    cout<<student1->total_marks<<endl;

    vector<int> all_marks = get_marks(student1);
    for (int num : all_marks){
        cout<<num<<"\n";
    }
    cout<<endl;
    vector<string> majina = {student1->full_name,student2->full_name,student3->full_name
                            ,student4->full_name,student5->full_name
                            ,student6->full_name,student7->full_name,student8->full_name
                            ,student9->full_name,student10->full_name};
    rankstudents(all_marks,majina);

    return 0;
}

//partition vector is used in quick sorting to sort the vectors
int partition(vector<int>& all_marks, vector<string>& majina, int low, int high) {
    int pivot = all_marks[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (all_marks[j] < pivot) {
            i++;
            swap(all_marks[i], all_marks[j]);
            swap(majina[i],majina[j]);
        }
    }

    swap(all_marks[i + 1], all_marks[high]);
    swap(majina[i+1],majina[high]);
    return i + 1;
}
void quicksort(vector<int>& all_marks, vector<string>& majina, int low, int high) {
    if (low < high) {
        int pivot = partition(all_marks, majina, low, high);

        quicksort(all_marks, majina, low, pivot - 1);
        quicksort(all_marks,majina, pivot + 1, high);
    }

}