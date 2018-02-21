//
// Created by Pablo on 20/02/2018.
//

#include "my_func.h"
#include <stdio.h>

int compf(float a,float b){

}

int sort_test() {
    FILE *file = fopen("sort_test.txt", "r");
    float my_float;
    int K;
    fscanf(file,"%d",&K);
    while(K--){
        int N,L;
        fscanf(file,"%d %d",&N,&L);
        float data[N];
        float res[L];
        for(int i=0;i<N;i++){
            fscanf(file,"%f",&data[i]);
        }
        for(int i=0;i<L;i++){
            fscanf(file,"%f",&res[i]);
        }
        float sorted_data[L];
        sort(L,data,sorted_data);

    }
}



int main(){

}