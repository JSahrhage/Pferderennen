#ifndef CARD_PIP_H
#define CARD_PIP_H

// C++ Library Includes
#include <vector>

namespace Card
{
    enum class Pip { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

    namespace PipConstants
    {
        const std::vector<Pip> StandardPips = { Pip::Ace,
                                                Pip::Two,
                                                Pip::Three,
                                                Pip::Four,
                                                Pip::Five,
                                                Pip::Six,
                                                Pip::Seven,
                                                Pip::Eight,
                                                Pip::Nine,
                                                Pip::Ten,
                                                Pip::Jack,
                                                Pip::Queen,
                                                Pip::King };

        const std::vector<Pip> PiquetPips = { Pip::Ace,
                                              Pip::Seven,
                                              Pip::Eight,
                                              Pip::Nine,
                                              Pip::Ten,
                                              Pip::Jack,
                                              Pip::Queen,
                                              Pip::King };

        const std::vector<Pip> PiquetPipsWithoutAces = { Pip::Seven,
                                                         Pip::Eight,
                                                         Pip::Nine,
                                                         Pip::Ten,
                                                         Pip::Jack,
                                                         Pip::Queen,
                                                         Pip::King };
    }
}

#endif // CARD_PIP_H
