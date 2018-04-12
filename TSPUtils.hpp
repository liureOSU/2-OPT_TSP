#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <chrono>

using namespace std;

struct vertex {
	int vertNumber;
	bool visited = false;
};

class TSPUtils {
public:
	static vector<vector<int>> fileInput(string);
	static void outputRows(vector<vector<int>>);
	static void outputRows(int * outputArray, int finalDistance, string fileName, int size);
	static int** distance(int**, int arrSize);
	static vertex* setStructs(int);
	static int* greedyTSP(vertex*, int, int**, int&);

	static int* twoOptTSP(int *, int, int&, int**, int);
	static int* twoOptSwitch(int * presorted, int size, int nodeX, int nodeY);
	static int newDistance(int *testSort, int size, int** distances);
private:

};