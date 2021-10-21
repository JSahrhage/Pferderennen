#ifndef CARD_PIP_H
#define CARD_PIP_H

#include <vector>

namespace Card
{
    enum class Pip { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

    const std::vector<Pip> standardPips = { Pip::Ace,
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

    const std::vector<Pip> piquetPips = { Pip::Ace,
                                          Pip::Seven,
                                          Pip::Eight,
                                          Pip::Nine,
                                          Pip::Ten,
                                          Pip::Jack,
                                          Pip::Queen,
                                          Pip::King };
}

#endif // CARD_PIP_H
