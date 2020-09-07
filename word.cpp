#include "word.h"
#include <iostream>
#include "constants.h"

Word::Word(const std::string &word) : m_word{ word }, m_count_guess_letters{ 0 }
{
    m_entered_letters.reserve(word.size());
    m_guess_letters.reserve(word.size());
}

void Word::printWord() const
{
    std::cout << "word: ";

    for(int letter{ 0 }; letter < static_cast<int>(m_word.size()); ++letter)
    {
        if(containLetter(m_word[letter],m_guess_letters))
        {
            std::cout << m_word[letter] << " ";
            continue;
        }

        std::cout << "_ ";
    }

    std::cout << '\n';
}

Word::TypeInput Word::checkLetter(char letter)
{
    if(containLetter(letter, m_guess_letters) || containLetter(letter, m_entered_letters))
        return Word::TypeInput::LETTER_ALREADY_ENTERED;

    calculateCountGuessLetter(letter);

    for(int sign{ 0 }; sign < static_cast<int>(m_word.size()); ++sign)
    {
        if(letter == m_word[sign])
        {
            m_guess_letters.push_back(letter);
            m_entered_letters.push_back(letter);
            return Word::TypeInput::LETTER_GUESSED;
        }

        m_entered_letters.push_back(letter);
    }

    return Word::TypeInput::LETTER_INCORRECT;
}

void Word::calculateCountGuessLetter(char letter)
{
    for(int sign{ 0 }; sign < static_cast<int>(m_word.size()); ++sign)
        if(letter == m_word[sign])
            ++m_count_guess_letters;
}

std::ostream& operator<<(std::ostream &out, const Word &word)
{
    out << "word: ";
    for(int letter{ 0 }; letter < static_cast<int>(word.m_word.size()); ++letter)
        out << word.m_word[letter];

    out << '\n';
    return out;
}

//support functions
bool Word::containLetter(char letter, const std::vector<char> &letters)
{
    for(const auto &l : letters)
        if(letter == l)
            return true;
    return false;
}

int Word::getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

std::string Word::getRandomWord()
{
    return words[getRandomNumber(0, Constants::max_words - 1)];
}

std::string *Word::words = new std::string[Constants::max_words] { "phone","keyboard","mouse","family","house",
                                                                   "space", "significantly","confidence","field",
                                                                   "think", "swim", "necessary", "beautiful","strange",
                                                                   "avengers", "computer", "program", "programmer", "programming",
                                                                   "laugh", "enjoy","forest","wizard","blackjack","dollar","memory",
                                                                   "remember", "coffee", "office", "movie", "river", "ocean", "picture"
                                                                   "constant", "variable", "hangman", "payment", "sadness", "string", "letter",
                                                                    "music", "hobby", "button", "paper", "village", "shadow"};
