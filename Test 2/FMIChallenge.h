#ifndef FMI_CHALLENGE_H
#define FMI_CHALLENGE_H

#include "TVFormat.h"
#include "helpers.h"
#include <sstream>

class FMIChallenge : public TVFormat
{
private:
    static const int FMI_CHALLENGE_PARTICIPANTS = 14;
    static const int FMI_CHALLENGE_GAMES = 10;
    char* games[FMI_CHALLENGE_GAMES];
    char* playNextGame();
    Person* findWorstPlayer();
    void freeGames();
    void copyGames(char* const games[FMI_CHALLENGE_GAMES]);
    void recordEvent(const char* game, const Person* player);

public:
    FMIChallenge(const Person& host, const std::vector<Person*>& participants, char* games[FMI_CHALLENGE_GAMES]);
    FMIChallenge(const FMIChallenge& other);
    FMIChallenge& operator=(const FMIChallenge& other);
    ~FMIChallenge();

    void doEvent() override;
};

#endif