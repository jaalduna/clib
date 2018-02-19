/*my_func.c*/

#include "my_func.h"



/*add_complex add the complex numbers n1 and n2 and return it*/
complex add(complex n1, complex n2)
{
      complex temp;

      temp.real = n1.real + n2.real;
      temp.imag = n1.imag + n2.imag;

      return(temp);
}