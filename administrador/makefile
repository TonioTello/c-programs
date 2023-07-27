#VPATH = source : include
vpath %.c source
vpath %.h include

objects = functions.o main.o

salida: $(objects)
	gcc $(objects) -o salida -g

menu.o: menu.c
	gcc -c $< -o $@ -I include

functions.o: functions.c
	gcc -c $< -o $@ -I include

main.o: main.c functions.c menu.c main.h struct.h
	gcc -c $< -o $@ -I include

clean:
	rm *.o salida
