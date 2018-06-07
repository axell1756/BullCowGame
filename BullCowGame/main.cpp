#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

int main() {

	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	return 0;

};

void PrintIntro() {

	// Introduction of the game
	constexpr int WORD_LENGHT = 5;

	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << WORD_LENGHT;
	std::cout << " letter isogram I am thinking off?\n";
	std::cout << std::endl;
	return;

};

void PlayGame() {

	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	//Loop for the number of turns left

	for (int i = 1; i <= MaxTries; i++) {

		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;

	};

	//TODO Summarise game

};

std::string GetGuess() {
	int CurrentTry = BCGame.GetCurrentTry();
	//Get a user input
	printf("Try %i. Enter your guess: ", CurrentTry);
	std::string Guess = "";
	std::getline(std::cin, Guess);

	return Guess;

}

bool AskToPlayAgain() {

	//Asks wheather player wants to play again
	std::cout << "Would you like to play again?: ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'Y') || (Response[0] == 'y');

	
}

