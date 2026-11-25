/*
 *  SPDX-FileCopyrightText: 2024 Oliver Beard <olib141@outlook.com>
 *
 *  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
 */

#pragma once

#include <QQmlEngine>

#include <KOSRelease>

// org.kde.plasma.welcome, Distro
// Provides distro information for Welcome Center

class Distro : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    Distro(QObject *parent = nullptr);

    QString name() const;
    QString logo() const;
    QString homeUrl() const;
    QString bugReportUrl() const;

    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString logo READ logo CONSTANT)
    Q_PROPERTY(QString homeUrl READ homeUrl CONSTANT)
    Q_PROPERTY(QString bugReportUrl READ bugReportUrl CONSTANT)

    // A distribution's own switch for its pages: the key of the [Distribution] group of plasma-welcomerc, read as
    // KConfig reads it (the user's file, then each folder of XDG_CONFIG_DIRS), false when no file sets it. A
    // distribution can set it for a kind of machine, for example from a session script that puts a folder with its own
    // plasma-welcomerc in front of XDG_CONFIG_DIRS, and a page can read it in `show`.
    Q_INVOKABLE bool flag(const QString &key) const;

private:
    KOSRelease m_release;
};
