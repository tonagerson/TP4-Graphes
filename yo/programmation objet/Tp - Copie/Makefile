# Nom de l'exécutable
TARGET = testReseauAerien

# Compilateur et options
CXX = g++
CXXFLAGS = -Wall -std=c++17 -g `wx-config --cxxflags`
LDLIBS = `wx-config --libs`

# Fichiers sources
SRCS = gui.cpp Connexion.cpp Aeroport.cpp 

# Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut
all: $(TARGET)

# Comment construire l'exécutable (AJOUT DE $(LDLIBS) A LA FIN ICI)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

# Comment compiler un .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJS) $(TARGET)