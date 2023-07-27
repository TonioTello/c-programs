//functions.c
#include <stdio.h>

void guardarDatos(void)
{
	FILE * ptr = NULL;
	ptr = fopen("usuarios.txt", "a+");
	fclose(ptr);
	ptr = fopen("materias.txt", "a+");
	fclose(ptr);
	ptr = fopen("notas_nombre_materia.txt", "a+");
	fclose(ptr);
	return;
}

void cargarDatos(void)
{
	char nombre[10];
	FILE * ptr = NULL;
	ptr = fopen("usuarios.txt", "r");
	printf("%s", fgets(nombre, 10, ptr));
	//scanf("%s", nombre);
	//fputs(nombre, ptr);
	fclose(ptr);
	return;
}
