#ifndef COMMANDDEALSTATE_H
#define COMMANDDEALSTATE_H
#include "control/interfacestate.h"

#define CHANGE_PASSWD   "passwd"

class userCommandDealstate: interfaceState
{
public:
    userCommandDealstate();
    QString waitPara1Deal(QString para) override;
};

#endif // COMMANDDEALSTATE_H
