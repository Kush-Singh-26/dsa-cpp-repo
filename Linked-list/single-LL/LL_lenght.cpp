#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int data1)
    {
        data = data1;
        next = nullptr;
    }

    node(int data1, node* next1)
    {
        data = data1;
        next = next1;
    }
};

int lenght(node* head)
{
    int count =0;
    node* temp = head;
    while(temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;

}

void printLL(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void create_from_array(vector<int> arr,node*& head)
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
    printf("\n");

    cout << "Lenght is : " << lenght(head) << "\n";
    return 0;
}