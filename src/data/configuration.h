#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "QString"

#define DATABASE_TYPE       "QSQLITE"
#define USER_CONNECT_NAME    "qt_sql_default_connection"
#define ACCOUNT_CONNECT_NAME    "qt_sql_account_connect"

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
