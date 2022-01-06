CC = g++  -std=c++11 
LIBS = -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio
TARGET = main
 
.PHONY: clean all default
 
default: $(TARGET)
all: default
 
OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard headers/*.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)
 
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@


.PHONY : clean
clean :
	rm -rf *.o 
