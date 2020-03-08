//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;       //some questions are a char * data;
    node * next;
};

class list
{
    public:
        //These functions are already written for you
        list();			    //supplied
        ~list();			//supplied
        void build();     	//supplied
        void display();  	//supplied

        /* ***************** YOUR TURN! **************************** */
        //Write your function prototype here:
        int same_as_head(); //count the number of items in the list that are the same as the first node and return the count.
        int same_as_tail(); //count the number of items in the list that are the same as the last node and return the count.
        int greater_than_4(); //count the number of items in the list that are greater than 4 and return the count.
        int sum_all_unique(); //display all the unique data that exists in the data structure and return the sum of all unique items.
        int first_to_last();//remove the first node and place it at the end of the list; return the number of items in the list.
        int remove_last_2();//remove the last '2' and return the total number of 2's in the list. Do this in only a single traversal.
        //remove all nodes after the last '2' and return the number of nodes removed. do in single traversal.
        //remove every '2' except the first one. return the number of nodes removed. single trav.
        //remove the last two nodes, but only if the last one is not a '2'. Return the sum of these nodes.
        //make a copy of the data structure, but only copy even data. return the number of nodes copied. Do not implement this with an insert function, traverse only once.
        //create an average of all the even data in the data structure.
        //sum all of the data less than 10 in the data structure.
        //make a copy of all even data items.
        //make a copy of all unique data.
        

    private:		//notice there is both a head and a tail!

        //recursive private methods and private helper methods
        int same_as_head(node* head, int key);
        int same_as_tail(node* head, int key);
        int find_key(node* head);
        int greater_than_4(node* head);
        int sum_all_unique(node* head);
        bool is_unique(node* head, node* keyNode); //checks if the number is unique recursively through the linked list. this is a sub method for sum_all_unique
        int first_to_last(node* head, node* movePointer);
        int remove_last_2(node* head, node* &marker);//TODO: figure out this zero node thing. might have something to do with passing by value

        /* ****************** DATA MEMBERS ************************* */
        node * head;
        node * tail;
};
