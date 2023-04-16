#SRC=Simulation.cpp Environment.cpp Agent.cpp Lumberjack.cpp Carpenter.cpp
#EXE=ForestEcosystem
SRC=Environment.cpp tests.cpp Agent.cpp Lumberjack.cpp Carpenter.cpp
EXE=TestForestEcosystem
CXX=g++
CXXFLAGS+=-Wall -Wextra -MMD -g
LDFLAGS= #-lSDL

OBJ=$(addprefix build/,$(SRC:.cpp=.o))
DEP=$(addprefix build/,$(SRC:.cpp=.d))

all: $(OBJ)
	$(CXX) -o $(EXE) $^ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch

-include $(DEP)
