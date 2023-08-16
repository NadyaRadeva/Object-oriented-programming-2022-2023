#include "FMIChallenge.h"
#include <climits>
#include<cassert>

FMIChallenge::FMIChallenge(const Person& host, const std::vector<Person*>& participants, char* games[FMI_CHALLENGE_GAMES]) : TVFormat(host, assertLength(participants, FMI_CHALLENGE_PARTICIPANTS))
{
    this->copyGames(games);
}

FMIChallenge::FMIChallenge(const FMIChallenge& other) : TVFormat(other)
{
    this->copyGames(other.games);
}

FMIChallenge& FMIChallenge::operator=(const FMIChallenge& other)
{
    if (this != &other)
    {
        this->TVFormat::operator=(other);

        this->freeGames();
        this->copyGames(other.games);
    }

    return *this;
}

FMIChallenge::~FMIChallenge()
{
    this->freeGames();
}

void FMIChallenge::doEvent()
{
    if (this->participants.size() == 1)
    {
        throw std::runtime_error("game over");
    }

    char* game = this->playNextGame();
    Person* player = this->findWorstPlayer();

    this->recordEvent(game, player);

    delete game;
    this->removeById(player->getId(), this->participants);
}

char* FMIChallenge::playNextGame()
{
    char* result = nullptr;

    for (size_t idx = 0; result == nullptr && idx < FMI_CHALLENGE_GAMES; ++idx)
    {
        if (this->games[idx] != nullptr)
        {
            result = this->games[idx];
            this->games[idx] = nullptr;
        }
    }

    assert(result != nullptr);

    return result;
}

Person* FMIChallenge::findWorstPlayer()
{
    double worst = 1;
    Person* result = nullptr;

    for (size_t idx = 0; idx < this->participants.size(); ++idx)
    {
        Person* candidate = this->participants[idx];
        double score = candidate->getSkills() / candidate->getAge();

        if (score < worst)
        {
            worst = score;
            result = candidate;
            std::swap(this->participants[idx], this->participants[this->participants.size() - 1]);
        }
    }

    assert(result != nullptr);

    return result;
}

void FMIChallenge::freeGames()
{
    for (size_t idx = 0; idx < FMI_CHALLENGE_GAMES; ++idx)
    {
        delete this->games[idx];
        this->games[idx] = nullptr;
    }
}

void FMIChallenge::copyGames(char* const games[FMI_CHALLENGE_GAMES])
{
    for (size_t idx = 0; idx < FMI_CHALLENGE_GAMES; ++idx)
    {
        this->games[idx] = new char[strlen(games[idx]) + 1];
        strcpy(this->games[idx], games[idx]);
    }
}

void FMIChallenge::recordEvent(const char* game, const Person* player)
{
    std::stringstream buffer;

    buffer << "Game was " << game << ", " << player->getName() << " was eliminated";

    this->addEvent(buffer.str());
}