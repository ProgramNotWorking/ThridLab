#include "Train.h"


Train::Train() {
    trainNumber = 0;
    tempStationsList = " ";
    type = " ";
}

Train::Train(int number, string tempString, std::string trainType) {
    trainNumber = number;
    tempStationsList = std::move(tempString);
    type = std::move(trainType);
}

Train::~Train() = default;

istream &operator>>(istream &in, Train &train) {
    in >> train.trainNumber;
    string tempString;
    getline(in, tempString);
    getline(in, train.tempStationsList);
    getline(in, train.type);

    return in;
}

void Train::operator=(Train &train) {
    trainNumber = train.trainNumber;
    tempStationsList = train.tempStationsList;
    type = train.type;
}

void Train::displayInfoOneTrain() {
    cout << "Train number: " << trainNumber << endl;
    cout << "Stations list: " << endl;
    cout << tempStationsList << endl;
    cout << "Train type: " << type << "\n\n";
}

void Train::displayInfo(const list<Train> &trains) {
    for (Train train: trains) {
        train.displayInfoOneTrain();
    }
}

int Train::getTrainNumber() const {
    return trainNumber;
}

list<string> Train::getStationsList(const list<Train> &trains, int someTrainNumber) {
    list<string> listArray;

    for (Train train: trains) {
        if (train.getTrainNumber() == someTrainNumber) {
            string tempWord;
            int k = 0;
            for (char i: train.tempStationsList) {
                if (i != ' ') {
                    tempWord += i;
                } else {
                    listArray.push_back(tempWord);
                    k++;
                    tempWord = "";
                }
            }
            listArray.push_back(tempWord);
        }
    }
    return listArray;
}

list<string> Train::getStationsList() {
    list<string> listArray;

    string tempWord;
    int k = 0;
    for (char i : Train::tempStationsList) {
        if (i != ' ') {
            tempWord += i;
        } else {
            listArray.push_back(tempWord);
            k++;
            tempWord = "";
        }
    }
    listArray.push_back(tempWord);

    return listArray;
}

void Train::setTrainNumber() {
    Train::trainNumber = 0;
    int trainNumberSet;
    cout << "Enter train number: ";
    cin >> trainNumberSet;
    Train::trainNumber = trainNumberSet;
}

void Train::setTempStationsList() {
    Train::tempStationsList = " ";
    string trainStationsListSet;
    string tempTrashStringILoveCLanguage;
    cout << "Enter train stations with space between them: " << endl;
    getline(cin, tempTrashStringILoveCLanguage);
    getline(cin, trainStationsListSet);
    Train::tempStationsList = trainStationsListSet;
}

void Train::setType() {
    Train::type = " ";
    string trainTypeSet;
    cout << "Enter train type: ";
    cin >> trainTypeSet;
    Train::type = trainTypeSet;
}

void Train::printInfoFromTrainNumber(const list<Train> &trains, int someTrainNumber) {
    bool isFind = false;
    for (Train train: trains) {
        if (train.getTrainNumber() == someTrainNumber) {
            train.displayInfoOneTrain();
            isFind = true;
        }
    }
    if (!isFind) {
        cout << "Train with this number is not exist" << endl;
    }
}
