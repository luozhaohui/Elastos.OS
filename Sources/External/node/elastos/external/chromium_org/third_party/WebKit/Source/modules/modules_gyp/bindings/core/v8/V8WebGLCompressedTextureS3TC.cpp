// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8WebGLCompressedTextureS3TC.h"

#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "bindings/v8/V8HiddenValue.h"
#include "bindings/v8/V8ObjectConstructor.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace WebCore {

static void initializeScriptWrappableForInterface(WebGLCompressedTextureS3TC* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8WebGLCompressedTextureS3TC::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::WebGLCompressedTextureS3TC* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8WebGLCompressedTextureS3TC::wrapperTypeInfo = { gin::kEmbedderBlink, V8WebGLCompressedTextureS3TC::domTemplate, V8WebGLCompressedTextureS3TC::derefObject, 0, 0, 0, V8WebGLCompressedTextureS3TC::installPerContextEnabledMethods, 0, WrapperTypeObjectPrototype, RefCountedObject };

namespace WebGLCompressedTextureS3TCV8Internal {

template <typename T> void V8_USE(T) { }

} // namespace WebGLCompressedTextureS3TCV8Internal

static void configureV8WebGLCompressedTextureS3TCTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "WebGLCompressedTextureS3TC", v8::Local<v8::FunctionTemplate>(), V8WebGLCompressedTextureS3TC::internalFieldCount,
        0, 0,
        0, 0,
        0, 0,
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();
    static const V8DOMConfiguration::ConstantConfiguration V8WebGLCompressedTextureS3TCConstants[] = {
        {"COMPRESSED_RGB_S3TC_DXT1_EXT", 0x83F0},
        {"COMPRESSED_RGBA_S3TC_DXT1_EXT", 0x83F1},
        {"COMPRESSED_RGBA_S3TC_DXT3_EXT", 0x83F2},
        {"COMPRESSED_RGBA_S3TC_DXT5_EXT", 0x83F3},
    };
    V8DOMConfiguration::installConstants(functionTemplate, prototypeTemplate, V8WebGLCompressedTextureS3TCConstants, WTF_ARRAY_LENGTH(V8WebGLCompressedTextureS3TCConstants), isolate);

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8WebGLCompressedTextureS3TC::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8WebGLCompressedTextureS3TCTemplate);
}

bool V8WebGLCompressedTextureS3TC::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8WebGLCompressedTextureS3TC::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

WebGLCompressedTextureS3TC* V8WebGLCompressedTextureS3TC::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

v8::Handle<v8::Object> wrap(WebGLCompressedTextureS3TC* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8WebGLCompressedTextureS3TC>(impl, isolate));
    return V8WebGLCompressedTextureS3TC::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8WebGLCompressedTextureS3TC::createWrapper(PassRefPtr<WebGLCompressedTextureS3TC> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8WebGLCompressedTextureS3TC>(impl.get(), isolate));
    if (ScriptWrappable::wrapperCanBeStoredInObject(impl.get())) {
        const WrapperTypeInfo* actualInfo = ScriptWrappable::fromObject(impl.get())->typeInfo();
        // Might be a XXXConstructor::wrapperTypeInfo instead of an XXX::wrapperTypeInfo. These will both have
        // the same object de-ref functions, though, so use that as the basis of the check.
        RELEASE_ASSERT_WITH_SECURITY_IMPLICATION(actualInfo->derefObjectFunction == wrapperTypeInfo.derefObjectFunction);
    }

    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &wrapperTypeInfo, toInternalPointer(impl.get()), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;

    installPerContextEnabledProperties(wrapper, impl.get(), isolate);
    V8DOMWrapper::associateObjectWithWrapper<V8WebGLCompressedTextureS3TC>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}

void V8WebGLCompressedTextureS3TC::derefObject(void* object)
{
    fromInternalPointer(object)->deref();
}

template<>
v8::Handle<v8::Value> toV8NoInline(WebGLCompressedTextureS3TC* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore
