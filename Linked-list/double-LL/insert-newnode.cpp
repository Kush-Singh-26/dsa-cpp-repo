#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* prev;
    node* next;

    node(int data1, node* next1, node* prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

    node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

node* addnode(node* head, int p, int x) {
        // 0 based indexing
        node* temp = head;
        for(int i =0;i<p;i++)
        {
            temp = temp->next;
        }
        node* ptr = new node(x);
        if(temp->next == nullptr)
        {
            ptr->prev = temp;
            temp->next = ptr;
        }
        else
        {
            ptr->prev = temp;
            ptr->next = temp->next;
            temp->next->prev = ptr;
            temp->next = ptr;  
        }
        
        
        return head;
    }

void add_from_arr(vector<int> arr, node* &head)
{
    head = new node(arr[0]);
    node*temp = head;
    for(int i =1;i<arr.size();i++)
    {
        temp->next = new node(arr[i]);
        temp->next->prev = temp;
        temp = temp->next;
    }
}

void printLL(node* head)
{
    node* temp = head;
    while(temp != nullptr)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    node* head = nullptr;

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};

    add_from_arr(arr,head);

    int pos, x;

    cin >> pos >> x;

    printLL(head);

    printf("\n");

    addnode(head,pos,x);

    printLL(head);
}