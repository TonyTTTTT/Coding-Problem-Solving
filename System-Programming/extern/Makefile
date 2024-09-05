a: a.o b.o
	gcc $^ -o $@

a.o: a.c b.h
	gcc $< -c -o $@

b.o: b.c b.h
	gcc $< -c -o $@