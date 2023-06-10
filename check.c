#include <stdio.h>

unsigned short int checksum(unsigned char T[], char tamano, char inicio){
   unsigned char carry, i;
   unsigned short int check;
   unsigned int CS = 0;

   for (i = inicio; i < tamano; i += 2) {
       CS += T[i] << 8 | T[i+1];
   }

   CS += CS >> 16;
   check = CS;

   return ~check;
}

// void main(){

// unsigned char T[] = {0x45,0x00,0x01,0x9c,0xd7,
//                       0xde,0x40,0x00,0x80,0x06,
//                       0x8f,0xe8,0xc0,0xa8,0x01,
//                       0x43,0x94,0xcc,0x3a,0xdd};

// char opcion;
// unsigned char aux[2];

// printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
// printf("%c Choose your character! %c\n", 186, 186);
// printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
// printf("%c 1. Alicia              %c\n", 186, 186);
// printf("%c 2. Betito              %c\n", 186, 186);
// printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

// scanf("%c",&opcion);
// opcion -= 48;

// if( opcion & 1 ){
	
//    printf("  Soy Alicia \n\n");
//    T[10] = 0;
//    T[11] = 0;
//    printf("  El checksum es %x.", checksum(T,20));

// } else{
//    printf("Soy Betito \n\n");
//    if( checksum(T,20) == 0 )
//       printf("  El checksum es correcto \n\n");
//    else{
//       printf("  El checksum es incorrecto \n\n");
//       printf("  El checksum correcto es :  %x.", checksum(T,20));
//    } 
// }
// }