/************************************************************************
Syggrafeas			: Prokopios Stamelias
AM                  : 1115201400190
*************************************************************************/
#include "TSEvr.h"

int TSEvr_setValue (TStoixeiouEvr *target, TStoixeiouEvr source)
{
	target->AirportID=source.AirportID;
	strcpy(target->Name,source.Name);
	strcpy(target->City,source.City);
	strcpy(target->Country,source.Country);
	strcpy(target->IATA,source.IATA);
	strcpy(target->ICAO,source.ICAO);
	target->afiksi=source.afiksi;
	target->anaxwrisi=source.anaxwrisi;
}

int TSEvr_readValue (FILE *from,  TStoixeiouEvr *Elem)
{
	char*  p;/*axriasti variable ,orizetai apla gi atn strtol*/
	long ch;
	char *air;
	int AirportID;
	char *Name,*City,*Country,*IATA,*ICAO;
	char *t;
	char buff[100];
	while(fgets(buff,100,from))
	{
		ch=strtol(buff,&p,10);
		air=strtok(buff,";");
		Name=strtok(NULL,";");
		City=strtok(NULL,";");
		Country=strtok(NULL,";");
		IATA=strtok(NULL,";");
		ICAO=strtok(NULL,";");
		t=strtok(NULL,"");
		break;/*i stop here the while loop because i read line line and give data*/
	}

	Elem->AirportID=ch;
	strcpy(Elem->Name,Name);
	strcpy(Elem->City,City);
	strcpy(Elem->Country,Country);
	strcpy(Elem->IATA,IATA);
	Elem->anaxwrisi=0;
	Elem->afiksi=0;
	if(ICAO==NULL)/*explanation on readme file*/ 
	{
		char str[3];
		int i;
		strncpy(Elem->ICAO,Elem->IATA,4);
		strncpy(Elem->IATA,Elem->Country,3);
		strncpy(Elem->Country,Elem->City,sizeof(Elem->Country));
		memset(Elem->City,0,sizeof(Elem->City));
		for(i=0;i<3;i++)
			str[i]=Elem->IATA[i];
		strcpy(Elem->IATA,str);
	}
	else
		strcpy(Elem->ICAO,ICAO);
	if(Elem->afiksi!=0||Elem->anaxwrisi!=0)
	{
		Elem->afiksi=0;
		Elem->anaxwrisi=0;
	}
}




int TSEvr_writeValue(FILE *to, TStoixeiouEvr Elem)
{
	
	fprintf(to,"ID=%d  Number Afiksewn=%d  Number Anaxwrisewn=%d\n",Elem.AirportID,Elem.afiksi,Elem.anaxwrisi);
	return 1;
}

