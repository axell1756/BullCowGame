#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() {Reset();}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLenth() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ { 3,5 },{ 4,7 },{ 5,10 },{ 6,12 } };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset() {
	bIsGameWon = false;

	//TODO add isogram array for user to chose the difficulty depending on length of isogram
	const FString HIDDEN_WORD = "planet";

	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	return;
}

// checks if the guess is a valid guess
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {

	if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_An_Isogram;
	} else if (!IsLowercase(Guess)) { 
		return EGuessStatus::Not_Lowercase;
	} else if (Guess.length() != GetHiddenWordLenth()) {
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

// checks if the guess is an isogram
bool FBullCowGame::IsIsogram(FString Word) const {

	TMap<char, bool> LetterSeen;

	for (auto Letter : Word) {
		Letter = tolower(Letter);

		if (!LetterSeen[Letter]) { 
			LetterSeen[Letter] = true; 
		} else {
			return false;
		}

	}

	if (Word.length() <= 1) { return true; }

	return true; // when \0 or number is entered
}

// checks if the guess is all lowercase letters
bool FBullCowGame::IsLowercase(FString Word) const {

	for (auto Letter : Word) {
		if (!islower(Letter)) {
			return false;
		} 
	}

	return true;
}

