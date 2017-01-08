CXX = g++
CXXFLAGS = -std=c++11 -Wall

output: main.o view.o controller.o validator.o
	mkdir bin
	$(CXX) $(CXXFLAGS) main.o view.o controller.o validator.o -o bin/utadl
	rm *.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

view.o: view.h
	$(CXX) $(CXXFLAGS) -c view.cpp

controller.o: controller.h
	$(CXX) $(CXXFLAGS) -c controller.cpp

validator.o: validator.h
	$(CXX) $(CXXFLAGS) -c validator.cpp
	
clean:
	rm *.o 

delete:
	rm utadl

run:
	./bin/utadl -h

install:
	cp bin/utadl /usr/local/bin