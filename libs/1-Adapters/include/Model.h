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

    void setDiamondPosition(const short& diamondsPosition) { this->m_diamondPosition = diamondsPosition; }
    short getDiamondPosition() { return this->m_diamondPosition; }

    void setHeartPosition(const short& heartsPosition) { this->m_heartPosition = heartsPosition; }
    short getHeartPosition() { return this->m_heartPosition; }

    void setSpadePosition(const short& spadesPosition) { this->m_spadePosition = spadesPosition; }
    short getSpadePosition() { return this->m_spadePosition; }

    void setClubPosition(const short& clubsPosition) { this->m_clubPosition = clubsPosition; }
    short getClubPosition() { return this->m_clubPosition; }

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

    void setHurdles(const std::vector<std::pair<Card::Card, bool>>& hurdles) { this->m_hurdles = hurdles; }
    std::vector<std::pair<Card::Card, bool>> getHurdles() { return this->m_hurdles; }

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
    short m_diamondPosition = 0;
    short m_heartPosition = 0;
    short m_spadePosition = 0;
    short m_clubPosition = 0;
    Card::Deck m_deck = Card::Deck(Card::DeckType(Card::SuitConstants::AllSuits, Card::PipConstants::PiquetPips));
    bool m_firstCardDrawn = false;
    Card::Card m_lastDrawnCard = Card::Card(Card::Identifier(Card::Suit::Diamond, Card::Pip::Seven));
    std::vector<std::pair<Card::Card, bool>> m_hurdles;
    bool m_gameDrawButtonActive = true;
    bool m_gameProceedButtonActive = false;
    // DistributeSips
};

#endif // MODEL_H
