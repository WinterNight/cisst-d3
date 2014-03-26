/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-    */
/* ex: set filetype=cpp softtabstop=4 shiftwidth=4 tabstop=4 cindent expandtab: */

#include "ComponentViewerD3.h"
#include <cisstMultiTask/mtsManagerGlobal.h>
#include <fstream>

ComponentViewerD3::ComponentViewerD3(const std::string & name = "ComponentViewerD3") :
    mtsComponentViewer(name)
{
}

ComponentViewerD3::~ComponentViewerD3()
{
}

void ComponentViewerD3::Configure(const std::string & filename)
{
    mtsComponentViewer::Configure(filename);

    std::cout << "###### ComponentViewerD3::Configure" << std::endl;
}

void ComponentViewerD3::Startup(void)
{
    mtsComponentViewer::Startup();

    std::cout << "###### ComponentViewerD3::Startup" << std::endl;
}

void ComponentViewerD3::Run(void)
{
    mtsComponentViewer::Run();

    std::cout << "###### ComponentViewerD3::Run" << std::endl;
}

void ComponentViewerD3::Cleanup(void)
{
    mtsComponentViewer::Cleanup();

    // close file for d3 ouput file
    parser->CloseFile();
    std::cout << "parser cleanup ................";
    std::cout << "###### ComponentViewerD3::Cleanup" << std::endl;
}

//------------------------------------------------------------ 
// Extract 
//------------------------------------------------------------ 
void ComponentViewerD3::SendAllInfo(void)
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
            if (mtsManagerGlobal::IsProxyComponent(componentList[j]))
                continue;
            std::cout << "\tComponent: " << componentList[j] << std::endl;
            
            /**
             * parse
             */
            Component *c = new Component(componentList[j], mtsManagerComponentBase::IsManagerComponent(componentList[j]) ? "true" : "false");
            p->Insert(c->GetName(), c);

            ManagerComponentServices->GetNamesOfInterfaces(
                processList[i], componentList[j], 
                requiredInterfaceList, providedInterfaceList);
            for (k = 0; k < requiredInterfaceList.size(); ++k) {
                std::cout << "\t\tRequired Interfaces: " << requiredInterfaceList[k] << std::endl;

                /**
                 * parse
                 */
                Interface *it = new Interface(requiredInterfaceList[k],
                        mtsManagerComponentBase::IsNameOfInternalInterface(requiredInterfaceList[k]) ? "true" : "false",
                        parser->GetInterfaceID());
                c->Insert(it->GetName(), it);
            }
            for (k = 0; k < providedInterfaceList.size(); ++k) {
                std::cout << "\t\tProvided Interfaces: " << providedInterfaceList[k] << std::endl;

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
    parser->Write();

    std::cout << "\n\nConnections:";
    std::vector<mtsDescriptionConnection> connectionList;
    connectionList = ManagerComponentServices->GetListOfConnections();

    std::cout << "\n\naaaaaaaaaaa:";
    for (i = 0; i < connectionList.size(); i++) {
        std::cout << "\t" << connectionList[i] << std::endl;
        // std::cout << connectionList[i].Client.ProcessName << endl;
        // std::cout << connectionList[i].Client.ComponentName << endl;
        // std::cout << connectionList[i].Client.InterfaceName << endl;
        // std::cout << connectionList[i].Server.ProcessName << endl;
        // std::cout << connectionList[i].Server.ComponentName << endl;
        // std::cout << connectionList[i].Server.InterfaceName << endl;
        // std::cout << endl;
        parser->ParseConnection(connectionList[i].Client.ProcessName, connectionList[i].Client.ComponentName, connectionList[i].Client.InterfaceName,
                                connectionList[i].Server.ProcessName, connectionList[i].Server.ComponentName, connectionList[i].Server.InterfaceName);
    }
}

void ComponentViewerD3::ProcessResponse(void)
{
    mtsComponentViewer::ProcessResponse();

    std::cout << "###### ComponentViewerD3::ProcessResponse" << std::endl;
}

//------------------------------------------------------------ 
// Event Handlers
//------------------------------------------------------------ 
void ComponentViewerD3::AddComponentHandler(const mtsDescriptionComponent &componentInfo)
{
    mtsComponentViewer::AddComponentHandler(componentInfo);

    std::cout << "###### ComponentViewerD3: AddComponentHandler" << std::endl;
}

void ComponentViewerD3::ChangeStateHandler(const mtsComponentStateChange &componentStateChange)
{
    mtsComponentViewer::ChangeStateHandler(componentStateChange);

    std::cout << "###### ComponentViewerD3: ChangeStateHandler" << std::endl;
}

void ComponentViewerD3::AddConnectionHandler(const mtsDescriptionConnection &connection)
{
    mtsComponentViewer::AddConnectionHandler(connection);

    std::cout << "###### ComponentViewerD3: AddConnectionHandler" << std::endl;
}

void ComponentViewerD3::RemoveConnectionHandler(const mtsDescriptionConnection &connection)
{
    mtsComponentViewer::RemoveConnectionHandler(connection);

    std::cout << "###### ComponentViewerD3: RemoveConnectionHandler" << std::endl;
}
