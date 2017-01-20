CXX = g++
CXXFLAGS = -std=c++11 -Wall

output: main.o view.o controller.o validator.o
	mkdir -p bin
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
	rm -r bin

run:
	./bin/utadl -h

install:
	cp bin/utadl /usr/local/bin
	cp man/*.1 /usr/local/man/man1

uninstall:
	rm /usr/local/man/man1/utadl_*
	rm /usr/local/bin/utadl


make test:
	@echo ""
	@echo "Testing node listing:"
	./bin/utadl -ln
	@echo ""
	@echo "Testing node listing with sudo:"
	sudo ./bin/utadl -ln
	@echo ""
	@echo "Opening man page, if this fails install the man pages:"
	./bin/utadl -g admin
