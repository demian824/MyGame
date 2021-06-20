#include <iostream>
#include <vector>

const size_t MAXCOUNT = 3;

enum SBO {
	e_strike,
	e_ball,
	e_out
};

class BallCount {
	std::vector<size_t> m_ballCount;
	std::vector<size_t> m_threeRandomNumber;
	std::vector<size_t> m_inputNumber;

	void resetBallCount();

public:
	BallCount();
	bool checkBallCount();
	void run();
	void printBallCount();

};
