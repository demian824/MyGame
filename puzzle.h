#pragma once
#include <vector>

const size_t startIndex = 24;

class Puzzle {
	std::vector<size_t> m_randomNumber;
	size_t m_curIndex = startIndex;
	
	void suffleNumber();
	void printTitle() const;
	void printFinish() const;
public:
	Puzzle();
	bool checkSortedNumber();
	void runGame();
	void printPuzzle() const;

};