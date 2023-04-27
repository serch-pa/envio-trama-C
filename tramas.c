#include <stdio.h>
#include <stdlib.h>
#define T_TRAMA 64

void main(){
                            /*        MAC DESTINO                      |   MAC ORIGEN                      |    ToT    |   DATOS
                                                                       |                                   |           | CONTROL               */
    unsigned char trama[T_TRAMA] = {0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x03, 0xf0, 0xf0,
				                    0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		// SS
  				                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x05, 0x90, 0x6d};            // 01 RNR
                                                                                                                                                // 10 REJ
    
    char ss[4][4]={"RR","RNR","REJ","SREJ"};
    char uc[32][6]={"UI","SIM","-","SARM","UP","-","-","SABM","DISC","-","-","SARME","-","-","-","SABME","SNRM","-","-","RSET","-","-","-","XID","-","-","-","-","-","-","-","-"};
    char ur[32][5]={"UI","RIM","-","DM","-","-","-","-","RD","-","-","-","UA","-","-","-","-","FRMR","-","-","-","-","-","XID","-","-","-","-","-","-","-","-"};                                                                                                                                    // 11 SREJ
    unsigned short int tot = (trama[12] << 8) | trama[13];
	
	printf("***********************Cabecera Ethernet***********************\n");
    printf("MAC destino: ");
    for(char i = 0; i < 5; i++){
        printf("%02x:", trama[i]);
    }
	printf("%02x", trama[5]);
	
    printf("\n\nMAC origen: ");
    for(char i = 6; i < 11; i++){
        printf("%02x:", trama[i]);
    }
	printf("%02x", trama[11]);

    printf("\n\nTipo o Tamanio: ");
	
    printf("\n\n El valor del ToT es: %d", tot);

    if(tot <= 1500){
        printf("\n\nTamano: \n\n");
	printf(" Cabecera LLC");

        switch(trama[16] & 3){

            case 1:
                printf("\n\n T-S");
		        printf("\n\n El SS de la trama es: %s y su N(R) es: %d \n",ss[(trama[16] >> 2) & 3], trama[17] >> 1);
                break;
            case 3:
                printf("\n\n T-U");
                unsigned char m = trama[16] << 4;
                m = ((trama[16] >> 5) << 2) | (m >> 6);
                printf("\n\n El Comando es %s y la Respuesta es %s y el mensaje en decimal es %d \n", uc[m], ur[m], m);
                break;
            default:
                printf("\n\n T-Is");
                printf("\n\n EL N(S) de la trama es: %d y su N(R) es: %d \n", trama[16] >> 1, trama[17] >> 1);
                break;
        }

    }else{
        printf("\n\n  Tipo: ");
    }

}
