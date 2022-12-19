#shamelessly stolen makefile z IJC slidu
CFLAGS = -Wall
CXXFLAGS = -g
PROGS = day1

all: $(PROGS)

day1: day1.c
	$(CC) $(CFLAGS) $(CXXFLAGS) -o $@ $<

clean:
	rm -rf $(PROGS)

run:
	./$(PROGS)