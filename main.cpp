/* 
 * File:   main.cpp
 * Author: Edward
 *
 * Created on November 1, 2014, 10:49 AM
 */

#include <cstdlib>
#include <iostream>
#include "list.h"



using namespace std;


int main() 
{
    echin_list::list<int> ed;
    
    ed.addition(1);
    ed.addition(3);
    ed.insert(5,2);
    ed.remove(3);

  
  
    
    
   
    
   
    
    
    cout << ed.head() << ed.count() << ed.view(2);
   
    return 0;
}
    

   


 
