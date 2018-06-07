#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() {Reset();}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset() {
	const FString HIDDEN_WORD = "ant";
	constexpr int32 MAX_TRIES = 8;

	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::IsGameWon() const { return false; }

bool FBullCowGame::CheckGuessValidity(FString) {
	return false;
}

// counts bulls and cows and increase MyCurrentTurn on a valid guess
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	// increment the turn value
	MyCurrentTry++;

	// setup a return value
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();

	// loop through all the letters in a guess and compare to the hidden word
	for (int32 i = 0; i < HiddenWordLength; i++) {
		// compare letters agains the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++) {
			// if they match
			if (Guess[i] == MyHiddenWord[i]) {
				// if they are in the same place
				if (i == j) {
					BullCowCount.Bulls++;
				} else {
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}
