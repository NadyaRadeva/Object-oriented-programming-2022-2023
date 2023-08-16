#include "Person.h"
#include "FMIChallenge.h"
#include "helpers.h"
#include "KitchenFormat.h"
#include "KitchenBulgaria.h"

void cleanUp(std::vector<Person*>& people)
{
    while (people.size() > 0)
    {
        delete people[people.size() - 1];
        people.pop_back();
    }
}

int main()
{
    const int FMI_CHALLENGE_GAMES = 10;
    char* fmiGames[FMI_CHALLENGE_GAMES] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten" };
    Person naum("Game Host", 30, "", 1.0);
    std::vector<Person*> fmiChallengers = {
        new Person("FMI Challenger One", 20, "", 0.1),
        new Person("FMI Challenger Two", 20, "", 0.2),
        new Person("FMI Challenger Three", 20, "", 0.3),
        new Person("FMI Challenger Four", 20, "", 0.4),
        new Person("FMI Challenger Five", 20, "", 0.5),
        new Person("FMI Challenger Six", 20, "", 0.6),
        new Person("FMI Challenger Seven", 20, "", 0.7),
        new Person("FMI Challenger Eight", 20, "", 0.8),
        new Person("FMI Challenger Nine", 20, "", 0.9),
        new Person("FMI Challenger Ten", 20, "", 0.91),
        new Person("FMI Challenger Eleven", 20, "", 0.92),
    };
    std::vector<Person*> cookingTeamA = {
        new Person("Cook One (A)", 30, "", 0.1),
        new Person("Cook Two (A)", 30, "", 0.2),
        new Person("Cook Three (A)", 30, "", 0.3),
        new Person("Cook Four (A)", 30, "", 0.4),
        new Person("Cook Five (A)", 30, "", 0.5),
        new Person("Cook Six (A)", 30, "", 0.6),
    };
    std::vector<Person*> cookingTeamB = {
        new Person("Cook One (B)", 30, "", 0.1),
        new Person("Cook Two (B)", 30, "", 0.2),
        new Person("Cook Three (B)", 30, "", 0.3),
        new Person("Cook Four (B)", 30, "", 0.4),
        new Person("Cook Five (B)", 30, "", 0.5),
        new Person("Cook Six (B)", 30, "", 0.6),
    };

    FMIChallenge challenge(naum, fmiChallengers, fmiGames);
    challenge.printFormatInformation();

    for (size_t idx = 0; idx < FMI_CHALLENGE_GAMES; ++idx)
    {
        challenge.doEvent();
    }

    challenge.showEvents(FMI_CHALLENGE_GAMES);

    KitchenFormat kitchen(naum, cookingTeamA, cookingTeamB);
    kitchen.printFormatInformation();

    for (size_t idx = 0; idx < cookingTeamA.size() + cookingTeamB.size() - 1; ++idx)
    {
        kitchen.doEvent();
    }

    kitchen.showEvents(cookingTeamA.size() + cookingTeamB.size() - 1);

    KitchenBulgaria<std::string> kitchenBulgaria(naum, cookingTeamA, cookingTeamB, "!hidden challenge this is!");
    kitchenBulgaria.printFormatInformation();

    for (size_t idx = 0; idx < cookingTeamA.size() + cookingTeamB.size() - 1; ++idx)
    {
        kitchenBulgaria.doEvent();
    }

    kitchenBulgaria.showEvents(cookingTeamA.size() + cookingTeamB.size() - 1);

    cleanUp(fmiChallengers);
    cleanUp(cookingTeamA);
    cleanUp(cookingTeamB);
}