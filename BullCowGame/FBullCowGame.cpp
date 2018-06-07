#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() {Reset();}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLenth() const { return MyHiddenWord.length(); }


void FBullCowGame::Reset() {
	const FString HIDDEN_WORD = "planet";
	constexpr int32 MAX_TRIES = 8;

	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::IsGameWon() const { return false; }

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {

	if (false) { // not an isogram
		return EGuessStatus::Not_An_Isogram;
	} else if (false) { // not lower case
		return EGuessStatus::Not_Lowercase;
	} else if (Guess.length() != GetHiddenWordLenth()) { // wrong length
		return EGuessStatus::Wrong_Length;
	} else {
		return EGuessStatus::OK;
	}

}

// counts bulls and cows and increase MyCurrentTurn on a valid guess
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	// increment the turn value
	MyCurrentTry++;

	// setup a return value
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();

	// loop through all the letters in a guess and compare to the hidden word
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		// compare letters agains the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			// if they match
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				// if they are in the same place
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				} else {
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}
