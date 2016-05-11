// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdlib.h>

#ifdef _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include "uv.h"
#include "node.h"
#include "v8.h"

#include "azure_c_shared_utility/threadapi.h"
#include "azure_c_shared_utility/iot_logging.h"

#include "module.h"
#include "message.h"
#include "message_bus.h"
#include "messageproperties.h"
#include "nodejs.h"

typedef struct NODEJS_MODULE_HANDLE_DATA_TAG
{
    MESSAGE_BUS_HANDLE          bus;
    STRING_HANDLE               main_path;
    STRING_HANDLE               configuration_json;
    THREAD_HANDLE               nodejs_thread;
    v8::Persistent<v8::Object>  module_object;
}NODEJS_MODULE_HANDLE_DATA;

static MODULE_HANDLE NODEJS_Create(MESSAGE_BUS_HANDLE bus, const void* configuration)
{
    return NULL;
}