#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    //object.same_as_head();
    //object.same_as_tail();
    //object.greater_than_4();
    //object.sum_all_unique();
    //object.first_to_last();
    object.remove_last_2();//TODO: figure out this zero node thing. might have something to do with passing by value

    

    object.display();  //displays the LLL again!
   
    
    return 0;
}
