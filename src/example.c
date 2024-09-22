#include "example.h"


unsigned int giai_thua(unsigned int n)
{
    if(n == 0 || n == 1) return 1;
    else if(n > 1){
        return(n * giai_thua(n-1));
    }
    return 0;
}
