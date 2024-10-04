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

node* rotateRight(node* head, int k) {
        if(head == NULL || head->next == NULL || k==0)
            return head;
        node *temp = head;
        int count = 1;
        while(temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
        temp->next = head;
        node* p = head;
        k = k%count;
        for(int i =1;i<count-k;i++)
        {
            p = p->next;
        }
        node* newhead = p->next;
        p->next = NULL;
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
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i=0; i<n;i++) 
        cin >> arr[i];
    
    int k; cin >> k;
    node* head = nullptr;

    create_from_array(arr,head);

    printLL(head);

    head = rotateRight(head,k);
    
    printLL(head);
    return 0;
}