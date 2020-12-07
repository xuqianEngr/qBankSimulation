#ifndef ADDUSERSTATE_H
#define ADDUSERSTATE_H
#include "control/interfacestate.h"
#include "database/usermanerger.h"

class adduserState: interfaceState
{
public:
    adduserState(QString* cout);
    QString waitPara1Deal(QString para) override;
    QString waitPara2Deal(QString para) override;
private:
    LOGIN_MESSAGE newUser;
};
#endif // ADDUSERSTATE_H
