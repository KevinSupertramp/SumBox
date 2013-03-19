#include "configuration.h"
#include "../logs/log.h"

Configuration::Configuration()
{
    m_file = NULL;
    m_config.clear();
}
Configuration::~Configuration()
{
    if (m_file)
        m_file->close();

    m_file = NULL;
    m_config.clear();
}

Configuration* Configuration::OpenFile(QString fileName)
{
    m_file = new QFile(fileName);
    if(!m_file->open(QIODevice::ReadOnly))
    {
        QString error = m_file->errorString();
        cout << "Cannot open configuration file " << fileName.toAscii().data() << " : " << error.toAscii().data() << endl;

        delete m_file;
        return NULL;
    }

    QSettings settings(fileName, QSettings::IniFormat);
    const QStringList keys = settings.allKeys();


    QStringList::const_iterator itr;
    for (itr = keys.constBegin(); itr != keys.constEnd(); ++itr)
        m_config.insert((*itr), settings.value((*itr)).toString());

    cout << "Configuration file " << fileName.toAscii().data() << " successfully loaded." << endl;
    m_file->close();
    return this;
}

QString Configuration::GetValue(QString name)
{
    ConfigMap::const_iterator i = m_config.find(name);
    if(i != m_config.end())
        return i.value();

    Log::Write(LOG_TYPE_NORMAL, "Trying to get config value \"%s\" but the value don't exist.", name.toAscii().data());
    return QString();
}

QString Configuration::GetQString(QString name)
{
    return GetValue(name);
}

std::string Configuration::GetString(QString name)
{
    return GetValue(name).toStdString();
}

bool Configuration::GetBool(QString name)
{
    QString val = GetValue(name);
    return (val == "true" || val == "TRUE" || val == "yes" || val == "YES" || val == "1");
}

int Configuration::GetInt(QString name)
{
    return GetValue(name).toInt();
}

int Configuration::GetUInt(QString name)
{
    return GetValue(name).toUInt();
}