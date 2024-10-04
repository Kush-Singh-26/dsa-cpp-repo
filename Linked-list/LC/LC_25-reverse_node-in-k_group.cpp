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

node* reverseLL(node* head)
    {
        node *curr = head,*prev = nullptr, *nextptr;
        while(curr != nullptr)
        {
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        return prev;
    }
    node* kThNode(node* head,int k)
    {
        k-=1;
        while(head != nullptr && k > 0)
        {
            k--;

            head = head->next;
        }

        return head;
    }


    node* reverseKGroup(node* head, int k) {
    node *temp = head, *prevLast = nullptr, *newHead = nullptr;

    while (temp != nullptr) {
        node *kth = kThNode(temp, k);

        if (kth == nullptr) {
            if (prevLast)
                prevLast->next = temp;  
            break;
        }

        node* nextNode = kth->next;  
        kth->next = nullptr;         

        node* reversedHead = reverseLL(temp);

        if (newHead == nullptr)
            newHead = reversedHead;
        else
            prevLast->next = reversedHead; 
        prevLast = temp;

        temp = nextNode;
    }

    return newHead;
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

    head = reverseKGroup(head,k);
    
    printLL(head);
    return 0;
}