// Скоро я кого-нибудь убью
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

#include "Train.h"

using namespace std;

//// get list element from his index(c++ not includes this lmao)
Train getTrain(list<Train> trains, int index);

bool isTrainChanged = false;
int editableTrainNumber;

int main() {
    ifstream info("Info.txt");
    int n;
    info >> n;
    int trainsCount = n;

    list<Train> trains;
    for (int i = 0; i < n; i++) {
        Train tempTrain;
        info >> tempTrain;
        trains.push_back(tempTrain);
    }

    Train editableTrain;

    int menuPoint = 1;
    while (menuPoint) {
        toStartMenu:
        cout << "Menu point: " << endl;
        cout << "1) Print all info" << endl;
        cout << "2) Add train" << endl;
        cout << "3) Delete train" << endl;
        cout << "4) Change train" << endl; // Not end yet, this case not change the train
        cout << "5) Sort of train number" << endl;
        cout << "6) Display train route" << endl; // check comm
        cout << "7) Display trains, where u can ride from VRN to another city" << endl;
        cout << "Another point - Exit" << endl;
        cin >> menuPoint;
        switch (menuPoint) {
            case 1: {
                Train tempTrain = getTrain(trains, 0);

                if (isTrainChanged) {
                    for (Train train : trains) {
                        if (train.getTrainNumber() == editableTrainNumber) {
                            editableTrain.displayInfoOneTrain();
                        } else {
                            tempTrain.printInfoFromTrainNumber(trains, train.getTrainNumber());
                        }
                    }
                } else {
                    tempTrain.displayInfo(trains);
                }
            }
                break;
            case 2: {
                Train tempNewTrain;
                tempNewTrain.setTrainNumber();
                tempNewTrain.setTempStationsList();
                tempNewTrain.setType();

                trains.push_back(tempNewTrain);
                trainsCount++;
                cout << "\n";
            }
                break;
            case 3: {
                int indexTrainDelete;
                cout << "Enter number of train, what u want to delete: ";
                cin >> indexTrainDelete;

                _List_iterator<Train> it = trains.begin();
                advance(it, indexTrainDelete - 1);
                trains.erase(it);
                trainsCount--;
                cout << "\n";
            }
                break;
            case 4: {
                isTrainChanged = true;
                cout << "Enter what train u want to edit(Enter number of train): ";
                cin >> editableTrainNumber;

                for (Train train : trains) {
                    if (train.getTrainNumber() == editableTrainNumber) {
                        editableTrain = train;
                    }
                }

                int changeInfoPoint = 1;
                while (changeInfoPoint >= 1 && changeInfoPoint <= 4) {
                    cout << "What information u want to change: " << endl;
                    cout << "1) Train number" << endl
                         << "2) Stations list" << endl
                         << "3) Train type" << endl
                         << "Another point to exit this menu" << endl;
                    cin >> changeInfoPoint;

                    switch (changeInfoPoint) {
                        case 1: {
                            editableTrain.setTrainNumber();
                        }
                            break;
                        case 2: {
                            editableTrain.setTempStationsList();
                        }
                            break;
                        case 3: {
                            editableTrain.setType();
                        }
                            break;
                        default: {
                            cout << "\n";
                            goto toStartMenu;
                        }
                    }
                }
            }
                break;
            case 5: {
                list<int> tempTrainNumbersList;
                for (Train train : trains) {
                    tempTrainNumbersList.push_back(train.getTrainNumber());
                }
                tempTrainNumbersList.sort();

                Train tempTrain = getTrain(trains, 0);
                for (int i : tempTrainNumbersList) {
                    tempTrain.printInfoFromTrainNumber(trains, i);
                }
                cout << "\n";
            }
                break;
            case 6: {
                Train tempTrain = getTrain(trains, 0);
                int trainNumber;
                cout << "Enter train number, which route u want display: ";
                cin >> trainNumber;
                list<string> stationsList = tempTrain.getStationsList(trains, trainNumber);

                cout << "This train route:" << endl;
                cout << stationsList.front() << " - " << stationsList.back() << endl;
                cout << "\n";
            }
                break;
            case 7: {
                string endStation;
                cout << "Enter station, through which the train must go: ";
                cin >> endStation;

                int countRightStations = 0;
                for (Train train : trains) {
                    for (string station : train.getStationsList()) {
                        if (station == "VRN" || station == endStation) {
                            countRightStations++;
                        }
                    }
                    if (countRightStations == 2) {
                        cout << train.getTrainNumber() << endl;
                        list<string> stationsList = train.getStationsList(trains, train.getTrainNumber());
                        cout << stationsList.front() << " - " << stationsList.back() << "\n\n";
                    }
                    countRightStations = 0;
                }
                cout << "\n";
            }
                break;
            default:
                return 0;
        }
    }


}

Train getTrain(list<Train> trains, int index) {
    auto it = trains.begin();
    for (int i = 0; i < index; i++) {
        ++it;
    }
    return *it;
}
