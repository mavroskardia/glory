CFLAGS=-Wall -Werror -Wextra -g3 -O0 -DDEBUG

CC=g++ -std=c++11 $(CFLAGS)
INCLUDES=-I/usr/include/SDL2
REXE=glory
DEXE=dglory
OBJS=main.o app.o shader_manager.o
LIBS=-lSDL2 -lSDL2_image -lGL

$(DEXE): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CC) -c $< $(INCLUDES)

clean:
	rm -f $(REXE) $(DEXE) $(OBJS)

$(REXE): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

release: CFLAGS=-Wall -Werror -Wextra -DNDEBUG -O2
release: $(REXE)
