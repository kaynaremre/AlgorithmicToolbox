#include <iostream>
#include <cstdlib>

using std::cout;

int main(){
    for(int i = 667; i < 867 ; i+=2){
        if( i % 50 == 0){
        std::cout << "Traffic.5.Man." << i << ".Limit = s " << rand() % 300 + 200 <<"\n";
        std::cout << "Traffic.5.Man." << i << ".LongDyn = auto " << rand() % 20 + 10 <<"\n";
        std::cout << "Traffic.5.Man." << i + 1 << ".Limit = s 1\n";
        std::cout << "Traffic.5.Man." << i + 1 << ".LongDyn = auto 15\n";
        }
        else{
        std::cout << "Traffic.5.Man." << i << ".Limit = s " << rand() %40 + 20 << "\n";
        std::cout << "Traffic.5.Man." << i << ".LongDyn = auto " << rand() %20 + 5 << "\n";
        std::cout << "Traffic.5.Man." << i + 1 << ".Limit = t " << rand() %15 + 5 << "\n";
        std::cout << "Traffic.5.Man." << i + 1 << ".LongDyn = auto 0\n";
        }

    }
    return 0;

}