#include "BigNumCalc.h"
#include <iostream>
#include <string>
int main(){
    std::string str="12345";
    std::list<int> listA = {1, 1, 2, 5};
    std::list<int> listB = {2};

    BigNumCalc bnc;
    std::list<int> numList = bnc.buildBigNum(str);
    std::list<int> listC = bnc.mul(listA, listB);
  
    
    for(int i : listC){
        std::cout<<i;
    }
    std::cout<<std::endl;
 
}