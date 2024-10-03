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

bool hasCycle(node *head) {
        node* fast = head;
        node* slow = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
            {
                return true;
            }
        }

        return false;
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

    int x;
    cin >> x;

    //creating a cycle
    node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    node* temp1 = head;
    for(int i = 1; i <= x; i++)  
    {
        temp1 = temp1->next;
    }

    temp->next = temp1;

    if(hasCycle(head))
        cout << "true" << "\n";
    else
        cout << "fasle" << "\n";
    

    return 0;
}