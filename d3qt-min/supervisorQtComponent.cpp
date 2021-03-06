/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-    */
/* ex: set filetype=cpp softtabstop=4 shiftwidth=4 tabstop=4 cindent expandtab: */

#include "supervisorQtComponent.h"
#include <cisstMultiTask/mtsManagerGlobal.h>
#include <fstream>
#include <QUrl>

// First Try
#include <QtWebKit/QWebFrame>
#include <QtWebKit/QWebView>
#include <QtWebKit/QWebPage>




supervisorQtComponent::supervisorQtComponent(const std::string & componentName) :
    mtsComponentViewer(componentName)
{
    supervisorWidget.setupUi(&CentralWidget);

    std::stringstream url;
    //url << "file://" << SF_SOURCE_ROOT_DIR << "/programs/supervisor/Qt/html/cubism/period.html";
    url << "../PCI.html";
    QUrl startURL = QUrl(url.str().c_str());
    supervisorWidget.webViewMonitor->setUrl(startURL);

    // First Try
    // QWebPage QWebView::page();
    // QWebFrame QWebPage::mainFrame();
    QWebFrame * frame = supervisorWidget.webViewMonitor->page()->mainFrame();
    // std::cout << "testing***********" << frame << std::endl;
    MyObject myObject;
    frame->addToJavaScriptWindowObject("myObject", &myObject);

    MainWindow.setCentralWidget(&CentralWidget);
    MainWindow.setWindowTitle(QString::fromStdString(componentName));
    MainWindow.show();

    // myWebPage.mainFrame()->addToJavaScriptWindowObject("myObject", &myObject);
}

supervisorQtComponent::~supervisorQtComponent()
{
}

void supervisorQtComponent::Configure(const std::string & filename)
{
    mtsComponentViewer::Configure(filename);

    std::cout << "###### supervisorQtComponent::Configure" << std::endl;
}

void supervisorQtComponent::Startup(void)
{
    mtsComponentViewer::Startup();

    std::cout << "###### supervisorQtComponent::Startup" << std::endl;
}

void supervisorQtComponent::Run(void)
{
    mtsComponentViewer::Run();

    std::cout << "###### supervisorQtComponent::Run" << std::endl;
}

void supervisorQtComponent::Cleanup(void)
{
    mtsComponentViewer::Cleanup();

    // close file for d3 ouput file
    parser->CloseFile();
    std::cout << "parser cleanup ................";
    std::cout << "###### supervisorQtComponent::Cleanup" << std::endl;
}

//------------------------------------------------------------ 
// Extract 
//------------------------------------------------------------ 
void supervisorQtComponent::SendAllInfo(void)
{
    static int cnt = 0;

    std::cout << "SendAllInfo (" << ++cnt << ")" << std::endl;

    mtsComponentViewer::SendAllInfo();

    std::vector<std::string> processList;
    std::vector<std::string> componentList;
    std::vector<std::string> providedInterfaceList;
    std::vector<std::string> requiredInterfaceList;
    size_t i, j, k;
    processList = ManagerComponentServices->GetNamesOfProcesses();
    for (i = 0; i < processList.size(); i++) {
        componentList = ManagerComponentServices->GetNamesOfComponents(processList[i]);

        /**
         * parse
         */
        Process *p = new Process(processList[i]);
        parser->Insert(p->GetName(), p);

        for (j = 0; j < componentList.size(); j++) {
            // if (mtsManagerGlobal::IsProxyComponent(componentList[j]))
            //     continue;
            // std::cout << "\tComponent: " << componentList[j] << std::endl;
            
            /**
             * parse
             */
            Component *c = new Component(componentList[j], mtsManagerComponentBase::IsManagerComponent(componentList[j]) ? "true" : "false");
            p->Insert(c->GetName(), c);

            ManagerComponentServices->GetNamesOfInterfaces(
                processList[i], componentList[j], 
                requiredInterfaceList, providedInterfaceList);
            for (k = 0; k < requiredInterfaceList.size(); ++k) {
                // std::cout << "\t\tRequired Interfaces: " << requiredInterfaceList[k] << std::endl;

                /**
                 * parse
                 */
                Interface *it = new Interface(requiredInterfaceList[k],
                        mtsManagerComponentBase::IsNameOfInternalInterface(requiredInterfaceList[k]) ? "true" : "false",
                        parser->GetInterfaceID());
                c->Insert(it->GetName(), it);
            }
            for (k = 0; k < providedInterfaceList.size(); ++k) {
                // std::cout << "\t\tProvided Interfaces: " << providedInterfaceList[k] << std::endl;

                /**
                 * parse
                 */
                Interface *it = new Interface(providedInterfaceList[k],
                        mtsManagerComponentBase::IsNameOfInternalInterface(providedInterfaceList[k]) ? "true" : "false",
                        parser->GetInterfaceID());
                c->Insert(it->GetName(), it);
            }
        }
    }

    std::cout << "\n\nConnections:";
    std::vector<mtsDescriptionConnection> connectionList;
    connectionList = ManagerComponentServices->GetListOfConnections();

    for (i = 0; i < connectionList.size(); i++) {
        // std::cout << "\t" << connectionList[i] << std::endl;
        parser->ParseConnection(connectionList[i].Client.ProcessName, connectionList[i].Client.ComponentName, connectionList[i].Client.InterfaceName,
                                connectionList[i].Server.ProcessName, connectionList[i].Server.ComponentName, connectionList[i].Server.InterfaceName);
    }

    parser->Write();
}

void supervisorQtComponent::ProcessResponse(void)
{
    mtsComponentViewer::ProcessResponse();

    std::cout << "###### supervisorQtComponent::ProcessResponse" << std::endl;
}

//------------------------------------------------------------ 
// Event Handlers
//------------------------------------------------------------ 
void supervisorQtComponent::AddComponentHandler(const mtsDescriptionComponent &componentInfo)
{
    mtsComponentViewer::AddComponentHandler(componentInfo);

    std::cout << "###### supervisorQtComponent: AddComponentHandler" << std::endl;
}

void supervisorQtComponent::ChangeStateHandler(const mtsComponentStateChange &componentStateChange)
{
    mtsComponentViewer::ChangeStateHandler(componentStateChange);

    std::cout << "###### supervisorQtComponent: ChangeStateHandler" << std::endl;
}

void supervisorQtComponent::AddConnectionHandler(const mtsDescriptionConnection &connection)
{
    mtsComponentViewer::AddConnectionHandler(connection);

    std::cout << "###### supervisorQtComponent: AddConnectionHandler" << std::endl;
}

void supervisorQtComponent::RemoveConnectionHandler(const mtsDescriptionConnection &connection)
{
    mtsComponentViewer::RemoveConnectionHandler(connection);

    std::cout << "###### supervisorQtComponent: RemoveConnectionHandler" << std::endl;
}
