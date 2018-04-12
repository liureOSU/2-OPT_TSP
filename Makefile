CXX = g++
CXXFLAGS = -std=c++11
OBJS = TSPMain.o TSPUtils.o

SRCS = TSPMain.cpp TSPUtils.cpp

HEADERS = TSPUtils.hpp

tsp: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o tsp
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o tsp