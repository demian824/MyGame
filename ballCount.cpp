#include <cstdlib>
#include <ctime>
#include <string>
#include "ballCount.h"


using namespace std;

BallCount::BallCount() {
	srand(std::time(nullptr));
	m_inputNumber.reserve(MAXCOUNT);
	m_threeRandomNumber.reserve(MAXCOUNT);
	m_ballCount.reserve(MAXCOUNT);

	size_t randomNum = 0;

	for (size_t i = 0; i < MAXCOUNT; i++) {
		m_ballCount.push_back(0);
		m_inputNumber.push_back(0);
		randomNum = (rand() % 8) + 1;
		m_threeRandomNumber.push_back(randomNum);
		if (i > 0) {
			while (m_threeRandomNumber[i] == m_threeRandomNumber[i - 1]) {
				m_threeRandomNumber[i] = (rand() % 8) + 1;
			}
		}
		
	}
	
}

void BallCount::run() {
	bool isOut = false;
	string numberName;
	static size_t NumberCount = 1;
	while (!isOut) {
		if (NumberCount > 1) cout << endl;
		cout << "Number Count: " << NumberCount++ << endl;
		cout << "Please Input 3 Numbers ( 1 to 9 )" << endl << endl;
		for (size_t i = 0; i < MAXCOUNT; i++) {
			if ((i + 1) == 1)
				numberName = "First Input Number : ";
			else if ((i + 1) == 2)
				numberName = "Second Input Number: ";
			else
				numberName = "Thrid Input Number : ";
			cout << numberName;
			cin >> m_inputNumber[i];
			while(m_inputNumber[i] <= 0 || m_inputNumber[i] > 9){
				cout << endl << "************************************"<< endl;
				cout << "Please input Number from '1' to '9'." << endl;
				cout << numberName;
				cin >> m_inputNumber[i];
				cout << "************************************" << endl;
			}
		}

		isOut = checkBallCount();
		printBallCount();
		resetBallCount();
	}


}

bool BallCount::checkBallCount() {
	for (size_t i = 0; i < MAXCOUNT; i++) {
		for (size_t j = 0; j < MAXCOUNT; j++){			
			if (m_threeRandomNumber[j] == m_inputNumber[i])
				if (i == j)	m_ballCount[e_strike]++;
				else m_ballCount[e_ball]++;
		}		
	}

	m_ballCount[e_out] = 3 - (m_ballCount[e_strike] + m_ballCount[e_ball]);

	bool isPass = false;

	if (m_ballCount[e_strike] == 3)
		isPass = true;

	return isPass;
}

void BallCount::resetBallCount() {
	for (auto& e : m_ballCount)
		e = 0;
}

void BallCount::printBallCount() {
	cout << endl << "====================================" << endl;
	cout << "Your Number: " << endl;
	size_t num = 1;
	for (auto& e : m_inputNumber)
		cout << num++ << ". " << e << "\t";
	cout << endl << "====================================" << endl;
	for (size_t i = 0; i < m_ballCount.size(); i++) {
		if (i == SBO::e_strike)
			cout << "Strike: ";
		else if (i == SBO::e_ball)
			cout << "Ball  : ";
		else
			cout << "Out   : ";
		cout << m_ballCount[i] << "\t";
	}
	cout << endl << "====================================" << endl << endl;

	if (m_ballCount[e_strike] == 3) {
		cout << "Congratuation! You got it!" << endl;
	}
}