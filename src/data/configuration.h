#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "QString"

struct LOGIN_MESSAGE{
    QString name;
    QString hashPasswd;
    QString buildTime;
    QString loginTime;
};

class configuration
{
public:
    static configuration* getInstance();
    LOGIN_MESSAGE getLoginUser();
    void setLoginUser(LOGIN_MESSAGE user);
    void loginOut();
private:
    static configuration* _configuration;
    LOGIN_MESSAGE loginUser;
    configuration();
};

#endif // CONFIGURATION_H
