#include <stdio.h> // printing
#include "main.h" // header
#include "niv.h" // Getting niv's library

int main() {
   enum Privates privates = get_privates();
   switch (privates) {
      case Shlong: {
         printf("Niv's shlong size is %d", get_shlong_size());
         break;
      }
      case NonBinary: {
         printf("Niv is %d/0 crazy", get_shlong_size());
         break;
      }
      default: {
         printf("Niv's cat is %d deep", get_shlong_size());
         break;
      }
   }
   return 0;
}
