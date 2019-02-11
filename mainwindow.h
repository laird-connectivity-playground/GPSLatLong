/******************************************************************************
** Copyright (C) 2018-2019 Laird Connectivity
**
** Project: GPSLatLong
**
** Module: mainwindow.h
**
** Notes:
**
** License: This program is free software: you can redistribute it and/or
**          modify it under the terms of the GNU General Public License as
**          published by the Free Software Foundation, version 3.
**
**          This program is distributed in the hope that it will be useful,
**          but WITHOUT ANY WARRANTY; without even the implied warranty of
**          MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**          GNU General Public License for more details.
**
**          You should have received a copy of the GNU General Public License
**          along with this program.  If not, see http://www.gnu.org/licenses/
**
*******************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/******************************************************************************/
// Include Files
/******************************************************************************/
#include <QMainWindow>
#include <QtLocation>
#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>
#include <QDateTime>

/******************************************************************************/
// Forward declaration of Class, Struct & Unions
/******************************************************************************/
namespace Ui
{
    class MainWindow;
}

/******************************************************************************/
// Class definitions
/******************************************************************************/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void
    PositionUpdated(
        QGeoPositionInfo gpiGPSLocation
        );
    void
    PositionUpdateFailed(
        );

private slots:
    void
    on_btn_GetLocation_clicked(
        );
    void
    on_btn_Export_clicked(
        );

private:
    Ui::MainWindow *ui;
    QGeoPositionInfoSource *gpisGPSSource;
};

#endif // MAINWINDOW_H
