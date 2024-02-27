#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int NUMCOURSE = 2;
struct Student
{
    int id;
    string name;
    int score[NUMCOURSE];
    double sum;
    double avg;
    struct Student *next;
};
#define struct Student Student;
// typedef struct Student Student;

Student *makeStudent(int N);
void printStudent(Student *head);
int getLength(Student *head);
Student *sortStudent(Student *head, int asc);

Student *makeStudent(int N){
    //Read the file “student.txt” 
    //and construct the linked list with dynamic memory allocation and pointer variables
    
    ifstream file;
    file.open("students.txt");
    if(!file){
        cerr << "FILE FAILED TO OPEN" << endl;
        exit(0);
    }

    // create linked list
    Student *head, *tmp, *prev;
    for (int i = 0; i < N; i++){
        tmp = new(Student);
        //ID NAME SCORE[]SUM AVG NEXT*
        file >> tmp->id >> tmp->name >> tmp->score[0] >> tmp->score[1];
        tmp->sum = (tmp->score[0] + tmp->score[2]);
        tmp->avg = (tmp->score[0] + tmp->score[1]) / 2;
        tmp->next = NULL;
        if (i == 0)
            head = tmp;
        else
            prev->next = tmp;
        prev = tmp;
    }
    return head;
}

void printStudent(Student *head)
{
    Student *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->id << "\t";
        cout << ptr->name << "\t";
        cout << ptr->score[0] << "\t";
        cout << ptr->score[1] << "\t";
        cout << ptr->sum << "\t";
        cout << ptr->avg << "\n";
        ptr = ptr->next;
    }
    cout << endl;
    /*******************************
     * Code your program here
     *******************************/
}
int getLength(Student *head)
{
    /*******************************
     * Code your program here
     *******************************/
}
Student *sortStudent(Student *head, int asc)
{
    /*******************************
     * Code your program here
     *******************************/
    return head;
}
