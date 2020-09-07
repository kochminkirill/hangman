#include "word.h"
#include <ctime>
#include <iostream>
#include "constants.h"

char getLetter()
{
    std::cout << "enter letter:";
    char letter{' '};
    std::cin >> letter;
    std::cin.ignore(INT_MAX, '\n');
    return letter;
}

void playHangman()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();

    Word word{ Word::getRandomWord() };
    char letter{' '};

    int count_attempts{ Constants::max_attempts };

    do
    {
        if(word.isGuessedWord())
        {
            word.printWord();
            std::cout << "You guessed word\n";
            return;
        }

        word.printWord();
        letter = getLetter();

        Word::TypeInput type_input = word.checkLetter(letter);
        if(type_input == Word::TypeInput::LETTER_ALREADY_ENTERED)
        {
            std::cout << "You already entered this letter(" << letter << ")." << '\n';
        }
        else if(type_input == Word::TypeInput::LETTER_INCORRECT)
            --count_attempts;

        std::cout << "\ncount attempts: " << count_attempts << "\n\n";

    } while(count_attempts > 0);

    std::cout << word;
}

int main()
{
    playHangman();
    return 0;
}
