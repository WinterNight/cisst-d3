#include <cisstCommon/cmnPortability.h>
#include <cisstCommon/cmnLogger.h>
#include <cisstCommon/cmnGetChar.h>
#include <cisstMultiTask/mtsManagerGlobal.h>
#include <cisstMultiTask/mtsManagerLocal.h>

#include <cisstOSAbstraction/osaThreadedLogFile.h>
#include <cisstMultiTask/mtsTaskManager.h>

#include <QApplication>

#include "supervisorQtComponent.h"

#if (CISST_OS == CISST_LINUX_XENOMAI)
#include <sys/mman.h>
#endif

int main(int argc, char *argv[])
{
#if (CISST_OS == CISST_LINUX_XENOMAI)
    mlockall(MCL_CURRENT|MCL_FUTURE);
#endif

    // log configuration
    cmnLogger::SetMask(CMN_LOG_ALLOW_ALL);
    cmnLogger::SetMaskDefaultLog(CMN_LOG_ALLOW_ALL);
    cmnLogger::AddChannel(std::cout, CMN_LOG_ALLOW_ERRORS_AND_WARNINGS);
    cmnLogger::SetMaskClassMatching("mts", CMN_LOG_ALLOW_ALL);
    cmnLogger::SetMaskClass("supervisorQtComponent", CMN_LOG_ALLOW_ALL);
    cmnLogger::SetMaskFunction(CMN_LOG_ALLOW_ALL);

    // create a Qt user interface
    QApplication application(argc, argv);

    // create the components with their respective UIs
    // supervisorQtComponent * supervisor = new supervisorQtComponent("supervisorQtComponent");

    // From d3 Component Viewer
    std::string ipGCM;
    if (argc == 2) {
        ipGCM = argv[1]; // connect to GCM with specified ip
    } else {
        ipGCM = "localhost"; // localhost by default
    }

    std::cout << "Connecting to Global Component Manager: " << ipGCM << " ... " << std::flush;

    mtsManagerLocal * localManager = 0;;
    const std::string thisProcessName = "supervisorQtComponent";
    try {
        localManager = mtsManagerLocal::GetInstance(ipGCM, thisProcessName);
    } catch (...) {
        std::cerr << "Failed" << std::endl;
        std::cerr << "Check if Global Component Manager is running." << std::endl;
        return 1;
    }
    std::cout << "Connected" << std::endl;

    supervisorQtComponent * componentViewer = new supervisorQtComponent("supervisorQtComponent");

    localManager->AddComponent(componentViewer);

    localManager->CreateAll();
    localManager->WaitForStateAll(mtsComponentState::READY);

    localManager->StartAll();
    localManager->WaitForStateAll(mtsComponentState::ACTIVE);

    // loop until 'q' is pressed
    // int key = ' ';
    // std::cout << "Press 'q' to quit" << std::endl;
    // while (key != 'q') {
    //     key = cmnGetChar();
    // }
    // std::cout << "Quitting ..." << std::endl;

    // run Qt user interface
    application.exec();

    // kill all components and perform cleanup
    localManager->KillAll();
    localManager->WaitForStateAll(mtsComponentState::FINISHED, 2.0 * cmn_s);

    localManager->Cleanup();
    delete componentViewer;
    return 0;
}
