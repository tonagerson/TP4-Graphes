# Nom de l'exécutable
TARGET = testReseauAerien

# Compilateur et options
CXX = g++
CXXFLAGS = -Wall -std=c++17 -g

# Fichiers sources
SRCS = main.cpp Connexion.cpp Aeroport.cpp Graphe.cpp

# Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut
all: $(TARGET)

# Comment construire l'exécutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Comment compiler un .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJS) $(TARGET)