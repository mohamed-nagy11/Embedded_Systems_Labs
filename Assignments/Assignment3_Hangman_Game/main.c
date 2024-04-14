#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "english_words.h"

#define MAX_TRIALS 10             // Number of trials
#define RANDOM_WORDS_SIZE 109     // Number of random words
#define MAX_GUESSED_LETTERS 26    // Maximum number of letters that can be guessed (number of English letters)

// Function to choose a random word from the array
char* randomWord() {
    srand(time(NULL));                            // Initialize the seed of the random number
    int index = rand() % RANDOM_WORDS_SIZE;       // Choose a random index from 0 to 108
    return englishWords[index];
}

// Function to display the current state of the word
void displayWord(char* word, char* guessedLetters) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (strchr(guessedLetters, word[i]) != NULL)
            printf("%c ", word[i]);
        else
            printf("_ ");
    }
    printf("\n");
}

// Function to check if the word has been completely guessed
int isWordGuessed(char* word, char* guessedLetters) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (strchr(guessedLetters, word[i]) == NULL) {
            return 0; // Any letter is not found in guessedLetters
        }
    }
    return 1; // All letters are found in guessedLetters
}


int main() {

    // Choose a random word
    char* word = randomWord();

    char guessedLetters[MAX_GUESSED_LETTERS + 1];     // +1 for the null terminator
    guessedLetters[0] = '\0';                         // Initialize guessedLetters to an empty string
    int trialsLeft = MAX_TRIALS;

    printf("=========== Welcome to Hangman Game! ===========\n\n");
    printf("Guess the word and save the man: ");
    displayWord(word, guessedLetters);

    while (trialsLeft > 0) {
        printf("\nTrials left: %d\n", trialsLeft);
        printf("Enter a letter: ");
        char guess;
        scanf(" %c", &guess);

        // Check if the player has entered the letter before
        if (strchr(guessedLetters, guess) != NULL) {
            printf("You've already guessed that letter berore\n");
            continue;
        } else {
            //Add the new guess to the guessdLetters
            guessedLetters[strlen(guessedLetters)] = guess;
            guessedLetters[strlen(guessedLetters)] = '\0';
        }

        // Compare the guess with the actual word
        if (strchr(word, guess) != NULL) {
            printf("Correct guess!\n");
        } else {
            printf("Incorrect guess!\n");
            trialsLeft--;
        }

        displayWord(word, guessedLetters);

        // Check if the word has been completely guessed
        if (isWordGuessed(word, guessedLetters)) {
            printf("\nWIIIIIN\n");
            return 0;
        }
    }

    if (trialsLeft == 0) {
        printf("\n======================= GAME OVER =======================\n");
        printf("Sorry, you've run out of trials. The word was: %s\n", word);
        printf("Man is Executed :(\n");
    }

    return 0;
}
