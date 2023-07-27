#include <stdio.h>
#include "main.h"
#include "menu.c"
//#include "struct.h"

int main (void)
{
	//typedef struct user user;
	//typedef struct materia materia;
	int com;
	menu();
	while(scanf("%d", &com) == 1)
	{
		switch(com)
		{
			case 1:
					guardarDatos();
					break;
			case 2:
					//cargarDatos();
					break;
			default:
					printf("esta ingresando datos erroneos\n\n");
		}
	}
	  scanf("%d", &com);

	return 0;
}
