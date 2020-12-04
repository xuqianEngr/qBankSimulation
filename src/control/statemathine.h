#ifndef STATEMATHINE_H
#define STATEMATHINE_H
//#include "QObject"
#include "control/interfacestate.h"

#define STATE_MATHINE

class stateMathine:public QObject
{
    Q_OBJECT
public:
    static stateMathine* getInstance();
    QString commandDeal(QString para);
private:
    static stateMathine* _stateMathine;
    interfaceState* currentState = nullptr;
    stateMathine();
private slots:
    void stateChanged(interfaceState* nextState);
};

#endif // STATEMATHINE_H
