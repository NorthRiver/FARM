obj_dir=obj/
bin_dir=bin/
src_dir=src/
CC=gcc
CFLAGS=-Wall -lSDL2_image -lSDL2  -g
LDFLAGS=`sdl2-config --cflags --libs` -lSDL2_ttf -lSDL2_gfx -g
EXEC=$(bin_dir)FARM.exe

all: $(EXEC)

$(bin_dir)FARM.exe: $(obj_dir)robot.o $(obj_dir)socket.o $(obj_dir)partie.o $(obj_dir)bebotte.o $(obj_dir)cJSON.o $(obj_dir)Sdl_init.o $(obj_dir)Sdl_fenetres.o $(obj_dir)Sdl_main.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(obj_dir)%.o: $(src_dir)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

doxygen:
	doxygen Doxyfile

clean:
	find . -type f | xargs -n 5 touch
	rm -f $(obj_dir)* $(bin_dir)*

start:
	./$(EXEC)

forceMaj:
	git pull && make clean && make && make start

maj:
	git pull && make && make start
