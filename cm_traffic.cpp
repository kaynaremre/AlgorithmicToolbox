#include <iostream>


int main(){
    for(int i = 667; i < 867 ; i+=2){
        if( i % 50 == 0){
        std::cout << "Traffic.5.Man." << i << ".Limit = s 300\n";
        std::cout << "Traffic.5.Man." << i << ".LongDyn = auto 15\n";
        std::cout << "Traffic.5.Man." << i + 1 << ".Limit = s 1\n";
        std::cout << "Traffic.5.Man." << i + 1 << ".LongDyn = auto 15\n";
        }
        else{
        std::cout << "Traffic.5.Man." << i << ".Limit = s 30\n";
        std::cout << "Traffic.5.Man." << i << ".LongDyn = auto 10\n";
        std::cout << "Traffic.5.Man." << i + 1 << ".Limit = t 10\n";
        std::cout << "Traffic.5.Man." << i + 1 << ".LongDyn = auto 0\n";
        }

    }
    return 0;

}