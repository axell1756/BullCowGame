#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// initial values = 0
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {

public:

	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make return richer
	bool CheckGuessValidity(FString); // TODO make return richer
	FBullCowCount SubmitGuess(FString);

private:

	// See constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;

};