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

#ifndef __ELASTOS_DROID_TEXT_METHOD_DIALERKEYLISTENER_H__
#define __ELASTOS_DROID_TEXT_METHOD_DIALERKEYLISTENER_H__

#include "elastos/droid/text/method/NumberKeyListener.h"

namespace Elastos {
namespace Droid {
namespace Text {
namespace Method {

/**
 * For dialing-only text entry
 * <p></p>
 * As for all implementations of {@link KeyListener}, this class is only concerned
 * with hardware keyboards.  Software input methods have no obligation to trigger
 * the methods in this class.
 */
class ECO_PUBLIC DialerKeyListener
    : public NumberKeyListener
    , public IDialerKeyListener
{
public:
    CAR_INTERFACE_DECL()

    DialerKeyListener();

    virtual ~DialerKeyListener();

    CARAPI constructor();

    static CARAPI GetInstance(
        /* [out] */ IDialerKeyListener** ret);

    CARAPI GetInputType(
        /* [out] */ Int32* ret);

    static CARAPI GetCHARACTERS(
        /* [out, callee] */ ArrayOf<Char32>** ret);

    //override
    CARAPI OnKeyUp(
        /* [in] */ IView* view,
        /* [in] */ IEditable* content,
        /* [in] */ Int32 keyCode,
        /* [in] */ IKeyEvent* event,
        /* [out] */ Boolean* ret);

    CARAPI ClearMetaKeyState(
        /* [in] */ IView* view,
        /* [in] */ IEditable* content,
        /* [in] */ Int32 states);

protected:
    //@Override
    CARAPI_(AutoPtr< ArrayOf<Char32> >) GetAcceptedChars();

    /**
     * Overrides the superclass's lookup method to prefer the number field
     * from the KeyEvent.
     */
    CARAPI_(Int32) Lookup(
        /* [in] */ IKeyEvent* event,
        /* [in] */ ISpannable* content);

public:
    /**
     * The characters that are used.
     *
     * @see KeyEvent#getMatch
     * @see #getAcceptedChars
     */
    static const AutoPtr<ArrayOf<Char32> > CHARACTERS;

private:
    static AutoPtr<IDialerKeyListener> sInstance;
};

} // namespace Method
} // namespace Text
} // namepsace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_TEXT_METHOD_DIALERKEYLISTENER_H__
