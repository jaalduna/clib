//
// Created by Pablo on 20/02/2018.
//

#include "my_func.h"
#include <stdio.h>

int compf(float a,float b,float eps){

    if(-eps<b&&b<eps)return a<eps&&a>-eps;
    int val=a/b < 1+eps && a/b > 1-eps;

    return val;
}

int sort_test() {
    FILE *file = fopen("sort_test.txt", "r");
    int K;
    fscanf(file,"%d",&K);
    int cant=0;
    for(int k=0;k<K;k++){
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
        int equals=1;
        for(int j=0;j<L;j++){
            if(!compf(sorted_data[j],res[j],0.000001)){
                equals=0;
                break;
            }
        }
        if(equals)cant++;
    }
    fprintf(stdout,"sort test: %d/%d\n",cant,K);
    return cant;
}

int mean_test() {
    FILE *file = fopen("mean_test.txt", "r");
    int K;
    fscanf(file,"%d",&K);
    int cant=0;
    for(int k=0;k<K;k++){
        int N,L;
        fscanf(file,"%d %d",&N,&L);
        float data[N];
        float res;
        for(int i=0;i<N;i++){
            fscanf(file,"%f",&data[i]);
        }
        fscanf(file,"%f",&res);
        
        float ans=mean(L,data);
        if(compf(ans,res,0.000001))cant++;
    }
    fprintf(stdout,"mean test: %d/%d\n",cant,K);
    return cant;
}

int weighted_mean_test() {
    FILE *file = fopen("weighted_mean_test.txt", "r");
    int K;
    fscanf(file,"%d",&K);
    int cant=0;
    for(int k=0;k<K;k++){
        int N,L;
        fscanf(file,"%d %d",&N,&L);
        float data[N];
        float res;
        float weights[L];
        for(int i=0;i<N;i++){
            fscanf(file,"%f",&data[i]);
        }
        for(int i=0;i<L;i++){
            fscanf(file,"%f",&weights[i]);
        }
        fscanf(file,"%f",&res);
        
        float ans=mean_weight(L,data,weights);
        if(compf(ans,res,0.000001))cant++;
    }
    fprintf(stdout,"weighted mean test: %d/%d\n",cant,K);
    return cant;
}

int var_test() {
    FILE *file = fopen("var_test.txt", "r");
    int K;
    fscanf(file,"%d",&K);
    int cant=0;
    for(int k=0;k<K;k++){
        int N,L;
        fscanf(file,"%d %d",&N,&L);
        float data[N];
        float res;
        for(int i=0;i<N;i++){
            fscanf(file,"%f",&data[i]);
        }
        fscanf(file,"%f",&res);
        
        float ans=var(L,mean(L,data),data);
        if(compf(ans,res,0.000001))cant++;
    }
    fprintf(stdout,"var test: %d/%d\n",cant,K);
    return cant;
}

int complex_add_test() {
    FILE *file = fopen("complex_add_test.txt", "r");
    int K;
    fscanf(file,"%d",&K);
    int cant=0;
    for(int k=0;k<K;k++){
        complex c1,c2,c_obt,c_esp;
        fscanf(file,"%f %f %f %f",&c1.real,&c1.imag,&c2.real,&c2.imag);
        c_obt=add_complex(c1,c2);
        fscanf(file,"%f %f",&c_esp.real,&c_esp.imag);
        
        if(compf(c_obt.real,c_esp.real,0.000001)&&compf(c_obt.imag,c_esp.imag,0.000001))cant++;
    }
    fprintf(stdout,"complex add test: %d/%d\n",cant,K);
    return cant;
}

int complex_mult_test() {
    FILE *file = fopen("complex_mult_test.txt", "r");
    int K;
    fscanf(file,"%d",&K);
    int cant=0;
    for(int k=0;k<K;k++){
        complex c1,c2,c_obt,c_esp;
        fscanf(file,"%f %f %f %f",&c1.real,&c1.imag,&c2.real,&c2.imag);
        c_obt=mult_complex(c1,c2);
        fscanf(file,"%f %f",&c_esp.real,&c_esp.imag);
        
        if(compf(c_obt.real,c_esp.real,0.00001)&&compf(c_obt.imag,c_esp.imag,0.000001))cant++;
    }
    fprintf(stdout,"complex mult test: %d/%d\n",cant,K);
    return cant;
}

int abs_complex_square_test() {
    FILE *file = fopen("abs_complex_square_test.txt", "r");
    int K;
    fscanf(file,"%d",&K);
    int cant=0;
    for(int k=0;k<K;k++){
        complex c;
        fscanf(file,"%f %f",&c.real,&c.imag);
        float res=abs_complex_squared(c);
        float ans;
        fscanf(file,"%f", &ans); 
        if(compf(res,ans,0.000001))cant++;
    }
    fprintf(stdout,"abs complex square test: %d/%d\n",cant,K);
    return cant;
}

int main(){
    sort_test();
    mean_test();
    weighted_mean_test();
    var_test();
    complex_add_test();
    complex_mult_test();
    abs_complex_square_test();
}