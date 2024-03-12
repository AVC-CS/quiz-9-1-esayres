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
Student *swapNode(Student *prev, Student *ptr);

Student *makeStudent(int N)
{
    // Read the file “student.txt”
    // and construct the linked list with dynamic memory allocation and pointer variables

    ifstream file;
    file.open("students.txt");
    if (!file)
    {
        cerr << "FILE FAILED TO OPEN" << endl;
        exit(0);
    }

    // create linked list
    Student *head, *tmp, *prev;
    for (int i = 0; i < N; i++)
    {
        tmp = new (Student);
        // ID NAME SCORE[]SUM AVG NEXT*
        file >> tmp->id >> tmp->name >> tmp->score[0] >> tmp->score[1];
        tmp->sum = (tmp->score[0] + tmp->score[1]);
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
    // gathers total length of Linked List
    Student *ptr = head;
    int cnt = 0;
    while (ptr != NULL)
    {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}
Student *sortStudent(Student *head, int asc)
{
    int length = getLength(head);

    if (length <= 1)
        return head;

    // bubble sort
    for (int i = 0; i < length - 1; ++i)
    {
        Student *current = head;
        Student *nextNode = head->next;
        Student *prev = NULL; // Keep track of the previous node for swapping

        for (int j = 0; j < length - i - 1 && nextNode != NULL; ++j)
        {
            // Compare values of adjacent nodes and swap if necessary
            if (current->sum > nextNode->sum && asc == 1)
            {
                // Swap the nodes
                if (current == head)
                {
                    head = swapNode(NULL, current);
                }
                else
                {
                    current = swapNode(prev, current);
                }
                // Update prev for the next iteration
                // current = nextNode;
                // nextNode = current->next;
            }
            else if (current->sum < nextNode->sum && asc == 0)
            {
                // Swap the nodes
                if (current == head)
                {
                    head = swapNode(NULL, current);
                }
                else
                {
                    current = swapNode(prev, current);
                }

                // Update prev for the next iteration
                // current = nextNode;
                // nextNode = current->next;
            }
            // Move to the next pair of nodes
            prev = current;
            current = current->next;
            // current = nextNode;
            // nextNode = nextNode->next;
            nextNode = current->next;
        }
    }
    return head;
}

Student *swapNode(Student *prev, Student *ptr)
{

    Student *nextNode = ptr->next;
    if (prev != NULL)
    {
        prev->next = nextNode;
    }
    ptr->next = nextNode->next;
    nextNode->next = ptr;
    return nextNode;
}
