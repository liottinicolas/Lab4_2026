CC = g++
CFLAGS = -Iinclude -Wall -Wextra -std=c++11

# Busca todos los archivos .cpp en la carpeta src
SRCS = $(wildcard src/*.cpp)

# Convierte las rutas de .cpp a .o (ej. src/main.cpp -> src/main.o)
OBJS = $(SRCS:.cpp=.o)

# Nombre del archivo ejecutable de salida
MAIN = principal.exe

.PHONY: all clean

# Regla por defecto para compilar todo
all: $(MAIN)
	@echo ====================================
	@echo   Programa compilado con éxito.
	@echo   Ejecútalo con: ./principal.exe
	@echo ====================================

# Enlaza los objetos (.o) para crear el ejecutable
$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(MAIN)

# Compila cada archivo fuente .cpp a su correspondiente archivo objeto .o
src/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Limpia los archivos temporales de compilación y el ejecutable
clean:
	rm -f src/*.o $(MAIN)
