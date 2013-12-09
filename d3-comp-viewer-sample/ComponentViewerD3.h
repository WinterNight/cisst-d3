/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-    */
/* ex: set filetype=cpp softtabstop=4 shiftwidth=4 tabstop=4 cindent expandtab: */

#ifndef _ComponentViewerD3_h
#define _ComponentViewerD3_h

#include <cisstMultiTask/mtsComponentViewer.h>
#include "Parser.h"

class ComponentViewerD3 : public mtsComponentViewer
{
private:
    // Give an output file name to initialize Parser
    Parser * parser = new Parser("output_d3");
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

public:
    ComponentViewerD3(const std::string & name);
    virtual ~ComponentViewerD3();
};

#endif
