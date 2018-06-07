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
FText GetGuess();
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

	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLenth();
	std::cout << " letter isogram I am thinking off?\n";
	std::cout << std::endl;
	return;

};

void PlayGame() {

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// Loop for the number of turns left
	for (int32 i = 1; i <= MaxTries; i++) { // TODO Change for loop to while once validation is working

		FText Guess = GetGuess(); 

		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// Print number of Bulls and Cows
		printf("Bulls = %i; Cows = %i", BullCowCount.Bulls, BullCowCount.Cows);
		std::cout << std::endl;

	};

	//TODO Summarise game

};
// TODO change to GetValidGuess
FText GetGuess() {
	int32 CurrentTry = BCGame.GetCurrentTry();
	//Get a user input
	printf("Try %i. Enter your guess: ", CurrentTry);
	FText Guess = "";
	std::getline(std::cin, Guess);

	return Guess;

}

bool AskToPlayAgain() {

	//Asks wheather player wants to play again
	std::cout << "Would you like to play again?: ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'Y') || (Response[0] == 'y');

	
}

