// This file is generated by TypeBuilder_h.template.

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef v8_inspector_protocol_Debugger_h
#define v8_inspector_protocol_Debugger_h

#include "src/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.
#include "src/inspector/protocol/Runtime.h"
#include "include/inspector/Debugger.h"

namespace v8_inspector {
namespace protocol {
namespace Debugger {
using BreakpointId = String;
using CallFrameId = String;
class Location;
class ScriptPosition;
class LocationRange;
class CallFrame;
class Scope;
class SearchMatch;
class BreakLocation;
using ScriptLanguage = String;
class DebugSymbols;

// ------------- Forward and enum declarations.

namespace ScriptLanguageEnum {
 extern const char JavaScript[];
 extern const char WebAssembly[];
} // namespace ScriptLanguageEnum

namespace ContinueToLocation {
namespace TargetCallFramesEnum {
 extern const char* Any;
 extern const char* Current;
} // TargetCallFramesEnum
} // ContinueToLocation

namespace SetInstrumentationBreakpoint {
namespace InstrumentationEnum {
 extern const char* BeforeScriptExecution;
 extern const char* BeforeScriptWithSourceMapExecution;
} // InstrumentationEnum
} // SetInstrumentationBreakpoint

namespace SetPauseOnExceptions {
namespace StateEnum {
 extern const char* None;
 extern const char* Uncaught;
 extern const char* All;
} // StateEnum
} // SetPauseOnExceptions

namespace Paused {
namespace ReasonEnum {
 extern const char* Ambiguous;
 extern const char* Assert;
 extern const char* CSPViolation;
 extern const char* DebugCommand;
 extern const char* DOM;
 extern const char* EventListener;
 extern const char* Exception;
 extern const char* Instrumentation;
 extern const char* OOM;
 extern const char* Other;
 extern const char* PromiseRejection;
 extern const char* XHR;
} // ReasonEnum
} // Paused

// ------------- Type and builder declarations.

class  Location : public ::v8_crdtp::ProtocolObject<Location> {
public:
    ~Location() override { }

    String getScriptId() { return m_scriptId; }
    void setScriptId(const String& value) { m_scriptId = value; }

    int getLineNumber() { return m_lineNumber; }
    void setLineNumber(int value) { m_lineNumber = value; }

    bool hasColumnNumber() { return m_columnNumber.isJust(); }
    int getColumnNumber(int defaultValue) { return m_columnNumber.isJust() ? m_columnNumber.fromJust() : defaultValue; }
    void setColumnNumber(int value) { m_columnNumber = value; }

    template<int STATE>
    class LocationBuilder {
    public:
        enum {
            NoFieldsSet = 0,
            ScriptIdSet = 1 << 1,
            LineNumberSet = 1 << 2,
            AllFieldsSet = (ScriptIdSet | LineNumberSet | 0)};


        LocationBuilder<STATE | ScriptIdSet>& setScriptId(const String& value)
        {
            static_assert(!(STATE & ScriptIdSet), "property scriptId should not be set yet");
            m_result->setScriptId(value);
            return castState<ScriptIdSet>();
        }

        LocationBuilder<STATE | LineNumberSet>& setLineNumber(int value)
        {
            static_assert(!(STATE & LineNumberSet), "property lineNumber should not be set yet");
            m_result->setLineNumber(value);
            return castState<LineNumberSet>();
        }

        LocationBuilder<STATE>& setColumnNumber(int value)
        {
            m_result->setColumnNumber(value);
            return *this;
        }

        std::unique_ptr<Location> build()
        {
            static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
            return std::move(m_result);
        }

    private:
        friend class Location;
        LocationBuilder() : m_result(new Location()) { }

        template<int STEP> LocationBuilder<STATE | STEP>& castState()
        {
            return *reinterpret_cast<LocationBuilder<STATE | STEP>*>(this);
        }

        std::unique_ptr<protocol::Debugger::Location> m_result;
    };

    static LocationBuilder<0> create()
    {
        return LocationBuilder<0>();
    }

private:
    DECLARE_SERIALIZATION_SUPPORT();

    Location()
    {
          m_lineNumber = 0;
    }

    String m_scriptId;
    int m_lineNumber;
    Maybe<int> m_columnNumber;
};


class  ScriptPosition : public ::v8_crdtp::ProtocolObject<ScriptPosition> {
public:
    ~ScriptPosition() override { }

    int getLineNumber() { return m_lineNumber; }
    void setLineNumber(int value) { m_lineNumber = value; }

    int getColumnNumber() { return m_columnNumber; }
    void setColumnNumber(int value) { m_columnNumber = value; }

    template<int STATE>
    class ScriptPositionBuilder {
    public:
        enum {
            NoFieldsSet = 0,
            LineNumberSet = 1 << 1,
            ColumnNumberSet = 1 << 2,
            AllFieldsSet = (LineNumberSet | ColumnNumberSet | 0)};


        ScriptPositionBuilder<STATE | LineNumberSet>& setLineNumber(int value)
        {
            static_assert(!(STATE & LineNumberSet), "property lineNumber should not be set yet");
            m_result->setLineNumber(value);
            return castState<LineNumberSet>();
        }

        ScriptPositionBuilder<STATE | ColumnNumberSet>& setColumnNumber(int value)
        {
            static_assert(!(STATE & ColumnNumberSet), "property columnNumber should not be set yet");
            m_result->setColumnNumber(value);
            return castState<ColumnNumberSet>();
        }

        std::unique_ptr<ScriptPosition> build()
        {
            static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
            return std::move(m_result);
        }

    private:
        friend class ScriptPosition;
        ScriptPositionBuilder() : m_result(new ScriptPosition()) { }

        template<int STEP> ScriptPositionBuilder<STATE | STEP>& castState()
        {
            return *reinterpret_cast<ScriptPositionBuilder<STATE | STEP>*>(this);
        }

        std::unique_ptr<protocol::Debugger::ScriptPosition> m_result;
    };

    static ScriptPositionBuilder<0> create()
    {
        return ScriptPositionBuilder<0>();
    }

private:
    DECLARE_SERIALIZATION_SUPPORT();

    ScriptPosition()
    {
          m_lineNumber = 0;
          m_columnNumber = 0;
    }

    int m_lineNumber;
    int m_columnNumber;
};


class  LocationRange : public ::v8_crdtp::ProtocolObject<LocationRange> {
public:
    ~LocationRange() override { }

    String getScriptId() { return m_scriptId; }
    void setScriptId(const String& value) { m_scriptId = value; }

    protocol::Debugger::ScriptPosition* getStart() { return m_start.get(); }
    void setStart(std::unique_ptr<protocol::Debugger::ScriptPosition> value) { m_start = std::move(value); }

    protocol::Debugger::ScriptPosition* getEnd() { return m_end.get(); }
    void setEnd(std::unique_ptr<protocol::Debugger::ScriptPosition> value) { m_end = std::move(value); }

    template<int STATE>
    class LocationRangeBuilder {
    public:
        enum {
            NoFieldsSet = 0,
            ScriptIdSet = 1 << 1,
            StartSet = 1 << 2,
            EndSet = 1 << 3,
            AllFieldsSet = (ScriptIdSet | StartSet | EndSet | 0)};


        LocationRangeBuilder<STATE | ScriptIdSet>& setScriptId(const String& value)
        {
            static_assert(!(STATE & ScriptIdSet), "property scriptId should not be set yet");
            m_result->setScriptId(value);
            return castState<ScriptIdSet>();
        }

        LocationRangeBuilder<STATE | StartSet>& setStart(std::unique_ptr<protocol::Debugger::ScriptPosition> value)
        {
            static_assert(!(STATE & StartSet), "property start should not be set yet");
            m_result->setStart(std::move(value));
            return castState<StartSet>();
        }

        LocationRangeBuilder<STATE | EndSet>& setEnd(std::unique_ptr<protocol::Debugger::ScriptPosition> value)
        {
            static_assert(!(STATE & EndSet), "property end should not be set yet");
            m_result->setEnd(std::move(value));
            return castState<EndSet>();
        }

        std::unique_ptr<LocationRange> build()
        {
            static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
            return std::move(m_result);
        }

    private:
        friend class LocationRange;
        LocationRangeBuilder() : m_result(new LocationRange()) { }

        template<int STEP> LocationRangeBuilder<STATE | STEP>& castState()
        {
            return *reinterpret_cast<LocationRangeBuilder<STATE | STEP>*>(this);
        }

        std::unique_ptr<protocol::Debugger::LocationRange> m_result;
    };

    static LocationRangeBuilder<0> create()
    {
        return LocationRangeBuilder<0>();
    }

private:
    DECLARE_SERIALIZATION_SUPPORT();

    LocationRange()
    {
    }

    String m_scriptId;
    std::unique_ptr<protocol::Debugger::ScriptPosition> m_start;
    std::unique_ptr<protocol::Debugger::ScriptPosition> m_end;
};


class  CallFrame : public ::v8_crdtp::ProtocolObject<CallFrame> {
public:
    ~CallFrame() override { }

    String getCallFrameId() { return m_callFrameId; }
    void setCallFrameId(const String& value) { m_callFrameId = value; }

    String getFunctionName() { return m_functionName; }
    void setFunctionName(const String& value) { m_functionName = value; }

    bool hasFunctionLocation() { return m_functionLocation.isJust(); }
    protocol::Debugger::Location* getFunctionLocation(protocol::Debugger::Location* defaultValue) { return m_functionLocation.isJust() ? m_functionLocation.fromJust() : defaultValue; }
    void setFunctionLocation(std::unique_ptr<protocol::Debugger::Location> value) { m_functionLocation = std::move(value); }

    protocol::Debugger::Location* getLocation() { return m_location.get(); }
    void setLocation(std::unique_ptr<protocol::Debugger::Location> value) { m_location = std::move(value); }

    String getUrl() { return m_url; }
    void setUrl(const String& value) { m_url = value; }

    protocol::Array<protocol::Debugger::Scope>* getScopeChain() { return m_scopeChain.get(); }
    void setScopeChain(std::unique_ptr<protocol::Array<protocol::Debugger::Scope>> value) { m_scopeChain = std::move(value); }

    protocol::Runtime::RemoteObject* getThis() { return m_this.get(); }
    void setThis(std::unique_ptr<protocol::Runtime::RemoteObject> value) { m_this = std::move(value); }

    bool hasReturnValue() { return m_returnValue.isJust(); }
    protocol::Runtime::RemoteObject* getReturnValue(protocol::Runtime::RemoteObject* defaultValue) { return m_returnValue.isJust() ? m_returnValue.fromJust() : defaultValue; }
    void setReturnValue(std::unique_ptr<protocol::Runtime::RemoteObject> value) { m_returnValue = std::move(value); }

    bool hasCanBeRestarted() { return m_canBeRestarted.isJust(); }
    bool getCanBeRestarted(bool defaultValue) { return m_canBeRestarted.isJust() ? m_canBeRestarted.fromJust() : defaultValue; }
    void setCanBeRestarted(bool value) { m_canBeRestarted = value; }

    template<int STATE>
    class CallFrameBuilder {
    public:
        enum {
            NoFieldsSet = 0,
            CallFrameIdSet = 1 << 1,
            FunctionNameSet = 1 << 2,
            LocationSet = 1 << 3,
            UrlSet = 1 << 4,
            ScopeChainSet = 1 << 5,
            ThisSet = 1 << 6,
            AllFieldsSet = (CallFrameIdSet | FunctionNameSet | LocationSet | UrlSet | ScopeChainSet | ThisSet | 0)};


        CallFrameBuilder<STATE | CallFrameIdSet>& setCallFrameId(const String& value)
        {
            static_assert(!(STATE & CallFrameIdSet), "property callFrameId should not be set yet");
            m_result->setCallFrameId(value);
            return castState<CallFrameIdSet>();
        }

        CallFrameBuilder<STATE | FunctionNameSet>& setFunctionName(const String& value)
        {
            static_assert(!(STATE & FunctionNameSet), "property functionName should not be set yet");
            m_result->setFunctionName(value);
            return castState<FunctionNameSet>();
        }

        CallFrameBuilder<STATE>& setFunctionLocation(std::unique_ptr<protocol::Debugger::Location> value)
        {
            m_result->setFunctionLocation(std::move(value));
            return *this;
        }

        CallFrameBuilder<STATE | LocationSet>& setLocation(std::unique_ptr<protocol::Debugger::Location> value)
        {
            static_assert(!(STATE & LocationSet), "property location should not be set yet");
            m_result->setLocation(std::move(value));
            return castState<LocationSet>();
        }

        CallFrameBuilder<STATE | UrlSet>& setUrl(const String& value)
        {
            static_assert(!(STATE & UrlSet), "property url should not be set yet");
            m_result->setUrl(value);
            return castState<UrlSet>();
        }

        CallFrameBuilder<STATE | ScopeChainSet>& setScopeChain(std::unique_ptr<protocol::Array<protocol::Debugger::Scope>> value)
        {
            static_assert(!(STATE & ScopeChainSet), "property scopeChain should not be set yet");
            m_result->setScopeChain(std::move(value));
            return castState<ScopeChainSet>();
        }

        CallFrameBuilder<STATE | ThisSet>& setThis(std::unique_ptr<protocol::Runtime::RemoteObject> value)
        {
            static_assert(!(STATE & ThisSet), "property this should not be set yet");
            m_result->setThis(std::move(value));
            return castState<ThisSet>();
        }

        CallFrameBuilder<STATE>& setReturnValue(std::unique_ptr<protocol::Runtime::RemoteObject> value)
        {
            m_result->setReturnValue(std::move(value));
            return *this;
        }

        CallFrameBuilder<STATE>& setCanBeRestarted(bool value)
        {
            m_result->setCanBeRestarted(value);
            return *this;
        }

        std::unique_ptr<CallFrame> build()
        {
            static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
            return std::move(m_result);
        }

    private:
        friend class CallFrame;
        CallFrameBuilder() : m_result(new CallFrame()) { }

        template<int STEP> CallFrameBuilder<STATE | STEP>& castState()
        {
            return *reinterpret_cast<CallFrameBuilder<STATE | STEP>*>(this);
        }

        std::unique_ptr<protocol::Debugger::CallFrame> m_result;
    };

    static CallFrameBuilder<0> create()
    {
        return CallFrameBuilder<0>();
    }

private:
    DECLARE_SERIALIZATION_SUPPORT();

    CallFrame()
    {
    }

    String m_callFrameId;
    String m_functionName;
    Maybe<protocol::Debugger::Location> m_functionLocation;
    std::unique_ptr<protocol::Debugger::Location> m_location;
    String m_url;
    std::unique_ptr<protocol::Array<protocol::Debugger::Scope>> m_scopeChain;
    std::unique_ptr<protocol::Runtime::RemoteObject> m_this;
    Maybe<protocol::Runtime::RemoteObject> m_returnValue;
    Maybe<bool> m_canBeRestarted;
};


class  Scope : public ::v8_crdtp::ProtocolObject<Scope> {
public:
    ~Scope() override { }

    struct  TypeEnum {
        static const char* Global;
        static const char* Local;
        static const char* With;
        static const char* Closure;
        static const char* Catch;
        static const char* Block;
        static const char* Script;
        static const char* Eval;
        static const char* Module;
        static const char* WasmExpressionStack;
    }; // TypeEnum

    String getType() { return m_type; }
    void setType(const String& value) { m_type = value; }

    protocol::Runtime::RemoteObject* getObject() { return m_object.get(); }
    void setObject(std::unique_ptr<protocol::Runtime::RemoteObject> value) { m_object = std::move(value); }

    bool hasName() { return m_name.isJust(); }
    String getName(const String& defaultValue) { return m_name.isJust() ? m_name.fromJust() : defaultValue; }
    void setName(const String& value) { m_name = value; }

    bool hasStartLocation() { return m_startLocation.isJust(); }
    protocol::Debugger::Location* getStartLocation(protocol::Debugger::Location* defaultValue) { return m_startLocation.isJust() ? m_startLocation.fromJust() : defaultValue; }
    void setStartLocation(std::unique_ptr<protocol::Debugger::Location> value) { m_startLocation = std::move(value); }

    bool hasEndLocation() { return m_endLocation.isJust(); }
    protocol::Debugger::Location* getEndLocation(protocol::Debugger::Location* defaultValue) { return m_endLocation.isJust() ? m_endLocation.fromJust() : defaultValue; }
    void setEndLocation(std::unique_ptr<protocol::Debugger::Location> value) { m_endLocation = std::move(value); }

    template<int STATE>
    class ScopeBuilder {
    public:
        enum {
            NoFieldsSet = 0,
            TypeSet = 1 << 1,
            ObjectSet = 1 << 2,
            AllFieldsSet = (TypeSet | ObjectSet | 0)};


        ScopeBuilder<STATE | TypeSet>& setType(const String& value)
        {
            static_assert(!(STATE & TypeSet), "property type should not be set yet");
            m_result->setType(value);
            return castState<TypeSet>();
        }

        ScopeBuilder<STATE | ObjectSet>& setObject(std::unique_ptr<protocol::Runtime::RemoteObject> value)
        {
            static_assert(!(STATE & ObjectSet), "property object should not be set yet");
            m_result->setObject(std::move(value));
            return castState<ObjectSet>();
        }

        ScopeBuilder<STATE>& setName(const String& value)
        {
            m_result->setName(value);
            return *this;
        }

        ScopeBuilder<STATE>& setStartLocation(std::unique_ptr<protocol::Debugger::Location> value)
        {
            m_result->setStartLocation(std::move(value));
            return *this;
        }

        ScopeBuilder<STATE>& setEndLocation(std::unique_ptr<protocol::Debugger::Location> value)
        {
            m_result->setEndLocation(std::move(value));
            return *this;
        }

        std::unique_ptr<Scope> build()
        {
            static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
            return std::move(m_result);
        }

    private:
        friend class Scope;
        ScopeBuilder() : m_result(new Scope()) { }

        template<int STEP> ScopeBuilder<STATE | STEP>& castState()
        {
            return *reinterpret_cast<ScopeBuilder<STATE | STEP>*>(this);
        }

        std::unique_ptr<protocol::Debugger::Scope> m_result;
    };

    static ScopeBuilder<0> create()
    {
        return ScopeBuilder<0>();
    }

private:
    DECLARE_SERIALIZATION_SUPPORT();

    Scope()
    {
    }

    String m_type;
    std::unique_ptr<protocol::Runtime::RemoteObject> m_object;
    Maybe<String> m_name;
    Maybe<protocol::Debugger::Location> m_startLocation;
    Maybe<protocol::Debugger::Location> m_endLocation;
};


class  SearchMatch : public ::v8_crdtp::ProtocolObject<SearchMatch>,
    public API::SearchMatch {
public:
    ~SearchMatch() override { }

    double getLineNumber() { return m_lineNumber; }
    void setLineNumber(double value) { m_lineNumber = value; }

    String getLineContent() { return m_lineContent; }
    void setLineContent(const String& value) { m_lineContent = value; }

    template<int STATE>
    class SearchMatchBuilder {
    public:
        enum {
            NoFieldsSet = 0,
            LineNumberSet = 1 << 1,
            LineContentSet = 1 << 2,
            AllFieldsSet = (LineNumberSet | LineContentSet | 0)};


        SearchMatchBuilder<STATE | LineNumberSet>& setLineNumber(double value)
        {
            static_assert(!(STATE & LineNumberSet), "property lineNumber should not be set yet");
            m_result->setLineNumber(value);
            return castState<LineNumberSet>();
        }

        SearchMatchBuilder<STATE | LineContentSet>& setLineContent(const String& value)
        {
            static_assert(!(STATE & LineContentSet), "property lineContent should not be set yet");
            m_result->setLineContent(value);
            return castState<LineContentSet>();
        }

        std::unique_ptr<SearchMatch> build()
        {
            static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
            return std::move(m_result);
        }

    private:
        friend class SearchMatch;
        SearchMatchBuilder() : m_result(new SearchMatch()) { }

        template<int STEP> SearchMatchBuilder<STATE | STEP>& castState()
        {
            return *reinterpret_cast<SearchMatchBuilder<STATE | STEP>*>(this);
        }

        std::unique_ptr<protocol::Debugger::SearchMatch> m_result;
    };

    static SearchMatchBuilder<0> create()
    {
        return SearchMatchBuilder<0>();
    }

private:
    DECLARE_SERIALIZATION_SUPPORT();

    SearchMatch()
    {
          m_lineNumber = 0;
    }

    double m_lineNumber;
    String m_lineContent;
};


class  BreakLocation : public ::v8_crdtp::ProtocolObject<BreakLocation> {
public:
    ~BreakLocation() override { }

    String getScriptId() { return m_scriptId; }
    void setScriptId(const String& value) { m_scriptId = value; }

    int getLineNumber() { return m_lineNumber; }
    void setLineNumber(int value) { m_lineNumber = value; }

    bool hasColumnNumber() { return m_columnNumber.isJust(); }
    int getColumnNumber(int defaultValue) { return m_columnNumber.isJust() ? m_columnNumber.fromJust() : defaultValue; }
    void setColumnNumber(int value) { m_columnNumber = value; }

    struct  TypeEnum {
        static const char* DebuggerStatement;
        static const char* Call;
        static const char* Return;
    }; // TypeEnum

    bool hasType() { return m_type.isJust(); }
    String getType(const String& defaultValue) { return m_type.isJust() ? m_type.fromJust() : defaultValue; }
    void setType(const String& value) { m_type = value; }

    template<int STATE>
    class BreakLocationBuilder {
    public:
        enum {
            NoFieldsSet = 0,
            ScriptIdSet = 1 << 1,
            LineNumberSet = 1 << 2,
            AllFieldsSet = (ScriptIdSet | LineNumberSet | 0)};


        BreakLocationBuilder<STATE | ScriptIdSet>& setScriptId(const String& value)
        {
            static_assert(!(STATE & ScriptIdSet), "property scriptId should not be set yet");
            m_result->setScriptId(value);
            return castState<ScriptIdSet>();
        }

        BreakLocationBuilder<STATE | LineNumberSet>& setLineNumber(int value)
        {
            static_assert(!(STATE & LineNumberSet), "property lineNumber should not be set yet");
            m_result->setLineNumber(value);
            return castState<LineNumberSet>();
        }

        BreakLocationBuilder<STATE>& setColumnNumber(int value)
        {
            m_result->setColumnNumber(value);
            return *this;
        }

        BreakLocationBuilder<STATE>& setType(const String& value)
        {
            m_result->setType(value);
            return *this;
        }

        std::unique_ptr<BreakLocation> build()
        {
            static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
            return std::move(m_result);
        }

    private:
        friend class BreakLocation;
        BreakLocationBuilder() : m_result(new BreakLocation()) { }

        template<int STEP> BreakLocationBuilder<STATE | STEP>& castState()
        {
            return *reinterpret_cast<BreakLocationBuilder<STATE | STEP>*>(this);
        }

        std::unique_ptr<protocol::Debugger::BreakLocation> m_result;
    };

    static BreakLocationBuilder<0> create()
    {
        return BreakLocationBuilder<0>();
    }

private:
    DECLARE_SERIALIZATION_SUPPORT();

    BreakLocation()
    {
          m_lineNumber = 0;
    }

    String m_scriptId;
    int m_lineNumber;
    Maybe<int> m_columnNumber;
    Maybe<String> m_type;
};


class  DebugSymbols : public ::v8_crdtp::ProtocolObject<DebugSymbols> {
public:
    ~DebugSymbols() override { }

    struct  TypeEnum {
        static const char* None;
        static const char* SourceMap;
        static const char* EmbeddedDWARF;
        static const char* ExternalDWARF;
    }; // TypeEnum

    String getType() { return m_type; }
    void setType(const String& value) { m_type = value; }

    bool hasExternalURL() { return m_externalURL.isJust(); }
    String getExternalURL(const String& defaultValue) { return m_externalURL.isJust() ? m_externalURL.fromJust() : defaultValue; }
    void setExternalURL(const String& value) { m_externalURL = value; }

    template<int STATE>
    class DebugSymbolsBuilder {
    public:
        enum {
            NoFieldsSet = 0,
            TypeSet = 1 << 1,
            AllFieldsSet = (TypeSet | 0)};


        DebugSymbolsBuilder<STATE | TypeSet>& setType(const String& value)
        {
            static_assert(!(STATE & TypeSet), "property type should not be set yet");
            m_result->setType(value);
            return castState<TypeSet>();
        }

        DebugSymbolsBuilder<STATE>& setExternalURL(const String& value)
        {
            m_result->setExternalURL(value);
            return *this;
        }

        std::unique_ptr<DebugSymbols> build()
        {
            static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
            return std::move(m_result);
        }

    private:
        friend class DebugSymbols;
        DebugSymbolsBuilder() : m_result(new DebugSymbols()) { }

        template<int STEP> DebugSymbolsBuilder<STATE | STEP>& castState()
        {
            return *reinterpret_cast<DebugSymbolsBuilder<STATE | STEP>*>(this);
        }

        std::unique_ptr<protocol::Debugger::DebugSymbols> m_result;
    };

    static DebugSymbolsBuilder<0> create()
    {
        return DebugSymbolsBuilder<0>();
    }

private:
    DECLARE_SERIALIZATION_SUPPORT();

    DebugSymbols()
    {
    }

    String m_type;
    Maybe<String> m_externalURL;
};


// ------------- Backend interface.

class  Backend {
public:
    virtual ~Backend() { }

    virtual DispatchResponse continueToLocation(std::unique_ptr<protocol::Debugger::Location> in_location, Maybe<String> in_targetCallFrames) = 0;
    virtual DispatchResponse disable() = 0;
    virtual DispatchResponse enable(Maybe<double> in_maxScriptsCacheSize, String* out_debuggerId) = 0;
    virtual DispatchResponse evaluateOnCallFrame(const String& in_callFrameId, const String& in_expression, Maybe<String> in_objectGroup, Maybe<bool> in_includeCommandLineAPI, Maybe<bool> in_silent, Maybe<bool> in_returnByValue, Maybe<bool> in_generatePreview, Maybe<bool> in_throwOnSideEffect, Maybe<double> in_timeout, std::unique_ptr<protocol::Runtime::RemoteObject>* out_result, Maybe<protocol::Runtime::ExceptionDetails>* out_exceptionDetails) = 0;
    virtual DispatchResponse getPossibleBreakpoints(std::unique_ptr<protocol::Debugger::Location> in_start, Maybe<protocol::Debugger::Location> in_end, Maybe<bool> in_restrictToFunction, std::unique_ptr<protocol::Array<protocol::Debugger::BreakLocation>>* out_locations) = 0;
    virtual DispatchResponse getScriptSource(const String& in_scriptId, String* out_scriptSource, Maybe<Binary>* out_bytecode) = 0;
    virtual DispatchResponse getWasmBytecode(const String& in_scriptId, Binary* out_bytecode) = 0;
    virtual DispatchResponse getStackTrace(std::unique_ptr<protocol::Runtime::StackTraceId> in_stackTraceId, std::unique_ptr<protocol::Runtime::StackTrace>* out_stackTrace) = 0;
    virtual DispatchResponse pause() = 0;
    virtual DispatchResponse pauseOnAsyncCall(std::unique_ptr<protocol::Runtime::StackTraceId> in_parentStackTraceId) = 0;
    virtual DispatchResponse removeBreakpoint(const String& in_breakpointId) = 0;
    virtual DispatchResponse restartFrame(const String& in_callFrameId, std::unique_ptr<protocol::Array<protocol::Debugger::CallFrame>>* out_callFrames, Maybe<protocol::Runtime::StackTrace>* out_asyncStackTrace, Maybe<protocol::Runtime::StackTraceId>* out_asyncStackTraceId) = 0;
    virtual DispatchResponse resume(Maybe<bool> in_terminateOnResume) = 0;
    virtual DispatchResponse searchInContent(const String& in_scriptId, const String& in_query, Maybe<bool> in_caseSensitive, Maybe<bool> in_isRegex, std::unique_ptr<protocol::Array<protocol::Debugger::SearchMatch>>* out_result) = 0;
    virtual DispatchResponse setAsyncCallStackDepth(int in_maxDepth) = 0;
    virtual DispatchResponse setBlackboxPatterns(std::unique_ptr<protocol::Array<String>> in_patterns) = 0;
    virtual DispatchResponse setBlackboxedRanges(const String& in_scriptId, std::unique_ptr<protocol::Array<protocol::Debugger::ScriptPosition>> in_positions) = 0;
    virtual DispatchResponse setBreakpoint(std::unique_ptr<protocol::Debugger::Location> in_location, Maybe<String> in_condition, String* out_breakpointId, std::unique_ptr<protocol::Debugger::Location>* out_actualLocation) = 0;
    virtual DispatchResponse setInstrumentationBreakpoint(const String& in_instrumentation, String* out_breakpointId) = 0;
    virtual DispatchResponse setBreakpointByUrl(int in_lineNumber, Maybe<String> in_url, Maybe<String> in_urlRegex, Maybe<String> in_scriptHash, Maybe<int> in_columnNumber, Maybe<String> in_condition, String* out_breakpointId, std::unique_ptr<protocol::Array<protocol::Debugger::Location>>* out_locations) = 0;
    virtual DispatchResponse setBreakpointOnFunctionCall(const String& in_objectId, Maybe<String> in_condition, String* out_breakpointId) = 0;
    virtual DispatchResponse setBreakpointsActive(bool in_active) = 0;
    virtual DispatchResponse setPauseOnExceptions(const String& in_state) = 0;
    virtual DispatchResponse setReturnValue(std::unique_ptr<protocol::Runtime::CallArgument> in_newValue) = 0;
    virtual DispatchResponse setScriptSource(const String& in_scriptId, const String& in_scriptSource, Maybe<bool> in_dryRun, Maybe<protocol::Array<protocol::Debugger::CallFrame>>* out_callFrames, Maybe<bool>* out_stackChanged, Maybe<protocol::Runtime::StackTrace>* out_asyncStackTrace, Maybe<protocol::Runtime::StackTraceId>* out_asyncStackTraceId, Maybe<protocol::Runtime::ExceptionDetails>* out_exceptionDetails) = 0;
    virtual DispatchResponse setSkipAllPauses(bool in_skip) = 0;
    virtual DispatchResponse setVariableValue(int in_scopeNumber, const String& in_variableName, std::unique_ptr<protocol::Runtime::CallArgument> in_newValue, const String& in_callFrameId) = 0;
    virtual DispatchResponse stepInto(Maybe<bool> in_breakOnAsyncCall, Maybe<protocol::Array<protocol::Debugger::LocationRange>> in_skipList) = 0;
    virtual DispatchResponse stepOut() = 0;
    virtual DispatchResponse stepOver(Maybe<protocol::Array<protocol::Debugger::LocationRange>> in_skipList) = 0;

};

// ------------- Frontend interface.

class  Frontend {
public:
  explicit Frontend(FrontendChannel* frontend_channel) : frontend_channel_(frontend_channel) {}
    void breakpointResolved(const String& breakpointId, std::unique_ptr<protocol::Debugger::Location> location);
    void paused(std::unique_ptr<protocol::Array<protocol::Debugger::CallFrame>> callFrames, const String& reason, Maybe<protocol::DictionaryValue> data = Maybe<protocol::DictionaryValue>(), Maybe<protocol::Array<String>> hitBreakpoints = Maybe<protocol::Array<String>>(), Maybe<protocol::Runtime::StackTrace> asyncStackTrace = Maybe<protocol::Runtime::StackTrace>(), Maybe<protocol::Runtime::StackTraceId> asyncStackTraceId = Maybe<protocol::Runtime::StackTraceId>(), Maybe<protocol::Runtime::StackTraceId> asyncCallStackTraceId = Maybe<protocol::Runtime::StackTraceId>());
    void resumed();
    void scriptFailedToParse(const String& scriptId, const String& url, int startLine, int startColumn, int endLine, int endColumn, int executionContextId, const String& hash, Maybe<protocol::DictionaryValue> executionContextAuxData = Maybe<protocol::DictionaryValue>(), Maybe<String> sourceMapURL = Maybe<String>(), Maybe<bool> hasSourceURL = Maybe<bool>(), Maybe<bool> isModule = Maybe<bool>(), Maybe<int> length = Maybe<int>(), Maybe<protocol::Runtime::StackTrace> stackTrace = Maybe<protocol::Runtime::StackTrace>(), Maybe<int> codeOffset = Maybe<int>(), Maybe<String> scriptLanguage = Maybe<String>(), Maybe<String> embedderName = Maybe<String>());
    void scriptParsed(const String& scriptId, const String& url, int startLine, int startColumn, int endLine, int endColumn, int executionContextId, const String& hash, Maybe<protocol::DictionaryValue> executionContextAuxData = Maybe<protocol::DictionaryValue>(), Maybe<bool> isLiveEdit = Maybe<bool>(), Maybe<String> sourceMapURL = Maybe<String>(), Maybe<bool> hasSourceURL = Maybe<bool>(), Maybe<bool> isModule = Maybe<bool>(), Maybe<int> length = Maybe<int>(), Maybe<protocol::Runtime::StackTrace> stackTrace = Maybe<protocol::Runtime::StackTrace>(), Maybe<int> codeOffset = Maybe<int>(), Maybe<String> scriptLanguage = Maybe<String>(), Maybe<protocol::Debugger::DebugSymbols> debugSymbols = Maybe<protocol::Debugger::DebugSymbols>(), Maybe<String> embedderName = Maybe<String>());

  void flush();
  void sendRawNotification(std::unique_ptr<Serializable>);
 private:
  FrontendChannel* frontend_channel_;
};

// ------------- Dispatcher.

class  Dispatcher {
public:
    static void wire(UberDispatcher*, Backend*);

private:
    Dispatcher() { }
};

// ------------- Metainfo.

class  Metainfo {
public:
    using BackendClass = Backend;
    using FrontendClass = Frontend;
    using DispatcherClass = Dispatcher;
    static const char domainName[];
    static const char commandPrefix[];
    static const char version[];
};

} // namespace Debugger
} // namespace v8_inspector
} // namespace protocol

#endif // !defined(v8_inspector_protocol_Debugger_h)
