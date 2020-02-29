#include "list.h"

int list::same_as_head()
{
    int key = head->data;
    int num_returned = same_as_head(head, key);
    if (num_returned >= 1)
        --num_returned;
    cout << "The number of nodes that match the head node is: " << num_returned << endl;
    return num_returned;
}

int list::same_as_head(node* head, int key)//gets the keyber of occurences of the first node->data
{
    if(head == NULL) 
        return 0;
    if(head->data == key)
        return same_as_head(head->next, key) + 1;
    else
        return same_as_head(head->next, key);
}

int list::same_as_tail()
{
    int key = find_key(head);
    int num_returned = same_as_tail(head, key);
    if (num_returned >= 1)
        --num_returned;
    cout << "The number of nodes that match the tail node is: " << num_returned << endl;
    return num_returned;

}

int list::find_key(node* head)
{
    if (head == NULL) return 0;
    if (head->next == NULL)
        return head->data;
    return find_key(head->next);
}

int list::same_as_tail(node* head, int key)
{
    if (head == NULL)
        return 0;
    int numOccurences = same_as_tail(head->next, key);
    if (head->data == key)
        return ++numOccurences;
    else
        return numOccurences;
}
