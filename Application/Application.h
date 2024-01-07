#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Application.h"

class Application : public QMainWindow
{
    Q_OBJECT

public:
    Application(QWidget *parent = nullptr);
    ~Application();

private:
    Ui::ApplicationClass ui;
};
