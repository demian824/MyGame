#include <conio.h>
#include <iostream>
#include <ctime>
#include"puzzle.h"

Puzzle::Puzzle() {
	m_randomNumber.reserve(25);
	srand(std::time(nullptr));

	for (size_t i = 0; i < startIndex; i++) {
		m_randomNumber.push_back(i + 1);
	}
	m_randomNumber.push_back(SIZE_MAX);

	suffleNumber();
}
void Puzzle::suffleNumber() {
	size_t idx1, idx2, temp;

	for (size_t i = 0; i < 100; i++) {
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		temp = m_randomNumber[idx1];
		m_randomNumber[idx1] = m_randomNumber[idx2];
		m_randomNumber[idx2] = temp;
	}
}

void Puzzle::runGame() {
	bool isDone = false;
	while (!isDone) {
		printPuzzle();
		char inputCh = _getch();

		switch (inputCh) {
		case'W':
		case'w':
			if (m_curIndex > 4) {
				m_randomNumber[m_curIndex] = m_randomNumber[m_curIndex - 5];
				m_randomNumber[m_curIndex - 5] = SIZE_MAX;
				m_curIndex -= 5;
			}
			break;
		case'S':
		case's':
			if (m_curIndex < 20) {
				m_randomNumber[m_curIndex] = m_randomNumber[m_curIndex + 5];
				m_randomNumber[m_curIndex + 5] = SIZE_MAX;
				m_curIndex += 5;
			}
			break;
		case'A':
		case'a':
			if ((m_curIndex % 5) != 0) {
				m_randomNumber[m_curIndex] = m_randomNumber[m_curIndex - 1];
				m_randomNumber[m_curIndex - 1] = SIZE_MAX;
				m_curIndex -= 1;
			}
			break;
		case'D':
		case'd':
			if ((m_curIndex % 5) != 4) {
				m_randomNumber[m_curIndex] = m_randomNumber[m_curIndex + 1];
				m_randomNumber[m_curIndex + 1] = SIZE_MAX;
				m_curIndex += 1;
			}
			break;
		case'Q':
		case'q':
			isDone = true;
			break;

		}

		if (checkSortedNumber()) {
			printFinish();
			isDone = true;
		}
		
	}
}

bool Puzzle::checkSortedNumber() {
	bool isSorted = false;

	for (size_t i = 0; i < m_randomNumber.size() - 1 ; i++) {
		if (m_randomNumber[i] == (i + 1)) 
			isSorted = true;		
		else {
			isSorted = false;
			break;
		}
	}
	return isSorted;
}

void Puzzle::printTitle() const {
	std::cout << "\t+=======================================+" << std::endl
		<< "\t+                                       +" << std::endl;
	std::cout << "\t+ 5 X 5 Number Puzzle                   +" << std::endl;
	std::cout << "\t+ Let's sort these numbers from 1 to 24 +" << std::endl
		<< "\t+                                       +" << std::endl;
	std::cout << "\t+=======================================+" << std::endl;
}

void Puzzle::printFinish() const {
	std::cout << "\t+=======================================+" << std::endl
		      << "\t+                                       +" << std::endl;
	std::cout << "\t+ Congratulations						  +" << std::endl
			  << "\t+                                       +" << std::endl;
	std::cout << "\t+=======================================+" << std::endl;
}



void Puzzle::printPuzzle() const {
	system("cls");

	printTitle();
	
	std::cout << "\tNumber Panel."
		<< std::endl << "\t+=======================================+" << std::endl;
	for (size_t i = 0; i < 5; i++) {
		std::cout << "\t+ " ;
		for (size_t j = 0; j < 5; j++) {
			if(m_randomNumber[(i * 5) + j] == SIZE_MAX)
				std::cout <<  "*\t";
			else
				std::cout << m_randomNumber[(i * 5) + j] << "\t";
		}
		std::cout<< "+" << std::endl;
	}
	std::cout << "\t+=======================================+" << std::endl;
	std::cout << std::endl
		<< "\tControl Key" << std::endl
		<< "\t+=======================================+" << std::endl
		<< "\t+                                       +" << std::endl
		<< "\t+   w: Up, s: Down, a: Left, d: Right   +" << std::endl
		<< "\t+   q: Exit the Game                    +" << std::endl 
		<< "\t+                                       +" << std::endl
		<< "\t+=======================================+" << std::endl;
}
