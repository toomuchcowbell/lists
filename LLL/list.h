//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;   //some questions are a char * data;
    node * next;
};

class list
{
    public:
        //These functions are already written for you
        list();			//supplied
        ~list();			//supplied
        void build();     		//supplied
        void display();  		//supplied

        /* *****************YOUR TURN! ******************************** */
        //Write your function prototype here:
        int same_as_head();
        int same_as_tail();
        

    private:		//notice there is both a head and a tail!
        int same_as_head(node* head, int key);
        int same_as_tail(node* head, int key);
        int find_key(node* head);

        node * head;
        node * tail;
};
