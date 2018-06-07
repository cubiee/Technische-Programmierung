#include "teilbar.h"

int teilbar(int zahl, int teiler){
    if(0 == zahl % teiler){
        return 1;
    }else{
        return 0;
    }
}