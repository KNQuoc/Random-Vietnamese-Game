#include<iostream>
#include<vector>
#include<iomanip>

const int NUM_ROWS = 2;
const int NUM_PITS = 5;

//Initialize the board with via vectors and its most basic functions
class board {
private:
	std::vector<std::vector<int>> pits;

public:
	board(int seedsPerPit) {
		pits.assign(NUM_ROWS, std::vector<int>(NUM_PITS, seedsPerPit));
	}
	
	void display(){
		for (int pit = 0; pit < NUM_PITS; ++pit) {
			std::cout << "|" << pits[0][pit] << "|";
		}
		std::cout << std::endl;
		std::cout << std::setw(15) << std::setfill(static_cast<char>(196)) << static_cast<char>(196) << std::endl;
		for (int pit = NUM_PITS - 1; pit >= 0; --pit) {
			std::cout << "|" << pits[1][pit] << "|";
		}
		std::cout << std::endl;
	}
	int getSeeds(int row, int pit){
		return pits[row][pit];
	}
	void setSeeds(int row, int pit, int numSeeds) {
		pits[row][pit] = numSeeds;
	}
};

// Testing, currently only shows how the board can look like
int main() {
	board board(5);
	int x, y;
	//std::cin >> x;
	//std::cin >> y;
	//int seedsInPit = board.getSeeds(x, y);
	//std::cout << "Seeds in pos (" << x << "," << y << ") is: " << seedsInPit << std::endl;

	std::cout << "board looks like:" << std::endl;
	board.display();


	
	return 0;
}