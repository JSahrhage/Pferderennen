#ifndef CARD_PIP_H
#define CARD_PIP_H

#include <vector>

enum class CardPip { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

std::vector<CardPip> standardCardPips = { CardPip::Ace,
                                          CardPip::Two,
                                          CardPip::Three,
                                          CardPip::Four,
                                          CardPip::Five,
                                          CardPip::Six,
                                          CardPip::Seven,
                                          CardPip::Eight,
                                          CardPip::Nine,
                                          CardPip::Ten,
                                          CardPip::Jack,
                                          CardPip::Queen,
                                          CardPip::King };

std::vector<CardPip> piquetCardPips = { CardPip::Ace,
                                        CardPip::Seven,
                                        CardPip::Eight,
                                        CardPip::Nine,
                                        CardPip::Ten,
                                        CardPip::Jack,
                                        CardPip::Queen,
                                        CardPip::King };

#endif // CARD_PIP_H
