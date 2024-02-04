#include<iostream>
#include<vector>
#include<iomanip>

const int NUM_ROWS = 2;
const int NUM_PITS = 6;

//Initialize the board with via vectors and its most basic functions
class board {
private:
	std::vector < std::vector<std::pair<int, bool>> > pits;
	int currentPlayer;

public:
	board(int numSeedsPerPit) {
		pits.assign(NUM_ROWS, std::vector<std::pair<int, bool>>(NUM_PITS, { numSeedsPerPit, false }));
		currentPlayer = 0;
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
	void distributeSeeds(int row, int pit) {
		int seedsOnHand = 0;
		int seeds = pits[row][pit].first;
		std::string side;

		if (currentPlayer == 0) {
			seedsOnHand = seeds;
			pits[0][pit].first = 0;
			if (side == "left") {
				for (int i = pit + 1; i < NUM_PITS; ++i) {
					++pits[0][i].first;
					--seedsOnHand;
					if (seedsOnHand == 0) {
						if (pits[0][i + 1].first > 0) {
							seedsOnHand = pits[0][i + 1].first;
							pits[0][i + 1].first = 0;
							i = i + 2;
							continue;
						}
						else {break;}
					}
				}
				while (seedsOnHand > 0) {
					for (int i = 0; i < NUM_PITS; ++i) {
						++pits[1][i].first;
						--seedsOnHand;
						if (seedsOnHand == 0) {
							if (pits[1][i + 1].first > 0) {
								seedsOnHand = pits[1][i - 1].first;
								pits[1][i + 1].first = 0;
								i = i + 2;
								continue;
							}
							else {break;}
						}
					}
					for (int i = 0; i < NUM_PITS; ++i) {
						++pits[0][i].first;
						--seedsOnHand;
						if (seedsOnHand == 0) {
							if (pits[0][i + 1].first > 0) {
								seedsOnHand = pits[0][i + 1].first;
								pits[0][i + 1].first = 0;
								i = i + 2;
								continue;
							}
							else {break;}
						}
					}
				}
			}
			if (side == "right") {
				for (int i = pit - 1; i >= 0; --i) {
					++pits[0][i].first;
					--seedsOnHand;
					if (seedsOnHand == 0) {
						if (pits[1][i + 1].first > 0) {
							seedsOnHand = pits[0][i + 1].first;
							pits[1][i + 1].first = 0;
							i = i + 2;
							continue;
						}
						else {break;}
					}
				}
				while (seedsOnHand > 0) {
					for (int i = NUM_PITS - 1; i >= 0; --i) {
						++pits[1][i].first;
						--seedsOnHand;
						if (seedsOnHand == 0) {
							if (pits[1][i + 1].first > 0) {
								seedsOnHand = pits[0][i + 1].first;
								pits[1][i + 1].first = 0;
								i = i + 2;
								continue;
							}
							else {break;}
						}
					}
					for (int i = NUM_PITS - 1; i >= 0; --i) {
						++pits[0][i].first;
						--seedsOnHand;
						if (seedsOnHand == 0) {
							if (pits[1][i + 1].first > 0) {
								seedsOnHand = pits[0][i + 1].first;
								pits[1][i + 1].first = 0;
								i = i + 2;
								continue;
							}
							else {break;}
						}
					}
				}
			}
		}
		if (currentPlayer == 1) {
			seedsOnHand = seeds;
			pits[1][pit].first = 0;
			if (side == "left") {
				for (int i = pit + 1; i < NUM_PITS; ++i) {
					++pits[1][i].first;
					--seedsOnHand;
					if (seedsOnHand == 0) {
						if (pits[1][i + 1].first > 0) {
							seedsOnHand = pits[0][i + 1].first;
							pits[1][i + 1].first = 0;
							i = i + 2;
							continue;
						}
						else {break;}
					}
				}
				while (seedsOnHand > 0) {
					for (int i = 0; i < NUM_PITS; ++i) {
						++pits[0][i].first;
						--seedsOnHand;
						if (seedsOnHand == 0) {
							if (pits[0][i + 1].first > 0) {
								seedsOnHand = pits[1][i + 1].first;
								pits[0][i + 1].first = 0;
								i = i + 2;
								continue;
							}
							else {break;}
						}
					}
					for (int i = 0; i < NUM_PITS; ++i) {
						++pits[1][i].first;
						--seedsOnHand;
						if (seedsOnHand == 0) {
							if (pits[1][i + 1].first > 0) {
								seedsOnHand = pits[0][i + 1].first;
								pits[1][i + 1].first = 0;
								i = i + 2;
								continue;
							}
							else {break;}
						}
					}
				}
			}
			if (side == "right") {
				for (int i = pit - 1; i >= 0; --i) {
					++pits[1][i].first;
					--seedsOnHand;
					if (seedsOnHand == 0) {
						if (pits[1][i - 1].first > 0) {
							seedsOnHand = pits[0][i - 1].first;
							pits[1][i - 1].first = 0;
							i = i - 2;
							continue;
						}
						else {break;}
					}
				}
			}
			while (seedsOnHand > 0) {
				for (int i = NUM_PITS - 1; i >= 0; --i) {
					++pits[0][i].first;
					--seedsOnHand;
					if (seedsOnHand == 0) {
						if (pits[0][i - 1].first > 0) {
							seedsOnHand = pits[0][i - 1].first;
							pits[0][i - 1].first = 0;
							i = i - 2;
							continue;
						}
						else {break;}
					}
				}
				for (int i = NUM_PITS - 1; i >= 0; --i) {
					++pits[1][i].first;
					--seedsOnHand;
					if (seedsOnHand == 0) {
						if (pits[1][i - 1].first > 0) {
							seedsOnHand = pits[0][i - 1].first;
							pits[1][i - 1].first = 0;
							i = i - 2;
							continue;
						}
						else {break;}
					}
				}
			}
		}
		currentPlayer = (currentPlayer + 1) % 2;
	}
	void captureSeeds(int row, int pit) {
		if (currentPlayer == 0) {
			if (pits[0][pit].first == 1 && pits[1][pit].first > 0) {
				pits[0][pit].first = 0;
				pits[1][pit].first = 0;
				pits[0][NUM_PITS - 1].first += pits[1][NUM_PITS - 1].first;
				pits[1][NUM_PITS - 1].first = 0;
			}
		}
		if (currentPlayer == 1) {
			if (pits[1][pit].first == 1 && pits[0][pit].first > 0) {
				pits[1][pit].first = 0;
				pits[0][pit].first = 0;
				pits[1][NUM_PITS - 1].first += pits[0][NUM_PITS - 1].first;
				pits[0][NUM_PITS - 1].first = 0;
			}
		}
	}

};
	// Testing, currently only shows how the board can look like
int main() {
	board board(5);
	board.setBigSeed(0, 0);
	board.setBigSeed(1, 0);
	

	std::cout << "board looks like:" << std::endl;
	board.display();



	return 0;
}