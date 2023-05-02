#include "BigNumCalc.h"
#include <iostream>
std::list<int> BigNumCalc::buildBigNum(std::string numString){
    std::list<int> newList;
    for(int i =0; i<numString.length();i++){
        newList.push_back(numString.at(i)-48);
    }
    return newList;
}
std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2){
    std::list<int> result;
    int remainder=0;
    int sum;
    
    int iterator;
    if(num1.size()>num2.size()){
    iterator = num1.size();
    }else{
       iterator = num2.size();
    }
    int dig1, dig2;

    for(int i = 0; i< iterator; i++){
        dig1 = 0;
        dig2 = 0;
        if(!num1.empty()){
            dig1=num1.back();
            num1.pop_back();
        }
        if(!num2.empty()){
            dig2=num2.back();
            num2.pop_back();
        }
        sum = dig1+dig2+remainder;
            if(sum>9){
                
                result.push_front(sum-10);
                remainder=1;
            }else{
                result.push_front(sum);
                remainder=0;
            }
            
               
    }
    while(result.front()==0){
        result.pop_front();
    }
    return result;
}
std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2){
    std::list<int> result;
    int carry=0;
    int sum;
    int iterator = num1.size();
    int dig1, dig2;

    for(int i = 0; i< iterator; i++){
        dig1 = 0;
        dig2 = 0;
        if(!num1.empty()){
            dig1=num1.back();
            num1.pop_back();
        }
        if(!num2.empty()){
            dig2=num2.back();
            num2.pop_back();
        }
        if(dig2>dig1){
            num1.back()-=1;
            carry=10;
        }
        else{

            carry=0;
        }
        sum = (dig1+carry)-dig2;    
        result.push_front(sum);
    }
    while(result.front()==0){
        result.pop_front();
    }
    return result;
}
std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2){
        std::list<int> result;
    int remainder=0;
    int sum;
    
    int iterator;
    if(num1.size()>num2.size()){
    iterator = num1.size();
    }else{
       iterator = num2.size();
    }
    int dig1, dig2;
    dig2=num2.back();
    for(int i = 0; i< iterator; i++){
        dig1 = 0;
       
        if(!num1.empty()){
            dig1=num1.back();
            num1.pop_back();
        }
        
        sum = dig1*dig2+remainder;
            if(sum>9){
                
                result.push_front(sum%10);
                remainder=(sum-sum%10)/10;
            }else{
                result.push_front(sum);
                remainder=0;
            }
            
               
    }
    while(result.front()==0){
        result.pop_front();
    }
    return result;
}
