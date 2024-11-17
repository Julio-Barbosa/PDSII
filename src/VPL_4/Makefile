# Makefile

# Diretórios
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Arquivos objeto
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Compilador e flags
CXX = g++
CXXFLAGS = -I$(INCLUDE_DIR) -std=c++11 -Wall

# Executável
TARGET = vpl_execution

# Regra default
all: $(TARGET)

# Regra para linkar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Regra para compilar os arquivos fonte em objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)
