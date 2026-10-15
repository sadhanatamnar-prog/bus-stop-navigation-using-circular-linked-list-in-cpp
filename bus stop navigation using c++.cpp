#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string stop;
    Node* next;
};

int main()
{
    Node *head = NULL, *temp, *newNode;
    int n;

    cout << "Enter number of bus stops: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        newNode = new Node;

        cout << "Enter bus stop name: ";
        cin >> newNode->stop;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    temp->next = head;

    cout << "\nForward Journey:\n";
    temp = head;

    for (int i = 0; i < n; i++)
    {
        cout << temp->stop << " -> ";
        temp = temp->next;
    }

    cout << head->stop << endl;

    cout << "\nReturn Journey:\n";

    Node* arr[100];
    temp = head;

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp;
        temp = temp->next;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i]->stop << " -> ";
    }

    cout << arr[n - 1]->stop << endl;

    return 0;
}
