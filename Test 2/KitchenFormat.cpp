#include "KitchenFormat.h"
#include <cassert>
#include "helpers.h"
#include<iostream>

Person* KitchenFormat::findWorstPlayer(std::vector<Person*>& team) {
	double worst = 1;
	Person* result = nullptr;

	for (size_t i = 0; i < team.size(); ++i) {
		Person* canditate = team[i];
		double score = canditate->getSkills() / canditate->getAge();

		if (score <= worst) {
			worst = score;
			result = canditate;
			std::swap(team[i], team[team.size() - 1]);
		}
	}

	assert(result != nullptr);

	return result;
}

void KitchenFormat::recordEvent(const Person* player) {
	std::stringstream buffer;

	buffer << player->getName() << " was eliminated." << std::endl;

	this->addEvent(buffer.str());

}

std::vector<Person*> KitchenFormat::copy(const std::vector<Person*>& team) {
	std::vector<Person*> result;

	for (size_t i = 0; i < team.size(); ++i) {
		result.push_back(new Person(*team[i]));
	}

	return result;
}

KitchenFormat::KitchenFormat(const Person& host, const std::vector<Person*>& teamA, const std::vector<Person*>& teamB) {
	assertLength(teamA, COOKS_TEAM_SIZE);
	assertLength(teamB, COOKS_TEAM_SIZE);

	this->teamA = copy(teamA);
	this->teamB = copy(teamB);
}

void KitchenFormat::doEvent() {
	if (this->teamA.size() == 0 || this->teamB.size() == 0)
	{
		throw std::runtime_error("game over");
	}

	std::vector<Person*>& team = this->teamB.size() > this->teamA.size() ? this->teamB : this->teamA;
	Person* player = this->findWorstPlayer(team);

	this->recordEvent(player);

	this->removeById(player->getId(), team);
	this->removeById(player->getId(), participants);
}
