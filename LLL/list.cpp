//list.cpp
#include "list.h"

//*************************************************
//functions related to same_as_head
int list::same_as_head()
{
    int key = head->data;
    int num_returned = same_as_head(head, key);
    if (num_returned >= 1)
        --num_returned;
    cout << "The number of nodes that match the head node is: " << num_returned << endl;
    return num_returned;
}
//gets the number of occurences of the first node->data
int list::same_as_head(node* head, int key)
{
    if(head == NULL) 
        return 0;
    if(head->data == key)
        return same_as_head(head->next, key) + 1;
    else
        return same_as_head(head->next, key);
}
//*************************************************




//*************************************************
//functions related to: same_as_tail

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

//*************************************************
//functions related to greater_than_4
int list::greater_than_4()
{
   int theCount = greater_than_4(head);
   cout << "The number of items in the list greater than 4 is: " << theCount << endl;
   return theCount; //it is referencing this->head
}

int list::greater_than_4(node* head)
{
   if (head == NULL) return 0;
   if (head->data > 4) 
           return greater_than_4(head->next) + 1;// if the data is greater than 4 increment count and continue recursion
   else return greater_than_4(head->next);
}
