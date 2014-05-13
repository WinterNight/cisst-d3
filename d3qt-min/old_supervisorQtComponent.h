#ifndef _supervisorQtComponent_h
#define _supervisorQtComponent_h

#include <cisstMultiTask/mtsComponent.h>

#include <QMainWindow>
#include <QObject>

#include "ui_supervisorQtWidget.h"

class supervisorQtComponent : public QObject, public mtsComponent
{
    Q_OBJECT;
    CMN_DECLARE_SERVICES(CMN_NO_DYNAMIC_CREATION, CMN_LOG_LOD_RUN_ERROR);

public:
    supervisorQtComponent(const std::string & componentName);
    ~supervisorQtComponent(void) {};

    void Configure(const std::string & CMN_UNUSED(filename)) {};
public slots:
    std::string SayHi() {return "Hi";};

protected:
#if 0
    void EventVoidHandler(void);
    void EventWriteHandler(const mtsInt & value);
#endif

    Ui::supervisorQtWidget supervisorWidget;
    QDockWidget CentralWidget;
    QMainWindow MainWindow;

#if 0
    mtsFunctionVoid Void;
    mtsFunctionWrite Write;
    mtsFunctionRead Read;
    mtsFunctionQualifiedRead QualifiedRead;

    int EventCounter;

signals:
    void ReadQSignal(int newValue);
    void QualifiedReadQSignal(int newValue);
    void EventQSignal(int newValue);

    public slots:
        void VoidQSlot(void);
    void WriteQSlot(int newValue);
    void ReadQSlot(void);
    void QualifiedReadQSlot(int newValue);
#endif
};

CMN_DECLARE_SERVICES_INSTANTIATION(supervisorQtComponent);

#endif  // _supervisorQtComponent_h
