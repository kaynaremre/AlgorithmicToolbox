#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int comparedouble (const void*  a, const void*  b)
{
  if ( *(double*)a <  *(double*)b ) return -1;
  if ( *(double*)a == *(double*)b ) return 0;
  if ( *(double*)a >  *(double*)b ) return 1;

  return 0;
}



int main(){

    double puv[3] = {3.31, 5.624, 4.3131};
    qsort(puv, 3, sizeof(double), comparedouble);

  for(int j = 0; j < 3; ++j){
    cout << puv[j] << " ";
  }
}
