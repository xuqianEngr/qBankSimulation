#include "workpath.h"

QString getWorkPath()
{
    //QDir dir(QDir::homePath());
    QDir dir(QDir::currentPath());
    if(!dir.exists(WORK_DIR_NAME))
    {
        dir.mkdir(WORK_DIR_NAME);
    }
    return QDir::currentPath() + "/" + WORK_DIR_NAME;
}

QString getDatabasePath()
{
    QString path = getWorkPath();
    QDir dir(path);
    if(!dir.exists(DATABASE_DIR_NAME))
    {
        dir.mkdir(DATABASE_DIR_NAME);
    }
    return getWorkPath() + "/" + DATABASE_DIR_NAME;
}
