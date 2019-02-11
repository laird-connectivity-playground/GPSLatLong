/******************************************************************************
** Copyright (C) 2018-2019 Laird Connectivity
**
** Project: GPSLatLong
**
** Module: mainwindow.cpp
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

/******************************************************************************/
// Include Files
/******************************************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"

/******************************************************************************/
// Local Functions or Private Members
/******************************************************************************/
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //Constructor
    ui->setupUi(this);
    gpisGPSSource = QGeoPositionInfoSource::createDefaultSource(this);
    if (gpisGPSSource)
    {
        //Setup GPS location events
        connect(gpisGPSSource, SIGNAL(positionUpdated(QGeoPositionInfo)), this, SLOT(PositionUpdated(QGeoPositionInfo)));
        connect(gpisGPSSource, SIGNAL(updateTimeout()), this, SLOT(PositionUpdateFailed()));
    }
}

//=============================================================================
//=============================================================================
MainWindow::~MainWindow()
{
    //Destructor, clean up objects
    delete ui;
    disconnect(gpisGPSSource, SIGNAL(positionUpdated(QGeoPositionInfo)), this, SLOT(PositionUpdated(QGeoPositionInfo)));
    disconnect(gpisGPSSource, SIGNAL(updateTimeout()), this, SLOT(PositionUpdateFailed()));
    delete gpisGPSSource;
}

//=============================================================================
//=============================================================================
void
MainWindow::PositionUpdated(
    QGeoPositionInfo gpiGPSLocation
    )
{
    //Position update sucessfully received
    gpisGPSSource->stopUpdates();
    ui->edit_DisplayLog->appendPlainText(QString(QDateTime::currentDateTime().toString("> HH:mm:ss")).append(", ").append((ui->rdo_1M->isChecked() ? "1Mbps" : (ui->rdo_2M->isChecked() ? "2Mbps" : (ui->rdo_500K->isChecked() ? "500Kbps" : (ui->rdo_125K->isChecked() ? "125Kbps" : "??"))))).append(", Tag: ").append(ui->edit_Tag->text()).append("\r\nLat: ").append(QString::number(gpiGPSLocation.coordinate().latitude(), 'g', 9)).append(", Long: ").append(QString::number(gpiGPSLocation.coordinate().longitude(), 'g', 9)).append("\r\n"));

    //Re-enable the inputs
    ui->btn_GetLocation->setEnabled(true);
    ui->rdo_1M->setEnabled(true);
    ui->rdo_2M->setEnabled(true);
    ui->rdo_500K->setEnabled(true);
    ui->rdo_125K->setEnabled(true);
    ui->edit_Tag->setEnabled(true);
}

//=============================================================================
//=============================================================================
void
MainWindow::PositionUpdateFailed(
    )
{
    //Position update failed
    gpisGPSSource->stopUpdates();
    ui->edit_DisplayLog->appendPlainText("Position update failed, please try again...\r\n");

    //Re-enable the inputs
    ui->btn_GetLocation->setEnabled(true);
    ui->rdo_1M->setEnabled(true);
    ui->rdo_2M->setEnabled(true);
    ui->rdo_500K->setEnabled(true);
    ui->rdo_125K->setEnabled(true);
    ui->edit_Tag->setEnabled(true);
}

//=============================================================================
//=============================================================================
void
MainWindow::on_btn_GetLocation_clicked(
    )
{
    //Get current GPS location
    gpisGPSSource->startUpdates();

    //Disable the inputs
    ui->btn_GetLocation->setEnabled(false);
    ui->rdo_1M->setEnabled(false);
    ui->rdo_2M->setEnabled(false);
    ui->rdo_500K->setEnabled(false);
    ui->rdo_125K->setEnabled(false);
    ui->edit_Tag->setEnabled(false);
}

//=============================================================================
//=============================================================================
void
MainWindow::on_btn_Export_clicked(
    )
{
    //Export data (copy to clipboard)
    QApplication::clipboard()->setText(ui->edit_DisplayLog->toPlainText());
}
