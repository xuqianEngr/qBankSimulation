#ifndef CHANGEPASSWDSTATE_H
#define CHANGEPASSWDSTATE_H
#include "control/interfacestate.h"
#include "database/usermanerger.h"

class changePasswdState: interfaceState
{
public:
    changePasswdState();
    QString waitPara1Deal(QString para) override;
    QString waitPara2Deal(QString para) override;
    QString waitPara3Deal(QString para) override;
    QString waitPara4Deal(QString para) override;
private:
    LOGIN_MESSAGE user;
};

#endif // CHANGEPASSWDSTATE_H
