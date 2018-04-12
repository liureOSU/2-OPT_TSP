#include "TSPUtils.hpp"
#include <chrono>

int main(int argc, char** argv) {
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	cout << "Start." << endl;

	try {
		TSPUtils newInst;

		// Change this line to process a different input file.
		vector<vector<int>> testVect = newInst.fileInput(argv[1]);
		cout << "Added to vectors." << endl;
		int sz = testVect.size();

		// Place vector into array.
		int ** testArray = new int*[sz];
		for (int i = 0; i < sz; i++) {
			testArray[i] = new int[3];
		}

		for (int i = 0; i < testVect.size(); i++) {
			for (int j = 0; j < testVect.at(i).size(); j++) {
				testArray[i][j] = testVect[i][j];
			}
		}

		// Create matrix of distances and perform nearest meighbor algorithm.
		int ** distanceMatrix = TSPUtils::distance(testArray, sz);
		vertex * vertArray = TSPUtils::setStructs(sz);
		int totalDistance;
		int * greedyResults = TSPUtils::greedyTSP(vertArray, sz, distanceMatrix, totalDistance);

		// Uncomment these lines to output greedy to file.
		//string outputName = std::string(argv[1]) + ".tour";
		//TSPUtils::outputRows(greedyResults, totalDistance, outputName, sz);


		// Set time limit and perform 2-OPT on Greedy result.
		std::chrono::steady_clock::time_point optStart = std::chrono::steady_clock::now();
		int compTime = 180 * 1000;
		int timeRemaining = compTime - std::chrono::duration_cast<std::chrono::milliseconds>(optStart - begin).count();
		int * optimizedRoute = TSPUtils::twoOptTSP(greedyResults, sz, totalDistance, distanceMatrix, timeRemaining);

		string outputName = std::string(argv[1]) + ".tour";
		TSPUtils::outputRows(optimizedRoute, totalDistance, outputName, sz);
	}

	catch (const std::exception& e) { // caught by reference to base
		std::cout << " a standard exception was caught, with message '"
			<< e.what() << "'\n";
	}

	// Display time elapsed since start.
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "\n\nTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() / 1000 << " s." << std::endl;
	return 0;
}