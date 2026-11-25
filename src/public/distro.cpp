/*
 *  SPDX-FileCopyrightText: 2024 Oliver Beard <olib141@outlook.com>
 *
 *  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
 */

#include "distro.h"

#include <KConfigGroup>
#include <KSharedConfig>

Distro::Distro(QObject *parent)
    : QObject(parent)
{
}

QString Distro::name() const
{
    return m_release.name();
}

QString Distro::logo() const
{
    return m_release.logo();
}

QString Distro::homeUrl() const
{
    return m_release.homeUrl();
}

QString Distro::bugReportUrl() const
{
    return m_release.bugReportUrl();
}

bool Distro::flag(const QString &key) const
{
    return KSharedConfig::openConfig(QStringLiteral("plasma-welcomerc"), KConfig::NoGlobals)->group(QStringLiteral("Distribution")).readEntry(key, false);
}

#include "moc_distro.cpp"
