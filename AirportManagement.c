/************************************************************************
Programma pelaths	: AirportManagement.c
Syggrafeas			: Prokopios Stamelias
AM                  : 1115201400190
Skopos				: skeleton main for askhsh 3
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "TSEvr.h"
#include "TSDDA.h"
#include "Evretirio.h"
#define N  4800

void fun2(EvrPtr E)
{
	/*Sinolikos Xronos pou apaitithike*/
	LARGE_INTEGER frequency;  /* ticks per second */
	LARGE_INTEGER t1,t2;   /* ticks */
	double sinolikos_elapsedTime;
	
	/* get ticks per second */
    QueryPerformanceFrequency(&frequency);

    /* start timer */
    QueryPerformanceCounter(&t1);
    
    LARGE_INTEGER frequency511;
    LARGE_INTEGER t1_511,t2_511;
    double elapsed_time511;
    
    /* get ticks per second */
    QueryPerformanceFrequency(&frequency511);
    
    /*start timer for 511*/
    QueryPerformanceCounter(&t1_511);
    
    
    
    
    
    
    LARGE_INTEGER frequency1023;
    LARGE_INTEGER t1_1023,t2_1023;
    double elapsed_time1023;
    
    /* get ticks per second */
    QueryPerformanceFrequency(&frequency1023);
    
    /*start timer for 511*/
    QueryPerformanceCounter(&t1_1023);
    
    
    
    
    LARGE_INTEGER frequency2047;
    LARGE_INTEGER t1_2047,t2_2047;
    double elapsed_time2047;
    
    /* get ticks per second */
    QueryPerformanceFrequency(&frequency2047);
    
    /*start timer for 511*/
    QueryPerformanceCounter(&t1_2047);
    
    
    
    
    LARGE_INTEGER frequency4095;
    LARGE_INTEGER t1_4095,t2_4095;
    double elapsed_time4095;
    
    /* get ticks per second */
    QueryPerformanceFrequency(&frequency4095);
    
    /*start timer for 511*/
    QueryPerformanceCounter(&t1_4095);
    
    
	/*doing something*/
	printf("Function2:\n");
	int x;
	TStoixeiouEvr kom;
	FILE *fp;
	fp=fopen("airportsSimpleWinRandomANSI.txt","r");
	int i;
	for(i=0;i<N;i++)
	{
		TSEvr_readValue(fp,&kom);
		x=Evr_Insert(E,kom);
		if(i==511)
			QueryPerformanceCounter(&t2_511);
		if(i==1023)
			QueryPerformanceCounter(&t2_1023);
		if(i==2047)
			QueryPerformanceCounter(&t2_2047);
		if(i==4094)
			QueryPerformanceCounter(&t2_4095);
	}
	/*doing something*/
	
	
	
	
	/* stop timer */
    QueryPerformanceCounter(&t2);
    
    
    /*elapsed time for 511*/
    elapsed_time511=(t2_511.QuadPart - t1_511.QuadPart) * 1000.0 / frequency511.QuadPart;
    printf("O xronos pou apaitithike meta apo tin eisagogi 511  stoxeiwn einai  %g msec\n",elapsed_time511);
    
       
    /*elapsed time for 1023*/
    elapsed_time1023=(t2_1023.QuadPart - t1_1023.QuadPart) * 1000.0 / frequency1023.QuadPart;
    printf("O xronos pou apaitithike meta apo tin eisagogi 1023 stoxeiwn einai %g msec\n",elapsed_time1023);

    
    /*elapse time for 2047*/
    elapsed_time2047=(t2_2047.QuadPart - t1_2047.QuadPart) * 1000.0 / frequency2047.QuadPart;
    printf("O xronos pou apaitithike meta apo tin eisagogi 2047 stoxeiwn einai  %g msec\n",elapsed_time2047);
    
       
    /*elapsed time for 4095*/
     elapsed_time4095=(t2_4095.QuadPart - t1_4095.QuadPart) * 1000.0 / frequency4095.QuadPart;
    printf("O xronos pou apaitithike meta apo tin eisagogi 4095 stoxeiwn einai  %g msec\n",elapsed_time4095);
    
    
    /*sinolikos xronos*/
    sinolikos_elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
    printf("elapsedTime=%g msec\n", sinolikos_elapsedTime);


	printf("o Sinolikos Arithmos stoxeiwn pou diavastikan  einai isos me %d\n",N);
	double mesos_oros;
	mesos_oros=sinolikos_elapsedTime/(float)N;
	printf("%.4f\n",mesos_oros);
	fclose(fp);
}	


void fun3(EvrPtr E,FILE** io)
{
	
	
	
	
	LARGE_INTEGER frequency;        /* ticks per second */
    LARGE_INTEGER t1, t2;           /* ticks */
    double elapsedTime;

    /* get ticks per second */
    QueryPerformanceFrequency(&frequency);

    /* start timer */
    QueryPerformanceCounter(&t1);

	
	
	
	
	
	/*do something*/
	int sin=0;
	int idkomvosin;
	int idkomvosout;
	int i;
	int posadiavasa=0;
	int metrtis_posa_vrethikan=0;
	int metritis_posa_den_vrethikan=0;
	TStoixeiouEvr komvos;
	FILE* fp;
	fp=fopen("routesWin.txt","r");
	for(i=0;i<67290;i++)
	{
		TSEvr_readValue (fp,&komvos);
		idkomvosin=atoi(komvos.Country);
		idkomvosout=atoi(komvos.ICAO);
		EvrSearch(E,idkomvosin,0,&sin);posadiavasa++;
		EvrSearch(E,idkomvosout,1,&sin);posadiavasa++;
		
		if(sin==1)
			metrtis_posa_vrethikan++;
		else
			metritis_posa_den_vrethikan++;
	}
	/* stop timer */
    QueryPerformanceCounter(&t2);
    /* compute and print the elapsed time in millisec */
    elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
	/*printf("Function3:Sinolikos xronos searching %g msec\n", elapsedTime);*/
	double mesos_oros_anazitisis=elapsedTime/(float)posadiavasa;
	double mesos_oros_oswn_vrethikan=elapsedTime/(float)metritis_posa_den_vrethikan;
	*io=fopen("OUTPUTRandomBST.txt","w");
	fprintf(*io,"Diavasa %d sindeseis\n Vrethikan %d aerodromia\n Den Vrethikan %d aerodromia\n",posadiavasa,metrtis_posa_vrethikan,metritis_posa_den_vrethikan);
	fprintf(*io,"Sinolikos Xronos Anazitisis %g msec\nO mesos oros anazitisis gia kathe aerodromio einai isos me %.3f\n",elapsedTime,mesos_oros_anazitisis);
	fprintf(*io,"o mesos oros autwn pou den vrethikan einai isos me %.3f\n",mesos_oros_oswn_vrethikan);
	fclose(fp);
	
}




void fun4(EvrPtr E,FILE** io)
{
	
	LARGE_INTEGER frequency;  /* ticks per second */
	LARGE_INTEGER t1,t2;   /* ticks */
	double elapsedTime;
	
	/* get ticks per second */
    QueryPerformanceFrequency(&frequency);

    /* start timer */
    QueryPerformanceCounter(&t1);
    printf("Function4:\n");
	int metritis=0;
	Evr_PrintAll(E,*io,&metritis);
	printf("Ektipwse akrivws %d stoxeia\n",metritis);

	fclose(*io);
	/* stop timer */
    QueryPerformanceCounter(&t2);
	
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
    printf("elapsedTime=%g msec\n",elapsedTime);
}



void fun6(EvrPtr E)
{
	/*Sinolikos Xronos pou apaitithike*/
	LARGE_INTEGER frequency;  /* ticks per second */
	LARGE_INTEGER t1,t2;   /* ticks */
	double sinolikos_elapsedTime;
	
	/* get ticks per second */
    QueryPerformanceFrequency(&frequency);

    /* start timer */
    QueryPerformanceCounter(&t1);
    
    LARGE_INTEGER frequency511;
    LARGE_INTEGER t1_511,t2_511;
    double elapsed_time511;
    
    /* get ticks per second */
    QueryPerformanceFrequency(&frequency511);
    
    /*start timer for 511*/
    QueryPerformanceCounter(&t1_511);
    
    
    
    
    
    
    LARGE_INTEGER frequency1023;
    LARGE_INTEGER t1_1023,t2_1023;
    double elapsed_time1023;
    
    /* get ticks per second */
    QueryPerformanceFrequency(&frequency1023);
    
    /*start timer for 511*/
    QueryPerformanceCounter(&t1_1023);
    
    
    
    
    LARGE_INTEGER frequency2047;
    LARGE_INTEGER t1_2047,t2_2047;
    double elapsed_time2047;
    
    /* get ticks per second */
    QueryPerformanceFrequency(&frequency2047);
    
    /*start timer for 511*/
    QueryPerformanceCounter(&t1_2047);
    
    
    
    
    LARGE_INTEGER frequency4095;
    LARGE_INTEGER t1_4095,t2_4095;
    double elapsed_time4095;
    
    /* get ticks per second */
    QueryPerformanceFrequency(&frequency4095);
    
    /*start timer for 511*/
    QueryPerformanceCounter(&t1_4095);
    
    
	/*doing something*/
	printf("Function6:\n");
	int x;
	TStoixeiouEvr kom;
	FILE *fp;
	fp=fopen("airportsSimpleWinSortedANSI.txt","r");
	int i;
	for(i=0;i<N;i++)
	{
		TSEvr_readValue(fp,&kom);
		x=Evr_Insert(E,kom);
		if(i==511)
			QueryPerformanceCounter(&t2_511);
		if(i==1023)
			QueryPerformanceCounter(&t2_1023);
		if(i==2047)
			QueryPerformanceCounter(&t2_2047);
		if(i==4094)
			QueryPerformanceCounter(&t2_4095);
	}
	/*doing something*/
	
	
	
	
	/* stop timer */
    QueryPerformanceCounter(&t2);
    
    
    /*elapsed time for 511*/
    elapsed_time511=(t2_511.QuadPart - t1_511.QuadPart) * 1000.0 / frequency511.QuadPart;
    printf("O xronos pou apaitithike meta apo tin eisagogi 511  stoxeiwn einai  %g msec\n",elapsed_time511);
    
       
    /*elapsed time for 1023*/
    elapsed_time1023=(t2_1023.QuadPart - t1_1023.QuadPart) * 1000.0 / frequency1023.QuadPart;
    printf("O xronos pou apaitithike meta apo tin eisagogi 1023 stoxeiwn einai %g msec\n",elapsed_time1023);

    
    /*elapse time for 2047*/
    elapsed_time2047=(t2_2047.QuadPart - t1_2047.QuadPart) * 1000.0 / frequency2047.QuadPart;
    printf("O xronos pou apaitithike meta apo tin eisagogi 2047 stoxeiwn einai  %g msec\n",elapsed_time2047);
    
       
    /*elapsed time for 4095*/
     elapsed_time4095=(t2_4095.QuadPart - t1_4095.QuadPart) * 1000.0 / frequency4095.QuadPart;
    printf("O xronos pou apaitithike meta apo tin eisagogi 4095 stoxeiwn einai  %g msec\n",elapsed_time4095);
    
    
    /*sinolikos xronos*/
    sinolikos_elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
    printf("elapsedTime=%g msec\n", sinolikos_elapsedTime);


	printf("o Sinolikos Arithmos stoxeiwn pou diavastikan  einai isos me %d\n",N);
	
	double mesos_oros;
	mesos_oros=sinolikos_elapsedTime/(float)N;
	printf("%.4f\n",mesos_oros);
	
	
	
	fclose(fp);
}


void fun7(EvrPtr E,FILE** io)
{
	
	
	
	
	LARGE_INTEGER frequency;        /* ticks per second */
    LARGE_INTEGER t1, t2;           /* ticks */
    double elapsedTime;

    /* get ticks per second */
    QueryPerformanceFrequency(&frequency);

    /* start timer */
    QueryPerformanceCounter(&t1);

	
	
	
	
	
	/*do something*/
	int sin=0;
	int idkomvosin;
	int idkomvosout;
	int i;
	int posadiavasa=0;
	int metrtis_posa_vrethikan=0;
	int metritis_posa_den_vrethikan=0;
	TStoixeiouEvr komvos;
	FILE* fp;
	fp=fopen("routesWin.txt","r");
	for(i=0;i<67290;i++)
	{
		TSEvr_readValue (fp,&komvos);
		idkomvosin=atoi(komvos.Country);
		idkomvosout=atoi(komvos.ICAO);
		EvrSearch(E,idkomvosin,0,&sin);posadiavasa++;
		EvrSearch(E,idkomvosout,1,&sin);posadiavasa++;
		
		if(sin==1)
			metrtis_posa_vrethikan++;
		else
			metritis_posa_den_vrethikan++;
	}
	/* stop timer */
    QueryPerformanceCounter(&t2);
    /* compute and print the elapsed time in millisec */
    elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
	/*printf("Function3:Sinolikos xronos searching %g msec\n", elapsedTime);*/
	double mesos_oros_anazitisis=elapsedTime/(float)posadiavasa;
	*io=fopen("OUTPUTSortedBST.txt","w");
	fprintf(*io,"Diavasa %d sindeseis\n Vrethikan %d aerodromia\n Den Vrethikan %d aerodromia\n",posadiavasa,metrtis_posa_vrethikan,metritis_posa_den_vrethikan);
	fprintf(*io,"Sinolikos Xronos Anazitisis %g msec\nO mesos oros anazitisis gia kathe aerodromio einai isos me %.3f\n",elapsedTime,mesos_oros_anazitisis);
	fclose(fp);
	
}

void fun8(EvrPtr E,FILE** myf)
{
	
	LARGE_INTEGER frequency;  /* ticks per second */
	LARGE_INTEGER t1,t2;   /* ticks */
	double elapsedTime;
	
	/* get ticks per second */
    QueryPerformanceFrequency(&frequency);

    /* start timer */
    QueryPerformanceCounter(&t1);
    printf("Function8:\n");
	int metritis=0;
	Evr_PrintAll(E,*myf,&metritis);
	printf("Ektipwse akrivws %d stoxeia\n",metritis);

	fclose(*myf);
	/* stop timer */
    QueryPerformanceCounter(&t2);
	
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
    printf("elapsedTime=%g msec\n",elapsedTime);
}

	
int main(int argc, char *argv[])
{ 

  FILE *fp,*Tr;	
  EvrPtr E;
  E=EvrConstruct(7200);
  fun2(E);
  fun3(E,&fp);
  fun4(E,&fp);
  Evr_katastrofi(&E);
  E=EvrConstruct(7200);
  fun6(E);
  fun7(E,&Tr);
  fun8(E,&Tr);
  Evr_katastrofi(&E);
  return 0;
}

