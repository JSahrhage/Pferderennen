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

    void setClubsPosition(const short& clubsPosition) { this->m_clubsPosition = clubsPosition; this->notify(); }
    short getClubsPosition() { return this->m_clubsPosition; }
        
    void setDiamondsPosition(const short& diamondsPosition) { this->m_diamondsPosition = diamondsPosition; this->notify(); }
    short getDiamondsPosition() { return this->m_diamondsPosition; }

    void setHeartsPosition(const short& heartsPosition) { this->m_heartsPosition = heartsPosition; this->notify(); }
    short getHeartsPosition() { return this->m_heartsPosition; }

    void setSpadesPosition(const short& spadesPosition) { this->m_spadesPosition = spadesPosition; this->notify(); }
    short getSpadesPosition() { return this->m_spadesPosition; }

    void setDeck(const Card::Deck& deck) { this->m_deck = deck; }
    Card::Deck getDeck() { return this->m_deck; }

    void setPlayer(const std::vector<Player>& player) { this->m_player = player; }
    void addPlayer(const Player& player) { this->m_player.push_back(player); }
    void deletePlayer(const Player& player) { this->m_player.erase(std::remove(this->m_player.begin(), this->m_player.end(), player)); }
    std::vector<Player> getPlayer() { return this->m_player; }

private:
    // Subject
    std::vector<std::shared_ptr<IObserver>> m_views;
    // View
    Game::View m_gameView = Game::View::SelectGameMode;
    // SelectGameMode
    Game::Mode m_gameMode = Game::Mode::Classic;
    // EnterPlayer
    std::vector<Player> m_player;
    // PlaceBets
    // Game
    short m_clubsPosition = 0;
    short m_diamondsPosition = 0;
    short m_heartsPosition = 0;
    short m_spadesPosition = 0;
    Card::Deck m_deck = Card::Deck(Card::DeckType(Card::SuitConstants::AllSuits, Card::PipConstants::PiquetPips));
    bool m_firstCardDrawn = false;
    Card::Card m_lastDrawnCard = Card::Card(Card::Identifier(Card::Suit::Diamonds, Card::Pip::Seven));
    std::map<Card::Card, bool> m_hurdles;
    bool m_drawButtonActive = true;
    // DistributeSips
};

#endif // MODEL_H
