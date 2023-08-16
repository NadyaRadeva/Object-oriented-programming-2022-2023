#ifndef KITCHEN_BULGARIA
#define KITCHEN_BULGARIA

#include "KitchenFormat.h"

template <typename T>
class KitchenBulgaria : public KitchenFormat
{
private:
    T hiddenChallenge;

public:
    KitchenBulgaria(const Person& host, const vector<Person*>& teamA, const vector<Person*>& teamB, T hiddenChallenge) : KitchenFormat(host, teamA, teamB)
    {
        this->hiddenChallenge = hiddenChallenge;
    }

    void printFormatInformation()
    {
        this->KitchenFormat::printFormatInformation();
        cout << "Hidden challenge: " << this->hiddenChallenge << endl;
    }
};
#endif