/************************************************************************
Syggrafeas			: Prokopios Stamelias
AM                  : 1115201400190
*************************************************************************/
#include "Evretirio.h"
#include<assert.h>
#define Simple 1 /*0 for AVL -any interger fors Simple*/
/* Oi diafores tvn ylopoihsevn Simple kai AVL einai mikres - mporeite na xrhsimopoihsete 
   thn  domh #if ... #else ...#endif gia na diaforopihsete tis dyo ylopoihseis  */
   
#if (Simple)
#include "BST/ch8_BSTpointer.h" /* gia Simple Ylopoihsh */
#else
#include "AVL/ch8_AVLpointer.h" /* gia AVL Ylopoihsh */
#endif


struct EvrNode{
       TStoixeiouEvr *DataArray; /* array of size MaxSize */
       int Index;              /* index of first available element in array */
       typos_deikti TreeRoot;     /* Root of DDA */
} EvrNode;

EvrPtr EvrConstruct(int MaxSize){
	EvrPtr E;
	E=malloc(sizeof(EvrNode));
	E->Index=0;
	E->DataArray=malloc(MaxSize*sizeof(TStoixeiouEvr));	
/* Oi diafores tvn ylopoihsevn Simple kai AVL einai mikres - 
	mporeite na xrhsimopoihsete thn  domh #if ... #else ...#endif */
   typos_deikti TreeRoot;
#if (Simple)
   	printf("use simple BST\n");
	Tree_dimiourgia(&TreeRoot);
#else   
    printf("use AVL BST\n");
   	AVLTree_dimiourgia(&TreeRoot);
#endif
	E->TreeRoot=TreeRoot;
	return E;
}

int Evr_Insert(EvrPtr E, TStoixeiouEvr Data)
{
	assert(E!=NULL);
	TStoixeiouDDA i;
	i.arrayIndex=E->Index;
	i.key=Data.AirportID; 
	TSEvr_setValue(&(E->DataArray[E->Index]),Data);
	int error=0;
	int y=0;
	int *not_var=&y;
#if(Simple)
	Tree_eisagogi(&(E->TreeRoot),i,&error);
	if(error)
	{
		printf("Something went wrong on Tree_eisagogi\n");
		return -1;
	}	
#else
	AVLTree_eisagogi(&(E->TreeRoot),i,not_var,&error);
	if(error)
	{
		printf("Something went wrong on AVLTree_eisagogi\n");
		return -1;
	}	
#endif
	++E->Index;
	return 1;
}


int EvrSearch(EvrPtr E, keyType key, int InOut, int * found)
{
	assert(E!=NULL);
	*found=0;
	int vrethike=0;
	TStoixeiouDDA ko;
	ko.key=key;
	typos_deikti komvosfound=NULL;
#if (Simple)
	Tree_anazitisi(E->TreeRoot,ko,&komvosfound,&vrethike);
	Tree_periexomeno(komvosfound,&ko);
#else
	AVLTree_anazitisi(E->TreeRoot,ko,&komvosfound,&vrethike);
	AVLTree_periexomeno(komvosfound,&ko);
#endif
	if(vrethike==1)
	{
		*found=1;
		if(InOut==0)
			E->DataArray[ko.arrayIndex].afiksi++;
		else
			E->DataArray[ko.arrayIndex].anaxwrisi++;
	}
	return 1;
}



void Print_Value_of_Tree(EvrPtr E,typos_deikti n,FILE* out,int** counter)
{
	TStoixeiouEvr Elem;
	TStoixeiouDDA ko;
	if(n==NULL)
		return ;
		
#if (Simple)
	Print_Value_of_Tree(E,Tree_apaidi(n),out,counter);
	/*printing the values ID,Afiksis,Anaxwriseis*/
	
	Tree_periexomeno(n,&ko);
	Elem=E->DataArray[ko.arrayIndex];
	TSEvr_writeValue(out,Elem);++**counter;
	
	/*printing the values ID,Afiksis,Anaxwriseis*/
	Print_Value_of_Tree(E,Tree_dpaidi(n),out,counter);

#else
	Print_Value_of_Tree(E,AVLTree_apaidi(n),out,counter);
	/*printing the values ID,Afiksis,Anaxwriseis*/
	
	AVLTree_periexomeno(n,&ko);
	Elem=E->DataArray[ko.arrayIndex];
	TSEvr_writeValue(out,Elem);++**counter;
	
	/*printing the values ID,Afikseis,Anaxwriseis*/
	Print_Value_of_Tree(E,AVLTree_dpaidi(n),out,counter);
#endif
}

int Evr_PrintAll(EvrPtr E, FILE *out, int * counter)
{
	assert(E!=NULL);
	typos_deikti a=E->TreeRoot;
	Print_Value_of_Tree(E,a,out,&counter);
	return *counter;
}

int Evr_katastrofi(EvrPtr* E)
{
	assert(E!=NULL);
	free((*E)->DataArray);
#if (Simple)
	Tree_katastrofi(&(*E)->TreeRoot);
#else
	AVLTree_katastrofi(&(*E)->TreeRoot);	
#endif
	free(*E);
	*E=NULL;
	return (*E==NULL);
}
