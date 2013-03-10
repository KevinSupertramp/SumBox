#include <QCoreApplication>
#include <QTime>

#include <QFile>
#include <iostream>
#include <csignal>
#include "../shared/define.h"
#include "worldserver.h"

#include <QtSql>
#include "../shared/databases/database.h"
#include "../shared/logs/log.h"
#include "../shared/configuration/configmgr.h"

using namespace std;

WorldServer worldserver;

void exit(int /*s*/)
{
    Log::Write(LOG_TYPE_NORMAL, "Stopping SumBox::Worldserver...");
    worldserver.Stop();
    QCoreApplication::exit();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTime t;
    t.start();

    cout << "Starting SumBox::WorldServer..." << endl;

    if (!ConfigMgr::Instance()->LoadAuthConfig("authserver.conf"))
        return 0;

    if (!ConfigMgr::Instance()->LoadWorldConfig("worldserver.conf"))
        return 0;

    Log::Instance()->OpenFile("worldserver.log");

    Database* db = Database::Instance();
    if (db->Error())
        return 0;

    if(!worldserver.Start(QHostAddress::LocalHost, quint16(ConfigMgr::World()->GetInt("WorldServerPort"))))
    {
        Log::Write(LOG_TYPE_NORMAL, worldserver.GetErrorString().toAscii().data());
        return 0;
    }
    else
       Log::Write(LOG_TYPE_NORMAL, "Worldserver started on port %i : waiting for connections", ConfigMgr::World()->GetInt("WorldServerPort"));

    Log::Write(LOG_TYPE_NORMAL, "Press ctrl + c to quit.");
    Log::Write(LOG_TYPE_NORMAL, "SumBox::Worldserver started in %s sec.", QString::number(t.elapsed() / IN_MILLISECONDS).toAscii().data());

    signal(SIGINT, &exit);
    return a.exec();
}
