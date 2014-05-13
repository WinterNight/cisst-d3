/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-    */
/* ex: set filetype=cpp softtabstop=4 shiftwidth=4 tabstop=4 cindent expandtab: */

#ifndef _supervisorQtComponent_h
#define _supervisorQtComponent_h

#include <cisstMultiTask/mtsComponentViewer.h>
#include <QMainWindow>
#include <QObject>

#include "Parser/Parser.h"
#include "Parser/Process.h"
#include "Parser/Component.h"
#include "Parser/Interface.h"

#include "ui_supervisorQtWidget.h"

class supervisorQtComponent : public QObject, public mtsComponentViewer
{

private:
    // Give an output file name to initialize Parser
    Parser * parser = new Parser("output.json");
protected:
    // Event Handlers
    void AddComponentHandler(const mtsDescriptionComponent &componentInfo);
    void ChangeStateHandler(const mtsComponentStateChange &componentStateChange);
    void AddConnectionHandler(const mtsDescriptionConnection &connectionInfo);
    void RemoveConnectionHandler(const mtsDescriptionConnection &connectionInfo);

    void SendAllInfo(void);
    void ProcessResponse(void);

    void Configure(const std::string & CMN_UNUSED(filename));
    void Startup(void);
    void Run(void);
    void Cleanup(void);

    Ui::supervisorQtWidget supervisorWidget;
    QDockWidget CentralWidget;
    QMainWindow MainWindow;

public:
    supervisorQtComponent(const std::string & name);
    virtual ~supervisorQtComponent();
};

class MyObject : public QObject {
     Q_OBJECT

     public slots:
         void doSomethingWithWebElement(const QWebElement&){
             std::cout << "do something" << std::endl;
         }
};
#endif
