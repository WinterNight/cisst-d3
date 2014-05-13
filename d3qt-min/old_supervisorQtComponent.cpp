#include "supervisorQtComponent.h"
#include <cisstMultiTask/mtsInterfaceRequired.h>

#include <QUrl>

CMN_IMPLEMENT_SERVICES(supervisorQtComponent);

supervisorQtComponent::supervisorQtComponent(const std::string & componentName):
    mtsComponent(componentName)
{
    /*
    // create the cisstMultiTask interface with commands and events
    mtsInterfaceRequired * required = AddInterfaceRequired("Required");
    if (required) {
        required->AddFunction("Void", Void);
        required->AddFunction("Write", Write);
        required->AddFunction("Read", Read);
        required->AddFunction("QualifiedRead", QualifiedRead);
        required->AddEventHandlerVoid(&supervisorQtComponent::EventVoidHandler, this, "EventVoid");
        required->AddEventHandlerWrite(&supervisorQtComponent::EventWriteHandler, this, "EventWrite");
    }
    */

    supervisorWidget.setupUi(&CentralWidget);

    std::stringstream url;
    //url << "file://" << SF_SOURCE_ROOT_DIR << "/programs/supervisor/Qt/html/cubism/period.html";
    url << "PCI.html";
    QUrl startURL = QUrl(url.str().c_str());
    supervisorWidget.webViewMonitor->setUrl(startURL);

    MainWindow.setCentralWidget(&CentralWidget);
    MainWindow.setWindowTitle(QString::fromStdString(componentName));
    MainWindow.show();

    /*
    // trigger void command
    QObject::connect(supervisorWidget.VoidButton, SIGNAL(clicked()),
                     this, SLOT(VoidQSlot()));
    // trigger write command
    QObject::connect(supervisorWidget.WriteSlider, SIGNAL(valueChanged(int)),
                     this, SLOT(WriteQSlot(int)));
    // trigger read command and then refresh the UI
    QObject::connect(supervisorWidget.ReadButton, SIGNAL(clicked()),
                     this, SLOT(ReadQSlot()));
    QObject::connect(this, SIGNAL(ReadQSignal(int)),
                     supervisorWidget.ReadValue, SLOT(setNum(int)));
    // trigger qualified read command and then refresh the UI
    QObject::connect(supervisorWidget.QualifiedReadSlider, SIGNAL(valueChanged(int)),
                     this, SLOT(QualifiedReadQSlot(int)));
    QObject::connect(this, SIGNAL(QualifiedReadQSignal(int)),
                     supervisorWidget.QualifiedReadReadValue, SLOT(setNum(int)));
    // refresh event counter when events are received
    QObject::connect(this, SIGNAL(EventQSignal(int)),
                     supervisorWidget.EventValue, SLOT(setNum(int)));
                     */
}

#if 0
void supervisorQtComponent::EventVoidHandler(void)
{
    EventCounter = 0;
    //emit EventQSignal(EventCounter);
}


void supervisorQtComponent::EventWriteHandler(const mtsInt & value)
{
    EventCounter += value.Data;
    //emit EventQSignal(EventCounter);
}


void supervisorQtComponent::VoidQSlot(void)
{
    Void();
}


void supervisorQtComponent::WriteQSlot(int newValue)
{
    mtsInt data = newValue;
    Write(data);
}


void supervisorQtComponent::ReadQSlot(void)
{
    mtsInt data;
    Read(data);
    emit ReadQSignal(data.Data);
}


void supervisorQtComponent::QualifiedReadQSlot(int newValue)
{
    mtsInt qualifier, data;
    qualifier.Data = newValue;
    QualifiedRead(qualifier, data);
    emit QualifiedReadQSignal(data.Data);
}
#endif
