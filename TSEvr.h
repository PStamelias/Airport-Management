/************************************************************************
Syggrafeas			: Prokopios Stamelias
AM                  : 1115201400190
*************************************************************************/
#ifndef __TSEvr__
#define __TSEvr__

#include <stdio.h>
#include <string.h>

typedef struct data {
    int AirportID;
    char Name[50];
    char City[50];
    char Country[50];
    char IATA[4];
    char ICAO[4];
    int afiksi;
    int anaxwrisi;
} TStoixeiouEvr;

int TSEvr_setValue (TStoixeiouEvr *target, TStoixeiouEvr source);

int TSEvr_readValue (FILE *from,  TStoixeiouEvr *Elem);

int TSEvr_writeValue(FILE *to, TStoixeiouEvr Elem);

#endif
