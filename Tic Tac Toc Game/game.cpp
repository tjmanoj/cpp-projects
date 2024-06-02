#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

#include "game.h"
#include "History.h"

History h;

void game::SetSize(int n) {
	this->n = n;
}

void game::getUserDetails() {
	h.getPlayerDetails(h);
}


void game::StartGame() {
	int size;
	cout << "Enter grid size: ";
	cin >> size;
	this->SetSize(size);
	h.setMode(size);

	vector<vector<char>> grid(size, vector<char>(size, ' '));
	vector<vector<int>> visited(size, vector<int>(size, 0));

	while (this->isGameOn) {
		system("cls");
		this->displayGrid(grid, size);
		this->PlayGame(grid, size, visited);
	}
	
}

void game::displayGrid(vector<vector<char>>& grid,int size) {
	
	// horizonal line
	cout << " ";
	for (int i = 0; i < size * 4 - 1; i++) {		//important
		cout << "-";
	}
	cout << endl;

	// display inner body game values
	for (int i = 0; i < size; i++) {
		cout << "|";
		for (int j = 0; j < size; j++) {
			cout << " " << grid[i][j] << " |";
		}

		cout << endl;
		// horizonal line
		cout << " ";
		for (int i = 0; i < size * 4 - 1; i++) {
			cout << "-";
		}
		cout << endl;
	}

	
}

int game::getInput(char player) {
	int position;
	cout << "Player " << player << " turn: ";
	cin >> position;
	return position;
}

void game::PlayGame(vector<vector<char>>& grid,int size, vector<vector<int>> &visited) {
	char player;
	int position;

	player = this->isXplayed ? 'O' : 'X';

	position = this->getInput(player);

	// other than valid field
	if (position > size * size || position <= 0) {
		cout << "Invalid input!" << endl;
		position = this->getInput(player);
	}

	int row = ceil((float)position / size) - 1;			//important
	int col = position - (size * row) - 1;

	// if already marked
	if (visited[row][col]) {
		cout << "Invalid input!" << endl;
		position = this->getInput(player);
	}


	grid[row][col] = player;
	visited[row][col] = 1;
	this->movesCount++;
	this->isXplayed = !this->isXplayed;

	bool isGameOn = this->validateGame(grid,size);

	if (isGameOn) {
		this->isGameOn = false;
		system("cls");
		displayGrid(grid,size);
		if (this->isDraw) {
			cout << "Match Draw!" << endl;
			h.setWinner("Draw");
		}
		else {
			if (this->Winner == 'X') h.setWinner(h.getuser1());
			else h.setWinner(h.getuser2());
			cout << h.getWinner() << " Wins!!" << endl;
			h.SaveDetails(h);
		}


	}

}

bool game::validateGame(vector<vector<char>>& grid, int size) {
	int countX = 0;
	int countO = 0;

	//horizontal
	for (int i = 0; i < size; i++) {
		countX = 0;
		countO = 0;
		for (int j = 0; j < size; j++) {
			if (grid[i][j] == 'X') countX++;
			if (grid[i][j] == 'O') countO++;
		}
		if (countX == size) {
			this->Winner = 'X';
			return true;
		}
		if (countO == size) {
			this->Winner = 'O';
			return true;
		}
	}

	// Vertical
	for (int i = 0; i < size; i++) {
		countX = 0;
		countO = 0;
		for (int j = 0; j < size; j++) {
			if (grid[j][i] == 'X') countX++;
			if (grid[j][i] == 'O') countO++;
		}
		if (countX == size) {
			this->Winner = 'X';
			return true;
		}
		if (countO == size) {
			this->Winner = 'O';
			return true;
		}
	}

	//diagonal right
	countX = 0;
	countO = 0;
	for (int i = 0; i < size; i++) {
		if (grid[i][i] == 'X') countX++;
		if (grid[i][i] == 'O') countO++;
	}
	if (countX == size) {
		this->Winner = 'X';
		return true;
	}
	if (countO == size) {
		this->Winner = 'O';
		return true;
	}


	//diagonal left
	countX = 0;
	countO = 0;
	for (int i = 0; i < size; i++) {
		if (grid[i][size - i - 1] == 'X') countX++;
		if (grid[i][size - i - 1] == 'O') countO++;
	}
	if (countX == size) {
		this->Winner = 'X';
		return true;
	}
	if (countO == size) {
		this->Winner = 'O';
		return true;
	}

	// Draw
	if (this->movesCount == size*size) {
		this->isDraw = true;
		return true;
	}
	return false;

}