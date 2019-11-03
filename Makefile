CC = g++
CFLAGS = -Wall -std=c++1z -w
DEPS = ls.h global_def.h
OBJ = cursor_h.o ls.o status_user_mode.o status_command_mode.o copy_filedir.o remove_filedir.o search_filedir.o search_print.o snapshot.o module1.o
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

module1: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	
clean:
	rm -rf *o module1
