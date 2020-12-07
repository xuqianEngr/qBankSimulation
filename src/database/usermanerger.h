#ifndef USERMANERGER_H
#define USERMANERGER_H

#include "QString"
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include "data/configuration.h"

#define USERS_FILE_NAME   "users.db"
#define CONNECT_NAME    "qt_sql_default_connection"
#define DATABASE_TYPE       "QSQLITE"

#define ADMIN_DEFAULT_NAME      "admin"
#define ADMIN_DEFAULT_PASSWD    "123456"



QString getHash(QString string);
bool initUserDatabse();
bool addUser(LOGIN_MESSAGE user);
bool changePasswd(LOGIN_MESSAGE user);
bool checkUserExist(QString userName);
bool userLogin(LOGIN_MESSAGE* user);

#endif // USERMANERGER_H
