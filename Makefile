TARGET = Mandelbulb.exe
SRC_FILES = main.cpp Mandelbulb.cpp Cube.cpp DebugRenderer.cpp

OBJECTS = $(SRC_FILES:.cpp=.o)

INCLUDE_PATH = -I"C:\mingw64\include"

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lglu32
LIB_PATH =

CXX = g++

all: $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CXX) -o $@ $^ $(LIB_PATH) $(LIBS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(INCLUDE_PATH)

clean:
	@$(RM) $(OBJECTS) $(TARGET)

run:
	@$(TARGET)

.PHONY: clean run

main.o: main.cpp Mandelbulb.o Cube.o DebugRenderer.o
Mandelbulb.o: Mandelbulb.cpp
Cube.o: Cube.cpp
DebugRenderer.o: DebugRenderer.cpp