#include <input.hpp>
#include <ifstream>
#include <sstream>

namespace INWAD {
    namespace DetailInput {
        std::vector<std::string> getAlphabet(const std::string &contentLine) {
            std::vector<std::string> alphabet;
            std::stringstream s(contentLine);

            std::string str;
            while(s >> str) {
                alphabet.emplace_back(str)
            }
            return alphabet;
        }
    }

BuchiAutomaton read(const std::string &filepath) {
    std::ifstream file(filepath);

    if (!file.is_open()) {
        BuchiAutomaton empty;
        return empty;
    }

    std::string lineContent;

    // Read in amount of states, first line
    std::getline(file, lineContent);
    const auto numberOfStates = std::stoi(lineContent);

    // Read and parse alphabet, second line
    std::getline(file, lineContent);
    const auto alphabet = DetailInput::getAlphabet(lineContent);

    // Read in initial state, third line
    std::getline(file, lineContent);
    const auto initialState = std::stoul(lineContent);

    BuchiAutomaton aut(numberOfStates, alphabet, initialState);

    // Add transitions
    char c;
    while (c << file) {
        switch(c) {
            case 'c':
                std::getline(file, lineContent);
                break;

            case 't':
                // std::basic_istringstream


        }
    }

    return aut;
}

} // namespace INWAD
