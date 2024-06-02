#pragma once
class game
{
private:
	int n;
	bool isXplayed;
	bool isGameOn;
	char Winner;
	int movesCount;
	bool isDraw;
public:
	game() : n(0),isXplayed(false),isGameOn(true),Winner(' '),movesCount(0),isDraw(false) {}

	void SetSize(int n);

	void StartGame();

	void displayGrid(vector<vector<char>>& grid, int size);

	void PlayGame(vector<vector<char>>& grid, int size, vector<vector<int>>& visited);

	int getInput(char player);

	bool validateGame(vector<vector<char>>& grid,int size);

	void getUserDetails();
};

