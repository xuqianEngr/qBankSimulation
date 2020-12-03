#ifndef WORKPATH_H
#define WORKPATH_H
#include "QString"
#include "QFile"
#include "QDir"

#define WORK_DIR_NAME    ".qbank"
#define DATABASE_DIR_NAME     "database"
#define WORK_PATH    getWorkPath()     //工作路径
#define DATABSE_PATH  getDatabasePath()    //数据库存储路径

QString getWorkPath();
QString getDatabasePath();
#endif // WORKPATH_H
