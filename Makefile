CC = gcc

CFLAGS = -lSDL2_image -lSDL2_image `sdl2-config --cflags --libs` -pthread

all: collider

collider: main.o tree.o Renderer.o box.o
	$(CC) main.o tree.o Renderer.o box.o -o collider $(CFLAGS)

main.o: main.c
	$(CC) main.c $(CFLAGS) -c

tree.o: tree.c
	$(CC) tree.c $(CFLAGS) -c

Renderer.o: Renderer.c
	$(CC) Renderer.c $(CFLAGS) -c
	
box.o: box.c
	$(CC) box.c $(CFLAGS) -c


clean:
	rm -rf *o collider