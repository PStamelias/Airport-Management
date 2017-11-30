/************************************************************************
Syggrafeas			: Prokopios Stamelias
AM                  : 1115201400190
*************************************************************************/
#include "TSDDA.h"

int TSDDA_setValue (TStoixeiouDDA *target, TStoixeiouDDA source)
{
	target->arrayIndex=source.arrayIndex;
	target->key=source.key;	
	return (TSDDA_iso(*target,source));
}

int TSDDA_setKey(keyType * key, keyType Val){*key=Val;}

int TSDDA_setIndex(int * Index, int Val){*Index=Val;}

int TSDDA_iso(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
	return (s1.key==s2.key);
}

int TSDDA_mikrotero(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
	return (s1.key<s2.key);
}

int TSDDA_megalytero(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
	return (s1.key>s2.key);
}

/* The Following are already Implemented using Above */

int TSDDA_mikrotero_iso(TStoixeiouDDA s1, TStoixeiouDDA s2)
{ 
    return TSDDA_mikrotero(s1,s2)||TSDDA_iso(s1,s2);
}

int TSDDA_megalytero_iso(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
    return TSDDA_megalytero(s1,s2)||TSDDA_iso(s1,s2);
}

int TSDDA_diaforo(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
    return !TSDDA_iso(s1,s2);
}
