

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from dds_msgs.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef dds_msgs_1583855963_hpp
#define dds_msgs_1583855963_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace dds_msgs {
    enum class EnumMission {
        None = 0, 
        AirBuild = 1, 
        AirDiff = 2, 
        GroundBuild = 3, 
        GroundDiff = 4
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const EnumMission& sample);
    enum class EnumPlatform {
        None = 0, 
        Drone = 1, 
        UGV = 2
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const EnumPlatform& sample);
    enum class EnumScan {
        None = 0, 
        Rectangular = 1, 
        LocalSquare = 2
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const EnumScan& sample);
    enum class EnumJpegGenerationSts {
        None = 0, 
        Waiting = 1, 
        Generating = 2, 
        Fail = 3
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const EnumJpegGenerationSts& sample);
    enum class EnumLasFileTransmissionSts {
        None = 0, 
        Finished = 1, 
        Verified = 2, 
        Error1 = 3, 
        Error2 = 4
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const EnumLasFileTransmissionSts& sample);
    enum class EnumCalculation {
        None = 0, 
        NewModel = 1, 
        DiffAnalysis = 2
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const EnumCalculation& sample);

    class NDDSUSERDllExport GeoPoint {
      public:
        GeoPoint();

        GeoPoint(
            double Lat,
            double Lon,
            double Alt);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        GeoPoint (GeoPoint&&) = default;
        GeoPoint& operator=(GeoPoint&&) = default;
        GeoPoint& operator=(const GeoPoint&) = default;
        GeoPoint(const GeoPoint&) = default;
        #else
        GeoPoint(GeoPoint&& other_) OMG_NOEXCEPT;  
        GeoPoint& operator=(GeoPoint&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        double& Lat() OMG_NOEXCEPT {
            return m_Lat_;
        }

        const double& Lat() const OMG_NOEXCEPT {
            return m_Lat_;
        }

        void Lat(double value) {
            m_Lat_ = value;
        }

        double& Lon() OMG_NOEXCEPT {
            return m_Lon_;
        }

        const double& Lon() const OMG_NOEXCEPT {
            return m_Lon_;
        }

        void Lon(double value) {
            m_Lon_ = value;
        }

        double& Alt() OMG_NOEXCEPT {
            return m_Alt_;
        }

        const double& Alt() const OMG_NOEXCEPT {
            return m_Alt_;
        }

        void Alt(double value) {
            m_Alt_ = value;
        }

        bool operator == (const GeoPoint& other_) const;
        bool operator != (const GeoPoint& other_) const;

        void swap(GeoPoint& other_) OMG_NOEXCEPT ;

      private:

        double m_Lat_;
        double m_Lon_;
        double m_Alt_;

    };

    inline void swap(GeoPoint& a, GeoPoint& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const GeoPoint& sample);

    class NDDSUSERDllExport LocalScan {
      public:
        LocalScan();

        LocalScan(
            const dds_msgs::GeoPoint& SquareCenter,
            uint16_t SquareSide);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        LocalScan (LocalScan&&) = default;
        LocalScan& operator=(LocalScan&&) = default;
        LocalScan& operator=(const LocalScan&) = default;
        LocalScan(const LocalScan&) = default;
        #else
        LocalScan(LocalScan&& other_) OMG_NOEXCEPT;  
        LocalScan& operator=(LocalScan&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        dds_msgs::GeoPoint& SquareCenter() OMG_NOEXCEPT {
            return m_SquareCenter_;
        }

        const dds_msgs::GeoPoint& SquareCenter() const OMG_NOEXCEPT {
            return m_SquareCenter_;
        }

        void SquareCenter(const dds_msgs::GeoPoint& value) {
            m_SquareCenter_ = value;
        }

        void SquareCenter(dds_msgs::GeoPoint&& value) {
            m_SquareCenter_ = std::move(value);
        }
        uint16_t& SquareSide() OMG_NOEXCEPT {
            return m_SquareSide_;
        }

        const uint16_t& SquareSide() const OMG_NOEXCEPT {
            return m_SquareSide_;
        }

        void SquareSide(uint16_t value) {
            m_SquareSide_ = value;
        }

        bool operator == (const LocalScan& other_) const;
        bool operator != (const LocalScan& other_) const;

        void swap(LocalScan& other_) OMG_NOEXCEPT ;

      private:

        dds_msgs::GeoPoint m_SquareCenter_;
        uint16_t m_SquareSide_;

    };

    inline void swap(LocalScan& a, LocalScan& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const LocalScan& sample);

    class NDDSUSERDllExport BaseMsg {
      public:
        BaseMsg();

        BaseMsg(
            uint8_t MsgId,
            uint32_t MsgCount,
            uint16_t MissionId);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        BaseMsg (BaseMsg&&) = default;
        BaseMsg& operator=(BaseMsg&&) = default;
        BaseMsg& operator=(const BaseMsg&) = default;
        BaseMsg(const BaseMsg&) = default;
        #else
        BaseMsg(BaseMsg&& other_) OMG_NOEXCEPT;  
        BaseMsg& operator=(BaseMsg&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint8_t& MsgId() OMG_NOEXCEPT {
            return m_MsgId_;
        }

        const uint8_t& MsgId() const OMG_NOEXCEPT {
            return m_MsgId_;
        }

        void MsgId(uint8_t value) {
            m_MsgId_ = value;
        }

        uint32_t& MsgCount() OMG_NOEXCEPT {
            return m_MsgCount_;
        }

        const uint32_t& MsgCount() const OMG_NOEXCEPT {
            return m_MsgCount_;
        }

        void MsgCount(uint32_t value) {
            m_MsgCount_ = value;
        }

        uint16_t& MissionId() OMG_NOEXCEPT {
            return m_MissionId_;
        }

        const uint16_t& MissionId() const OMG_NOEXCEPT {
            return m_MissionId_;
        }

        void MissionId(uint16_t value) {
            m_MissionId_ = value;
        }

        bool operator == (const BaseMsg& other_) const;
        bool operator != (const BaseMsg& other_) const;

        void swap(BaseMsg& other_) OMG_NOEXCEPT ;

      private:

        uint8_t m_MsgId_;
        uint32_t m_MsgCount_;
        uint16_t m_MissionId_;

    };

    inline void swap(BaseMsg& a, BaseMsg& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BaseMsg& sample);

    class NDDSUSERDllExport MissionPlanMsg
    : public dds_msgs::BaseMsg {
      public:
        MissionPlanMsg();

        MissionPlanMsg(
            uint8_t MsgId,
            uint32_t MsgCount,
            uint16_t MissionId,
            const std::string& MissionName,
            const dds_msgs::EnumMission& MissionType,
            uint8_t StationId,
            const dds_msgs::EnumPlatform& PlatformType,
            uint8_t PlatformId,
            const dds_msgs::EnumScan& ScanType,
            const ::dds::core::array< dds_msgs::GeoPoint, 3L>& ScanArea,
            int16_t ScanAreaGroundAvgAlt,
            uint16_t FlightAltAboveGroundAvgAlt,
            int16_t TakeoffAltAboveSeaLevel,
            uint8_t FlightSpeed,
            uint8_t CameraHorizontalFOV,
            uint8_t CameraVerticalFOV,
            uint16_t CameraHorizontalResolution,
            uint16_t CameraVerticalResolution,
            uint8_t OverlapInFlightDirection,
            uint8_t OverlapInLateralDirection,
            int16_t GimbalPitchAngle,
            const dds_msgs::GeoPoint& SquareCenter,
            uint16_t SquareSide,
            const ::dds::core::optional< std::string >& GeoPathJpegFiles,
            const std::string& GeoPathCurrModel,
            const ::dds::core::optional< std::string >& GeoPathRefModel,
            const ::dds::core::optional< std::string >& GeoPathDiffModel,
            const std::string& CloudUrlCurrModel,
            const ::dds::core::optional< std::string >& CloudUrlRefModel,
            const ::dds::core::optional< std::string >& CloudUrlDiffModel);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        MissionPlanMsg (MissionPlanMsg&&) = default;
        MissionPlanMsg& operator=(MissionPlanMsg&&) = default;
        MissionPlanMsg& operator=(const MissionPlanMsg&) = default;
        MissionPlanMsg(const MissionPlanMsg&) = default;
        #else
        MissionPlanMsg(MissionPlanMsg&& other_) OMG_NOEXCEPT;  
        MissionPlanMsg& operator=(MissionPlanMsg&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        std::string& MissionName() OMG_NOEXCEPT {
            return m_MissionName_;
        }

        const std::string& MissionName() const OMG_NOEXCEPT {
            return m_MissionName_;
        }

        void MissionName(const std::string& value) {
            m_MissionName_ = value;
        }

        void MissionName(std::string&& value) {
            m_MissionName_ = std::move(value);
        }
        dds_msgs::EnumMission& MissionType() OMG_NOEXCEPT {
            return m_MissionType_;
        }

        const dds_msgs::EnumMission& MissionType() const OMG_NOEXCEPT {
            return m_MissionType_;
        }

        void MissionType(const dds_msgs::EnumMission& value) {
            m_MissionType_ = value;
        }

        void MissionType(dds_msgs::EnumMission&& value) {
            m_MissionType_ = std::move(value);
        }
        uint8_t& StationId() OMG_NOEXCEPT {
            return m_StationId_;
        }

        const uint8_t& StationId() const OMG_NOEXCEPT {
            return m_StationId_;
        }

        void StationId(uint8_t value) {
            m_StationId_ = value;
        }

        dds_msgs::EnumPlatform& PlatformType() OMG_NOEXCEPT {
            return m_PlatformType_;
        }

        const dds_msgs::EnumPlatform& PlatformType() const OMG_NOEXCEPT {
            return m_PlatformType_;
        }

        void PlatformType(const dds_msgs::EnumPlatform& value) {
            m_PlatformType_ = value;
        }

        void PlatformType(dds_msgs::EnumPlatform&& value) {
            m_PlatformType_ = std::move(value);
        }
        uint8_t& PlatformId() OMG_NOEXCEPT {
            return m_PlatformId_;
        }

        const uint8_t& PlatformId() const OMG_NOEXCEPT {
            return m_PlatformId_;
        }

        void PlatformId(uint8_t value) {
            m_PlatformId_ = value;
        }

        dds_msgs::EnumScan& ScanType() OMG_NOEXCEPT {
            return m_ScanType_;
        }

        const dds_msgs::EnumScan& ScanType() const OMG_NOEXCEPT {
            return m_ScanType_;
        }

        void ScanType(const dds_msgs::EnumScan& value) {
            m_ScanType_ = value;
        }

        void ScanType(dds_msgs::EnumScan&& value) {
            m_ScanType_ = std::move(value);
        }
        ::dds::core::array< dds_msgs::GeoPoint, 3L>& ScanArea() OMG_NOEXCEPT {
            return m_ScanArea_;
        }

        const ::dds::core::array< dds_msgs::GeoPoint, 3L>& ScanArea() const OMG_NOEXCEPT {
            return m_ScanArea_;
        }

        void ScanArea(const ::dds::core::array< dds_msgs::GeoPoint, 3L>& value) {
            m_ScanArea_ = value;
        }

        void ScanArea(::dds::core::array< dds_msgs::GeoPoint, 3L>&& value) {
            m_ScanArea_ = std::move(value);
        }
        int16_t& ScanAreaGroundAvgAlt() OMG_NOEXCEPT {
            return m_ScanAreaGroundAvgAlt_;
        }

        const int16_t& ScanAreaGroundAvgAlt() const OMG_NOEXCEPT {
            return m_ScanAreaGroundAvgAlt_;
        }

        void ScanAreaGroundAvgAlt(int16_t value) {
            m_ScanAreaGroundAvgAlt_ = value;
        }

        uint16_t& FlightAltAboveGroundAvgAlt() OMG_NOEXCEPT {
            return m_FlightAltAboveGroundAvgAlt_;
        }

        const uint16_t& FlightAltAboveGroundAvgAlt() const OMG_NOEXCEPT {
            return m_FlightAltAboveGroundAvgAlt_;
        }

        void FlightAltAboveGroundAvgAlt(uint16_t value) {
            m_FlightAltAboveGroundAvgAlt_ = value;
        }

        int16_t& TakeoffAltAboveSeaLevel() OMG_NOEXCEPT {
            return m_TakeoffAltAboveSeaLevel_;
        }

        const int16_t& TakeoffAltAboveSeaLevel() const OMG_NOEXCEPT {
            return m_TakeoffAltAboveSeaLevel_;
        }

        void TakeoffAltAboveSeaLevel(int16_t value) {
            m_TakeoffAltAboveSeaLevel_ = value;
        }

        uint8_t& FlightSpeed() OMG_NOEXCEPT {
            return m_FlightSpeed_;
        }

        const uint8_t& FlightSpeed() const OMG_NOEXCEPT {
            return m_FlightSpeed_;
        }

        void FlightSpeed(uint8_t value) {
            m_FlightSpeed_ = value;
        }

        uint8_t& CameraHorizontalFOV() OMG_NOEXCEPT {
            return m_CameraHorizontalFOV_;
        }

        const uint8_t& CameraHorizontalFOV() const OMG_NOEXCEPT {
            return m_CameraHorizontalFOV_;
        }

        void CameraHorizontalFOV(uint8_t value) {
            m_CameraHorizontalFOV_ = value;
        }

        uint8_t& CameraVerticalFOV() OMG_NOEXCEPT {
            return m_CameraVerticalFOV_;
        }

        const uint8_t& CameraVerticalFOV() const OMG_NOEXCEPT {
            return m_CameraVerticalFOV_;
        }

        void CameraVerticalFOV(uint8_t value) {
            m_CameraVerticalFOV_ = value;
        }

        uint16_t& CameraHorizontalResolution() OMG_NOEXCEPT {
            return m_CameraHorizontalResolution_;
        }

        const uint16_t& CameraHorizontalResolution() const OMG_NOEXCEPT {
            return m_CameraHorizontalResolution_;
        }

        void CameraHorizontalResolution(uint16_t value) {
            m_CameraHorizontalResolution_ = value;
        }

        uint16_t& CameraVerticalResolution() OMG_NOEXCEPT {
            return m_CameraVerticalResolution_;
        }

        const uint16_t& CameraVerticalResolution() const OMG_NOEXCEPT {
            return m_CameraVerticalResolution_;
        }

        void CameraVerticalResolution(uint16_t value) {
            m_CameraVerticalResolution_ = value;
        }

        uint8_t& OverlapInFlightDirection() OMG_NOEXCEPT {
            return m_OverlapInFlightDirection_;
        }

        const uint8_t& OverlapInFlightDirection() const OMG_NOEXCEPT {
            return m_OverlapInFlightDirection_;
        }

        void OverlapInFlightDirection(uint8_t value) {
            m_OverlapInFlightDirection_ = value;
        }

        uint8_t& OverlapInLateralDirection() OMG_NOEXCEPT {
            return m_OverlapInLateralDirection_;
        }

        const uint8_t& OverlapInLateralDirection() const OMG_NOEXCEPT {
            return m_OverlapInLateralDirection_;
        }

        void OverlapInLateralDirection(uint8_t value) {
            m_OverlapInLateralDirection_ = value;
        }

        int16_t& GimbalPitchAngle() OMG_NOEXCEPT {
            return m_GimbalPitchAngle_;
        }

        const int16_t& GimbalPitchAngle() const OMG_NOEXCEPT {
            return m_GimbalPitchAngle_;
        }

        void GimbalPitchAngle(int16_t value) {
            m_GimbalPitchAngle_ = value;
        }

        dds_msgs::GeoPoint& SquareCenter() OMG_NOEXCEPT {
            return m_SquareCenter_;
        }

        const dds_msgs::GeoPoint& SquareCenter() const OMG_NOEXCEPT {
            return m_SquareCenter_;
        }

        void SquareCenter(const dds_msgs::GeoPoint& value) {
            m_SquareCenter_ = value;
        }

        void SquareCenter(dds_msgs::GeoPoint&& value) {
            m_SquareCenter_ = std::move(value);
        }
        uint16_t& SquareSide() OMG_NOEXCEPT {
            return m_SquareSide_;
        }

        const uint16_t& SquareSide() const OMG_NOEXCEPT {
            return m_SquareSide_;
        }

        void SquareSide(uint16_t value) {
            m_SquareSide_ = value;
        }

        ::dds::core::optional< std::string >& GeoPathJpegFiles() OMG_NOEXCEPT {
            return m_GeoPathJpegFiles_;
        }

        const ::dds::core::optional< std::string >& GeoPathJpegFiles() const OMG_NOEXCEPT {
            return m_GeoPathJpegFiles_;
        }

        void GeoPathJpegFiles(const ::dds::core::optional< std::string >& value) {
            m_GeoPathJpegFiles_ = value;
        }

        void GeoPathJpegFiles(::dds::core::optional< std::string >&& value) {
            m_GeoPathJpegFiles_ = std::move(value);
        }
        std::string& GeoPathCurrModel() OMG_NOEXCEPT {
            return m_GeoPathCurrModel_;
        }

        const std::string& GeoPathCurrModel() const OMG_NOEXCEPT {
            return m_GeoPathCurrModel_;
        }

        void GeoPathCurrModel(const std::string& value) {
            m_GeoPathCurrModel_ = value;
        }

        void GeoPathCurrModel(std::string&& value) {
            m_GeoPathCurrModel_ = std::move(value);
        }
        ::dds::core::optional< std::string >& GeoPathRefModel() OMG_NOEXCEPT {
            return m_GeoPathRefModel_;
        }

        const ::dds::core::optional< std::string >& GeoPathRefModel() const OMG_NOEXCEPT {
            return m_GeoPathRefModel_;
        }

        void GeoPathRefModel(const ::dds::core::optional< std::string >& value) {
            m_GeoPathRefModel_ = value;
        }

        void GeoPathRefModel(::dds::core::optional< std::string >&& value) {
            m_GeoPathRefModel_ = std::move(value);
        }
        ::dds::core::optional< std::string >& GeoPathDiffModel() OMG_NOEXCEPT {
            return m_GeoPathDiffModel_;
        }

        const ::dds::core::optional< std::string >& GeoPathDiffModel() const OMG_NOEXCEPT {
            return m_GeoPathDiffModel_;
        }

        void GeoPathDiffModel(const ::dds::core::optional< std::string >& value) {
            m_GeoPathDiffModel_ = value;
        }

        void GeoPathDiffModel(::dds::core::optional< std::string >&& value) {
            m_GeoPathDiffModel_ = std::move(value);
        }
        std::string& CloudUrlCurrModel() OMG_NOEXCEPT {
            return m_CloudUrlCurrModel_;
        }

        const std::string& CloudUrlCurrModel() const OMG_NOEXCEPT {
            return m_CloudUrlCurrModel_;
        }

        void CloudUrlCurrModel(const std::string& value) {
            m_CloudUrlCurrModel_ = value;
        }

        void CloudUrlCurrModel(std::string&& value) {
            m_CloudUrlCurrModel_ = std::move(value);
        }
        ::dds::core::optional< std::string >& CloudUrlRefModel() OMG_NOEXCEPT {
            return m_CloudUrlRefModel_;
        }

        const ::dds::core::optional< std::string >& CloudUrlRefModel() const OMG_NOEXCEPT {
            return m_CloudUrlRefModel_;
        }

        void CloudUrlRefModel(const ::dds::core::optional< std::string >& value) {
            m_CloudUrlRefModel_ = value;
        }

        void CloudUrlRefModel(::dds::core::optional< std::string >&& value) {
            m_CloudUrlRefModel_ = std::move(value);
        }
        ::dds::core::optional< std::string >& CloudUrlDiffModel() OMG_NOEXCEPT {
            return m_CloudUrlDiffModel_;
        }

        const ::dds::core::optional< std::string >& CloudUrlDiffModel() const OMG_NOEXCEPT {
            return m_CloudUrlDiffModel_;
        }

        void CloudUrlDiffModel(const ::dds::core::optional< std::string >& value) {
            m_CloudUrlDiffModel_ = value;
        }

        void CloudUrlDiffModel(::dds::core::optional< std::string >&& value) {
            m_CloudUrlDiffModel_ = std::move(value);
        }

        bool operator == (const MissionPlanMsg& other_) const;
        bool operator != (const MissionPlanMsg& other_) const;

        void swap(MissionPlanMsg& other_) OMG_NOEXCEPT ;

      private:

        std::string m_MissionName_;
        dds_msgs::EnumMission m_MissionType_;
        uint8_t m_StationId_;
        dds_msgs::EnumPlatform m_PlatformType_;
        uint8_t m_PlatformId_;
        dds_msgs::EnumScan m_ScanType_;
        ::dds::core::array< dds_msgs::GeoPoint, 3L> m_ScanArea_;
        int16_t m_ScanAreaGroundAvgAlt_;
        uint16_t m_FlightAltAboveGroundAvgAlt_;
        int16_t m_TakeoffAltAboveSeaLevel_;
        uint8_t m_FlightSpeed_;
        uint8_t m_CameraHorizontalFOV_;
        uint8_t m_CameraVerticalFOV_;
        uint16_t m_CameraHorizontalResolution_;
        uint16_t m_CameraVerticalResolution_;
        uint8_t m_OverlapInFlightDirection_;
        uint8_t m_OverlapInLateralDirection_;
        int16_t m_GimbalPitchAngle_;
        dds_msgs::GeoPoint m_SquareCenter_;
        uint16_t m_SquareSide_;
        ::dds::core::optional< std::string > m_GeoPathJpegFiles_;
        std::string m_GeoPathCurrModel_;
        ::dds::core::optional< std::string > m_GeoPathRefModel_;
        ::dds::core::optional< std::string > m_GeoPathDiffModel_;
        std::string m_CloudUrlCurrModel_;
        ::dds::core::optional< std::string > m_CloudUrlRefModel_;
        ::dds::core::optional< std::string > m_CloudUrlDiffModel_;

    };

    inline void swap(MissionPlanMsg& a, MissionPlanMsg& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const MissionPlanMsg& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< dds_msgs::GeoPoint >;
    template class NDDSUSERDllExport std::vector< dds_msgs::GeoPoint >;
    #endif
    class NDDSUSERDllExport GetDroneScanRouteMsg
    : public dds_msgs::BaseMsg {
      public:
        GetDroneScanRouteMsg();

        GetDroneScanRouteMsg(
            uint8_t MsgId,
            uint32_t MsgCount,
            uint16_t MissionId,
            const dds_msgs::EnumScan& ScanType,
            const ::rti::core::bounded_sequence< dds_msgs::GeoPoint, 3L >& ScanArea,
            int16_t ScanAreaGroundAvgAlt,
            int16_t FlightAltAboveGroundAvgAlt,
            int16_t TakeoffAltAboveSeaLevel,
            uint8_t FlightSpeed,
            uint8_t CameraHorizontalFOV,
            uint8_t CameraVerticalFOV,
            uint16_t CameraHorizontalResolution,
            uint16_t CameraVerticalResolution,
            uint8_t OverlapInFlightDirection,
            uint8_t OverlapInLateralDirection,
            int16_t GimbalPitchAngle,
            const dds_msgs::GeoPoint& SquareCenter,
            uint16_t SquareSide);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        GetDroneScanRouteMsg (GetDroneScanRouteMsg&&) = default;
        GetDroneScanRouteMsg& operator=(GetDroneScanRouteMsg&&) = default;
        GetDroneScanRouteMsg& operator=(const GetDroneScanRouteMsg&) = default;
        GetDroneScanRouteMsg(const GetDroneScanRouteMsg&) = default;
        #else
        GetDroneScanRouteMsg(GetDroneScanRouteMsg&& other_) OMG_NOEXCEPT;  
        GetDroneScanRouteMsg& operator=(GetDroneScanRouteMsg&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        dds_msgs::EnumScan& ScanType() OMG_NOEXCEPT {
            return m_ScanType_;
        }

        const dds_msgs::EnumScan& ScanType() const OMG_NOEXCEPT {
            return m_ScanType_;
        }

        void ScanType(const dds_msgs::EnumScan& value) {
            m_ScanType_ = value;
        }

        void ScanType(dds_msgs::EnumScan&& value) {
            m_ScanType_ = std::move(value);
        }
        ::rti::core::bounded_sequence< dds_msgs::GeoPoint, 3L >& ScanArea() OMG_NOEXCEPT {
            return m_ScanArea_;
        }

        const ::rti::core::bounded_sequence< dds_msgs::GeoPoint, 3L >& ScanArea() const OMG_NOEXCEPT {
            return m_ScanArea_;
        }

        void ScanArea(const ::rti::core::bounded_sequence< dds_msgs::GeoPoint, 3L >& value) {
            m_ScanArea_ = value;
        }

        void ScanArea(::rti::core::bounded_sequence< dds_msgs::GeoPoint, 3L >&& value) {
            m_ScanArea_ = std::move(value);
        }
        int16_t& ScanAreaGroundAvgAlt() OMG_NOEXCEPT {
            return m_ScanAreaGroundAvgAlt_;
        }

        const int16_t& ScanAreaGroundAvgAlt() const OMG_NOEXCEPT {
            return m_ScanAreaGroundAvgAlt_;
        }

        void ScanAreaGroundAvgAlt(int16_t value) {
            m_ScanAreaGroundAvgAlt_ = value;
        }

        int16_t& FlightAltAboveGroundAvgAlt() OMG_NOEXCEPT {
            return m_FlightAltAboveGroundAvgAlt_;
        }

        const int16_t& FlightAltAboveGroundAvgAlt() const OMG_NOEXCEPT {
            return m_FlightAltAboveGroundAvgAlt_;
        }

        void FlightAltAboveGroundAvgAlt(int16_t value) {
            m_FlightAltAboveGroundAvgAlt_ = value;
        }

        int16_t& TakeoffAltAboveSeaLevel() OMG_NOEXCEPT {
            return m_TakeoffAltAboveSeaLevel_;
        }

        const int16_t& TakeoffAltAboveSeaLevel() const OMG_NOEXCEPT {
            return m_TakeoffAltAboveSeaLevel_;
        }

        void TakeoffAltAboveSeaLevel(int16_t value) {
            m_TakeoffAltAboveSeaLevel_ = value;
        }

        uint8_t& FlightSpeed() OMG_NOEXCEPT {
            return m_FlightSpeed_;
        }

        const uint8_t& FlightSpeed() const OMG_NOEXCEPT {
            return m_FlightSpeed_;
        }

        void FlightSpeed(uint8_t value) {
            m_FlightSpeed_ = value;
        }

        uint8_t& CameraHorizontalFOV() OMG_NOEXCEPT {
            return m_CameraHorizontalFOV_;
        }

        const uint8_t& CameraHorizontalFOV() const OMG_NOEXCEPT {
            return m_CameraHorizontalFOV_;
        }

        void CameraHorizontalFOV(uint8_t value) {
            m_CameraHorizontalFOV_ = value;
        }

        uint8_t& CameraVerticalFOV() OMG_NOEXCEPT {
            return m_CameraVerticalFOV_;
        }

        const uint8_t& CameraVerticalFOV() const OMG_NOEXCEPT {
            return m_CameraVerticalFOV_;
        }

        void CameraVerticalFOV(uint8_t value) {
            m_CameraVerticalFOV_ = value;
        }

        uint16_t& CameraHorizontalResolution() OMG_NOEXCEPT {
            return m_CameraHorizontalResolution_;
        }

        const uint16_t& CameraHorizontalResolution() const OMG_NOEXCEPT {
            return m_CameraHorizontalResolution_;
        }

        void CameraHorizontalResolution(uint16_t value) {
            m_CameraHorizontalResolution_ = value;
        }

        uint16_t& CameraVerticalResolution() OMG_NOEXCEPT {
            return m_CameraVerticalResolution_;
        }

        const uint16_t& CameraVerticalResolution() const OMG_NOEXCEPT {
            return m_CameraVerticalResolution_;
        }

        void CameraVerticalResolution(uint16_t value) {
            m_CameraVerticalResolution_ = value;
        }

        uint8_t& OverlapInFlightDirection() OMG_NOEXCEPT {
            return m_OverlapInFlightDirection_;
        }

        const uint8_t& OverlapInFlightDirection() const OMG_NOEXCEPT {
            return m_OverlapInFlightDirection_;
        }

        void OverlapInFlightDirection(uint8_t value) {
            m_OverlapInFlightDirection_ = value;
        }

        uint8_t& OverlapInLateralDirection() OMG_NOEXCEPT {
            return m_OverlapInLateralDirection_;
        }

        const uint8_t& OverlapInLateralDirection() const OMG_NOEXCEPT {
            return m_OverlapInLateralDirection_;
        }

        void OverlapInLateralDirection(uint8_t value) {
            m_OverlapInLateralDirection_ = value;
        }

        int16_t& GimbalPitchAngle() OMG_NOEXCEPT {
            return m_GimbalPitchAngle_;
        }

        const int16_t& GimbalPitchAngle() const OMG_NOEXCEPT {
            return m_GimbalPitchAngle_;
        }

        void GimbalPitchAngle(int16_t value) {
            m_GimbalPitchAngle_ = value;
        }

        dds_msgs::GeoPoint& SquareCenter() OMG_NOEXCEPT {
            return m_SquareCenter_;
        }

        const dds_msgs::GeoPoint& SquareCenter() const OMG_NOEXCEPT {
            return m_SquareCenter_;
        }

        void SquareCenter(const dds_msgs::GeoPoint& value) {
            m_SquareCenter_ = value;
        }

        void SquareCenter(dds_msgs::GeoPoint&& value) {
            m_SquareCenter_ = std::move(value);
        }
        uint16_t& SquareSide() OMG_NOEXCEPT {
            return m_SquareSide_;
        }

        const uint16_t& SquareSide() const OMG_NOEXCEPT {
            return m_SquareSide_;
        }

        void SquareSide(uint16_t value) {
            m_SquareSide_ = value;
        }

        bool operator == (const GetDroneScanRouteMsg& other_) const;
        bool operator != (const GetDroneScanRouteMsg& other_) const;

        void swap(GetDroneScanRouteMsg& other_) OMG_NOEXCEPT ;

      private:

        dds_msgs::EnumScan m_ScanType_;
        ::rti::core::bounded_sequence< dds_msgs::GeoPoint, 3L > m_ScanArea_;
        int16_t m_ScanAreaGroundAvgAlt_;
        int16_t m_FlightAltAboveGroundAvgAlt_;
        int16_t m_TakeoffAltAboveSeaLevel_;
        uint8_t m_FlightSpeed_;
        uint8_t m_CameraHorizontalFOV_;
        uint8_t m_CameraVerticalFOV_;
        uint16_t m_CameraHorizontalResolution_;
        uint16_t m_CameraVerticalResolution_;
        uint8_t m_OverlapInFlightDirection_;
        uint8_t m_OverlapInLateralDirection_;
        int16_t m_GimbalPitchAngle_;
        dds_msgs::GeoPoint m_SquareCenter_;
        uint16_t m_SquareSide_;

    };

    inline void swap(GetDroneScanRouteMsg& a, GetDroneScanRouteMsg& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const GetDroneScanRouteMsg& sample);

    class NDDSUSERDllExport DroneScanRouteMsg
    : public dds_msgs::BaseMsg {
      public:
        DroneScanRouteMsg();

        DroneScanRouteMsg(
            uint8_t MsgId,
            uint32_t MsgCount,
            uint16_t MissionId,
            const ::rti::core::bounded_sequence< dds_msgs::GeoPoint, 100L >& Waypoints,
            uint16_t ScanAreaLength,
            uint16_t ScanAreaWidth,
            uint8_t ModelGroundResolution,
            uint16_t TimePeriodBetweenFrames,
            uint16_t ShortLegLength,
            uint16_t NumOfFramesPerLongLeg,
            uint16_t TotalNumOfFrames);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DroneScanRouteMsg (DroneScanRouteMsg&&) = default;
        DroneScanRouteMsg& operator=(DroneScanRouteMsg&&) = default;
        DroneScanRouteMsg& operator=(const DroneScanRouteMsg&) = default;
        DroneScanRouteMsg(const DroneScanRouteMsg&) = default;
        #else
        DroneScanRouteMsg(DroneScanRouteMsg&& other_) OMG_NOEXCEPT;  
        DroneScanRouteMsg& operator=(DroneScanRouteMsg&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        ::rti::core::bounded_sequence< dds_msgs::GeoPoint, 100L >& Waypoints() OMG_NOEXCEPT {
            return m_Waypoints_;
        }

        const ::rti::core::bounded_sequence< dds_msgs::GeoPoint, 100L >& Waypoints() const OMG_NOEXCEPT {
            return m_Waypoints_;
        }

        void Waypoints(const ::rti::core::bounded_sequence< dds_msgs::GeoPoint, 100L >& value) {
            m_Waypoints_ = value;
        }

        void Waypoints(::rti::core::bounded_sequence< dds_msgs::GeoPoint, 100L >&& value) {
            m_Waypoints_ = std::move(value);
        }
        uint16_t& ScanAreaLength() OMG_NOEXCEPT {
            return m_ScanAreaLength_;
        }

        const uint16_t& ScanAreaLength() const OMG_NOEXCEPT {
            return m_ScanAreaLength_;
        }

        void ScanAreaLength(uint16_t value) {
            m_ScanAreaLength_ = value;
        }

        uint16_t& ScanAreaWidth() OMG_NOEXCEPT {
            return m_ScanAreaWidth_;
        }

        const uint16_t& ScanAreaWidth() const OMG_NOEXCEPT {
            return m_ScanAreaWidth_;
        }

        void ScanAreaWidth(uint16_t value) {
            m_ScanAreaWidth_ = value;
        }

        uint8_t& ModelGroundResolution() OMG_NOEXCEPT {
            return m_ModelGroundResolution_;
        }

        const uint8_t& ModelGroundResolution() const OMG_NOEXCEPT {
            return m_ModelGroundResolution_;
        }

        void ModelGroundResolution(uint8_t value) {
            m_ModelGroundResolution_ = value;
        }

        uint16_t& TimePeriodBetweenFrames() OMG_NOEXCEPT {
            return m_TimePeriodBetweenFrames_;
        }

        const uint16_t& TimePeriodBetweenFrames() const OMG_NOEXCEPT {
            return m_TimePeriodBetweenFrames_;
        }

        void TimePeriodBetweenFrames(uint16_t value) {
            m_TimePeriodBetweenFrames_ = value;
        }

        uint16_t& ShortLegLength() OMG_NOEXCEPT {
            return m_ShortLegLength_;
        }

        const uint16_t& ShortLegLength() const OMG_NOEXCEPT {
            return m_ShortLegLength_;
        }

        void ShortLegLength(uint16_t value) {
            m_ShortLegLength_ = value;
        }

        uint16_t& NumOfFramesPerLongLeg() OMG_NOEXCEPT {
            return m_NumOfFramesPerLongLeg_;
        }

        const uint16_t& NumOfFramesPerLongLeg() const OMG_NOEXCEPT {
            return m_NumOfFramesPerLongLeg_;
        }

        void NumOfFramesPerLongLeg(uint16_t value) {
            m_NumOfFramesPerLongLeg_ = value;
        }

        uint16_t& TotalNumOfFrames() OMG_NOEXCEPT {
            return m_TotalNumOfFrames_;
        }

        const uint16_t& TotalNumOfFrames() const OMG_NOEXCEPT {
            return m_TotalNumOfFrames_;
        }

        void TotalNumOfFrames(uint16_t value) {
            m_TotalNumOfFrames_ = value;
        }

        bool operator == (const DroneScanRouteMsg& other_) const;
        bool operator != (const DroneScanRouteMsg& other_) const;

        void swap(DroneScanRouteMsg& other_) OMG_NOEXCEPT ;

      private:

        ::rti::core::bounded_sequence< dds_msgs::GeoPoint, 100L > m_Waypoints_;
        uint16_t m_ScanAreaLength_;
        uint16_t m_ScanAreaWidth_;
        uint8_t m_ModelGroundResolution_;
        uint16_t m_TimePeriodBetweenFrames_;
        uint16_t m_ShortLegLength_;
        uint16_t m_NumOfFramesPerLongLeg_;
        uint16_t m_TotalNumOfFrames_;

    };

    inline void swap(DroneScanRouteMsg& a, DroneScanRouteMsg& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DroneScanRouteMsg& sample);

    class NDDSUSERDllExport PlatformLocationMsg
    : public dds_msgs::BaseMsg {
      public:
        PlatformLocationMsg();

        PlatformLocationMsg(
            uint8_t MsgId,
            uint32_t MsgCount,
            uint16_t MissionId,
            const dds_msgs::EnumPlatform& PlatformType,
            uint8_t PlatformId,
            uint8_t PlatformSpeed,
            double PlatformHeading,
            const dds_msgs::GeoPoint& PlatformLocation,
            uint64_t Timestamp);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        PlatformLocationMsg (PlatformLocationMsg&&) = default;
        PlatformLocationMsg& operator=(PlatformLocationMsg&&) = default;
        PlatformLocationMsg& operator=(const PlatformLocationMsg&) = default;
        PlatformLocationMsg(const PlatformLocationMsg&) = default;
        #else
        PlatformLocationMsg(PlatformLocationMsg&& other_) OMG_NOEXCEPT;  
        PlatformLocationMsg& operator=(PlatformLocationMsg&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        dds_msgs::EnumPlatform& PlatformType() OMG_NOEXCEPT {
            return m_PlatformType_;
        }

        const dds_msgs::EnumPlatform& PlatformType() const OMG_NOEXCEPT {
            return m_PlatformType_;
        }

        void PlatformType(const dds_msgs::EnumPlatform& value) {
            m_PlatformType_ = value;
        }

        void PlatformType(dds_msgs::EnumPlatform&& value) {
            m_PlatformType_ = std::move(value);
        }
        uint8_t& PlatformId() OMG_NOEXCEPT {
            return m_PlatformId_;
        }

        const uint8_t& PlatformId() const OMG_NOEXCEPT {
            return m_PlatformId_;
        }

        void PlatformId(uint8_t value) {
            m_PlatformId_ = value;
        }

        uint8_t& PlatformSpeed() OMG_NOEXCEPT {
            return m_PlatformSpeed_;
        }

        const uint8_t& PlatformSpeed() const OMG_NOEXCEPT {
            return m_PlatformSpeed_;
        }

        void PlatformSpeed(uint8_t value) {
            m_PlatformSpeed_ = value;
        }

        double& PlatformHeading() OMG_NOEXCEPT {
            return m_PlatformHeading_;
        }

        const double& PlatformHeading() const OMG_NOEXCEPT {
            return m_PlatformHeading_;
        }

        void PlatformHeading(double value) {
            m_PlatformHeading_ = value;
        }

        dds_msgs::GeoPoint& PlatformLocation() OMG_NOEXCEPT {
            return m_PlatformLocation_;
        }

        const dds_msgs::GeoPoint& PlatformLocation() const OMG_NOEXCEPT {
            return m_PlatformLocation_;
        }

        void PlatformLocation(const dds_msgs::GeoPoint& value) {
            m_PlatformLocation_ = value;
        }

        void PlatformLocation(dds_msgs::GeoPoint&& value) {
            m_PlatformLocation_ = std::move(value);
        }
        uint64_t& Timestamp() OMG_NOEXCEPT {
            return m_Timestamp_;
        }

        const uint64_t& Timestamp() const OMG_NOEXCEPT {
            return m_Timestamp_;
        }

        void Timestamp(uint64_t value) {
            m_Timestamp_ = value;
        }

        bool operator == (const PlatformLocationMsg& other_) const;
        bool operator != (const PlatformLocationMsg& other_) const;

        void swap(PlatformLocationMsg& other_) OMG_NOEXCEPT ;

      private:

        dds_msgs::EnumPlatform m_PlatformType_;
        uint8_t m_PlatformId_;
        uint8_t m_PlatformSpeed_;
        double m_PlatformHeading_;
        dds_msgs::GeoPoint m_PlatformLocation_;
        uint64_t m_Timestamp_;

    };

    inline void swap(PlatformLocationMsg& a, PlatformLocationMsg& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const PlatformLocationMsg& sample);

    class NDDSUSERDllExport StartJpegGenerationMsg
    : public dds_msgs::BaseMsg {
      public:
        StartJpegGenerationMsg();

        StartJpegGenerationMsg(
            uint8_t MsgId,
            uint32_t MsgCount,
            uint16_t MissionId,
            const dds_msgs::EnumPlatform& PlatformType,
            uint8_t PlatformId,
            const std::string& GeoPathJpegFiles);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        StartJpegGenerationMsg (StartJpegGenerationMsg&&) = default;
        StartJpegGenerationMsg& operator=(StartJpegGenerationMsg&&) = default;
        StartJpegGenerationMsg& operator=(const StartJpegGenerationMsg&) = default;
        StartJpegGenerationMsg(const StartJpegGenerationMsg&) = default;
        #else
        StartJpegGenerationMsg(StartJpegGenerationMsg&& other_) OMG_NOEXCEPT;  
        StartJpegGenerationMsg& operator=(StartJpegGenerationMsg&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        dds_msgs::EnumPlatform& PlatformType() OMG_NOEXCEPT {
            return m_PlatformType_;
        }

        const dds_msgs::EnumPlatform& PlatformType() const OMG_NOEXCEPT {
            return m_PlatformType_;
        }

        void PlatformType(const dds_msgs::EnumPlatform& value) {
            m_PlatformType_ = value;
        }

        void PlatformType(dds_msgs::EnumPlatform&& value) {
            m_PlatformType_ = std::move(value);
        }
        uint8_t& PlatformId() OMG_NOEXCEPT {
            return m_PlatformId_;
        }

        const uint8_t& PlatformId() const OMG_NOEXCEPT {
            return m_PlatformId_;
        }

        void PlatformId(uint8_t value) {
            m_PlatformId_ = value;
        }

        std::string& GeoPathJpegFiles() OMG_NOEXCEPT {
            return m_GeoPathJpegFiles_;
        }

        const std::string& GeoPathJpegFiles() const OMG_NOEXCEPT {
            return m_GeoPathJpegFiles_;
        }

        void GeoPathJpegFiles(const std::string& value) {
            m_GeoPathJpegFiles_ = value;
        }

        void GeoPathJpegFiles(std::string&& value) {
            m_GeoPathJpegFiles_ = std::move(value);
        }

        bool operator == (const StartJpegGenerationMsg& other_) const;
        bool operator != (const StartJpegGenerationMsg& other_) const;

        void swap(StartJpegGenerationMsg& other_) OMG_NOEXCEPT ;

      private:

        dds_msgs::EnumPlatform m_PlatformType_;
        uint8_t m_PlatformId_;
        std::string m_GeoPathJpegFiles_;

    };

    inline void swap(StartJpegGenerationMsg& a, StartJpegGenerationMsg& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const StartJpegGenerationMsg& sample);

    class NDDSUSERDllExport StopJpegGenerationMsg
    : public dds_msgs::BaseMsg {
      public:
        StopJpegGenerationMsg();

        StopJpegGenerationMsg(
            uint8_t MsgId,
            uint32_t MsgCount,
            uint16_t MissionId,
            const dds_msgs::EnumPlatform& PlatformType,
            uint8_t PlatformId);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        StopJpegGenerationMsg (StopJpegGenerationMsg&&) = default;
        StopJpegGenerationMsg& operator=(StopJpegGenerationMsg&&) = default;
        StopJpegGenerationMsg& operator=(const StopJpegGenerationMsg&) = default;
        StopJpegGenerationMsg(const StopJpegGenerationMsg&) = default;
        #else
        StopJpegGenerationMsg(StopJpegGenerationMsg&& other_) OMG_NOEXCEPT;  
        StopJpegGenerationMsg& operator=(StopJpegGenerationMsg&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        dds_msgs::EnumPlatform& PlatformType() OMG_NOEXCEPT {
            return m_PlatformType_;
        }

        const dds_msgs::EnumPlatform& PlatformType() const OMG_NOEXCEPT {
            return m_PlatformType_;
        }

        void PlatformType(const dds_msgs::EnumPlatform& value) {
            m_PlatformType_ = value;
        }

        void PlatformType(dds_msgs::EnumPlatform&& value) {
            m_PlatformType_ = std::move(value);
        }
        uint8_t& PlatformId() OMG_NOEXCEPT {
            return m_PlatformId_;
        }

        const uint8_t& PlatformId() const OMG_NOEXCEPT {
            return m_PlatformId_;
        }

        void PlatformId(uint8_t value) {
            m_PlatformId_ = value;
        }

        bool operator == (const StopJpegGenerationMsg& other_) const;
        bool operator != (const StopJpegGenerationMsg& other_) const;

        void swap(StopJpegGenerationMsg& other_) OMG_NOEXCEPT ;

      private:

        dds_msgs::EnumPlatform m_PlatformType_;
        uint8_t m_PlatformId_;

    };

    inline void swap(StopJpegGenerationMsg& a, StopJpegGenerationMsg& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const StopJpegGenerationMsg& sample);

    class NDDSUSERDllExport ReportJpegGenerationLivenessMsg
    : public dds_msgs::BaseMsg {
      public:
        ReportJpegGenerationLivenessMsg();

        ReportJpegGenerationLivenessMsg(
            uint8_t MsgId,
            uint32_t MsgCount,
            uint16_t MissionId,
            const dds_msgs::EnumPlatform& PlatformType,
            uint8_t PlatformId,
            uint16_t NumOfJpegFiles,
            const dds_msgs::EnumJpegGenerationSts& Status,
            uint8_t ErrorCode);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        ReportJpegGenerationLivenessMsg (ReportJpegGenerationLivenessMsg&&) = default;
        ReportJpegGenerationLivenessMsg& operator=(ReportJpegGenerationLivenessMsg&&) = default;
        ReportJpegGenerationLivenessMsg& operator=(const ReportJpegGenerationLivenessMsg&) = default;
        ReportJpegGenerationLivenessMsg(const ReportJpegGenerationLivenessMsg&) = default;
        #else
        ReportJpegGenerationLivenessMsg(ReportJpegGenerationLivenessMsg&& other_) OMG_NOEXCEPT;  
        ReportJpegGenerationLivenessMsg& operator=(ReportJpegGenerationLivenessMsg&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        dds_msgs::EnumPlatform& PlatformType() OMG_NOEXCEPT {
            return m_PlatformType_;
        }

        const dds_msgs::EnumPlatform& PlatformType() const OMG_NOEXCEPT {
            return m_PlatformType_;
        }

        void PlatformType(const dds_msgs::EnumPlatform& value) {
            m_PlatformType_ = value;
        }

        void PlatformType(dds_msgs::EnumPlatform&& value) {
            m_PlatformType_ = std::move(value);
        }
        uint8_t& PlatformId() OMG_NOEXCEPT {
            return m_PlatformId_;
        }

        const uint8_t& PlatformId() const OMG_NOEXCEPT {
            return m_PlatformId_;
        }

        void PlatformId(uint8_t value) {
            m_PlatformId_ = value;
        }

        uint16_t& NumOfJpegFiles() OMG_NOEXCEPT {
            return m_NumOfJpegFiles_;
        }

        const uint16_t& NumOfJpegFiles() const OMG_NOEXCEPT {
            return m_NumOfJpegFiles_;
        }

        void NumOfJpegFiles(uint16_t value) {
            m_NumOfJpegFiles_ = value;
        }

        dds_msgs::EnumJpegGenerationSts& Status() OMG_NOEXCEPT {
            return m_Status_;
        }

        const dds_msgs::EnumJpegGenerationSts& Status() const OMG_NOEXCEPT {
            return m_Status_;
        }

        void Status(const dds_msgs::EnumJpegGenerationSts& value) {
            m_Status_ = value;
        }

        void Status(dds_msgs::EnumJpegGenerationSts&& value) {
            m_Status_ = std::move(value);
        }
        uint8_t& ErrorCode() OMG_NOEXCEPT {
            return m_ErrorCode_;
        }

        const uint8_t& ErrorCode() const OMG_NOEXCEPT {
            return m_ErrorCode_;
        }

        void ErrorCode(uint8_t value) {
            m_ErrorCode_ = value;
        }

        bool operator == (const ReportJpegGenerationLivenessMsg& other_) const;
        bool operator != (const ReportJpegGenerationLivenessMsg& other_) const;

        void swap(ReportJpegGenerationLivenessMsg& other_) OMG_NOEXCEPT ;

      private:

        dds_msgs::EnumPlatform m_PlatformType_;
        uint8_t m_PlatformId_;
        uint16_t m_NumOfJpegFiles_;
        dds_msgs::EnumJpegGenerationSts m_Status_;
        uint8_t m_ErrorCode_;

    };

    inline void swap(ReportJpegGenerationLivenessMsg& a, ReportJpegGenerationLivenessMsg& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ReportJpegGenerationLivenessMsg& sample);

    class NDDSUSERDllExport LasFileTransmissionStsMsg
    : public dds_msgs::BaseMsg {
      public:
        LasFileTransmissionStsMsg();

        explicit LasFileTransmissionStsMsg(
            uint8_t MsgId,
            uint32_t MsgCount,
            uint16_t MissionId,
            const dds_msgs::EnumLasFileTransmissionSts& Status);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        LasFileTransmissionStsMsg (LasFileTransmissionStsMsg&&) = default;
        LasFileTransmissionStsMsg& operator=(LasFileTransmissionStsMsg&&) = default;
        LasFileTransmissionStsMsg& operator=(const LasFileTransmissionStsMsg&) = default;
        LasFileTransmissionStsMsg(const LasFileTransmissionStsMsg&) = default;
        #else
        LasFileTransmissionStsMsg(LasFileTransmissionStsMsg&& other_) OMG_NOEXCEPT;  
        LasFileTransmissionStsMsg& operator=(LasFileTransmissionStsMsg&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        dds_msgs::EnumLasFileTransmissionSts& Status() OMG_NOEXCEPT {
            return m_Status_;
        }

        const dds_msgs::EnumLasFileTransmissionSts& Status() const OMG_NOEXCEPT {
            return m_Status_;
        }

        void Status(const dds_msgs::EnumLasFileTransmissionSts& value) {
            m_Status_ = value;
        }

        void Status(dds_msgs::EnumLasFileTransmissionSts&& value) {
            m_Status_ = std::move(value);
        }

        bool operator == (const LasFileTransmissionStsMsg& other_) const;
        bool operator != (const LasFileTransmissionStsMsg& other_) const;

        void swap(LasFileTransmissionStsMsg& other_) OMG_NOEXCEPT ;

      private:

        dds_msgs::EnumLasFileTransmissionSts m_Status_;

    };

    inline void swap(LasFileTransmissionStsMsg& a, LasFileTransmissionStsMsg& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const LasFileTransmissionStsMsg& sample);

    class NDDSUSERDllExport SingleUrlMsg
    : public dds_msgs::BaseMsg {
      public:
        SingleUrlMsg();

        explicit SingleUrlMsg(
            uint8_t MsgId,
            uint32_t MsgCount,
            uint16_t MissionId,
            const std::string& CloudUrl);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        SingleUrlMsg (SingleUrlMsg&&) = default;
        SingleUrlMsg& operator=(SingleUrlMsg&&) = default;
        SingleUrlMsg& operator=(const SingleUrlMsg&) = default;
        SingleUrlMsg(const SingleUrlMsg&) = default;
        #else
        SingleUrlMsg(SingleUrlMsg&& other_) OMG_NOEXCEPT;  
        SingleUrlMsg& operator=(SingleUrlMsg&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        std::string& CloudUrl() OMG_NOEXCEPT {
            return m_CloudUrl_;
        }

        const std::string& CloudUrl() const OMG_NOEXCEPT {
            return m_CloudUrl_;
        }

        void CloudUrl(const std::string& value) {
            m_CloudUrl_ = value;
        }

        void CloudUrl(std::string&& value) {
            m_CloudUrl_ = std::move(value);
        }

        bool operator == (const SingleUrlMsg& other_) const;
        bool operator != (const SingleUrlMsg& other_) const;

        void swap(SingleUrlMsg& other_) OMG_NOEXCEPT ;

      private:

        std::string m_CloudUrl_;

    };

    inline void swap(SingleUrlMsg& a, SingleUrlMsg& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SingleUrlMsg& sample);

    class NDDSUSERDllExport DoubleUrlMsg
    : public dds_msgs::BaseMsg {
      public:
        DoubleUrlMsg();

        DoubleUrlMsg(
            uint8_t MsgId,
            uint32_t MsgCount,
            uint16_t MissionId,
            const std::string& GeoPath,
            const std::string& CloudUrl);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        DoubleUrlMsg (DoubleUrlMsg&&) = default;
        DoubleUrlMsg& operator=(DoubleUrlMsg&&) = default;
        DoubleUrlMsg& operator=(const DoubleUrlMsg&) = default;
        DoubleUrlMsg(const DoubleUrlMsg&) = default;
        #else
        DoubleUrlMsg(DoubleUrlMsg&& other_) OMG_NOEXCEPT;  
        DoubleUrlMsg& operator=(DoubleUrlMsg&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        std::string& GeoPath() OMG_NOEXCEPT {
            return m_GeoPath_;
        }

        const std::string& GeoPath() const OMG_NOEXCEPT {
            return m_GeoPath_;
        }

        void GeoPath(const std::string& value) {
            m_GeoPath_ = value;
        }

        void GeoPath(std::string&& value) {
            m_GeoPath_ = std::move(value);
        }
        std::string& CloudUrl() OMG_NOEXCEPT {
            return m_CloudUrl_;
        }

        const std::string& CloudUrl() const OMG_NOEXCEPT {
            return m_CloudUrl_;
        }

        void CloudUrl(const std::string& value) {
            m_CloudUrl_ = value;
        }

        void CloudUrl(std::string&& value) {
            m_CloudUrl_ = std::move(value);
        }

        bool operator == (const DoubleUrlMsg& other_) const;
        bool operator != (const DoubleUrlMsg& other_) const;

        void swap(DoubleUrlMsg& other_) OMG_NOEXCEPT ;

      private:

        std::string m_GeoPath_;
        std::string m_CloudUrl_;

    };

    inline void swap(DoubleUrlMsg& a, DoubleUrlMsg& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DoubleUrlMsg& sample);

} // namespace dds_msgs  

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< dds_msgs::GeoPoint > {
            NDDSUSERDllExport static std::string value() {
                return "dds_msgs::GeoPoint";
            }
        };

        template<>
        struct topic_type_support< dds_msgs::GeoPoint > {
            NDDSUSERDllExport 
            static void reset_sample(dds_msgs::GeoPoint& sample);

            NDDSUSERDllExport 
            static void allocate_sample(dds_msgs::GeoPoint& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< dds_msgs::LocalScan > {
            NDDSUSERDllExport static std::string value() {
                return "dds_msgs::LocalScan";
            }
        };

        template<>
        struct topic_type_support< dds_msgs::LocalScan > {
            NDDSUSERDllExport 
            static void reset_sample(dds_msgs::LocalScan& sample);

            NDDSUSERDllExport 
            static void allocate_sample(dds_msgs::LocalScan& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< dds_msgs::BaseMsg > {
            NDDSUSERDllExport static std::string value() {
                return "dds_msgs::BaseMsg";
            }
        };

        template<>
        struct is_topic_type< dds_msgs::BaseMsg > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< dds_msgs::BaseMsg > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const dds_msgs::BaseMsg& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(dds_msgs::BaseMsg& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(dds_msgs::BaseMsg& sample);

            NDDSUSERDllExport 
            static void allocate_sample(dds_msgs::BaseMsg& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< dds_msgs::MissionPlanMsg > {
            NDDSUSERDllExport static std::string value() {
                return "dds_msgs::MissionPlanMsg";
            }
        };

        template<>
        struct is_topic_type< dds_msgs::MissionPlanMsg > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< dds_msgs::MissionPlanMsg > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const dds_msgs::MissionPlanMsg& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(dds_msgs::MissionPlanMsg& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(dds_msgs::MissionPlanMsg& sample);

            NDDSUSERDllExport 
            static void allocate_sample(dds_msgs::MissionPlanMsg& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< dds_msgs::GetDroneScanRouteMsg > {
            NDDSUSERDllExport static std::string value() {
                return "dds_msgs::GetDroneScanRouteMsg";
            }
        };

        template<>
        struct is_topic_type< dds_msgs::GetDroneScanRouteMsg > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< dds_msgs::GetDroneScanRouteMsg > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const dds_msgs::GetDroneScanRouteMsg& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(dds_msgs::GetDroneScanRouteMsg& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(dds_msgs::GetDroneScanRouteMsg& sample);

            NDDSUSERDllExport 
            static void allocate_sample(dds_msgs::GetDroneScanRouteMsg& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< dds_msgs::DroneScanRouteMsg > {
            NDDSUSERDllExport static std::string value() {
                return "dds_msgs::DroneScanRouteMsg";
            }
        };

        template<>
        struct is_topic_type< dds_msgs::DroneScanRouteMsg > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< dds_msgs::DroneScanRouteMsg > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const dds_msgs::DroneScanRouteMsg& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(dds_msgs::DroneScanRouteMsg& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(dds_msgs::DroneScanRouteMsg& sample);

            NDDSUSERDllExport 
            static void allocate_sample(dds_msgs::DroneScanRouteMsg& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< dds_msgs::PlatformLocationMsg > {
            NDDSUSERDllExport static std::string value() {
                return "dds_msgs::PlatformLocationMsg";
            }
        };

        template<>
        struct is_topic_type< dds_msgs::PlatformLocationMsg > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< dds_msgs::PlatformLocationMsg > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const dds_msgs::PlatformLocationMsg& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(dds_msgs::PlatformLocationMsg& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(dds_msgs::PlatformLocationMsg& sample);

            NDDSUSERDllExport 
            static void allocate_sample(dds_msgs::PlatformLocationMsg& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< dds_msgs::StartJpegGenerationMsg > {
            NDDSUSERDllExport static std::string value() {
                return "dds_msgs::StartJpegGenerationMsg";
            }
        };

        template<>
        struct is_topic_type< dds_msgs::StartJpegGenerationMsg > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< dds_msgs::StartJpegGenerationMsg > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const dds_msgs::StartJpegGenerationMsg& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(dds_msgs::StartJpegGenerationMsg& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(dds_msgs::StartJpegGenerationMsg& sample);

            NDDSUSERDllExport 
            static void allocate_sample(dds_msgs::StartJpegGenerationMsg& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< dds_msgs::StopJpegGenerationMsg > {
            NDDSUSERDllExport static std::string value() {
                return "dds_msgs::StopJpegGenerationMsg";
            }
        };

        template<>
        struct is_topic_type< dds_msgs::StopJpegGenerationMsg > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< dds_msgs::StopJpegGenerationMsg > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const dds_msgs::StopJpegGenerationMsg& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(dds_msgs::StopJpegGenerationMsg& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(dds_msgs::StopJpegGenerationMsg& sample);

            NDDSUSERDllExport 
            static void allocate_sample(dds_msgs::StopJpegGenerationMsg& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< dds_msgs::ReportJpegGenerationLivenessMsg > {
            NDDSUSERDllExport static std::string value() {
                return "dds_msgs::ReportJpegGenerationLivenessMsg";
            }
        };

        template<>
        struct is_topic_type< dds_msgs::ReportJpegGenerationLivenessMsg > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< dds_msgs::ReportJpegGenerationLivenessMsg > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const dds_msgs::ReportJpegGenerationLivenessMsg& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(dds_msgs::ReportJpegGenerationLivenessMsg& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(dds_msgs::ReportJpegGenerationLivenessMsg& sample);

            NDDSUSERDllExport 
            static void allocate_sample(dds_msgs::ReportJpegGenerationLivenessMsg& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< dds_msgs::LasFileTransmissionStsMsg > {
            NDDSUSERDllExport static std::string value() {
                return "dds_msgs::LasFileTransmissionStsMsg";
            }
        };

        template<>
        struct is_topic_type< dds_msgs::LasFileTransmissionStsMsg > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< dds_msgs::LasFileTransmissionStsMsg > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const dds_msgs::LasFileTransmissionStsMsg& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(dds_msgs::LasFileTransmissionStsMsg& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(dds_msgs::LasFileTransmissionStsMsg& sample);

            NDDSUSERDllExport 
            static void allocate_sample(dds_msgs::LasFileTransmissionStsMsg& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< dds_msgs::SingleUrlMsg > {
            NDDSUSERDllExport static std::string value() {
                return "dds_msgs::SingleUrlMsg";
            }
        };

        template<>
        struct is_topic_type< dds_msgs::SingleUrlMsg > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< dds_msgs::SingleUrlMsg > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const dds_msgs::SingleUrlMsg& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(dds_msgs::SingleUrlMsg& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(dds_msgs::SingleUrlMsg& sample);

            NDDSUSERDllExport 
            static void allocate_sample(dds_msgs::SingleUrlMsg& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< dds_msgs::DoubleUrlMsg > {
            NDDSUSERDllExport static std::string value() {
                return "dds_msgs::DoubleUrlMsg";
            }
        };

        template<>
        struct is_topic_type< dds_msgs::DoubleUrlMsg > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< dds_msgs::DoubleUrlMsg > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const dds_msgs::DoubleUrlMsg& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(dds_msgs::DoubleUrlMsg& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(dds_msgs::DoubleUrlMsg& sample);

            NDDSUSERDllExport 
            static void allocate_sample(dds_msgs::DoubleUrlMsg& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<dds_msgs::EnumMission>
        {
            static const dds_msgs::EnumMission value;
        };
        template<>
        struct dynamic_type< dds_msgs::EnumMission > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::EnumMission > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<dds_msgs::EnumPlatform>
        {
            static const dds_msgs::EnumPlatform value;
        };
        template<>
        struct dynamic_type< dds_msgs::EnumPlatform > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::EnumPlatform > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<dds_msgs::EnumScan>
        {
            static const dds_msgs::EnumScan value;
        };
        template<>
        struct dynamic_type< dds_msgs::EnumScan > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::EnumScan > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<dds_msgs::EnumJpegGenerationSts>
        {
            static const dds_msgs::EnumJpegGenerationSts value;
        };
        template<>
        struct dynamic_type< dds_msgs::EnumJpegGenerationSts > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::EnumJpegGenerationSts > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<dds_msgs::EnumLasFileTransmissionSts>
        {
            static const dds_msgs::EnumLasFileTransmissionSts value;
        };
        template<>
        struct dynamic_type< dds_msgs::EnumLasFileTransmissionSts > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::EnumLasFileTransmissionSts > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<dds_msgs::EnumCalculation>
        {
            static const dds_msgs::EnumCalculation value;
        };
        template<>
        struct dynamic_type< dds_msgs::EnumCalculation > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::EnumCalculation > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< dds_msgs::GeoPoint > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::GeoPoint > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< dds_msgs::LocalScan > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::LocalScan > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< dds_msgs::BaseMsg > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::BaseMsg > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< dds_msgs::MissionPlanMsg > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::MissionPlanMsg > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< dds_msgs::GetDroneScanRouteMsg > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::GetDroneScanRouteMsg > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< dds_msgs::DroneScanRouteMsg > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::DroneScanRouteMsg > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< dds_msgs::PlatformLocationMsg > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::PlatformLocationMsg > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< dds_msgs::StartJpegGenerationMsg > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::StartJpegGenerationMsg > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< dds_msgs::StopJpegGenerationMsg > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::StopJpegGenerationMsg > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< dds_msgs::ReportJpegGenerationLivenessMsg > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::ReportJpegGenerationLivenessMsg > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< dds_msgs::LasFileTransmissionStsMsg > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::LasFileTransmissionStsMsg > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< dds_msgs::SingleUrlMsg > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::SingleUrlMsg > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< dds_msgs::DoubleUrlMsg > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< dds_msgs::DoubleUrlMsg > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // dds_msgs_1583855963_hpp

