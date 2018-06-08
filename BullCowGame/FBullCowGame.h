#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// initial values = 0
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	Invalid_Status,
	OK,
	Wrong_Length,
	Not_An_Isogram,
	Not_Lowercase
};

class FBullCowGame {

public:

	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	EGuessStatus CheckGuessValidity(FString) const;
	int32 GetHiddenWordLenth() const;
	bool IsGameWon() const;

	void Reset(); // TODO make return richer
	FBullCowCount SubmitValidGuess(FString);

private:

	// See constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bIsGameWon;

};