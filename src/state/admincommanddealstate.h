#ifndef ADMINCOMMANDDEALSTATE_H
#define ADMINCOMMANDDEALSTATE_H
#include "control/interfacestate.h"

#define ADD_USER_COMMAND        "adduser"

class adminCommandDealState: interfaceState
{
public:
    adminCommandDealState();
    QString waitPara1Deal(QString para) override;
};

#endif // ADMINCOMMANDDEALSTATE_H
