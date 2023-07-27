//struct.h

struct user {
	char name[30];
	char cedula[10];
	char user[10];
	char password[8];
	struct user * ptr;
}

struct materia {
	char name[30];
	char creditos;
	char nameteach[30];
	struct materia * ptr;
}
