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

node* deleteMiddle(node* head) {
       node *fast = head, *slow = head;
       if(head->next == NULL || head == NULL)
        return nullptr;
        fast = fast->next->next;
       while(fast != nullptr && fast->next != nullptr)
       {
        fast = fast->next->next;
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
        
    node* head = nullptr;

    create_from_array(arr,head);

    printLL(head);

    deleteMiddle(head);

    printLL(head);
    return 0;
}