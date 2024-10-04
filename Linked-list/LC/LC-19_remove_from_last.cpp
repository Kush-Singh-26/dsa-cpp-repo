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

node* removeNthFromEnd(node* head, int n) {
    node* temp = head;
    node* slow = head;
    for(int i =0;i<n;i++)
        temp = temp->next;

    if(temp == nullptr)
        return head->next;

    while(temp->next != nullptr)
    {
        temp = temp->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
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
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i=0; i<n;i++) 
        cin >> arr[i];

    int x; cin >> x;
        
    node* head = nullptr;

    create_from_array(arr,head);

    printLL(head);

    removeNthFromEnd(head,x);

    printLL(head);
    return 0;
}