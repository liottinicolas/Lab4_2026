CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./include
SRCDIR = src
OBJDIR = obj
TARGET = lab4

# Comando de Valgrind
#VALGRIND = valgrind --leak-check=full --show-leak-kinds=definite
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

# Encontrar todos los archivos .cpp en src/
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Regla principal
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Regla para compilar archivos .cpp a .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos compilados
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET)

# **Analizar con Valgrind**
check: $(TARGET)
	$(VALGRIND) ./$(TARGET)

# Regla para mostrar ayuda
help:
	@echo "Comandos disponibles:"
	@echo "  make        - Compilar el proyecto"
	@echo "  make run    - Compilar y ejecutar"
	@echo "  make check  - Ejecutar con Valgrind"
	@echo "  make clean  - Limpiar archivos compilados"
	@echo "  make help   - Mostrar esta ayuda"

.PHONY: clean run check help
