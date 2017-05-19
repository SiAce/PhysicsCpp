CXXFLAGS = -std=c++11
CC = g++

LIB = lorentz_vector.o vector_3d.o 
TARGET = test_lorentz_vector

all: $(TARGET)

test_lorentz_vector: test_lorentz_vector.o $(LIB)

.PHONY: clean

clean:
	rm -f $(TARGET) *.o *~
