#include <string>

#ifndef QUESTION_H_
#define QUESTION_H_

class Question {
protected:
    std::string question;
    double points;

public:
    Question(const std::string& question1, double points1);

    virtual void ask() = 0;
    virtual double grade() = 0;
    virtual void print() = 0;

    static bool validYesNoAnswer(const std::string& ans);
    static bool correctYesNoAnswer(const std::string& ans, bool correct_is_yes);
    static const std::string YES;
    static const std::string NO;
};

#endif
