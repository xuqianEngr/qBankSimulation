#ifndef LOGINSTATE_H
#define LOGINSTATE_H
#include "control/interfacestate.h"
#include "database/usermanerger.h"

class loginState: interfaceState
{
public:
    loginState(QString* cout);
    QString waitPara1Deal(QString para) override;
    QString waitPara2Deal(QString para) override;
private:
    LOGIN_MESSAGE user;
};

#endif // LOGINSTATE_H
