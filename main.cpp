#include<iostream>
#include<vector>
#include<iomanip>

const int NUM_ROWS = 2;
const int NUM_PITS = 6;

//Initialize the board with via vectors and its most basic functions
class board {
private:
	std::vector < std::vector<std::pair<int, bool>> > pits;

public:
	board(int numSeedsPerPit) {
		pits.assign(NUM_ROWS, std::vector<std::pair<int, bool>>(NUM_PITS, { numSeedsPerPit, false }));
	}
	int getSeeds(int row, int pit) {
		return pits[row][pit].first;
	}
	bool isBigSeed(int row, int pit) {
		return pits[row][pit].second;
	}
	void setSeeds(int row, int pit, int numSeeds) {
		pits[row][pit].first = numSeeds;
		pits[row][pit].second = false; //Dont set a big seed?
	}
	void setBigSeed(int row, int pit) {
		pits[row][pit].second = true; //Set a big seed?
	}
	void display() {
		for (int pit = 0; pit < NUM_PITS; ++pit) {
			std::cout << "|";
			if (pits[1][pit].second) {
				std::cout << "B|";
			}
			else {
				std::cout << pits[1][pit].first;
				std::cout << "|";
			}
		}
		std::cout << std::endl << std::setw(4);
		for (int pit = NUM_PITS - 1; pit >= 0; --pit) {
			std::cout << "|";
			if (pits[0][pit].second) {
				std::cout << "B|";
			}
			else {
				std::cout << pits[0][pit].first;
				std::cout << "|";
			}
		}
		std::cout << std::endl;
	}
};
	// Testing, currently only shows how the board can look like
int main() {
	board board(5);
	board.setBigSeed(0, 0);
	board.setBigSeed(1, 0);
	//int x, y;
	//std::cin >> x;
	//std::cin >> y;
	//int seedsInPit = board.getSeeds(x, y);
	//std::cout << "Seeds in pos (" << x << "," << y << ") is: " << seedsInPit << std::endl;

	std::cout << "board looks like:" << std::endl;
	board.display();



	return 0;
}