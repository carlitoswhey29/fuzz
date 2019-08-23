
#include <iostream>     // std::cout
#include <iterator>     // std::next
#include <list>         // std::list
#include <algorithm>    // std::for_each

/*<#========== prototype functions ============#>*/
void Print_Output(int x);
void PrintFuzz();
void PrintBuzz();
void PrintFuzzBuzz();

int main(){ 

    std::list<int> mylist;                              // declare instance of list of type int
    int max = 10;                                       // declare max iterations
    for (int i=0; i < max; i++){                        
        mylist.push_back(i+1); //(i*10);                // initialize mylist starting at index 0 = 1
    }

    std::cout << "\nMylist: ";
    std::for_each (mylist.begin(),
                    std::next(mylist.begin(), max),     // example of next iterating from beginning to end through for_each loop
                    [&](int j) {Print_Output(j);} );     // example of lambda calls function to determine output

    std::cout << '\n';

  return 0;
} 

/*<#========== Functions ============#>*/
void Print_Output(int x){

    std::cout << std::endl; 

    if((x % 5 == 0) && (x % 3 == 0)){     //divisible by both 5 and 3
        PrintFuzzBuzz();
    }else if(x % 5 == 0){                 //divisible by 5
        PrintFuzz();
    }else if(x % 3 == 0){                 //divisible by 3
        PrintBuzz();
    }else{      
        std::cout << x;
    }
}
/*<#========== Small Functions ============#>*/
void PrintFuzz(){std::cout << "Fuzz";}
void PrintBuzz(){std::cout << "Buzz";}
void PrintFuzzBuzz(){std::cout << "FuzzBuzz";}
