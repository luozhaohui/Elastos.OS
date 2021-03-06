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

#include "elastos/droid/os/CParcelUuidHelper.h"
#include "elastos/droid/os/CParcelUuid.h"

namespace Elastos {
namespace Droid {
namespace Os {

CAR_INTERFACE_IMPL(CParcelUuidHelper, Singleton, IParcelUuidHelper)

CAR_SINGLETON_IMPL(CParcelUuidHelper)

ECode CParcelUuidHelper::FromString(
    /* [in] */ const String& uuid,
    /* [out] */ IParcelUuid** id)
{
    return CParcelUuid::FromString(uuid, id);
}

} // namespace Os
} // namespace Droid
} // namespace Elastos