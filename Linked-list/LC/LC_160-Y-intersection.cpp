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

node *getIntersectionNode(node *headA, node *headB) {
        node *a = headA,*b = headB;
        while(a->next != nullptr)
            a = a->next;
        while(b->next != nullptr)
            b = b->next;
        if(a != b)
            return NULL;
        a = headA;
        b = headB;
        while(a != b)
        {
            a = a->next;
            b = b->next;
            if(a == nullptr)
                a = headB;
            if(b == nullptr)
                b = headA;
        }
        return a;
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

void add_end(node* head, node* comm)
{
    node*temp = head;
    while(temp->next != nullptr)
        temp = temp->next;
    temp->next = comm;
}

int main()
{
    int n;
    cin >> n;
    vector <int> arr1(n);
    for(int i=0; i<n;i++) 
        cin >> arr1[i];
    
    int m;
    cin >> m;
    vector <int> arr2(m);
    for(int i=0; i<m;i++) 
        cin >> arr2[i];

    int o;
    cin >> o;
    vector <int> arr3(o);
    for(int i=0; i<o;i++) 
        cin >> arr3[i];
        
    node* head1 = nullptr;
    node* head2 = nullptr;
    node* common = nullptr;

    create_from_array(arr1,head1);
    create_from_array(arr2,head2);
    create_from_array(arr3,common);

    add_end(head1,common);
    add_end(head2,common);

    printLL(head1);
    printLL(head2);

    int val =0; 
    if(getIntersectionNode(head1,head2))
    {
        val = getIntersectionNode(head1,head2)->data;
    }

    cout << "intersection node is : " << val << "\n";
;


    return 0;
}