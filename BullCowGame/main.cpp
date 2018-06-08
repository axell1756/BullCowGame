/************************************************************** 
	This is the console executable, that makes use of classes.
	This Acts as the vies in MVS pattern and is responsible 
	for user interactions. For game logic, see FBullCowGame.cpp
***************************************************************/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;

using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGameSummary();
FText GetValidGuess();
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
	std::cout << std::endl;
	std::cout << " ((...))               L...L" << "\n";
	std::cout << " ( O O )              < o o >" << "\n";
	std::cout << "  \\   /                \\   / " << "\n";
	std::cout << "  (`_`)                 ^_^ " << "\n";
	std::cout << std::endl;

	printf("Welcome to Bulls and Cows!\nCan you guess the %i letter isogram I am thinking off?\n", BCGame.GetHiddenWordLenth());
	std::cout << std::endl;
	return;

};

void PlayGame() {

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// Loop for the number of turns left
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {

		FText Guess = GetValidGuess(); 

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows;
		std::cout << std::endl;
		std::cout << std::endl;

	};

	PrintGameSummary();
	return;
};

FText GetValidGuess() {

	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;

	do {

		int32 CurrentTry = BCGame.GetCurrentTry();
		int32 MaxTries = BCGame.GetMaxTries();
		//Get a user input
		printf("Try %i out of %i. Enter your guess: ", CurrentTry, MaxTries);
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status) {
		case EGuessStatus::Wrong_Length:
			printf("Please, enter %i letters long word. \n", BCGame.GetHiddenWordLenth());
			std::cout << std::endl;
			break;
		case EGuessStatus::Not_An_Isogram:
			printf("That is not an isogram, please use isograms only. \n", Guess);
			std::cout << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please, use lowercase only. \n";
			std::cout << std::endl;
			break;
		default:
			break;
		}
	} while (Status != EGuessStatus::OK);
	
	return Guess;
}

bool AskToPlayAgain() {

	//Asks wheather player wants to play again
	std::cout << "Would you like to guess the same word again?: ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'Y') || (Response[0] == 'y');

	
}

void PrintGameSummary() {

	if (BCGame.IsGameWon() == true) {
		std::cout << "Congratulations! You successfully guessed the word!" << "\n";
	} else {
		std::cout << "Better luck next time!" << "\n";
	}
	return;
}