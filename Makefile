sample: simdb.hpp sample.cpp
	g++ sample.cpp -std=c++11 -g -O3 -o sample
clean:
	rm  -f sample