#include <cisstOSAbstraction/osaThreadedLogFile.h>
#include <cisstMultiTask/mtsTaskManager.h>

#include <QApplication>

#include "supervisorQtComponent.h"

int main(int argc, char *argv[])
{
    // log configuration
    cmnLogger::SetMask(CMN_LOG_ALLOW_ALL);
    cmnLogger::SetMaskDefaultLog(CMN_LOG_ALLOW_ALL);
    cmnLogger::AddChannel(std::cout, CMN_LOG_ALLOW_ERRORS_AND_WARNINGS);
    cmnLogger::SetMaskClassMatching("mts", CMN_LOG_ALLOW_ALL);
    cmnLogger::SetMaskClass("supervisorQtComponent", CMN_LOG_ALLOW_ALL);

    // create a Qt user interface
    QApplication application(argc, argv);

    // create the components with their respective UIs
    supervisorQtComponent * supervisor = new supervisorQtComponent("supervisor");

    // add the components to the component manager
    mtsComponentManager * componentManager = mtsComponentManager::GetInstance();

    // connect the components, e.g. RequiredInterface -> ProvidedInterface
    /*
    componentManager->Connect("supervisor", "Required",
                              "ServerDelay", "Provided");
    componentManager->Connect("ServerDelay", "Required",
                              "Server", "Provided");
                              */

    // create and start all components
    componentManager->CreateAll();
    componentManager->WaitForStateAll(mtsComponentState::READY);
    componentManager->StartAll();
    componentManager->WaitForStateAll(mtsComponentState::ACTIVE);

    // run Qt user interface
    application.exec();

    // kill all components and perform cleanup
    componentManager->KillAll();
    componentManager->WaitForStateAll(mtsComponentState::FINISHED, 2.0 * cmn_s);

    componentManager->Cleanup();
    return 0;
}
