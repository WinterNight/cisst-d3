/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-    */
/* ex: set filetype=cpp softtabstop=4 shiftwidth=4 tabstop=4 cindent expandtab: */
/*
  $Id: serverWithDelay.h 3419 2012-02-03 17:32:58Z adeguet1 $

  Author(s):  Anton Deguet
  Created on: 2012-02-02

  (C) Copyright 2012 Johns Hopkins University (JHU), All Rights
  Reserved.

--- begin cisst license - do not edit ---

This software is provided "as is" under an open source license, with
no warranty.  The complete license can be found in license.txt and
http://www.cisst.org/cisst/license.txt.

--- end cisst license ---

*/

#ifndef _serverWithDelay_h
#define _serverWithDelay_h

#include <cisstMultiTask/mtsComponentAddLatency.h>

class serverWithDelay: public mtsComponentAddLatency {
    CMN_DECLARE_SERVICES(CMN_NO_DYNAMIC_CREATION, CMN_LOG_ALLOW_ERRORS_AND_WARNINGS);

 public:
    serverWithDelay(const std::string & componentName, double period); 
};

CMN_DECLARE_SERVICES_INSTANTIATION(serverWithDelay);

#endif // _serverWithDelay_h
