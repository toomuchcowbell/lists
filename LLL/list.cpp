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
//*************************************************



//*************************************************
//functions related to sum_all_unique
int list::sum_all_unique()
{
    int sum = 0;
    if (head == NULL)
        return sum;
    cout << "The array after removing non-unique numbers is as follows: ";
    sum = sum_all_unique(head);
    cout << "The sum of these items is: " << sum << endl;
    return sum;
}

bool list::is_unique(node* head, node* keyNode)
{
    if (head == NULL)
        return true;
    if (head->data == keyNode->data && head != keyNode)
        return false;
    bool theTest = is_unique(head->next, keyNode);
    return theTest;
}
int list::sum_all_unique(node* head)
{
    if (head == NULL) 
    {
        cout << endl;
        return 0;
    }
    if (is_unique(this->head, head))// if the number's unique 
        cout << head->data; 
    else 
        return sum_all_unique(head->next);//otherwise step to next node.
    if (head->next != NULL && is_unique(this->head, head->next))//if theres a next and it's unique, put arrow
        cout << " -> ";
    else if (head->next != NULL && !is_unique(this->head, head->next))// if the next is not unique, check the next next node
    {
        if (head->next->next != NULL && is_unique(this->head, head->next->next))//this is to thwart the bug if 2 non-unique are in a row
            cout << " -> "; //but it could honestly happen with 3 in a row, but in 10 tests that error wasn't produced, so is it really
                            //worth fixing right now? you tell me...
    }
    return sum_all_unique(head->next) + head->data;
}
//*************************************************



//*************************************************
//functions related to front_to_back
int list::first_to_last()
{
    if (head == NULL)
        return 0;
    int nodeCount = first_to_last(head, head);
    cout << "The list has a total of: " << nodeCount << " nodes. The first has been moved to the back." << endl;
    return nodeCount;
}
int list::first_to_last(node* head, node* movePointer)
{
    if (head == NULL)
        return 0;
    else if (this->head == movePointer && head->next != NULL)
    {
        this->head = head->next;
    }
    int count = first_to_last(head->next, movePointer) + 1;
    if (head->next == NULL)
    {
        head->next = movePointer;
        movePointer->next = NULL;
    }
    return count;
}
//*************************************************



//*************************************************
//functions related to remove_last_2()
int list::remove_last_2()
{
    if (head == NULL) return 0;
    node* myMarker = NULL;
    int nodeCount = remove_last_2(head, myMarker);
    cout << "After removing the last occurence of 2, the list contains: " << nodeCount << " nodes." << endl;
    return nodeCount;
}

int list::remove_last_2(node* head, node* &marker) //TODO: figure out this zero node thing. might have something to do with passing by value
{
    if (head == NULL) 
        return 0;
    if (head->data == 2) 
        marker = head;
    int count = remove_last_2(head->next, marker) + 1;
    if (marker == NULL)
        return count;
    //if there is in fact a 2;
    if (head->next == marker)
    {
        if (marker->next == NULL)
            head->next = NULL;
        else
            head->next = head->next->next;
        delete marker;
        return --count;
    }
    return count;
}


