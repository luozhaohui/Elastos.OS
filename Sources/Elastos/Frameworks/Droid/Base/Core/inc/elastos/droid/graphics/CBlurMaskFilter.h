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

#ifndef __ELASTOS_DROID_GRAPHICS_CBLURMASKFILTER_H__
#define __ELASTOS_DROID_GRAPHICS_CBLURMASKFILTER_H__

#include "_Elastos_Droid_Graphics_CBlurMaskFilter.h"
#include "elastos/droid/graphics/MaskFilter.h"

namespace Elastos {
namespace Droid {
namespace Graphics {

/**
 * This takes a mask, and blurs its edge by the specified radius. Whether or
 * or not to include the original mask, and whether the blur goes outside,
 * inside, or straddles, the original mask's border, is controlled by the
 * Blur enum.
 */
CarClass(CBlurMaskFilter)
    , public MaskFilter
    , public IBlurMaskFilter
{
public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    /**
     * Create a blur maskfilter.
     *
     * @param radius The radius to extend the blur from the original mask. Must be > 0.
     * @param style  The Blur to use
     * @return       The new blur maskfilter
     */
    CARAPI constructor(
        /* [in] */ Float radius,
        /* [in] */ Int32 style);

private:
    static CARAPI NativeConstructor(
        /* [in] */ Float radius,
        /* [in] */ Int32 style,
        /* [out] */ Int64* outfilter);
};

} // namespace Graphics
} // namepsace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_GRAPHICS_CBLURMASKFILTER_H__
