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

#include <Elastos.CoreLibrary.Utility.h>
#include "elastos/droid/internal/utility/Preconditions.h"
#include <elastos/core/Math.h>
#include <elastos/core/Object.h>

using Elastos::Core::Object;
using Elastos::Utility::IIterator;

namespace Elastos {
namespace Droid {
namespace Internal {
namespace Utility {

const String Preconditions::TAG("Preconditions");

ECode Preconditions::CheckNotNull(
    /* [in] */ const String& reference)
{
    if (reference.IsNull()) {
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_NULL_POINTER_EXCEPTION, backtrace:\n%s",
            __FUNCTION__, stack.toString("").string());
        return E_NULL_POINTER_EXCEPTION;
    }
    return NOERROR;
}

ECode Preconditions::CheckNotNull(
    /* [in] */ IInterface* reference,
    /* [in] */ IObject* errorMessage)
{
    if (reference == NULL) {
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_NULL_POINTER_EXCEPTION, msg:%s, backtrace:\n%s",
            __FUNCTION__, TO_CSTR(errorMessage), stack.toString("").string());
        return E_NULL_POINTER_EXCEPTION;
    }
    return NOERROR;
}

ECode Preconditions::CheckState(
    /* [in] */ Boolean expression)
{
    if (!expression) {
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_ILLEGAL_STATE_EXCEPTION, backtrace:\n%s",
            __FUNCTION__, stack.toString("").string());
        return E_ILLEGAL_STATE_EXCEPTION;
    }
    return NOERROR;
}

ECode Preconditions::CheckFlagsArgument(
    /* [in] */ Int32 requestedFlags,
    /* [in] */ Int32 allowedFlags)
{
    if ((requestedFlags & allowedFlags) != requestedFlags) {
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "Line: %d, E_ILLEGAL_ARGUMENT_EXCEPTION: Requested flags 0x%x, but only 0x%x are allowed. backtrace:\n%s",
            __FUNCTION__, requestedFlags, allowedFlags, stack.toString("").string());
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }
    return NOERROR;
}

ECode Preconditions::CheckArgumentNonnegative(
    /* [in] */ Int32 value,
    /* [in] */ const String& errorMessage)
{
    if (value < 0) {
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_ILLEGAL_ARGUMENT_EXCEPTION, msg:%s, backtrace:\n%s",
            __FUNCTION__, errorMessage.string(), stack.toString("").string());
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }

    return NOERROR;
}

ECode Preconditions::CheckArgumentNonnegative(
    /* [in] */ Int64 value,
    /* [in] */ const String& errorMessage)
{
    if (value < 0) {
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_ILLEGAL_ARGUMENT_EXCEPTION, msg:%s, backtrace:\n%s",
            __FUNCTION__, errorMessage.string(), stack.toString("").string());
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }

    return NOERROR;
}

ECode Preconditions::CheckArgumentPositive(
    /* [in] */ Int32 value,
    /* [in] */ const String& errorMessage)
{
    if (value <= 0) {
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_ILLEGAL_ARGUMENT_EXCEPTION, msg:%s, backtrace:\n%s",
            __FUNCTION__, errorMessage.string(), stack.toString("").string());
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }

    return NOERROR;
}

ECode Preconditions::CheckArgumentFinite(
    /* [in] */ Float value,
    /* [in] */ const String& valueName)
{
    if (Elastos::Core::Math::IsNaN(value)) {
        Logger::E(TAG, "%s must not be NaN", valueName.string());
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_ILLEGAL_ARGUMENT_EXCEPTION, backtrace:\n%s",
            __FUNCTION__, stack.toString("").string());
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }
    else if (Elastos::Core::Math::IsInfinite(value)) {
        Logger::E(TAG, "%s must not be infinite", valueName.string());
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_ILLEGAL_ARGUMENT_EXCEPTION, backtrace:\n%s",
            __FUNCTION__, stack.toString("").string());
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }

    return NOERROR;
}

ECode Preconditions::CheckArgumentInRange(
    /* [in] */ Float value,
    /* [in] */ Float lower,
    /* [in] */ Float upper,
    /* [in] */ const String& valueName)
{
    if (Elastos::Core::Math::IsNaN(value)) {
        Logger::E(TAG, "%s must not be NaN", valueName.string());
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_ILLEGAL_ARGUMENT_EXCEPTION, backtrace:\n%s",
            __FUNCTION__, stack.toString("").string());
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }
    else if (value < lower) {
        Logger::E(TAG, "%s (%.2f) is out of range of [%f, %f] (too low)", valueName.string(), value, lower, upper);
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_ILLEGAL_ARGUMENT_EXCEPTION, backtrace:\n%s",
            __FUNCTION__, stack.toString("").string());
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }
    else if (value > upper) {
        Logger::E(TAG, "%s (%.2f) is out of range of [%f, %f] (too high)", valueName.string(), value, lower, upper);
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_ILLEGAL_ARGUMENT_EXCEPTION, backtrace:\n%s",
            __FUNCTION__, stack.toString("").string());
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }

    return NOERROR;
}

ECode Preconditions::CheckArgumentInRange(
    /* [in] */ Int32 value,
    /* [in] */ Int32 lower,
    /* [in] */ Int32 upper,
    /* [in] */ const String& valueName)
{
    if (value < lower) {
        Logger::E(TAG, "%s (%d) is out of range of [%d, %d] (too low)", valueName.string(), value, lower, upper);
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_ILLEGAL_ARGUMENT_EXCEPTION, backtrace:\n%s",
            __FUNCTION__, stack.toString("").string());
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }
    else if (value > upper) {
        Logger::E(TAG, "%s (%d) is out of range of [%d, %d] (too low)", valueName.string(), value, lower, upper);
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_ILLEGAL_ARGUMENT_EXCEPTION, backtrace:\n%s",
            __FUNCTION__, stack.toString("").string());
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }

    return NOERROR;
}

ECode Preconditions::CheckArrayElementsNotNull(
    /* [in] */ ArrayOf<IInterface*>* value,
    /* [in] */ const String& valueName)
{
    if (value == NULL) {
        Logger::E(TAG, "%s must not be NULL", valueName.string());
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_NULL_POINTER_EXCEPTION, backtrace:\n%s",
            __FUNCTION__, stack.toString("").string());
        return E_NULL_POINTER_EXCEPTION;
    }

    for (Int32 i = 0; i < value->GetLength(); ++i) {
        if ((*value)[i] == NULL) {
            Logger::E(TAG, "%s[%d] must not be NULL", valueName.string(), i);
            android::CallStack stack;
            stack.update();
            Logger::E(TAG, "%s, E_NULL_POINTER_EXCEPTION, backtrace:\n%s",
                __FUNCTION__, stack.toString("").string());
            return E_NULL_POINTER_EXCEPTION;
        }
    }

    return NOERROR;
}

ECode Preconditions::CheckCollectionElementsNotNull(
    /* [in] */ ICollection* value,
    /* [in] */ const String& valueName)
{
    if (value == NULL) {
        Logger::E(TAG, "%s must not be NULL", valueName.string());
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_NULL_POINTER_EXCEPTION, backtrace:\n%s",
            __FUNCTION__, stack.toString("").string());
        return E_NULL_POINTER_EXCEPTION;
    }

    Int64 ctr = 0;
    AutoPtr<IIterator> iter;
    value->GetIterator((IIterator**)&iter);
    Boolean hasNext;
    while (iter->HasNext(&hasNext), hasNext) {
        AutoPtr<IInterface> elem;
        iter->GetNext((IInterface**)&elem);
        if (elem == NULL) {
            Logger::E(TAG, "%s[%lld] must not be NULL", valueName.string(), ctr);
            android::CallStack stack;
            stack.update();
            Logger::E(TAG, "%s, E_NULL_POINTER_EXCEPTION, backtrace:\n%s",
                __FUNCTION__, stack.toString("").string());
            return E_NULL_POINTER_EXCEPTION;
        }
        ++ctr;
    }

    return NOERROR;
}

ECode Preconditions::CheckCollectionNotEmpty(
    /* [in] */ ICollection* value,
    /* [in] */ const String& valueName)
{
    if (value == NULL) {
        Logger::E(TAG, "%s must not be NULL", valueName.string());
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_NULL_POINTER_EXCEPTION, backtrace:\n%s",
            __FUNCTION__, stack.toString("").string());
        return E_NULL_POINTER_EXCEPTION;
    }

    Boolean isEmpty;
    value->IsEmpty(&isEmpty);
    if (isEmpty) {
        Logger::E(TAG, "%s is empty", valueName.string());
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_ILLEGAL_ARGUMENT_EXCEPTION, backtrace:\n%s",
            __FUNCTION__, stack.toString("").string());
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }
    return NOERROR;
}

ECode Preconditions::CheckArrayElementsInRange(
    /* [in] */ ArrayOf<Float>* value,
    /* [in] */ Float lower,
    /* [in] */ Float upper,
    /* [in] */ const String& valueName)
{
    if (value == NULL) {
        Logger::E(TAG, "%s must not be NULL", valueName.string());
        android::CallStack stack;
        stack.update();
        Logger::E(TAG, "%s, E_NULL_POINTER_EXCEPTION, backtrace:\n%s",
            __FUNCTION__, stack.toString("").string());
        return E_NULL_POINTER_EXCEPTION;
    }

    for (Int32 i = 0; i < value->GetLength(); ++i) {
        Float v = (*value)[i];

        if (Elastos::Core::Math::IsNaN(v)) {
            Logger::E(TAG, "%s[%d] must not be NaN", valueName.string(), i);
            android::CallStack stack;
            stack.update();
            Logger::E(TAG, "%s, E_ILLEGAL_ARGUMENT_EXCEPTION, backtrace:\n%s",
                __FUNCTION__, stack.toString("").string());
            return E_ILLEGAL_ARGUMENT_EXCEPTION;
        }
        else if (v < lower) {
            Logger::E(TAG, "%s[%d] is out of range of [%f, %f] (too low)",
                valueName.string(), i, lower, upper);
            android::CallStack stack;
            stack.update();
            Logger::E(TAG, "%s, E_ILLEGAL_ARGUMENT_EXCEPTION, backtrace:\n%s",
                __FUNCTION__, stack.toString("").string());
            return E_ILLEGAL_ARGUMENT_EXCEPTION;
        }
        else if (v > upper) {
            Logger::E(TAG, "%s[%d] is out of range of [%f, %f] (too high)",
                valueName.string(), i, lower, upper);
            android::CallStack stack;
            stack.update();
            Logger::E(TAG, "%s, E_ILLEGAL_ARGUMENT_EXCEPTION, backtrace:\n%s",
                __FUNCTION__, stack.toString("").string());
            return E_ILLEGAL_ARGUMENT_EXCEPTION;
        }
    }

    return NOERROR;
}

} // namespace Utility
} // namespace Internal
} // namespace Droid
} // namespace Elastos
