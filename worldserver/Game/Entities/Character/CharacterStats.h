#ifndef CHARACTERSTATS_H
#define CHARACTERSTATS_H

#include <QtCore>

enum CharacterStatsType
{
    CHARACTER_STAT_TYPE_BASE,
    CHARACTER_STAT_TYPE_ITEM,
    CHARACTER_STAT_TYPE_DON,
    CHARACTER_STAT_TYPE_BOOST,
    TOTAL_CHARACTER_STAT_TYPE
};

enum CharacterStats
{
    CHARACTER_STAT_PA,
    CHARACTER_STAT_PM,
    CHARACTER_STAT_STRENGTH,
    CHARACTER_STAT_HEALTH,
    CHARACTER_STAT_WISDOM,
    CHARACTER_STAT_LUCK,
    CHARACTER_STAT_AGILITY,
    CHARACTER_STAT_INTELLIGENCE,
    CHARACTER_STAT_RANGE,
    CHARACTER_STAT_INVOCATION,
    CHARACTER_STAT_BONUS_DAMAGE,
    CHARACTER_STAT_BONUS_DAMAGE_MELEE,
    CHARACTER_STAT_BONUS_DAMAGE_SPELL,
    CHARACTER_STAT_BONUS_DAMAGE_PERCENT,
    CHARACTER_STAT_BONUS_HEAL,
    CHARACTER_STAT_BONUS_DAMAGE_TRAP,
    CHARACTER_STAT_BONUS_DAMAGE_TRAP_PERCENT,
    CHARACTER_STAT_BONUS_RETURN_DAMAGE,
    CHARACTER_STAT_BONUS_CRITICAL,
    CHARACTER_STAT_BONUS_FAIL,
    CHARACTER_STAT_DODGE_PA,
    CHARACTER_STAT_DODGE_PM,
    CHARACTER_STAT_RESI_NEUTRAL,
    CHARACTER_STAT_RESI_NEUTRAL_PERCENT,
    CHARACTER_STAT_RESI_NEUTRAL_PVP,
    CHARACTER_STAT_RESI_NEUTRAL_PVP_PERCENT,
    CHARACTER_STAT_RESI_STRENGTH,
    CHARACTER_STAT_RESI_STRENGTH_PERCENT,
    CHARACTER_STAT_RESI_STRENGTH_PVP,
    CHARACTER_STAT_RESI_STRENGTH_PVP_PERCENT,
    CHARACTER_STAT_RESI_LUCK,
    CHARACTER_STAT_RESI_LUCK_PERCENT,
    CHARACTER_STAT_RESI_LUCK_PVP,
    CHARACTER_STAT_RESI_LUCK_PVP_PERCENT,
    CHARACTER_STAT_RESI_AGILITY,
    CHARACTER_STAT_RESI_AGILITY_PERCENT,
    CHARACTER_STAT_RESI_AGILITY_PVP,
    CHARACTER_STAT_RESI_AGILITY_PVP_PERCENT,
    CHARACTER_STAT_RESI_INTELLIGENCE,
    CHARACTER_STAT_RESI_INTELLIGENCE_PERCENT,
    CHARACTER_STAT_RESI_INTELLIGENCE_PVP,
    CHARACTER_STAT_RESI_INTELLIGENCE_PVP_PERCENT,
    TOTAL_CHARACTER_STATS
};

struct sCharacterStats
{
    sCharacterStats()
    {
        for (quint8 i = 0; i < TOTAL_CHARACTER_STAT_TYPE; ++i)
            m_stats[i] = 0;
    }

    void Set(CharacterStatsType type, QVariant value)
    {
        m_stats[type] = value;
    }

    QVariant Get(CharacterStatsType type)
    {
        return m_stats[type];
    }

    QString ToPacketString()
    {
        QString stats = QString();
        for (quint8 i = 0; i < TOTAL_CHARACTER_STAT_TYPE; ++i)
            stats += m_stats[i].toByteArray() + ",";

        return stats.remove(stats.length() - 1, 1) + "|";
    }

    QVariant m_stats[TOTAL_CHARACTER_STAT_TYPE];
};

#endif // CHARACTERSTATS_H
