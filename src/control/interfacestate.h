#ifndef INTERFACESTATE_H
#define INTERFACESTATE_H
#include "QString"
#include "QObject"
#include "control/terminalcontrol.h"

#define COMMAND_ERRO  "command erro"

enum WAIT_NEXT_PARA_STATE{
    wait_para1,
    wait_para2,
    wait_para3,
    wait_para4,
};

class interfaceState: public QObject
{
    Q_OBJECT
public:
    QString deal(QString para);
protected:
    WAIT_NEXT_PARA_STATE stage = WAIT_NEXT_PARA_STATE::wait_para1;
    virtual QString waitPara1Deal(QString para);
    virtual QString waitPara2Deal(QString para);
    virtual QString waitPara3Deal(QString para);
    virtual QString waitPara4Deal(QString para);
signals:
    void changeState(interfaceState* state);
};

#endif // INTERFACESTATE_H
