#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string chef;
    Node *next;
    Node *prev;

    Node(string chef)
    {
        this->prev = NULL;
        this->chef = chef;
        this->next = NULL;
    }
};
void printOptions()
{
    cout << endl
         << endl
         << "Welcome Manager" << endl;
    cout << "1. Print Chefs" << endl;
    cout << "2. Add Head-Chef" << endl;
    cout << "3. Add Junior-Chef" << endl;
    cout << "4. Add Chef in  a Position" << endl;
    cout << "5. Total Number of  Chefs" << endl;
    cout << "6. Delete A Chef" << endl;
    cout << "Want Terminate ? Press Any Key" << endl
         << endl;
}
void printChefs(Node *head, Node *tail)
{
    cout << "---------------" << endl;
    if (head == NULL)
    {
        cout << "No Chef Found!!" << endl;
        cout << "---------------" << endl;
        return;
    }
    for (Node *i = head; i != NULL; i = i->next)
    {
        cout << i->chef << " ";
    }
    cout << endl
         << "---------------" << endl;

    for (Node *i = tail; i != NULL; i = i->prev)
    {
        cout << i->chef << " ";
    }
    cout << endl
         << "---------------" << endl;
}
int sizeOf(Node *head)
{
    int c = 0;
    for (Node *i = head; i != NULL; i = i->next)
    {
        c++;
    }
    return c;
}
void insertHeadChef(Node *&head, Node *&tail, string name)
{
    Node *headChef = new Node(name);

    if (head == NULL)
    {
        head = headChef;
        tail = headChef;
        printChefs(head, tail);
        return;
    }
    head->prev = headChef;
    headChef->next = head;
    head = headChef;
    printChefs(head, tail);
}
void insertJuniorChef(Node *&head, Node *&tail, string name)
{
    Node *juniorChef = new Node(name);

    if (head == NULL)
    {
        head = juniorChef;
        tail = juniorChef;
        printChefs(head, tail);
        return;
    }
    tail->next = juniorChef;
    juniorChef->prev = tail;
    tail = juniorChef;
    printChefs(head, tail);
}
void insertAtPosition(Node *head, Node *tail, string name, int pos)
{
    Node *current = head;
    for (int c = 1; c <= pos - 1; c++)
    {
        current = current->next;
    }
    Node *newChef = new Node(name);
    newChef->prev = current;
    newChef->next = current->next;

    current->next->prev = newChef;
    current->next = newChef;
    printChefs(head, tail);
}

void deleteChef(Node *head, int pos)
{
    Node *current = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        current = current->next;
    }
    Node *tmpNode = current->next;
    current->next = current->next->next;
    current->next->prev = current;
    delete tmpNode;
}

void deleteHeadChef(Node *&head)
{
    Node *tmpNode = head;
    head = head->next;
    head->prev = NULL;
    delete tmpNode;
}

void deleteJuniorChef(Node *&tail)
{
    Node *tmpNode = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete tmpNode;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        int option, pos;
        printOptions();
        cin >> option;
        string name;
        switch (option)
        {
        case 1:
            printChefs(head, tail);
            break;
        case 2:
            cout << "Insert Head-Chef  Name : ";
            cin >> name;
            insertHeadChef(head, tail, name);
            break;
        case 3:
            cout << "Insert Junor-Chef  Name : ";
            cin >> name;
            insertJuniorChef(head, tail, name);
            break;
        case 4:
            cout << "Insert Junor-Chef  Name & position : ";
            cin >> name >> pos;
            if (pos == 0)
            {
                insertHeadChef(head, tail, name);
            }
            else
            {

                if (pos > sizeOf(head))
                {
                    cout << "invalid index" << endl;
                }
                else if (pos == sizeOf(head))
                {
                    insertJuniorChef(head, tail, name);
                }
                else
                {
                    insertAtPosition(head, tail, name, pos);
                }
            }
            break;
        case 5:
            cout << "size  = " << sizeOf(head) << endl;

            break;
        case 6:
            cin >> pos;
            if (pos >= sizeOf(head))
            {
                cout << "ivalid index" << endl;
            }
            else if (pos == 0)
            {
                cout << "deleting HeadChef" << endl;
                deleteHeadChef(head);
            }
            else if (pos == sizeOf(head) - 1)
            {
                cout << "deleting JuniorChef" << endl;
                deleteJuniorChef(tail);
            }
            else
            {
                deleteChef(head, pos);
                printChefs(head, tail);
            }

            break;
        default:
            return 0;
        }
    }
    // insert at Head
    // Insert at Tail
    // Insert at any position
    // print List
    // Print List from reverse

    return 0;
}