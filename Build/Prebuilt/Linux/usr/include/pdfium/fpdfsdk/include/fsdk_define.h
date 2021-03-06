// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
 
// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef _FPDFSDK_DEFINE_H
#define _FPDFSDK_DEFINE_H

#ifdef _WIN32
#include <tchar.h>
#include <math.h>
#endif

//#define API5
#define API6
#define  _FPDFAPI_ASYNC_PARSING_
#define _FXSDK_OPENSOURCE_

#ifdef _FPDFEMB_WCE_
	#include "../../core/include/fpdfapi/fpdfapi.h" 
	#include "../../core/include/fpdfapi/fpdf_parser.h" 
	#include "../../core/include/fpdfapi/fpdf_module.h" 
	#include "../../core/include/fpdfapi/fpdf_render.h" 
	#include "../../core/include/fpdfapi/fpdf_pageobj.h" 
	#include "../../core/include/fpdfapi/fpdf_serial.h" 

	#include "../../core/include/fpdftext/fpdf_text.h"

	#include "../../core/include/fxge/fx_ge_win32.h"
	#include "../../core/include/fxge/fx_ge.h"

	#include "../../core/include/fxcodec/fx_codec.h"

	#include "../../core/include/fpdfdoc/fpdf_doc.h" 
	#include "../../core/include/fpdfdoc/fpdf_vt.h" 

	#include "../../core/include/fxcrt/fx_xml.h" 
	#include "../../core/include/fxcrt/fx_crypt.h"

#else
	#ifdef API6
		#include "../../core/include/fpdfapi/fpdf_parser.h" 
		#include "../../core/include/fpdfapi/fpdfapi.h" 
		#include "../../core/include/fpdfapi/fpdf_parser.h" 
		#include "../../core/include/fpdfapi/fpdf_module.h" 
		#include "../../core/include/fpdfapi/fpdf_render.h" 
		#include "../../core/include/fpdfapi/fpdf_pageobj.h" 
		#include "../../core/include/fpdfapi/fpdf_serial.h" 

		#include "../../core/include/fpdftext/fpdf_text.h"

		#include "../../core/include/fxge/fx_ge_win32.h"
		#include "../../core/include/fxge/fx_ge.h"

		#include "../../core/include/fxcodec/fx_codec.h"

		#include "../../core/include/fpdfdoc/fpdf_doc.h" 
		#include "../../core/include/fpdfdoc/fpdf_vt.h" 

		#include "../../core/include/fxcrt/fx_xml.h" 
	//	#include "../../core/include/fdrm/fx_crypt.h"
		#ifdef _LICENSED_BUILD_
			#include "../../cryptopp/Cryptlib.h"
		#endif
	#endif
#endif


#ifndef FX_GetAValue
/** @brief It retrieves an intensity value for the alpha component of a #FX_ARGB value. */
#define FX_GetAValue(argb)			((argb & 0xFF000000) >> 24)
#endif

#ifndef FX_GetRValue
/** @brief It retrieves an intensity value for the red component of a #FX_ARGB value. */
#define FX_GetRValue(argb)			((argb & 0x00FF0000) >> 16)
#endif

#ifndef FX_GetGValue
/** @brief It retrieves an intensity value for the green component of a #FX_ARGB value. */
#define FX_GetGValue(argb)			((argb & 0x0000FF00) >> 8)
#endif

#ifndef FX_GetBValue
/** @brief It retrieves an intensity value for the blue component of a #FX_ARGB value. */
#define FX_GetBValue(argb)			(argb & 0x000000FF)
#endif

#ifndef FX_ARGBTOCOLORREF
/** @brief Convert a #FX_ARGB to a #FX_COLORREF. */
#define FX_ARGBTOCOLORREF(argb)		((((FX_DWORD)argb & 0x00FF0000) >> 16)|((FX_DWORD)argb & 0x0000FF00)|(((FX_DWORD)argb & 0x000000FF) << 16))
#endif

#ifndef FX_COLORREFTOARGB
/** @brief Convert a #FX_COLORREF to a #FX_ARGB. */
#define FX_COLORREFTOARGB(rgb)		((FX_DWORD)0xFF000000|(((FX_DWORD)rgb & 0x000000FF) << 16)|((FX_DWORD)rgb & 0x0000FF00)|(((FX_DWORD)rgb & 0x00FF0000) >> 16))
#endif

typedef unsigned int FX_UINT;	

#include "fpdfview.h"

class CPDF_CustomAccess : public IFX_FileRead, public CFX_Object
{
public:
	CPDF_CustomAccess(FPDF_FILEACCESS* pFileAccess);
	virtual ~CPDF_CustomAccess() {}

	virtual CFX_ByteString GetFullPath() { return ""; }
	virtual FX_FILESIZE	GetSize() { return m_FileAccess.m_FileLen; }

	virtual FX_BOOL		GetByte(FX_DWORD pos, FX_BYTE& ch);
	virtual FX_BOOL		GetBlock(FX_DWORD pos, FX_LPBYTE pBuf, FX_DWORD size);
	virtual void		Release() { delete this; }

	virtual FX_BOOL		ReadBlock(void* buffer, FX_FILESIZE offset, size_t size);

	FPDF_FILEACCESS		m_FileAccess;
	FX_BYTE				m_Buffer[512];
	FX_DWORD			m_BufferOffset;
};

void		FSDK_SetSandBoxPolicy(FPDF_DWORD policy, FPDF_BOOL enable);
FPDF_BOOL	FSDK_IsSandBoxPolicyEnabled(FPDF_DWORD policy);


#endif//_FPDFSDK_DEFINE_H
