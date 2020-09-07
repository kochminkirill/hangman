#ifndef WORD_H
#define WORD_H

#include <string>
#include <vector>
#include <ostream>

class Word
{
public:
    enum class TypeInput
    {
        LETTER_ALREADY_ENTERED,
        LETTER_INCORRECT,
        LETTER_GUESSED
    };

    Word(const std::string&);
    ~Word() { delete [] words; }

    void printWord() const;
    friend std::ostream& operator<<(std::ostream&, const Word&);
    //return false if letter was already entered
    TypeInput checkLetter(char);

    bool isGuessedWord() { return (static_cast<int>(m_word.size()) == m_count_guess_letters);}

private:
    std::string m_word;
    std::vector<char> m_guess_letters;
    std::vector<char> m_entered_letters;
    int m_count_guess_letters;
    void calculateCountGuessLetter(char);

public:
    static std::string getRandomWord();

private:
    static std::string *words;
    static int getRandomNumber(int,int);
    static bool containLetter(char, const std::vector<char>&);
};

#endif
