#ifndef _KITCHENFORMAT_H
#define _KITCHENFORMAT_H

#include "TVFormat.h"
#include<vector>
#include <sstream>

class KitchenFormat : public TVFormat {
private:
	static const int COOKS_TEAM_SIZE = 6;

	std::vector<Person*> teamA;
	std::vector<Person*> teamB;

	Person* findWorstPlayer(std::vector<Person*>& team);
	void recordEvent(const Person* player);
	std::vector<Person*> copy(const std::vector<Person*>& team);

public:
	KitchenFormat(const Person& host, const std::vector<Person*>& teamA, const std::vector<Person*>& teamB);
	void doEvent() override;
};

#endif // !_KITCHENFORMAT_H
