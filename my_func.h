/*my_func.h*/

typedef struct complex
{
    float real;
    float imag;
} complex;



/*mean calculates the mean value of the first L registers in data and returns it*/
float mean(int L, float data[]);

/*mean_weight calculates the weighted mean of the first L registers with weights given by weigth[] and returns it*/
float mean_weigth(int L, float data[], float weigth[]);

/*var calculates the variance of the first L registers in data and returns it*/
float var(int L, float mean_val, float data[]);

/*sort arrange the first L registers in data in descending order and return them in sort_data*/
void sort (int L, float data[], float sort_data[]);

/*mult_complex calculates the complex multiplication between n1 and n2 and return it*/
complex mult_complex(complex n1, complex n2);

/*add_complex add the complex numbers n1 and n2 and return it*/
complex add_complex(complex n1, complex n2);

/*abs_complex_squared calculates the squared absolute value of a complex number (real^2 + img^2)*/
float abs_complex_squared (complex n1);


