obj_dir=obj/
bin_dir=bin/
src_dir=src/
CC=gcc
CFLAGS=-Wall -g -I/usr/include/mysql
LDFLAGS=`mysql_config --cflags --libs` -g
EXEC=$(bin_dir)FARM.exe

all: $(EXEC)

$(bin_dir)FARM.exe: $(obj_dir)database.o
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
