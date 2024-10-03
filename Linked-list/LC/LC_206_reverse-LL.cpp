#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    // constructor when next node is provided

    node(int data1, node* next1)
    {
        data = data1;
        next = next1;
    }

    // constructor when only data is given

    node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

node* reverseListRecursive(node* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        node* newhead = reverseListRecursive(head->next);

        node* front = head->next;

        front->next = head;

        head->next = nullptr;

        return newhead;
    }

node* reverseList(node* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        node* newhead = reverseList(head->next);

        node* front = head->next;

        front->next = head;

        head->next = nullptr;

        return newhead;
    }

void printLL(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

void create_from_array(vector<int> arr,node*&head)
{
    head = new node(arr[0]);
    node* temp = head;
    for(int i = 1;i<arr.size();i++)
    {
        temp->next = new node(arr[i]);
        temp = temp->next;
    }
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8};

    node* head = nullptr;

    create_from_array(arr,head);

    printLL(head);

    printLL(reverseList(head));

    return 0;
}