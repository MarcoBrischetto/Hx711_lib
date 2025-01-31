/*
 * Nombre del archivo:   main.c
 *
*/

#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "user.h"
#include "system.h"
#include "hx711.h"


void main(void){
    int32_t value,acum;
    float weight;
    initApp();
    uartConfig();
    hx711Init();
    while(1){
        acum=0;
        for(uint8_t i=0;i<10;i++){
            value=hx711Read();
            acum+=value;
            __delay_ms(100);
        }
        acum/=10;
        //weight=acum;
        weight=M*acum+B;
        printf("%.2f\r\n",weight-70.0f);  
        __delay_ms(500);
                
    }
    //aprox 126g de agua destilada  15-16 grados densidad 999.15-999.06 Kg/m3
    
    //    126g/0.999105 =126.1128cm3
}

/* ------------------------ Fin de archivo ---------------------------------- */
