main: sort matrix

sort: sorting_algorithms.cpp sorting/merge_sort.hpp sorting/quick_sort.hpp sorting/select_sort.hpp
	g++ -Wall -o sortmain sorting_algorithms.cpp -g

matrix: matrix_algorithms.cpp matrix/cubic_optimized.hpp matrix/cubic_standard.hpp matrix/strassen.hpp
	g++ -Wall -o matrixmain matrix_algorithms.cpp -g