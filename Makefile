sort: sorting_algorithms.cpp sorting/default_sort.hpp sorting/merge_sort.hpp sorting/quick_sort.hpp sorting/select_sort.hpp
	g++ -Wall -o sortmain sorting_algorithms.cpp

matrix: matrix_algorithms.cpp 
	g++ -Wall -o matrixmain matrix_algorithms.cpp