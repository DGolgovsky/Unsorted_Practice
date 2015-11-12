#include <stdio.h>

int main( void )
{
   int i, a = 0;

   for( i = 0; i<5; i++)
   {
       a = ++a%2;
       printf( "a = %d\n", a);
   }
}
//If you expect 1 0 1 0 1, you will be disappointed.
