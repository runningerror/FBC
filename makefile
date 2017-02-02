CC = g++
LD = g++

BIN_DIR = bin
INCLUDE_DIR = include
LIB_DIR = libs
SRC_DIR = src

INCLUDES = 	$(INCLUDE_DIR) \
			$(shell pkg-config --cflags-only-I sdl2) \
			$(shell pkg-config --cflags-only-I glew)
			
DEFINES = -DDEBUG=0
CFLAGS =	$(INCLUDES) \
			$(DEFINES) \
			$(shell pkg-config --cflags-only-other sdl2) \
			-c
			
LIBS = 	$(shell pkg-config --libs sdl2) \
		$(shell pkg-config --libs glew)
		
LDFLAGS = 	-L$(LIB_DIR) \
			$(LIBS)
			
OBJECTS = $(BIN_DIR)/main.o
OUTPUT = FBC

all: $(OBJECTS)
	$(LD) $^ -o$(OUTPUT) $(LDFLAGS)
	
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cxx
	$(CC) $< -o$@ $(CFLAGS)