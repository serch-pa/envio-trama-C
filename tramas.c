#include <stdio.h>
#include <stdlib.h>
#define T_TRAMA 32

void main(){
                            /*        MAC DESTINO                      |   MAC ORIGEN                      |    ToT    |   DATOS
                                                                       |                                   |           | CONTROL                   SS       */
    unsigned char trama[T_TRAMA] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x00, 0x0E, 0x00, 0x0F,             // 00 RR
                                    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F};            // 01 RNR
                                                                                                                                                // 10 REJ
                                                                                                                                                // 11 SREJ
    short int tot = 0x0000;

    printf("MAC destino: ");
    for(char i = 0; i < 6; i++){
        printf("%02x:", trama[i]);
    }

    printf("\n\nMAC origen: ");
    for(char i = 6; i < 12; i++){
        printf("%02x:", trama[i]);
    }

    printf("\n\nTipo o Tamanio: ");
    printf("%02x%02x", trama[12], trama[13]);
    tot = (trama[12] << 8) + trama[13];
    printf("\n\n El valor del ToT es: %c", tot);

    if(tot <= 1500){
        printf("\n\nTamano: \n\n");
        printf("  SAPd: %02x     SAPo: %02x\n", trama[14], trama[15]);
        printf("\n  Control: ");

        switch(trama[16] & 3){

            case 1:
                printf("T-S");
                break;
            case 3:
                printf("T-U");
                break;
            default:
                printf("T-I");
                break;
        }

        printf("\n\nCRC: ");
        for(char i = T_TRAMA -4; i < T_TRAMA; i++){
            printf("%02x:", trama[i]);
        }
        printf("\n\n");
    }else{
        printf("Tipo: ");
    }

}