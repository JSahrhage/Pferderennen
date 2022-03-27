#ifndef MODEL_H
#define MODEL_H

// C++ Library Includes
#include <string>
#include <map>

// Project Includes
#include "IModel.h"
#include "GameView.h"
#include "GameMode.h"
#include "CardDeck.h"
#include "Card.h"
#include "Player.h"
#include "Bet.h"

class Model : public IModel
{
public:
    void attach(std::shared_ptr<IObserver> observer) override { this->m_views.push_back(observer); }
    void detach(std::shared_ptr<IObserver> observer) override { this->m_views.erase(std::remove(this->m_views.begin(), this->m_views.end(), observer)); }
    void notify() override { for (std::shared_ptr<IObserver> observer : this->m_views) { observer->update(); } }

    void setGameView(const Game::View& gameView) { this->m_gameView = gameView; this->notify(); }
    Game::View getGameView() { return this->m_gameView; }

    void setGameMode(const Game::Mode& gameMode) { this->m_gameMode = gameMode; }
    Game::Mode getGameMode() { return this->m_gameMode; }

    void setDiamondPosition(const short& diamondsPosition) { this->m_diamondsPosition = diamondsPosition; this->notify(); }
    short getDiamondPosition() { return this->m_diamondsPosition; }

    void setHeartPosition(const short& heartsPosition) { this->m_heartsPosition = heartsPosition; this->notify(); }
    short getHeartPosition() { return this->m_heartsPosition; }

    void setSpadePosition(const short& spadesPosition) { this->m_spadesPosition = spadesPosition; this->notify(); }
    short getSpadePosition() { return this->m_spadesPosition; }

    void setClubPosition(const short& clubsPosition) { this->m_clubsPosition = clubsPosition; this->notify(); }
    short getClubPosition() { return this->m_clubsPosition; }

    void setDeck(const Card::Deck& deck) { this->m_deck = deck; }
    Card::Deck getDeck() { return this->m_deck; }

    void setPlayer(const std::vector<Player>& player) { this->m_player = player; }
    std::vector<Player> getPlayer() { return this->m_player; }

    void setOpenBets(const std::vector<Bet>& openBets) { this->m_openBets = openBets; }
    std::vector<Bet> getOpenBets() { return this->m_openBets; }

    void setFirstCardDrawn(const bool& firstCardDrawn) { this->m_firstCardDrawn = firstCardDrawn; }
    bool getFirstCardDrawn() { return this->m_firstCardDrawn; }

    void setLastDrawnCard(const Card::Card& lastDrawnCard) { this->m_lastDrawnCard = lastDrawnCard; }
    Card::Card getLastDrawnCard() { return this->m_lastDrawnCard; }

    void setGameDrawButtonActive(const bool& gameDrawButtonActive) { this->m_gameDrawButtonActive = gameDrawButtonActive; }
    bool getGameDrawButtonActive() { return this->m_gameDrawButtonActive; }

    void setGameProceedButtonActive(const bool& gameProceedButtonActive) { this->m_gameProceedButtonActive = gameProceedButtonActive; }
    bool getGameProceedButtonActive() { return this->m_gameProceedButtonActive; }

private:
    // Subject
    std::vector<std::shared_ptr<IObserver>> m_views;
    // View
    Game::View m_gameView = Game::View::ChooseGameMode;
    // SelectGameMode
    Game::Mode m_gameMode = Game::Mode::Classic;
    // EnterPlayer
    std::vector<Player> m_player;
    // PlaceBets
    std::vector<Bet> m_openBets;
    // Game
    short m_diamondsPosition = 0;
    short m_heartsPosition = 0;
    short m_spadesPosition = 0;
    short m_clubsPosition = 0;
    Card::Deck m_deck = Card::Deck(Card::DeckType(Card::SuitConstants::AllSuits, Card::PipConstants::PiquetPips));
    bool m_firstCardDrawn = true;
    Card::Card m_lastDrawnCard = Card::Card(Card::Identifier(Card::Suit::Diamonds, Card::Pip::Seven));
    std::map<Card::Card, bool> m_hurdles;
    bool m_gameDrawButtonActive = true;
    bool m_gameProceedButtonActive = false;
    // DistributeSips
};

#endif // MODEL_H
