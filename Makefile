vector_length: vector_length.o Vector3D.o
	g++ -o vector_length vector_length.o Vector3D.o
vector_length.o: vector_length.cc
	g++ -c -o vector_length.o -std=c++11 vector_length.cc
