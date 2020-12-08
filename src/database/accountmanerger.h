#ifndef ACCOUNTMANERGER_H
#define ACCOUNTMANERGER_H
#include "out/textout.h"
#include "QString"
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include "data/configuration.h"
#include "control/workpath.h"

#define NO_DATABASE     ERRO_HEAD+"no database file !!"

struct USER_SURVEY{
    QString freshDate;
    QString remain;
    QString regular;
};

class accountManerger
{
public:
    accountManerger(LOGIN_MESSAGE user);
    USER_SURVEY getSurvey();
    bool creatAccount();
    bool income(QString money, QString tag = NULL);
    bool expend(QString money, QString tag = NULL);
private:
    LOGIN_MESSAGE user;
    void checkoutdbconn(QSqlDatabase* dbconn);
};
#endif // ACCOUNTMANERGER_H
