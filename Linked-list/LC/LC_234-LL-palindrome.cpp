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

node* reverseLink(node* head)
    {      
        
        node* prev = nullptr;
        node* curr = head;
        while(curr != NULL)
        {
            node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(node* head) {

        node* fast = head;
        node* slow = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        node* second = reverseLink(slow);

        node* first = head;

        while(second != NULL)
        {
            if(second->data != first->data)
            {
                return 0;
            }
            second = second->next;
            first = first->next;
        }

        return 1;
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

    if(isPalindrome(head))
        cout << "true" << "\n";
    else
        cout << "false" << "\n";
    return 0;
}