#pragma once

#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

namespace INWAD {

using State = unsigned long;
using Transition = std::pair<std::string,State>;
using Alphabet = std::vector<std::string>;

//! A non-deterministic Buchi Automaton.
class BuchiAutomaton {
public:
    BuchiAutomaton() = default;
    BuchiAutomaton(const int numberOfStates, const Alphabet &alphabet, const State initialState);

    inline int states() const noexcept { return static_cast<int>(m_transitions.size()); }
    int transitions() const noexcept;

    void addTransition(const State source, const std::string &label, const State target);

    //! Union operation
    friend BuchiAutomaton operator|(const BuchiAutomaton &autA, const BuchiAutomaton &autB);
    //! Intersection operation
    friend BuchiAutomaton operator&(const BuchiAutomaton &autA, const BuchiAutomaton &autB);
    //! Complementation operation
    friend BuchiAutomaton operator~(const BuchiAutomaton &aut);


private:
    // Adjacency list
    std::vector<std::unordered_multimap<std::string,State>> m_transitions;
    Alphabet m_alphabet;
    State m_initialState;
};

} // namespace INWAD
