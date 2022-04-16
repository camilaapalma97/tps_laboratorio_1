/*
 ============================================================================
 Name        : TP1.c
 Author      : Palma, Camila Agustina. 1K
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

int main(void)
{
	setbuf(stdout, NULL);

    int opcion;
    int respuesta;
    int opcion1=0;
	int opcion2=0;
	int opcion3=0;
	int opcion5=0;
	float kilometros;
	float precioLatam;
	float precioAerolineas;
	float debitoL;
	float debitoA;
	float creditoL;
	float creditoA;
	float bitcoinL;
	float bitcoinA;
	float unitarioL;
	float unitarioA;
	float difDePrecio;


	do{ //entra al do para mostrar el menu y pedir que ingrese una opcion.

		respuesta = getNumero(&opcion,"\n\nSeleccionar una opcion\n\n1. Ingresar Kilometros.\n2. Ingresar Precio de Vuelos\n3. Calcular todos los costos\n4. Informar Resultados\n5. Carga forzada de datos\n6. Salir\n","Error, ingrese un dato valido\n",1,6,4);
		if(!respuesta)
		{
			switch(opcion) //switch para entrar a la opcion que haya elegido.
			{
			case 1:
			        getFloat(&kilometros,"\n\nIngresar los kilometros: \n","Error, ingrese un dato valido (999~9999999)\n",999,9999999,2);
					opcion1=1;
					break;
			case 2:
			        if(opcion1 == 1){
					getFloat(&precioLatam,"\n\nIngresar precio del vuelo en Latam: \n","Error, ingrese un dato valido (999~9999999)\n",999,9999999,2);
					getFloat(&precioAerolineas,"\n\nIngresar precio del vuelo en Aerolineas: \n","Error, ingrese un dato valido (999~9999999)\n",999,999999,2);
					opcion2=1;}
					break;
			case 3:
			        if(opcion2 == 1){
					calculos(precioLatam, precioAerolineas, kilometros,&debitoL,&debitoA,&creditoL,&creditoA,&bitcoinL,&bitcoinA,&unitarioL,&unitarioA,&difDePrecio);
					opcion3 = 1;}
					break;
			case 4:
			        if(opcion3 == 1 || opcion5 == 1){
					mostarResultados(kilometros,precioLatam,precioAerolineas,debitoL,debitoA,creditoL,creditoA,bitcoinL,bitcoinA,unitarioL,unitarioA,difDePrecio);}
					break;
			case 5:
			        cargaForzada(&precioLatam, &precioAerolineas, &kilometros,&debitoL,&debitoA,&creditoL,&creditoA,&bitcoinL,&bitcoinA,&unitarioL,&unitarioA,&difDePrecio);
					opcion5=1;
					mostarResultados(kilometros,precioLatam,precioAerolineas,debitoL,debitoA,creditoL,creditoA,bitcoinL,bitcoinA,unitarioL,unitarioA,difDePrecio);
					break;
			case 6:         // Para salir
					break;
			}

		}

	}while(opcion != 6); //while en caso que indique la opcion 6 (salir de la funcion).


	return 0;
}
