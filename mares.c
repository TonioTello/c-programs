#include <ncurses.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "cabe.h"	

#define ESTUDIANTE 0
#define PROFESOR 1
#define TRUE 1
#define FALSE 0
#define ADMUSERNAME  "administrador"
#define PASSWORD "mares"

struct usuarios {

	char nombre_usua[20];
	char cedula_usua[15];
	char username[20];
	char password[30];
	struct usuarios *sig;
};



struct notasmaterias {          
	
	int num_notas;
	char **apt_ident;             
          int *apt_portj;        
};


	
struct materias{

	char name_materia[20];
	int creditos;
	char name_teacher[20];
	struct calificaciones * apt_calificaciones;
	struct notasmaterias *apt_notasmaterias; 	
          struct materias *next; 
};

struct calificaciones{
       char Ccdula[15];
       char **notas;
       struct calificaciones *sgt;       
};

typedef struct materias curs;
typedef struct usuarios usua;
typedef struct calificaciones cali;
typedef struct notasmaterias  nota;

void pause(void);
char Menu_principal();
char Rol_student();
char Rol_teacher();
char Rol_second_teacher();
char Rol_Administrator();


//#include "cabe2.h"
usua *insertarEnUsua(usua *apuntador);
void mostrarListaUsua(usua *apuntador);
void crearArchivos(FILE * ptd, FILE *ptk);
void saveInFile_dataUsua(usua *apuntador, usua *apuntador2, FILE *ptd);
curs *insertarEnMaterias(curs *apuntador, usua *apuntador2);
void mostrarListaMateria(curs *apuntador);
void saveInFile_dataMateria(curs *apuntador, FILE *ptd);
int buscarDatoCrearCuenta(usua *apuntador, char *cedula);
int ingresarCuenta(usua *apuntador, char *apodo, char *clave);
void buscarUsername(usua *apuntador, curs *apuntador2, char *apodo);
void mostrarCursos(curs *apuntador, char *nombre);
nota *definirNotas(nota *apuntador);
curs *buscaMateria(curs *apuntador, int num);
curs *ingresarNotas(usua *apuntador2, int num, curs *apuntador3);
int buscarCedula(char *cedula, usua *apuntador);
void mostrarListaStudiantAProfesor(usua *apuntador);
curs *buscaMateria2(curs *apuntador, int num);
int numeroNotas(nota *apuntador);
void informacionDeMateriaAStudieant(usua *apuntador, curs *apuntador2,  char *apodo);

//End #include "cabe2.h"


int main(void)
{
	char opc1, opc_stu, AUX, opc1_2, opc_teach, opc_teach_2, opc1_adm, opc_adm2, numCedula[20], rol, nom_materia[20], creditos, opc_adm3;
	char apodo[20], clave[30];			
	int sw, answ, ch, curso;	   // sw y ch, son variables tipo switch
	usua * aptstudent=NULL, *aptteacher=NULL;
          curs *aptmateria=NULL;
		    
	initscr();

	do
	{	
		erase();     
		opc1 = Menu_principal();
		erase(); //opc1= EOF;
		
		switch (opc1)
		{
		       case '1':  printw("Menu_principal/Creacion_una_cuenta_de_usuario");

			        answ=3;   sw=0;   // Inicializacion de variables;
	
                                move(6,4); printw("Identificacion: ");
			        //noecho();		
			        scanw("%s", &numCedula);				
			        //echo();
			        //printw("%s", numCedula);

			        answ = buscarDatoCrearCuenta(aptstudent,numCedula);

			        if(!answ){	    // !answ equivale a answ ==0
				     answ = buscarDatoCrearCuenta(aptteacher,numCedula);
				     sw=1;			
			        }	
			        
			        if(!answ)
  				      printw("\n\nEl numero de cedula ingresado, no esta en registrado!!\n\n");	
				

			        pause();
			        refresh();
		       	        erase();	
		
			        break; 		
				
		       case '2':  //**********Menu de acuerdo al rol************//
			        printw("Menu_principal/Ingresar_a_su_cuenta");	

			        ///*************Ingresar_a_su_cuenta****************		 
			        apodo[0]='\0';   clave[0]='\0';
			        move(6,4);printw("username: ");    	
			        scanw("%s", apodo);	     
		   	        move(8,4);printw("password: ");     
				noecho();
			        scanw("%s", clave);	    
			        echo();

			        ch=1;   answ=3;	 opc1_2='1';	
			        answ = ingresarCuenta(aptstudent, apodo, clave);
	
			        if(!answ){	    // !answ equivale a answ ==0
				     answ = ingresarCuenta(aptteacher, apodo, clave);
				     ch=2;	opc1_2 = '2';	
			        }	
			
			        if( (strcmp(ADMUSERNAME, apodo)==0) && (strcmp(PASSWORD, clave)==0) ){
				     answ=1;  ch=3; opc1_2 = '3';
			        }		
				///***************************************************		    

			        if(!answ){	
				    printw("\n\nError!! Fallo de autentificacion");
				    pause();   break;
			        }		
			        else
			        {					   				   	  
					  erase();
					  switch (opc1_2)
					  {				   
						 case '1':  //*********Menu Estudiante*********//							      
							       							      							      
							       opc_stu = Rol_student();
							       erase();
							       while(opc_stu != '2')
							       {		    
								      if(opc_stu=='1')
								          //informacionDeMateriaAStudieant(aptstudent, aptmateria, apodo);  nos produce un fallo de segmentacion
									     								    						      
								      pause();  erase();								      							
								      opc_stu = Rol_student();
								      erase();

							       }
							       break;	
		     
						 case '2':  //*********Menu Profesor*********//
							       
							do
							{								       
							       erase();
							       opc_teach = Rol_teacher(); 
							       erase();
		     
							       switch (opc_teach)
							       {
								      case '1':  //*********Menu Secundario Profesor*********//
										    
										    do
										    {	   erase();	
											   opc_teach_2 = Rol_second_teacher();
											   erase();			



											   if( (aptmateria == NULL)  && (opc_teach_2 !='4')){
												  printw("\n\nNo tiene cursos!!");  pause();  continue;
										           }
										    
											   switch (opc_teach_2) 		
											   {
												  
												  
												  case '1': 	 //***aqui lista de cursos...despues de seleccionar el curso viene 2menu***//
														printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Profesor/Menu_Secundario_Profesor/Definir_notas");
														
							
														buscarUsername(aptteacher,aptmateria,apodo);
														printw("\n\nSeleccione el curso al cual quiere acceder: ");
														scanw("%d", &curso);

														aptmateria = buscaMateria(aptmateria,curso); // busca el curso correspondiente para definir las notas
														break;

												  case '2':      //****el profesor podrá ver la lista de estudiantes matriculados en******
														printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Profesor/Menu_Secundario_Profesor/Ingresar_notas");
														buscarUsername(aptteacher,aptmateria,apodo);
														printw("\n\nSeleccione el curso al cual quiere acceder: ");
														scanw("%d", &curso);
														aptmateria = ingresarNotas(aptstudent, curso, aptmateria);					      
														break; 
												  case '3':     printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Profesor/Menu_Secundario_Profesor/Ver_notas");
														break;												  
											   }

											   if(opc_teach_2 != '4'){
												  printw("\n\nIngrese cualquier tecla para continuar, o, \"q\" para volver al menu anterior ");	
												  opc_teach_2=getch();
											   }								  
										    }
										    while(opc_teach_2 != 'q');

										    break;

								      case '2':     printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Profesor/Ver_lista_de_clase");
										    printw("\n\nLista de estudiantes matriculados...\n\n");
										    mostrarListaStudiantAProfesor(aptstudent);
										    pause();  erase();
										    break;

								      case '3':     break;  // aqui retorna al menu principal	
								      default :     move(4,4); printw("Opcion no validad.");
										    move(7,4); pause();
										    erase();								  
							       }
						
							}
							while(opc_teach != '3');							      
							break;

						 case '3':  //*********Menu Administrador*********// 							       
							
							do
							{
							       
							       opc1_adm = Rol_Administrator();
							       erase();

							       switch (opc1_adm) 		
							       {
								      case '1': 
										    break;
								      case '2': 
										    break;
								      case '3':  

										    do
										    {
											   erase();
											   printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Administrador/Gestionar_usuarios/");	
											   move(4,4); printw("1. Ver la lista de usuarios");
											   move(5,4); printw("2. Ingresar nuevo usuario");
											   move(6,4); printw("3. <------");	
											   move(8,7); printw("Opcion: ");	
											   opc_adm2 = getch();    erase(); 
											   refresh();  
											   
						 
											   switch (opc_adm2)
											   {
											   
												  case '1':  erase();
													 printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Administrador/Gestionar_usuarios/Ver_la_lista_de_usuarios");	
													 printw("\n\n\nLista Estudiantes\n\n");
													 mostrarListaUsua(aptstudent);  // llamado a una funcion
													 printw("\n\n************************************************\n\nLista Profesores\n\n\n\n");
													 mostrarListaUsua(aptteacher);   // llamado a una funcion
													 pause(); erase();
													 refresh();  
													 break;

												  case '2': 
													 printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Administrador/Gestionar_usuarios/Ingresar_nuevo_usuario");	
													 move(4,4); printw("Para ingresar un nuevo usuario seleccione el rol. (Presione 1 o 2)");											  
													 move(6,4); printw("1. Estudiante"); 	
													 move(7,4); printw("2. Profesor");
													 move(8,4); printw("3. <------");	
													 move(10,7); printw("Opcion: ");												              	
													 rol = getch();  refresh(); 

													 if( (rol == '1') || (rol == '2') )												 	      	      
														printw("\n\nSelccionó %s\n", rol=='1' ? "Estudiante" : "Profesor");	  
														
													 switch (rol)
													 {
														erase();		     
														case '1':  aptstudent = insertarEnUsua(aptstudent);
															   break; 	
														case '2':  aptteacher = insertarEnUsua(aptteacher);
														           break; 	
														case '3':
														           break; 	
														default :  erase(); move(4,4); printw("Opcion no validad.");
														           pause();
														           refresh();		  
													 }		      	

													 if( (rol == '1') || (rol == '2') )
													 {												 	      
														printw("\n\nNuevo usuario ingresadó!!");  pause();
													 }	      
													 refresh();   
													 erase();	      
													 break;

												  case '3':  break;		

												  default:   move(4,4); printw("Opcion no validad.");
													 move(7,4); pause();
													 refresh();  erase();
											   }					     
										    }
										    while( opc_adm2!='3');	
										    
										    break;
								      case '4': 

										    do
										    {
											   erase();	
											   printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Administrador/Gestionar_materias_del_semestre");	
											   move(4,4); printw("1. Ver la lista de materias");
											   move(5,4); printw("2. Ingresar nueva materia");
											   move(6,4); printw("3. <------");	
											   move(8,7); printw("Opcion: ");	
											   opc_adm3 = getch();   erase(); 
											   refresh();  
											   
						 
											   switch (opc_adm3)
											   {
											   
												  case '1':  erase();
													 printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Administrador/Gestionar_materias_del_semestre/Ver_la_lista_de_materias");	
													 printw("\n\n\nLista de Materias\n\n");
													 mostrarListaMateria(aptmateria); 							   			         
													 pause(); erase();
													 refresh();  
													 break;

												  case '2':
													 printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Administrador/Gestionar_materias_del_semestre/Ingresar_nueva_materia");		 
													 printw("\n\n\nPara ingresar una nueva materia, ingrese nombre y #de creditos...\n\n");										
													 printw("Recuerde!. No se dejar espacios en el nombre de la materia.\n\n");
													 aptmateria = insertarEnMaterias(aptmateria,aptteacher); 
													 pause(); refresh();  erase();					
													 break;

												  case '3':  break;		

												  default:   move(4,4); printw("Opcion no validad.");
													 move(7,4); pause();
													 refresh();  erase();
											   }					     
										    }
										    while( opc_adm3!='3');	

										    break;
								      case '5': 
										    break;
								      default:  
										    move(4,4); printw("Opcion no validad.");
										    move(7,4); pause();
										    erase();				

							       }	
							}
							while( opc1_adm!='5' );	
							break;

						 default :  move(4,4); printw("Opcion no validad.");
							    move(7,4); pause();  erase();					     
						 
					  }					  
			        }	

			        break; 

		       case '3':printw("\n\nMini-mares se esta cerrando....");
			        pause(); break;
	
		       default:  move(4,4); printw("Opcion no validad.");
			         move(7,4); pause();  erase();					
			        
		}
	       

	}
        while(opc1 != '3');
	
	endwin();
	

	return 0;
	
}



//funfun.c

usua *insertarEnUsua(usua *apuntador) // permite ingresar dentro de una lista enlazada los valores correpondientes
{
	usua *apuntadorAux, *newStruct;

	newStruct = (usua *)malloc(sizeof(usua));
	
 	if(newStruct != NULL)   // ingresa aqui, en caso de que la creacion dinamica de memoria se exitosa
	{
		printw("Nombre: ");         // ingresamos por teclado la informacion correpondiente...
		scanw("%s", newStruct-> nombre_usua);
		printw("Cedula: ");
		scanw("%s", newStruct-> cedula_usua);
		strcpy(newStruct-> username, "NA");
		strcpy(newStruct-> password, "NA");
		newStruct-> sig = NULL;
		
		if(apuntador == NULL)
		{
			apuntador = newStruct;
		}
		else
		{
			apuntadorAux = apuntador;
			while( apuntadorAux->sig != NULL)
				apuntadorAux = apuntadorAux->sig;
			apuntadorAux->sig = newStruct;
		}
	}
	return apuntador;
}

void mostrarListaUsua(usua *apuntador)  // imprime en pantalla la lista de usuarios
{
	usua * apuntadorAux;
	int k=1, sw=0;
	apuntadorAux = apuntador;
	
	printw("    %-20s Cedula\n", "Nombre" ); 
        refresh(); 
	 
	while(apuntadorAux != NULL)
	{
		printw("%d.  %-20s %-20s %-20s %s\n", k ,apuntadorAux->nombre_usua, apuntadorAux->cedula_usua, apuntadorAux->username, apuntadorAux->password);		
		apuntadorAux = apuntadorAux -> sig;   
		  
		++k;
		   sw=1; 
	}
	refresh();
	
	if(!sw)
	    printw("\n    ¡Lista vaciá!\n");
	putchar('\n');  
	refresh();  
}

void crearArchivos(FILE * ptd, FILE *ptk)
{
	ptd = fopen("usuarios.txt","r");
	ptk = fopen("materias.txt","r");	
	
	if (!ptd)
	{
		ptd = fopen("usuarios.txt","w");
		printf("Archivo creado...\n\n");	
	}	
	else
	{	
		//printf("Ya exites este archivo...\n\n");	
	}
	fclose(ptd);
}


void saveInFile_dataUsua(usua *apuntador, usua *apuntador2, FILE *ptd)
{
	char nombre[20], cedula[15], apodo[20], clave[30], cadena[100];
	usua *apuntadorAux, *apuntadorAux2;

	ptd = fopen("usuarios.txt","a"); //abre el archivo de (usuarios.txt) para añadir...

	apuntadorAux = apuntador;      // apuntador que apunta a la primera estructura...estudiantes
	apuntadorAux2 = apuntador2;     // apuntador que apunta a la primera estructura...profesor

	while(apuntadorAux != NULL)  // para usuarios del rol estudiante
	{
		fgets(cadena, 100, ptd);
		if(cadena[0]=='\n')
			break;

		strcpy( nombre, apuntadorAux -> nombre_usua ); //En "nombre de tipo cadena" se guarda el valor de  "otroapuntadorAuxiliar -> nombre_usua"...
		fputs(nombre, ptd); // en el archivo el cual es apuntado por ptd se escribe lo que esta en la variable nombre, que es una cadena.
		fputc(',', ptd);
		fputc(32, ptd); // en el archivo el cual... se escribe un enter (32 valor ascii correspondiente a un espacio).

		strcpy( cedula, apuntadorAux-> cedula_usua );
		fputs(cedula, ptd);
		fputc(',', ptd);
		fputc(32, ptd);

		strcpy( apodo, apuntadorAux -> username );
		fputs(apodo, ptd);
		fputc(',', ptd);   
		fputc(32, ptd);

		strcpy( clave, apuntadorAux-> password );
		fputs(clave, ptd);		

		fputc('\n',ptd);	
		apuntadorAux = apuntadorAux -> sig;
	}
	fputc('\n',ptd);	// enter para diferenciar los estudiantes de los profesores
	
	
	while(apuntadorAux2 != NULL)   // para usuarios del rol profesor
	{
		strcpy( nombre, apuntadorAux2 -> nombre_usua ); //En "nombre de tipo cadena" se guarda el valor de  "otroapuntadorAuxiliar -> nombre_usua"...
		fputs(nombre, ptd); // en el archivo el cual es apuntado por ptd se escribe lo que esta en la variable nombre, que es una cadena.
		fputc(',', ptd);
		fputc(32, ptd); // en el archivo el cual... se escribe un enter (32 valor ascii correspondiente a un espacio).

		strcpy( cedula, apuntadorAux2-> cedula_usua );
		fputs(cedula, ptd);
		fputc(',', ptd);
		fputc(32, ptd);

		strcpy( apodo, apuntadorAux2 -> username );
		fputs(apodo, ptd);
		fputc(',', ptd);   
		fputc(32, ptd);

		strcpy( clave, apuntadorAux2-> password );
		fputs(clave, ptd);		

		fputc('\n',ptd);	
		apuntadorAux2 = apuntadorAux2 -> sig;
	}
	fclose(ptd);	
}




curs *insertarEnMaterias(curs *apuntador, usua *apuntador2) // permite ingresar dentro de una lista enlazada la informacion respecto a las materias
{
	curs *apuntadorAux,  *newStruct=NULL;  // este es un apuntador a materias
	usua *apuntadorAux2;  // este es apuntador a usuarios
	int num, k, sw=0;
	char opc;  
	 
	if(apuntador2 != NULL )   // probamos primero que haya profesores, sino no perdemos tiempo creando espacio en memoria...
                newStruct = (curs *) malloc(sizeof(curs));
	else
		printw("\n\nNo hay profesores!");   
	
 	if(newStruct != NULL)   // ingresa aqui, en caso de que la creacion dinamica de memoria se exitosa
	{
	   	printw("Materia: ");         // ingresamos por teclado la informacion correpondiente...
	  	scanw("%s", newStruct-> name_materia);
		printw("Creditos : ");
		scanw("%d", &newStruct-> creditos);     		

	  	printw("\nSeleccione el profesor. Presione el numero correspondiente.\n\n");
		mostrarListaUsua(apuntador2);//apuntador2
		printw("    Opcion: ");   

		while( scanw("%d", &num) != 1);   // num = getchar();
		    printw("\n    OK!....");
	
		apuntadorAux2 = apuntador2;  
		for(k=1; k< num; ++k)//selecciona la struct del profesor indicado
		     apuntadorAux2 = apuntadorAux2 -> sig;
		      		  
	 	strcpy( (newStruct -> name_teacher), (apuntadorAux2 -> nombre_usua) );				
				
		newStruct-> apt_calificaciones = NULL;
		newStruct-> apt_notasmaterias = NULL;
		newStruct-> next = NULL;

		if(apuntador == NULL){
			apuntador = newStruct;
		}
		else{
			apuntadorAux = apuntador;
			while( apuntadorAux->next != NULL)
				apuntadorAux = apuntadorAux->next;
			apuntadorAux->next = newStruct;
		}
	}
	
	return apuntador;
}

void mostrarListaMateria(curs *apuntador)  // imprime en pantalla la lista de materias
{
	curs * apuntadorAux;
	int k=1, sw=0;
	apuntadorAux = apuntador;
	
	printw("   %-20s %-20s Profesor\n", "Nombre", "Creditos"); refresh();  
	while(apuntadorAux != NULL)
	{
		printw("%d. %-20s %-20d %s", k ,apuntadorAux->name_materia, apuntadorAux->creditos, apuntadorAux->name_teacher);
		apuntadorAux = apuntadorAux -> next;   
		refresh(); 
		++k;
		sw=1; 
		printw("\n");    refresh();  
	}
	
	if(!sw)
	    printw("\n    ¡Lista vaciá!\n");
	putchar('\n');  
	refresh();  
}


void saveInFile_dataMateria(curs *apuntador, FILE *ptd)
{
	char materia[20], teacher[20], ncreditos;
	curs *apuntadorAux;

	ptd = fopen("materias.txt","a"); //abre el archivo de (usuarios.txt) para añadir...
	apuntadorAux = apuntador;

	while(apuntadorAux != NULL)
	{
		strcpy( materia, apuntadorAux -> name_materia ); //En "nombre de tipo cadena" se guarda el valor de  "otroapuntadorAuxiliar -> nombre_usua"...
		fputs(materia, ptd); // en el archivo el cual es apuntado por ptd se escribe lo que esta en la variable nombre, que es una cadena.
		fputc(',', ptd);
		fputc(32, ptd); // en el archivo el cual... se escribe un enter (32 valor ascii correspondiente a un espacio).

		ncreditos = apuntadorAux-> creditos;
		fputc(ncreditos, ptd);
		fputc(',', ptd);
		fputc(32, ptd);

		strcpy( teacher, apuntadorAux -> name_teacher );
		fputs(teacher, ptd);

		fputc('\n',ptd);	
		apuntadorAux = apuntadorAux -> next;
	}	
	fclose(ptd);	
}


int buscarDatoCrearCuenta(usua *apuntador, char *cedula)
{
	int sw=0;

	usua *apuntadorAuxiliar;   
	apuntadorAuxiliar = apuntador;   
		
	for(  ; apuntadorAuxiliar != NULL;  apuntadorAuxiliar = apuntadorAuxiliar -> sig ){
		if( strcmp(cedula, apuntadorAuxiliar-> cedula_usua)==0 ){
			 sw = 1;   
			 break;	
		}
	}

	if(sw==0){
	       return FALSE;    //printf("\nNo esta en lista\n");	
	}
	else{

	       if(strcmp("NA", apuntadorAuxiliar->username)==0 )
	       {
		    printw("\n\nPara crear una cuenta de usuario...");		
		    printw("\n\nIngrese su nombre de usuario: ");
		    scanw("%s", &apuntadorAuxiliar->username );
		    printw("\nIngrese su contraseña ");	       
		    noecho();
		    scanw("%s", &apuntadorAuxiliar->password );  
		    echo(); 
		    printw("\n\nCuenta creadá!!...\n\n");			
	       }
	       else
	       {
		    printw("\n\nUd ya tiene una cuanta activa!!\n\n");	
	       }
			
   	       return TRUE;     //printf("\nEsta en lista\n");	
	}
}

int ingresarCuenta(usua *apuntador, char *apodo, char *clave) // esta funcio verifica el nombre de usuario  y su contraseña
{
	int sw=0;
	usua *apuntadorAuxiliar;   
	
	apuntadorAuxiliar = apuntador;   
		
	for(  ; apuntadorAuxiliar != NULL;  apuntadorAuxiliar = apuntadorAuxiliar -> sig ){
		if( (strcmp(apodo, apuntadorAuxiliar-> username)==0) && (strcmp(clave, apuntadorAuxiliar-> password)==0) ){
			 sw = 1;   break;	
		}
	}
        return !sw ? FALSE:TRUE; 
}


void buscarUsername(usua *apuntador, curs *apuntador2, char *apodo) // busca la estructura donde esta el apodo del profesor, luego toma el verdadero nombre del profor y lo pasa a "mostrarCursos"....
{
	int sw=0;

	usua *apuntadorAuxiliar;   
	apuntadorAuxiliar = apuntador;   // hay que utilizar un apondor a _nodo auxiliar para que no modifiquemos la el apuntador que apunta a la cabeza...
		
	for(  ; apuntadorAuxiliar != NULL;  apuntadorAuxiliar = apuntadorAuxiliar -> sig ){
		if( strcmp(apodo, apuntadorAuxiliar-> username)==0 ){
			 mostrarCursos(apuntador2, apuntadorAuxiliar-> nombre_usua); 
			 break;	
		}
	}

}

void mostrarCursos(curs *apuntador, char *nombre) //imprime los cursos que el profesor tiene disponible	
{
        int k=0, sw=0;
	curs *apuntadorAuxiliar;   
	apuntadorAuxiliar = apuntador;   // hay que utilizar un apondor a auxiliar para que no modifiquemos el apuntador que apunta a la cabeza...
		
	printw("\n\n    Cursos:\n");      
	for(  ; apuntadorAuxiliar != NULL;  apuntadorAuxiliar = apuntadorAuxiliar -> next){
		if( strcmp(nombre, apuntadorAuxiliar-> name_teacher)==0 ){			 
			 printw("%d.  %s\n", ++k, apuntadorAuxiliar-> name_materia );  
		         sw=1;			 
		}
	}       
        if(!sw)
	      printw("\n\nNo tiene cursos!!");
}


nota *definirNotas(nota *apuntador) //define la cantidad de notas y el porcentage de cada una, permite ingresar dentro de una lista enlazada los valores correpondientes
{
	nota *apuntadorAux, *newStruct;
        char identif[20]; 
	int acumulador=0, j, k;      

	newStruct = (nota *)malloc(sizeof(nota));
	
 	if(newStruct != NULL)   // ingresa aqui, en caso de que la creacion dinamica de memoria se exitosa
	{	        
		printw("\nCantidad de notas: ");         // ingresamos por teclado la informacion correpondiente...
		scanw("%d", &newStruct-> num_notas);
	      	        
       
	        newStruct-> apt_ident = (char **) malloc( newStruct-> num_notas * sizeof(char *) );	
       	
	         k=0;
	        for(j=0; j < (newStruct-> num_notas); ++j )
	        {
			    newStruct-> apt_ident[j] = (char *) malloc( 20 * sizeof(char ) );
			    

			    printw("Ingresar el identificador de la nota #%d\n", j+1);
			    scanw("%s", &(newStruct-> apt_ident)[k][j]);			   
	      
		}  	        

	        newStruct-> apt_portj = (int *) malloc( newStruct-> num_notas * sizeof(int) );
	        

	        while(acumulador!=100){
		     acumulador = 0;
		     printw("\nPorcentajes...\n\n");
		     for(j=0; j < (newStruct-> num_notas); ++j )
		     {
			    printw("Valor porcentual de la nota #%d\n", j+1);
			    scanw("%d", &(newStruct-> apt_portj)[j]);
			    acumulador += (newStruct-> apt_portj)[j];
		     }

		     if(acumulador != 100)
		     {
			    erase();
			    printw("\nEl porcentaje total diferente del 100%...Ingrese nuevamente los porcentajes correspondientes\n");
			    
		     }		     
	        }

	}
	return newStruct;
}


curs *buscaMateria(curs *apuntador, int num) //imprime los cursos que el profesor tiene disponible	
{
        int k=0, sw=0;
	curs *apuntadorAux;   

        if(apuntador == NULL){
	      printw("\n\nNo tiene cursos!!");
	      return NULL;
        }
        
	apuntadorAux = apuntador;  //variable global-cabeza de materias... // hay que utilizar un apuntador a auxiliar para que no modifiquemos el apuntador que apunta a la cabeza...
		       
        for(k=1; k< num; ++k)
	     apuntadorAux = apuntadorAux->next;
	printw("\n\nSeleccionó el curso de %s\n", apuntadorAux-> name_materia); 
        if(apuntadorAux-> apt_notasmaterias == NULL )
	      apuntadorAux-> apt_notasmaterias = definirNotas(apuntadorAux-> apt_notasmaterias);        
        else
	      printw("\n\nYa!! definio notas en este curso...");

	return apuntador;				  		       
}


curs *ingresarNotas(usua *apuntador2, int num, curs *apuntador3)   // permite ingresar dentro de una lista enlazada los valores correpondientes
{
	cali *apuntadorAux, *newStruct = NULL;
        curs *apuntadorAux3; 
        char opc, **ident_notas;
        int k, numnotas;

	if(apuntador2 ==NULL)
	        return NULL;

       apuntadorAux3 = apuntador3;  		       	      
        for(k=1; k< num; ++k)
	             apuntadorAux3 = apuntadorAux3->next;

        do
        {
	      newStruct = (cali *)malloc(sizeof(cali));
	      

	      mostrarListaStudiantAProfesor(apuntador2);
	      
	      if(newStruct != NULL)   // ingresa aqui, en caso de que la creacion dinamica de memoria se exitosa
	      {
		     printw("\n\nNumero de cedula: ");
		     scanw("%s", newStruct->Ccdula);

		     while(!buscarCedula(newStruct->Ccdula, apuntador2))
		     {		     
			    printw("\n\nDato incorrecto!!...¡intente nuevamente!\n\n");
			    printw("Numero de cedula: ");
			    scanw("%s", newStruct->Ccdula);
		     } 

		     numnotas= (apuntadorAux3->apt_notasmaterias)->num_notas; // asignamos a esta variable la cantidad de notas

		     newStruct-> notas = (char **) malloc (numnotas * sizeof(char *));                    

		     for(k=0; k < numnotas ; ++k )	
		     {
			    (newStruct-> notas)[k] = (char *) malloc( 7 * sizeof(char) );     
			    strcpy( ((newStruct-> notas)[k]), "NI" );	
		     }     
			    
		    k=0;
		    do      
		     {
			    printw("\n\nIngrese Nota%d: ", k+1);     
			    scanw("%s", (newStruct-> notas)[k]); 			    
			    if(k<numnotas){
				   printw("\n\nDigite un tecla diferente de \"s\" para ingresar otra nota...");	
				   opc = getch();			   
			    }
			    ++k;
			    //if(opc = 's')
				//   break;      		        		     
		     }
		     while( (k<numnotas) && opc != 's');				 
		     
		     if( apuntadorAux3 -> apt_calificaciones == NULL)
		     {
			    apuntadorAux3 -> apt_calificaciones = newStruct;
		     }
		     else
		     {
			    apuntadorAux = apuntadorAux3 -> apt_calificaciones;
			    while( apuntadorAux->sgt != NULL)
				   apuntadorAux = apuntadorAux->sgt;
			    apuntadorAux->sgt = newStruct;
		     }
	      }	
	      printw("\n\nDigite un tecla diferente de \"q\" para ingresar las notas..."); 
	      opc = getch();
        }
        while(opc != 'q');

       return apuntador3;
       
}


int buscarCedula(char *cedula, usua *apuntador) // dice si un numero de cedula ingresado por el usuario esta en la base de datos(usuaPRUEBA)
{
	int sw=0;

	usua *apuntadorAuxiliar;   
	apuntadorAuxiliar = apuntador; //variable global  // hay que utilizar un apondor a _nodo auxiliar para que no modifiquemos la el apuntador que apunta a la cabeza...
		
	for(  ; apuntadorAuxiliar != NULL;  apuntadorAuxiliar = apuntadorAuxiliar -> sig ){
		if( strcmp(cedula, apuntadorAuxiliar-> cedula_usua)==0 ){
			 sw = 1;   
			 break;	
		}
	}

        return !sw ? FALSE:TRUE;
}


void mostrarListaStudiantAProfesor(usua *apuntador)  // imprime en pantalla la lista de usuarios
{
	usua * apuntadorAux;
	int k=1, sw=0;
	apuntadorAux = apuntador;
	
	printw("\n\n    %-20s Cedula\n", "Nombre" ); 
        refresh(); 
	 
	while(apuntadorAux != NULL)
	{
		printw("%d.  %-20s %s\n", k ,apuntadorAux->nombre_usua, apuntadorAux->cedula_usua);		
		apuntadorAux = apuntadorAux -> sig;   
		  
		++k;
		   sw=1; 
	}
	refresh();
	
	if(!sw)
	    printw("\n    ¡Lista vaciá!\n");
	putchar('\n');  
	refresh();  
}

//fun.c other functions - MENUS

void pause(void)  // funcion que me permite hacer pausas en la ejecucion del programa...
{
	printw("\n\nPresione cualquier tecla para continuar..."); getch();
	erase();		    
}

//**********Menu principal************//
char Menu_principal(void)
{	
	char opc;  
          printw("Menu_principal");
	move(4,7); printw("Bienvenidos a Mini-mares (Menu Principal). ");
	move(6,4); printw("1. Crear una nueva cuenta. ");
	move(7,4); printw("2. Ingresar a su cuenta. ");	
	move(8,4); printw("3. Salir de Mini-mares");
          move(10,7); printw("Opcion: ");
	refresh();
	//scanf("%c", &opc);			
	opc =getch();  // getch();
	return opc;
}


//*********Menu Estudiante*********//
char Rol_student(void)
{
	char opc;
	do        //****Valida que el numero ingresado si este dentro de las opciones****/
	{
	        printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Estudiante");
		move(4,7); printw("Menu de Opciones Para Estudiante. ");			
		move(6,4); printw("1. Consultar notas.\n");
		move(7,4); printw("2. Volver a menu principal.\n");
		move(9,7); printw("Opcion: ");	
		
		opc = getch();
		if( (opc!='1') && (opc!='2') )	
		{	erase();
			move(4,4); printw("Opcion no validad.");
			move(7,4); pause();
			erase();						
		}
	  	refresh();	
	}
	while ( (opc!='1') && (opc!='2') );
	return opc;
}

//*********Menu Profesor*********//
char Rol_teacher(void)
{
	char opc;
        printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Profesor");
	move(4,7); printw("Menu de Opciones Para Profesor. ");			
	move(6,4); printw("1. Gestionar notas.\n");
	move(7,4); printw("2. Ver lista de clase.\n");
	move(8,4); printw("3. Volver a menu principal.\n");
	move(10,7); printw("Opcion: ");	
	refresh();
	opc = getch();
	return opc;
}

//*********Menu Secundario Profesor*********//
char Rol_second_teacher(void)
{
	char opc;
	do        
	{	
	        printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Profesor/Menu_Secundario_Profesor/");
		move(4,7); printw("Opciones Para Profesores. ");						
		move(6,4); printw("1. Definir notas.\n");
		move(7,4); printw("2. Ingresar notas.\n");
		move(8,4); printw("3. Ver notas.\n");
		move(9,4); printw("4. <------\n");
		move(11,7); printw("Opcion: ");	
		
		opc = getch();
		if( (opc!='1') && (opc!='2') && (opc!='3') && (opc!='4') )	
		{	erase();
			move(4,4); printw("Opcion no validad.");
			move(7,4); pause();
			erase();						
		}
	  	refresh();	
	}
	while ( (opc!='1') && (opc!='2') && (opc!='3') && (opc!='4') );
	return opc;
}

//*********Menu Administrador*********// 
char Rol_Administrator(void)
{
	char opc;

        printw("Menu_principal/Ingresar_a_su_cuenta/Menu_Administrador");     
        move(4,7); printw("Menu de Opciones Para Adminiestrador ");						
        move(6,4); printw("1. Guardar datos del sistema.\n");
        move(7,4); printw("2. Cargar datos del sistema.\n");
        move(8,4); printw("3. Gestionar usuarios ");		
        move(9,4); printw("4. Gestionar materias del semestre.\n");
        move(10,4); printw("5. Volver a menu principal.\n");
        move(12,7); printw("Opcion: ");	       
        opc = getch();
        refresh();	
		
	return opc;
}
