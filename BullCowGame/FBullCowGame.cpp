#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() {Reset();}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLenth() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

void FBullCowGame::Reset() {
	bIsGameWon = false;
	const FString HIDDEN_WORD = "planet";
	constexpr int32 MAX_TRIES = 8;

	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;

	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {

	if (false) { // TODO not an isogram
		return EGuessStatus::Not_An_Isogram;
	} else if (false) { // TODO not lower case
		return EGuessStatus::Not_Lowercase;
	} else if (Guess.length() != GetHiddenWordLenth()) { // wrong length
		return EGuessStatus::Wrong_Length;
	} else {
		return EGuessStatus::OK;
	}

}

// counts bulls and cows and increase MyCurrentTurn on a valid guess
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {

	MyCurrentTry++;

	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();

	// loop through all the letters in the hidden word and compare to guess
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
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

	(Guess == MyHiddenWord) ? bIsGameWon = true : bIsGameWon = false;
	
	return BullCowCount;
}
