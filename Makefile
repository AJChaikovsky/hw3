CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

# Object files needed for the logic simulator.
OBJS := logicsim.o circuit.o wire.o gate.o

# The main target: the logic simulator executable.
logicsim: $(OBJS)
	$(CXX) $(CXXFLAGS) -o logicsim $(OBJS)

# Compile logicsim.cpp; it should include circuit.h and others.
logicsim.o: logicsim.cpp circuit.h wire.h gate.h event.h heap.h
	$(CXX) $(CXXFLAGS) -c logicsim.cpp

# Compile circuit.cpp; depends on circuit.h and other headers.
circuit.o: circuit.cpp circuit.h wire.h gate.h event.h heap.h
	$(CXX) $(CXXFLAGS) -c circuit.cpp

# Compile wire.cpp.
wire.o: wire.cpp wire.h
	$(CXX) $(CXXFLAGS) -c wire.cpp

# Compile gate.cpp.
gate.o: gate.cpp gate.h wire.h event.h
	$(CXX) $(CXXFLAGS) -c gate.cpp

clean:
	rm -f $(OBJS) logicsim *~

.PHONY: clean
