/*
 * validaciones.c
 *
 *  Created on: 11 abr 2022
 *      Author: Infernum
 */


#include <stdio.h>
#include <stdlib.h>

#define descuento 0.10;
#define incremento 0.25;
#define bitcoin 4607000.00;

int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do{
			printf("%s", mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >=0);

	}
	return retorno;
}

int getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%c",&buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
				printf("%s",mensajeError);
				reintentos--;
		}while(reintentos >=0);

	}
	return retorno;
}

int getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do{
			printf("%s", mensaje);
			scanf("%f",&bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >=0);

	}
	return retorno;
}

int calculos(float latam, float aerolineas, float kilometros, float* debitoL, float* debitoA, float* creditoL, float* creditoA, float* bitcoinL, float* bitcoinA, float* unitarioL, float* unitarioA, float* diferencia)
{

	int retorno = -1;

		*debitoL = latam-latam*descuento;
		*debitoA = aerolineas-aerolineas*descuento;
		*creditoL = latam+latam*incremento;
		*creditoA = aerolineas+aerolineas*incremento;
		*bitcoinL = latam/bitcoin;
		*bitcoinA = aerolineas/bitcoin;
		*unitarioL = latam/kilometros;
		*unitarioA = aerolineas/kilometros;

		if(latam < aerolineas)
		{
		*diferencia = aerolineas - latam;
		}
		else
		{
		*diferencia = latam - aerolineas;
		}

	retorno = 0;
	return retorno;
}

void mostarResultados(float kil,float lat,float aer,float debL,float debA,float creL,float creA,float bitL,float bitA,float uniL,float uniA,float difP)
{
	printf("\nKilometros ingresados: %.2f Km.\n\n"
			"Latam: $ %.2f\n"
			"a) Precio con tarjeta de debito: $%.2f \n"
			"b) Precio con tarjeta de credito: $%.2f \n"
			"c) Precio pagando con bitcoin : %f BTC\n"
			"d) Precio unitario: $%.2f por kilometro\n"
			"\nAerolineas: $ %.2f\n"
			"a) Precio con tarjeta de debito: $%.2f \n"
			"b) Precio con tarjeta de credito: $%.2f \n"
			"c) Precio pagando con bitcoin : %f BTC\n"
			"d) Precio unitario: $%.2f por kilometro\n"
			"La diferencia de precio es de: $%.2f \n",kil,lat,debL,creL,bitL,uniL,aer,debA,creA,bitA,uniA,difP);
}

void cargaForzada(float* latam, float* aerolineas, float* kilometros,float* debitoL, float* debitoA, float* creditoL, float* creditoA, float* bitcoinL, float* bitcoinA, float* unitarioL, float* unitarioA, float* diferencia)
{

	float kil = 7090;
	float lat = 159339;
	float aer = 162965;

	*kilometros= kil;
	*latam = lat;
	*aerolineas = aer;
	*debitoL = lat-lat*descuento;
	*debitoA = aer-aer*descuento;
	*creditoL = lat+lat*incremento;
	*creditoA = aer+aer*incremento;
	*bitcoinL = lat/bitcoin;
	*bitcoinA = aer/bitcoin;
	*unitarioL = lat/kil;
	*unitarioA = aer/kil;
	*diferencia = aer-lat;

}
