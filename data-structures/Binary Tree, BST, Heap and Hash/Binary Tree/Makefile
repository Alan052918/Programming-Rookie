binary_tree: main_bt.o binary_tree.o
	clang++ -o binary_tree main_bt.o binary_tree.o

main_bt.o: main_bt.cpp
	clang++ -o main_bt.o main_bt.cpp

binary_tree.o: binary_tree.cpp
	clang++ -o binary_tree.o binary_tree.cpp

.PHONY: clean
clean:
	rm *.o binary_tree
