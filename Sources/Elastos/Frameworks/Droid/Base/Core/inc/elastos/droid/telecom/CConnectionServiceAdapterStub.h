//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_DROID_TELECOM_CCONNECTIONSERVICEADAPTERSTUB_H__
#define __ELASTOS_DROID_TELECOM_CCONNECTIONSERVICEADAPTERSTUB_H__

#include "Elastos.Droid.Os.h"
#include "Elastos.Droid.Internal.h"
#include "_Elastos_Droid_Telecom_CConnectionServiceAdapterStub.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Os::IHandler;
using Elastos::Droid::Net::IUri;
using Elastos::Droid::Internal::Telecom::IIConnectionServiceAdapter;
using Elastos::Droid::Internal::Telecom::IRemoteServiceCallback;
using Elastos::Droid::Internal::Telecom::IIVideoProvider;
using Elastos::Core::Object;
using Elastos::Utility::IList;

namespace Elastos {
namespace Droid {
namespace Telecom {

CarClass(CConnectionServiceAdapterStub)
    , public Object
    , public IIConnectionServiceAdapter
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CARAPI constructor(
        /* [in] */ IHandler* handler);

    CARAPI HandleCreateConnectionComplete(
        /* [in] */ const String& id,
        /* [in] */ IConnectionRequest* request,
        /* [in] */ IParcelableConnection* connection);

    CARAPI SetActive(
        /* [in] */ const String& connectionId);

    CARAPI SetRinging(
        /* [in] */ const String& connectionId);

    CARAPI SetDialing(
        /* [in] */ const String& connectionId);

    CARAPI SetDisconnected(
        /* [in] */ const String& connectionId,
        /* [in] */ IDisconnectCause* disconnectCause);

    CARAPI SetOnHold(
        /* [in] */ const String& connectionId);

    CARAPI SetRingbackRequested(
        /* [in] */ const String& connectionId,
        /* [in] */ Boolean ringback);

    CARAPI SetCallCapabilities(
        /* [in] */ const String& connectionId,
        /* [in] */ Int32 callCapabilities);

    CARAPI SetIsConferenced(
        /* [in] */ const String& callId,
        /* [in] */ const String& conferenceCallId);

    CARAPI AddConferenceCall(
        /* [in] */ const String& callId,
        /* [in] */ IParcelableConference* parcelableConference);

    CARAPI RemoveCall(
        /* [in] */ const String& connectionId);

    CARAPI OnPostDialWait(
        /* [in] */ const String& connectionId,
        /* [in] */ const String& remainingDigits);

    CARAPI QueryRemoteConnectionServices(
        /* [in] */ IRemoteServiceCallback* callback);

    CARAPI SetVideoState(
        /* [in] */ const String& connectionId,
        /* [in] */ Int32 videoState);

    CARAPI SetVideoProvider(
        /* [in] */ const String& connectionId,
        /* [in] */ IIVideoProvider* videoProvider);

    CARAPI SetIsVoipAudioMode(
        /* [in] */ const String& connectionId,
        /* [in] */ Boolean isVoip);

    CARAPI SetStatusHints(
        /* [in] */ const String& connectionId,
        /* [in] */ IStatusHints* statusHints);

    CARAPI SetAddress(
        /* [in] */ const String& connectionId,
        /* [in] */ IUri* address,
        /* [in] */ Int32 presentation);

    CARAPI SetCallerDisplayName(
        /* [in] */ const String& connectionId,
        /* [in] */ const String& callerDisplayName,
        /* [in] */ Int32 presentation);

    CARAPI SetConferenceableConnections(
        /* [in] */ const String& connectionId,
        /* [in] */ IList* conferenceableConnectionIds);

public:
    AutoPtr<IHandler> mHandler;
};

} // namespace Telecom
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_TELECOM_CCONNECTIONSERVICEADAPTERSTUB_H__
