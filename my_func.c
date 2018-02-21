/*my_func.c*/

#include "my_func.h"


/*mean calculates the mean value of the first L registers in data and returns it*/
float mean(int L, float data[]){
    float ans=0;
    for(int i=0;i<L;i++){
        ans+=data[i];
    }
    ans=ans/L;
    return ans;
}


/*mean_weight calculates the weighted mean of the first L registers with weights given by weigth[] and returns it*/
float mean_weigth(int L, float data[], float weigth[]){
    float ans=0;
    float total_weight=0;
    for(int i=0;i<L;i++){
        ans+=data[i]*weigth[i];
        total_weight+=weigth[i];
    }
    return ans/total_weight;
}


/*var calculates the variance of the first L registers in data and returns it*/
float var(int L, float mean_val, float data[]){
    float ans=0;
    for(int i=0;i<L;i++){
        ans += data[i]*data[i];
    }
    ans= ans / L - mean_val*mean_val;
    return ans;
}


void swap(float data[],int i,int j){
    float aux=data[i];
    data[i]=data[j];
    data[j]=aux;
}

void quick_sort(float data[], int l, int r){
    if(l>=r)return;
    float piv=data[l];
    int i=l+1;
    int j=r;
    while(i<=j){
        if (data[i]<piv){
            i++;
            if(data[j]>=piv) j--;
        }
        else{
            if(data[j]<piv){
                swap(data,i,j);
                i++;
            }
            j--;
        }
    }
    int m;
    if(j==r){
        swap(data,l,r);
        m=r;
    }
    else if(j==l){
        m=l;
    }
    else{
        swap(data,l,j);
        m=j;
    }
    quick_sort(data,l,m-1);
    quick_sort(data,m+1,r);
}

/*sort arrange the first L registers in data in descending order and return them in sort_data*/
void sort (int L, float data[], float sort_data[]){
    for(int i=0;i<L;i++){
        sort_data[i]=data[i];
    }
    quick_sort(sort_data,0,L-1);
}

/*add_complex add the complex numbers n1 and n2 and return it*/
complex add(complex n1, complex n2)
{
    complex temp;

    temp.real = n1.real + n2.real;
    temp.imag = n1.imag + n2.imag;

    return(temp);
}


/*mult_complex calculates the complex multiplication between n1 and n2 and return it*/
complex mult_complex(complex n1, complex n2){

    complex temp;

    temp.real = n1.real * n2.real - n1.imag * n2.imag;
    temp.imag = n1.real * n2.imag + n1.imag * n2.real;

    return(temp);
}


/*abs_complex_squared calculates the squared absolute value of a complex number (real^2 + img^2)*/
float abs_complex_squared (complex n1){
    return n1.real*n1.real+n1.imag*n1.imag;
}

