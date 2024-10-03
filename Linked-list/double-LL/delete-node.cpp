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

node* deleteNode(node* head, int x) {
        node* temp = head;
        for(int i = 1;i<x;i++)
        {
            temp =temp->next;
        }
        if(x==1)
        {
            temp->next->prev=NULL;
            temp=temp->next;
            return temp;
            
        }
        else
        {
            if(temp->next == nullptr)
            {
                temp->prev->next = nullptr;
            }
        
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
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

    int pos;

    cin >> pos;

    printLL(head);

    printf("\n");

    deleteNode(head,pos);

    printLL(head);
}