# MAKEFILE PARA C

# Las fuentes van a ser: *.c
# Utilizamos 'wildcard' que es el equivalente en bash del *
SOURCES := $(wildcard *.c)
OBJECTS := $(subst .c,.o,$(SOURCES))

ejecutable.exe: $(OBJECTS)
	gcc -o $@ $^		

%.o: %.c
	gcc -o $@ -c $^ -I.

info:
	$(info $(SOURCES))
	$(info $(OBJECTS))
