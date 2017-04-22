# -------------------------------------------------
# Project created by chenjc 2017-04-19
# -------------------------------------------------
QT += core \
    gui \
    widgets \
    xml
LIBS += /Afc/Run/Lib/libMobileScan.so \
    /Afc/Run/Lib/libDllCLogOper.so \
    /Afc/Run/Lib/libLoki.so \
    /Afc/Run/Lib/libQRCodeCreate.so
INCLUDEPATH += Include \
    Include/soap \
    SlePublicInclude \
    Interface
HEADERS += MobileScan.h \
    Include/soap/stdsoap2.h \
    Include/soap/soapStub.h \
    Include/soap/soapSLEWebServiceSoapProxy.h \
    Include/soap/soapH.h \
    Include/QRCPayDef.h \
    Include/CQRCPay.h \
    SlePublicInclude/WavPlayer.h \
    SlePublicInclude/synclock.h \
    SlePublicInclude/SlePublicFunc.h \
    SlePublicInclude/SleParamAttriDefPublic.h \
    SlePublicInclude/qrencode.h \
    SlePublicInclude/PubXml.h \
    SlePublicInclude/PubSleDb.h \
    SlePublicInclude/PubNtpSyncClockDef.h \
    SlePublicInclude/PubNtpSyncClock.h \
    SlePublicInclude/PubComApi.h \
    SlePublicInclude/MD5Checksum.h \
    SlePublicInclude/MaintainTestPublicDef.h \
    SlePublicInclude/DataDef.h \
    SlePublicInclude/CashAndTicketContainer.h \
    SlePublicInclude/BomPublicDataInfo.h \
    SlePublicInclude/BomIpcMsgDef.h \
    SlePublicInclude/AfcTpuPublic.h \
    SlePublicInclude/AfcStatusTable.h \
    SlePublicInclude/AfcPublic.h \
    SlePublicInclude/AfcErrorCode.h \
    SlePublicInclude/loki/Visitor.h \
    SlePublicInclude/loki/TypeTraits.h \
    SlePublicInclude/loki/TypeManip.h \
    SlePublicInclude/loki/TypelistMacros.h \
    SlePublicInclude/loki/Typelist.h \
    SlePublicInclude/loki/Tuple.h \
    SlePublicInclude/loki/Threads.h \
    SlePublicInclude/loki/StrongPtr.h \
    SlePublicInclude/loki/static_check.h \
    SlePublicInclude/loki/SPCachedFactory.h \
    SlePublicInclude/loki/SmartPtr.h \
    SlePublicInclude/loki/SmallObj.h \
    SlePublicInclude/loki/Singleton.h \
    SlePublicInclude/loki/Sequence.h \
    SlePublicInclude/loki/ScopeGuard.h \
    SlePublicInclude/loki/SafeFormat.h \
    SlePublicInclude/loki/SafeBits.h \
    SlePublicInclude/loki/Register.h \
    SlePublicInclude/loki/RefToValue.h \
    SlePublicInclude/loki/Pimpl.h \
    SlePublicInclude/loki/OrderedStatic.h \
    SlePublicInclude/loki/NullType.h \
    SlePublicInclude/loki/MultiMethods.h \
    SlePublicInclude/loki/LokiTypeInfo.h \
    SlePublicInclude/loki/LokiExport.h \
    SlePublicInclude/loki/LockingPtr.h \
    SlePublicInclude/loki/LevelMutex.h \
    SlePublicInclude/loki/Key.h \
    SlePublicInclude/loki/HierarchyGenerators.h \
    SlePublicInclude/loki/Functor.h \
    SlePublicInclude/loki/Function.h \
    SlePublicInclude/loki/Factory.h \
    SlePublicInclude/loki/EmptyType.h \
    SlePublicInclude/loki/DataGenerators.h \
    SlePublicInclude/loki/ConstPolicy.h \
    SlePublicInclude/loki/CheckReturn.h \
    SlePublicInclude/loki/Checker.h \
    SlePublicInclude/loki/CachedFactory.h \
    SlePublicInclude/loki/AssocVector.h \
    SlePublicInclude/loki/Allocator.h \
    SlePublicInclude/loki/AbstractFactory.h \
    Include/MobileScanPayCommonDef.h \
    Include/MobileScanCommonFunc.h \
    Interface/IWebPayEvenHandler.h \
    Interface/IMobileScanPaymentFunction.h \
    Interface/IDeviceCommonFunction.h \
    Include/CLogOper2.h \
    Include/CLogOper.h \
    Interface/IProgressReport.h \
    Include/qrencode.h \
    Include/qrcodecreate.h
SOURCES += MobileScan.cpp \
    main.cpp
