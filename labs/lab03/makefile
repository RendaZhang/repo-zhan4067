CXXFLAGS = -Wall -c -std=c++11
CXX = g++
LDFLAGS = -o
OBJS = main.o Duck.o DecoyDuck.o MallardDuck.o MuteQuack.o Quack.o QuackBehavior.o RubberDuck.o Squeak.o

all: $(OBJS)
	$(CXX) $(LDFLAGS) ducks $(OBJS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

Duck.o: Duck.h Duck.cpp
	$(CXX) $(CXXFLAGS) Duck.cpp

DecoyDuck.o: DecoyDuck.h DecoyDuck.cpp
	$(CXX) $(CXXFLAGS) DecoyDuck.cpp

MallardDuck: MallardDuck.h MallardDuck.cpp
	$(CXX) $(CXXFLAGS) MallardDuck.cpp

MuteQuack.o: MuteQuack.h MuteQuack.cpp
	$(CXX) $(CXXFLAGS) MuteQuack.cpp

Quack.o: Quack.h Quack.cpp
	$(CXX) $(CXXFLAGS) Quack.cpp

QuackBehavior.o: QuackBehavior.h QuackBehavior.cpp
	$(CXX) $(CXXFLAGS) QuackBehavior.cpp

RubberDuck.o: RubberDuck.h RubberDuck.cpp
	$(CXX) $(CXXFLAGS) RubberDuck.cpp

Squeak.o: Squeak.h Squeak.cpp
	$(CXX) $(CXXFLAGS) Squeak.cpp

clean:
	rm $(OBJS) ducks
