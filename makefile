Lab05: main.o City.o UnorderedArray.o AvlTree.o Node.o
	g++ -g main.o City.o UnorderedArray.o AvlTree.o Node.o -o Lab05
main.o: main.cpp
	g++ -g -c main.cpp
City.o: City.cpp City.h
	g++ -g -c City.cpp
UnorderedArray.o: UnorderedArray.cpp UnorderedArray.h
	g++ -g -c UnorderedArray.cpp
AvlTree.o: AvlTree.cpp AvlTree.h
	g++ -g -c AvlTree.cpp
Node.o: Node.cpp Node.h
	g++ -g -c Node.cpp
