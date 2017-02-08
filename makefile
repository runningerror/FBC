CC = g++
LD = g++

BIN_DIR = bin
INCLUDE_DIR = include
LIB_DIR = libs
SRC_DIR = src

INCLUDES = 	-I$(INCLUDE_DIR) \
			$(shell pkg-config --cflags-only-I sdl2) \
			$(shell pkg-config --cflags-only-I glew)

DEFINES = -DDEBUG=0
CFLAGS =	$(INCLUDES) \
			$(DEFINES) \
			$(shell pkg-config --cflags-only-other sdl2) \
			-c \
			-std=c++11 \
			-Wall

LIBS = 	$(shell pkg-config --libs sdl2) \
		$(shell pkg-config --libs glew)

LDFLAGS = 	-L$(LIB_DIR) \
			$(LIBS)

OBJECTS = $(BIN_DIR)/main.o \
					$(BIN_DIR)/Window.o \
					$(BIN_DIR)/Exception.o \
					$(BIN_DIR)/WindowCreInfo.o \
					$(BIN_DIR)/CreationFailedException.o \
					$(BIN_DIR)/NotInitializedException.o

OUTPUT = FBC

all: $(OBJECTS)
	$(LD) $^ -o$(OUTPUT) $(LDFLAGS)

clean:
	-@rm $(OUTPUT)*
	-@rm $(BIN_DIR)/*

rebuild: clean all

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cxx
	$(CC) $< -o$@ $(CFLAGS)
