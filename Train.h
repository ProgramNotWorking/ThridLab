#ifndef THRIDLAB_TRAIN_H
#define THRIDLAB_TRAIN_H

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <utility>
#include <sstream>

using namespace std;

class Train {
private:
    int trainNumber;
    string tempStationsList;
    string type;

public:
    Train();
    Train(int number, string tempString, string trainType);
    ~Train();
    friend istream &operator>>(istream &in, Train &train);
    void operator=(Train &train);
    void displayInfo(const list<Train>& trains);
    int getTrainNumber() const;
    list<string> getStationsList(const list<Train>& trains, int someTrainNumber);
    list<string> getStationsList();
    void setTrainNumber();
    void setTempStationsList();
    void setType();
    void printInfoFromTrainNumber(const list<Train>& trains, int someTrainNumber);
    void displayInfoOneTrain();
};


#endif //THRIDLAB_TRAIN_H
