

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from dds_msgs.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "dds_msgs.hpp"
#include "dds_msgsPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

namespace dds_msgs {

    std::ostream& operator << (std::ostream& o,const EnumMission& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case EnumMission::None:
            o << "EnumMission::None" << " ";
            break;
            case EnumMission::AirBuild:
            o << "EnumMission::AirBuild" << " ";
            break;
            case EnumMission::AirDiff:
            o << "EnumMission::AirDiff" << " ";
            break;
            case EnumMission::GroundBuild:
            o << "EnumMission::GroundBuild" << " ";
            break;
            case EnumMission::GroundDiff:
            o << "EnumMission::GroundDiff" << " ";
            break;
        }
        return o;
    }

    std::ostream& operator << (std::ostream& o,const EnumPlatform& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case EnumPlatform::None:
            o << "EnumPlatform::None" << " ";
            break;
            case EnumPlatform::Drone:
            o << "EnumPlatform::Drone" << " ";
            break;
            case EnumPlatform::UGV:
            o << "EnumPlatform::UGV" << " ";
            break;
        }
        return o;
    }

    std::ostream& operator << (std::ostream& o,const EnumScan& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case EnumScan::None:
            o << "EnumScan::None" << " ";
            break;
            case EnumScan::Rectangular:
            o << "EnumScan::Rectangular" << " ";
            break;
            case EnumScan::LocalSquare:
            o << "EnumScan::LocalSquare" << " ";
            break;
        }
        return o;
    }

    std::ostream& operator << (std::ostream& o,const EnumJpegGenerationSts& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case EnumJpegGenerationSts::None:
            o << "EnumJpegGenerationSts::None" << " ";
            break;
            case EnumJpegGenerationSts::Waiting:
            o << "EnumJpegGenerationSts::Waiting" << " ";
            break;
            case EnumJpegGenerationSts::Generating:
            o << "EnumJpegGenerationSts::Generating" << " ";
            break;
            case EnumJpegGenerationSts::Fail:
            o << "EnumJpegGenerationSts::Fail" << " ";
            break;
        }
        return o;
    }

    std::ostream& operator << (std::ostream& o,const EnumLasFileTransmissionSts& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case EnumLasFileTransmissionSts::None:
            o << "EnumLasFileTransmissionSts::None" << " ";
            break;
            case EnumLasFileTransmissionSts::Finished:
            o << "EnumLasFileTransmissionSts::Finished" << " ";
            break;
            case EnumLasFileTransmissionSts::Verified:
            o << "EnumLasFileTransmissionSts::Verified" << " ";
            break;
            case EnumLasFileTransmissionSts::Error1:
            o << "EnumLasFileTransmissionSts::Error1" << " ";
            break;
            case EnumLasFileTransmissionSts::Error2:
            o << "EnumLasFileTransmissionSts::Error2" << " ";
            break;
        }
        return o;
    }

    std::ostream& operator << (std::ostream& o,const EnumCalculation& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case EnumCalculation::None:
            o << "EnumCalculation::None" << " ";
            break;
            case EnumCalculation::NewModel:
            o << "EnumCalculation::NewModel" << " ";
            break;
            case EnumCalculation::DiffAnalysis:
            o << "EnumCalculation::DiffAnalysis" << " ";
            break;
        }
        return o;
    }

    // ---- GeoPoint: 

    GeoPoint::GeoPoint() :
        m_Lat_ (0.0) ,
        m_Lon_ (0.0) ,
        m_Alt_ (0.0)  {
    }   

    GeoPoint::GeoPoint (
        double Lat,
        double Lon,
        double Alt)
        :
            m_Lat_( Lat ),
            m_Lon_( Lon ),
            m_Alt_( Alt ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    GeoPoint::GeoPoint(GeoPoint&& other_) OMG_NOEXCEPT  :m_Lat_ (std::move(other_.m_Lat_))
    ,
    m_Lon_ (std::move(other_.m_Lon_))
    ,
    m_Alt_ (std::move(other_.m_Alt_))
    {
    } 

    GeoPoint& GeoPoint::operator=(GeoPoint&&  other_) OMG_NOEXCEPT {
        GeoPoint tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void GeoPoint::swap(GeoPoint& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_Lat_, other_.m_Lat_);
        swap(m_Lon_, other_.m_Lon_);
        swap(m_Alt_, other_.m_Alt_);
    }  

    bool GeoPoint::operator == (const GeoPoint& other_) const {
        if (m_Lat_ != other_.m_Lat_) {
            return false;
        }
        if (m_Lon_ != other_.m_Lon_) {
            return false;
        }
        if (m_Alt_ != other_.m_Alt_) {
            return false;
        }
        return true;
    }
    bool GeoPoint::operator != (const GeoPoint& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const GeoPoint& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "Lat: " << std::setprecision(15) <<sample.Lat()<<", ";
        o << "Lon: " << std::setprecision(15) <<sample.Lon()<<", ";
        o << "Alt: " << std::setprecision(15) <<sample.Alt() ;
        o <<"]";
        return o;
    }

    // ---- LocalScan: 

    LocalScan::LocalScan() :
        m_SquareSide_ (0U)  {
    }   

    LocalScan::LocalScan (
        const dds_msgs::GeoPoint& SquareCenter,
        uint16_t SquareSide)
        :
            m_SquareCenter_( SquareCenter ),
            m_SquareSide_( SquareSide ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    LocalScan::LocalScan(LocalScan&& other_) OMG_NOEXCEPT  :m_SquareCenter_ (std::move(other_.m_SquareCenter_))
    ,
    m_SquareSide_ (std::move(other_.m_SquareSide_))
    {
    } 

    LocalScan& LocalScan::operator=(LocalScan&&  other_) OMG_NOEXCEPT {
        LocalScan tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void LocalScan::swap(LocalScan& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_SquareCenter_, other_.m_SquareCenter_);
        swap(m_SquareSide_, other_.m_SquareSide_);
    }  

    bool LocalScan::operator == (const LocalScan& other_) const {
        if (m_SquareCenter_ != other_.m_SquareCenter_) {
            return false;
        }
        if (m_SquareSide_ != other_.m_SquareSide_) {
            return false;
        }
        return true;
    }
    bool LocalScan::operator != (const LocalScan& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const LocalScan& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "SquareCenter: " << sample.SquareCenter()<<", ";
        o << "SquareSide: " << sample.SquareSide() ;
        o <<"]";
        return o;
    }

    // ---- BaseMsg: 

    BaseMsg::BaseMsg() :
        m_MsgId_ (0) ,
        m_MsgCount_ (0UL) ,
        m_MissionId_ (0U)  {
    }   

    BaseMsg::BaseMsg (
        uint8_t MsgId,
        uint32_t MsgCount,
        uint16_t MissionId)
        :
            m_MsgId_( MsgId ),
            m_MsgCount_( MsgCount ),
            m_MissionId_( MissionId ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    BaseMsg::BaseMsg(BaseMsg&& other_) OMG_NOEXCEPT  :m_MsgId_ (std::move(other_.m_MsgId_))
    ,
    m_MsgCount_ (std::move(other_.m_MsgCount_))
    ,
    m_MissionId_ (std::move(other_.m_MissionId_))
    {
    } 

    BaseMsg& BaseMsg::operator=(BaseMsg&&  other_) OMG_NOEXCEPT {
        BaseMsg tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void BaseMsg::swap(BaseMsg& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_MsgId_, other_.m_MsgId_);
        swap(m_MsgCount_, other_.m_MsgCount_);
        swap(m_MissionId_, other_.m_MissionId_);
    }  

    bool BaseMsg::operator == (const BaseMsg& other_) const {
        if (m_MsgId_ != other_.m_MsgId_) {
            return false;
        }
        if (m_MsgCount_ != other_.m_MsgCount_) {
            return false;
        }
        if (m_MissionId_ != other_.m_MissionId_) {
            return false;
        }
        return true;
    }
    bool BaseMsg::operator != (const BaseMsg& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const BaseMsg& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "MsgId: " << (int)sample.MsgId() <<", ";
        o << "MsgCount: " << sample.MsgCount()<<", ";
        o << "MissionId: " << sample.MissionId() ;
        o <<"]";
        return o;
    }

    // ---- MissionPlanMsg: 

    MissionPlanMsg::MissionPlanMsg() :
        m_MissionName_ ("") ,
        m_MissionType_(dds_msgs::EnumMission::None) ,
        m_StationId_ (0) ,
        m_PlatformType_(dds_msgs::EnumPlatform::None) ,
        m_PlatformId_ (0U) ,
        m_ScanType_(dds_msgs::EnumScan::None) ,
        m_ScanAreaGroundAvgAlt_ (0) ,
        m_FlightAltAboveGroundAvgAlt_ (0U) ,
        m_TakeoffAltAboveSeaLevel_ (0) ,
        m_FlightSpeed_ (0) ,
        m_CameraHorizontalFOV_ (0) ,
        m_CameraVerticalFOV_ (0) ,
        m_CameraHorizontalResolution_ (0U) ,
        m_CameraVerticalResolution_ (0U) ,
        m_OverlapInFlightDirection_ (0) ,
        m_OverlapInLateralDirection_ (0) ,
        m_GimbalPitchAngle_ (0) ,
        m_SquareSide_ (0U) ,
        m_GeoPathCurrModel_ ("") ,
        m_CloudUrlCurrModel_ ("")  {
    }   

    MissionPlanMsg::MissionPlanMsg (
        uint8_t MsgId,
        uint32_t MsgCount,
        uint16_t MissionId,
        const std::string& MissionName,
        const dds_msgs::EnumMission& MissionType,
        uint8_t StationId,
        const dds_msgs::EnumPlatform& PlatformType,
        uint16_t PlatformId,
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
        const ::dds::core::optional< std::string >& CloudUrlDiffModel)
        :
            dds_msgs::BaseMsg(MsgId,MsgCount,MissionId ),
            m_MissionName_( MissionName ),
            m_MissionType_( MissionType ),
            m_StationId_( StationId ),
            m_PlatformType_( PlatformType ),
            m_PlatformId_( PlatformId ),
            m_ScanType_( ScanType ),
            m_ScanArea_( ScanArea ),
            m_ScanAreaGroundAvgAlt_( ScanAreaGroundAvgAlt ),
            m_FlightAltAboveGroundAvgAlt_( FlightAltAboveGroundAvgAlt ),
            m_TakeoffAltAboveSeaLevel_( TakeoffAltAboveSeaLevel ),
            m_FlightSpeed_( FlightSpeed ),
            m_CameraHorizontalFOV_( CameraHorizontalFOV ),
            m_CameraVerticalFOV_( CameraVerticalFOV ),
            m_CameraHorizontalResolution_( CameraHorizontalResolution ),
            m_CameraVerticalResolution_( CameraVerticalResolution ),
            m_OverlapInFlightDirection_( OverlapInFlightDirection ),
            m_OverlapInLateralDirection_( OverlapInLateralDirection ),
            m_GimbalPitchAngle_( GimbalPitchAngle ),
            m_SquareCenter_( SquareCenter ),
            m_SquareSide_( SquareSide ),
            m_GeoPathJpegFiles_( GeoPathJpegFiles ),
            m_GeoPathCurrModel_( GeoPathCurrModel ),
            m_GeoPathRefModel_( GeoPathRefModel ),
            m_GeoPathDiffModel_( GeoPathDiffModel ),
            m_CloudUrlCurrModel_( CloudUrlCurrModel ),
            m_CloudUrlRefModel_( CloudUrlRefModel ),
            m_CloudUrlDiffModel_( CloudUrlDiffModel ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    MissionPlanMsg::MissionPlanMsg(MissionPlanMsg&& other_) OMG_NOEXCEPT  : 
    dds_msgs::BaseMsg(std::move(other_)),
    m_MissionName_ (std::move(other_.m_MissionName_))
    ,
    m_MissionType_ (std::move(other_.m_MissionType_))
    ,
    m_StationId_ (std::move(other_.m_StationId_))
    ,
    m_PlatformType_ (std::move(other_.m_PlatformType_))
    ,
    m_PlatformId_ (std::move(other_.m_PlatformId_))
    ,
    m_ScanType_ (std::move(other_.m_ScanType_))
    ,
    m_ScanArea_ (std::move(other_.m_ScanArea_))
    ,
    m_ScanAreaGroundAvgAlt_ (std::move(other_.m_ScanAreaGroundAvgAlt_))
    ,
    m_FlightAltAboveGroundAvgAlt_ (std::move(other_.m_FlightAltAboveGroundAvgAlt_))
    ,
    m_TakeoffAltAboveSeaLevel_ (std::move(other_.m_TakeoffAltAboveSeaLevel_))
    ,
    m_FlightSpeed_ (std::move(other_.m_FlightSpeed_))
    ,
    m_CameraHorizontalFOV_ (std::move(other_.m_CameraHorizontalFOV_))
    ,
    m_CameraVerticalFOV_ (std::move(other_.m_CameraVerticalFOV_))
    ,
    m_CameraHorizontalResolution_ (std::move(other_.m_CameraHorizontalResolution_))
    ,
    m_CameraVerticalResolution_ (std::move(other_.m_CameraVerticalResolution_))
    ,
    m_OverlapInFlightDirection_ (std::move(other_.m_OverlapInFlightDirection_))
    ,
    m_OverlapInLateralDirection_ (std::move(other_.m_OverlapInLateralDirection_))
    ,
    m_GimbalPitchAngle_ (std::move(other_.m_GimbalPitchAngle_))
    ,
    m_SquareCenter_ (std::move(other_.m_SquareCenter_))
    ,
    m_SquareSide_ (std::move(other_.m_SquareSide_))
    ,
    m_GeoPathJpegFiles_ (std::move(other_.m_GeoPathJpegFiles_))
    ,
    m_GeoPathCurrModel_ (std::move(other_.m_GeoPathCurrModel_))
    ,
    m_GeoPathRefModel_ (std::move(other_.m_GeoPathRefModel_))
    ,
    m_GeoPathDiffModel_ (std::move(other_.m_GeoPathDiffModel_))
    ,
    m_CloudUrlCurrModel_ (std::move(other_.m_CloudUrlCurrModel_))
    ,
    m_CloudUrlRefModel_ (std::move(other_.m_CloudUrlRefModel_))
    ,
    m_CloudUrlDiffModel_ (std::move(other_.m_CloudUrlDiffModel_))
    {
    } 

    MissionPlanMsg& MissionPlanMsg::operator=(MissionPlanMsg&&  other_) OMG_NOEXCEPT {
        MissionPlanMsg tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void MissionPlanMsg::swap(MissionPlanMsg& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        dds_msgs::BaseMsg::swap(other_);
        swap(m_MissionName_, other_.m_MissionName_);
        swap(m_MissionType_, other_.m_MissionType_);
        swap(m_StationId_, other_.m_StationId_);
        swap(m_PlatformType_, other_.m_PlatformType_);
        swap(m_PlatformId_, other_.m_PlatformId_);
        swap(m_ScanType_, other_.m_ScanType_);
        swap(m_ScanArea_, other_.m_ScanArea_);
        swap(m_ScanAreaGroundAvgAlt_, other_.m_ScanAreaGroundAvgAlt_);
        swap(m_FlightAltAboveGroundAvgAlt_, other_.m_FlightAltAboveGroundAvgAlt_);
        swap(m_TakeoffAltAboveSeaLevel_, other_.m_TakeoffAltAboveSeaLevel_);
        swap(m_FlightSpeed_, other_.m_FlightSpeed_);
        swap(m_CameraHorizontalFOV_, other_.m_CameraHorizontalFOV_);
        swap(m_CameraVerticalFOV_, other_.m_CameraVerticalFOV_);
        swap(m_CameraHorizontalResolution_, other_.m_CameraHorizontalResolution_);
        swap(m_CameraVerticalResolution_, other_.m_CameraVerticalResolution_);
        swap(m_OverlapInFlightDirection_, other_.m_OverlapInFlightDirection_);
        swap(m_OverlapInLateralDirection_, other_.m_OverlapInLateralDirection_);
        swap(m_GimbalPitchAngle_, other_.m_GimbalPitchAngle_);
        swap(m_SquareCenter_, other_.m_SquareCenter_);
        swap(m_SquareSide_, other_.m_SquareSide_);
        swap(m_GeoPathJpegFiles_, other_.m_GeoPathJpegFiles_);
        swap(m_GeoPathCurrModel_, other_.m_GeoPathCurrModel_);
        swap(m_GeoPathRefModel_, other_.m_GeoPathRefModel_);
        swap(m_GeoPathDiffModel_, other_.m_GeoPathDiffModel_);
        swap(m_CloudUrlCurrModel_, other_.m_CloudUrlCurrModel_);
        swap(m_CloudUrlRefModel_, other_.m_CloudUrlRefModel_);
        swap(m_CloudUrlDiffModel_, other_.m_CloudUrlDiffModel_);
    }  

    bool MissionPlanMsg::operator == (const MissionPlanMsg& other_) const {
        if (!dds_msgs::BaseMsg::operator == (other_)){
            return false;
        }
        if (m_MissionName_ != other_.m_MissionName_) {
            return false;
        }
        if (m_MissionType_ != other_.m_MissionType_) {
            return false;
        }
        if (m_StationId_ != other_.m_StationId_) {
            return false;
        }
        if (m_PlatformType_ != other_.m_PlatformType_) {
            return false;
        }
        if (m_PlatformId_ != other_.m_PlatformId_) {
            return false;
        }
        if (m_ScanType_ != other_.m_ScanType_) {
            return false;
        }
        if (m_ScanArea_ != other_.m_ScanArea_) {
            return false;
        }
        if (m_ScanAreaGroundAvgAlt_ != other_.m_ScanAreaGroundAvgAlt_) {
            return false;
        }
        if (m_FlightAltAboveGroundAvgAlt_ != other_.m_FlightAltAboveGroundAvgAlt_) {
            return false;
        }
        if (m_TakeoffAltAboveSeaLevel_ != other_.m_TakeoffAltAboveSeaLevel_) {
            return false;
        }
        if (m_FlightSpeed_ != other_.m_FlightSpeed_) {
            return false;
        }
        if (m_CameraHorizontalFOV_ != other_.m_CameraHorizontalFOV_) {
            return false;
        }
        if (m_CameraVerticalFOV_ != other_.m_CameraVerticalFOV_) {
            return false;
        }
        if (m_CameraHorizontalResolution_ != other_.m_CameraHorizontalResolution_) {
            return false;
        }
        if (m_CameraVerticalResolution_ != other_.m_CameraVerticalResolution_) {
            return false;
        }
        if (m_OverlapInFlightDirection_ != other_.m_OverlapInFlightDirection_) {
            return false;
        }
        if (m_OverlapInLateralDirection_ != other_.m_OverlapInLateralDirection_) {
            return false;
        }
        if (m_GimbalPitchAngle_ != other_.m_GimbalPitchAngle_) {
            return false;
        }
        if (m_SquareCenter_ != other_.m_SquareCenter_) {
            return false;
        }
        if (m_SquareSide_ != other_.m_SquareSide_) {
            return false;
        }
        if (m_GeoPathJpegFiles_ != other_.m_GeoPathJpegFiles_) {
            return false;
        }
        if (m_GeoPathCurrModel_ != other_.m_GeoPathCurrModel_) {
            return false;
        }
        if (m_GeoPathRefModel_ != other_.m_GeoPathRefModel_) {
            return false;
        }
        if (m_GeoPathDiffModel_ != other_.m_GeoPathDiffModel_) {
            return false;
        }
        if (m_CloudUrlCurrModel_ != other_.m_CloudUrlCurrModel_) {
            return false;
        }
        if (m_CloudUrlRefModel_ != other_.m_CloudUrlRefModel_) {
            return false;
        }
        if (m_CloudUrlDiffModel_ != other_.m_CloudUrlDiffModel_) {
            return false;
        }
        return true;
    }
    bool MissionPlanMsg::operator != (const MissionPlanMsg& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const MissionPlanMsg& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << static_cast<const dds_msgs::BaseMsg &>(sample);
        o << "MissionName: " << sample.MissionName()<<", ";
        o << "MissionType: " << sample.MissionType()<<", ";
        o << "StationId: " << (int)sample.StationId() <<", ";
        o << "PlatformType: " << sample.PlatformType()<<", ";
        o << "PlatformId: " << sample.PlatformId()<<", ";
        o << "ScanType: " << sample.ScanType()<<", ";
        o << "ScanArea: " << sample.ScanArea()<<", ";
        o << "ScanAreaGroundAvgAlt: " << sample.ScanAreaGroundAvgAlt()<<", ";
        o << "FlightAltAboveGroundAvgAlt: " << sample.FlightAltAboveGroundAvgAlt()<<", ";
        o << "TakeoffAltAboveSeaLevel: " << sample.TakeoffAltAboveSeaLevel()<<", ";
        o << "FlightSpeed: " << (int)sample.FlightSpeed() <<", ";
        o << "CameraHorizontalFOV: " << (int)sample.CameraHorizontalFOV() <<", ";
        o << "CameraVerticalFOV: " << (int)sample.CameraVerticalFOV() <<", ";
        o << "CameraHorizontalResolution: " << sample.CameraHorizontalResolution()<<", ";
        o << "CameraVerticalResolution: " << sample.CameraVerticalResolution()<<", ";
        o << "OverlapInFlightDirection: " << (int)sample.OverlapInFlightDirection() <<", ";
        o << "OverlapInLateralDirection: " << (int)sample.OverlapInLateralDirection() <<", ";
        o << "GimbalPitchAngle: " << sample.GimbalPitchAngle()<<", ";
        o << "SquareCenter: " << sample.SquareCenter()<<", ";
        o << "SquareSide: " << sample.SquareSide()<<", ";
        o << "GeoPathJpegFiles: " << sample.GeoPathJpegFiles()<<", ";
        o << "GeoPathCurrModel: " << sample.GeoPathCurrModel()<<", ";
        o << "GeoPathRefModel: " << sample.GeoPathRefModel()<<", ";
        o << "GeoPathDiffModel: " << sample.GeoPathDiffModel()<<", ";
        o << "CloudUrlCurrModel: " << sample.CloudUrlCurrModel()<<", ";
        o << "CloudUrlRefModel: " << sample.CloudUrlRefModel()<<", ";
        o << "CloudUrlDiffModel: " << sample.CloudUrlDiffModel() ;
        o <<"]";
        return o;
    }

    // ---- GetDroneScanRouteMsg: 

    GetDroneScanRouteMsg::GetDroneScanRouteMsg() :
        m_ScanType_(dds_msgs::EnumScan::None) ,
        m_ScanAreaGroundAvgAlt_ (0) ,
        m_FlightAltAboveGroundAvgAlt_ (0) ,
        m_TakeoffAltAboveSeaLevel_ (0) ,
        m_FlightSpeed_ (0) ,
        m_CameraHorizontalFOV_ (0) ,
        m_CameraVerticalFOV_ (0) ,
        m_CameraHorizontalResolution_ (0U) ,
        m_CameraVerticalResolution_ (0U) ,
        m_OverlapInFlightDirection_ (0) ,
        m_OverlapInLateralDirection_ (0) ,
        m_GimbalPitchAngle_ (0) ,
        m_SquareSide_ (0U)  {
    }   

    GetDroneScanRouteMsg::GetDroneScanRouteMsg (
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
        uint16_t SquareSide)
        :
            dds_msgs::BaseMsg(MsgId,MsgCount,MissionId ),
            m_ScanType_( ScanType ),
            m_ScanArea_( ScanArea ),
            m_ScanAreaGroundAvgAlt_( ScanAreaGroundAvgAlt ),
            m_FlightAltAboveGroundAvgAlt_( FlightAltAboveGroundAvgAlt ),
            m_TakeoffAltAboveSeaLevel_( TakeoffAltAboveSeaLevel ),
            m_FlightSpeed_( FlightSpeed ),
            m_CameraHorizontalFOV_( CameraHorizontalFOV ),
            m_CameraVerticalFOV_( CameraVerticalFOV ),
            m_CameraHorizontalResolution_( CameraHorizontalResolution ),
            m_CameraVerticalResolution_( CameraVerticalResolution ),
            m_OverlapInFlightDirection_( OverlapInFlightDirection ),
            m_OverlapInLateralDirection_( OverlapInLateralDirection ),
            m_GimbalPitchAngle_( GimbalPitchAngle ),
            m_SquareCenter_( SquareCenter ),
            m_SquareSide_( SquareSide ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    GetDroneScanRouteMsg::GetDroneScanRouteMsg(GetDroneScanRouteMsg&& other_) OMG_NOEXCEPT  : 
    dds_msgs::BaseMsg(std::move(other_)),
    m_ScanType_ (std::move(other_.m_ScanType_))
    ,
    m_ScanArea_ (std::move(other_.m_ScanArea_))
    ,
    m_ScanAreaGroundAvgAlt_ (std::move(other_.m_ScanAreaGroundAvgAlt_))
    ,
    m_FlightAltAboveGroundAvgAlt_ (std::move(other_.m_FlightAltAboveGroundAvgAlt_))
    ,
    m_TakeoffAltAboveSeaLevel_ (std::move(other_.m_TakeoffAltAboveSeaLevel_))
    ,
    m_FlightSpeed_ (std::move(other_.m_FlightSpeed_))
    ,
    m_CameraHorizontalFOV_ (std::move(other_.m_CameraHorizontalFOV_))
    ,
    m_CameraVerticalFOV_ (std::move(other_.m_CameraVerticalFOV_))
    ,
    m_CameraHorizontalResolution_ (std::move(other_.m_CameraHorizontalResolution_))
    ,
    m_CameraVerticalResolution_ (std::move(other_.m_CameraVerticalResolution_))
    ,
    m_OverlapInFlightDirection_ (std::move(other_.m_OverlapInFlightDirection_))
    ,
    m_OverlapInLateralDirection_ (std::move(other_.m_OverlapInLateralDirection_))
    ,
    m_GimbalPitchAngle_ (std::move(other_.m_GimbalPitchAngle_))
    ,
    m_SquareCenter_ (std::move(other_.m_SquareCenter_))
    ,
    m_SquareSide_ (std::move(other_.m_SquareSide_))
    {
    } 

    GetDroneScanRouteMsg& GetDroneScanRouteMsg::operator=(GetDroneScanRouteMsg&&  other_) OMG_NOEXCEPT {
        GetDroneScanRouteMsg tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void GetDroneScanRouteMsg::swap(GetDroneScanRouteMsg& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        dds_msgs::BaseMsg::swap(other_);
        swap(m_ScanType_, other_.m_ScanType_);
        swap(m_ScanArea_, other_.m_ScanArea_);
        swap(m_ScanAreaGroundAvgAlt_, other_.m_ScanAreaGroundAvgAlt_);
        swap(m_FlightAltAboveGroundAvgAlt_, other_.m_FlightAltAboveGroundAvgAlt_);
        swap(m_TakeoffAltAboveSeaLevel_, other_.m_TakeoffAltAboveSeaLevel_);
        swap(m_FlightSpeed_, other_.m_FlightSpeed_);
        swap(m_CameraHorizontalFOV_, other_.m_CameraHorizontalFOV_);
        swap(m_CameraVerticalFOV_, other_.m_CameraVerticalFOV_);
        swap(m_CameraHorizontalResolution_, other_.m_CameraHorizontalResolution_);
        swap(m_CameraVerticalResolution_, other_.m_CameraVerticalResolution_);
        swap(m_OverlapInFlightDirection_, other_.m_OverlapInFlightDirection_);
        swap(m_OverlapInLateralDirection_, other_.m_OverlapInLateralDirection_);
        swap(m_GimbalPitchAngle_, other_.m_GimbalPitchAngle_);
        swap(m_SquareCenter_, other_.m_SquareCenter_);
        swap(m_SquareSide_, other_.m_SquareSide_);
    }  

    bool GetDroneScanRouteMsg::operator == (const GetDroneScanRouteMsg& other_) const {
        if (!dds_msgs::BaseMsg::operator == (other_)){
            return false;
        }
        if (m_ScanType_ != other_.m_ScanType_) {
            return false;
        }
        if (m_ScanArea_ != other_.m_ScanArea_) {
            return false;
        }
        if (m_ScanAreaGroundAvgAlt_ != other_.m_ScanAreaGroundAvgAlt_) {
            return false;
        }
        if (m_FlightAltAboveGroundAvgAlt_ != other_.m_FlightAltAboveGroundAvgAlt_) {
            return false;
        }
        if (m_TakeoffAltAboveSeaLevel_ != other_.m_TakeoffAltAboveSeaLevel_) {
            return false;
        }
        if (m_FlightSpeed_ != other_.m_FlightSpeed_) {
            return false;
        }
        if (m_CameraHorizontalFOV_ != other_.m_CameraHorizontalFOV_) {
            return false;
        }
        if (m_CameraVerticalFOV_ != other_.m_CameraVerticalFOV_) {
            return false;
        }
        if (m_CameraHorizontalResolution_ != other_.m_CameraHorizontalResolution_) {
            return false;
        }
        if (m_CameraVerticalResolution_ != other_.m_CameraVerticalResolution_) {
            return false;
        }
        if (m_OverlapInFlightDirection_ != other_.m_OverlapInFlightDirection_) {
            return false;
        }
        if (m_OverlapInLateralDirection_ != other_.m_OverlapInLateralDirection_) {
            return false;
        }
        if (m_GimbalPitchAngle_ != other_.m_GimbalPitchAngle_) {
            return false;
        }
        if (m_SquareCenter_ != other_.m_SquareCenter_) {
            return false;
        }
        if (m_SquareSide_ != other_.m_SquareSide_) {
            return false;
        }
        return true;
    }
    bool GetDroneScanRouteMsg::operator != (const GetDroneScanRouteMsg& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const GetDroneScanRouteMsg& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << static_cast<const dds_msgs::BaseMsg &>(sample);
        o << "ScanType: " << sample.ScanType()<<", ";
        o << "ScanArea: " << sample.ScanArea()<<", ";
        o << "ScanAreaGroundAvgAlt: " << sample.ScanAreaGroundAvgAlt()<<", ";
        o << "FlightAltAboveGroundAvgAlt: " << sample.FlightAltAboveGroundAvgAlt()<<", ";
        o << "TakeoffAltAboveSeaLevel: " << sample.TakeoffAltAboveSeaLevel()<<", ";
        o << "FlightSpeed: " << (int)sample.FlightSpeed() <<", ";
        o << "CameraHorizontalFOV: " << (int)sample.CameraHorizontalFOV() <<", ";
        o << "CameraVerticalFOV: " << (int)sample.CameraVerticalFOV() <<", ";
        o << "CameraHorizontalResolution: " << sample.CameraHorizontalResolution()<<", ";
        o << "CameraVerticalResolution: " << sample.CameraVerticalResolution()<<", ";
        o << "OverlapInFlightDirection: " << (int)sample.OverlapInFlightDirection() <<", ";
        o << "OverlapInLateralDirection: " << (int)sample.OverlapInLateralDirection() <<", ";
        o << "GimbalPitchAngle: " << sample.GimbalPitchAngle()<<", ";
        o << "SquareCenter: " << sample.SquareCenter()<<", ";
        o << "SquareSide: " << sample.SquareSide() ;
        o <<"]";
        return o;
    }

    // ---- DroneScanRouteMsg: 

    DroneScanRouteMsg::DroneScanRouteMsg() :
        m_ScanAreaLength_ (0U) ,
        m_ScanAreaWidth_ (0U) ,
        m_ModelGroundResolution_ (0) ,
        m_TimePeriodBetweenFrames_ (0U) ,
        m_ShortLegLength_ (0U) ,
        m_NumOfFramesPerLongLeg_ (0U) ,
        m_TotalNumOfFrames_ (0U)  {
    }   

    DroneScanRouteMsg::DroneScanRouteMsg (
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
        uint16_t TotalNumOfFrames)
        :
            dds_msgs::BaseMsg(MsgId,MsgCount,MissionId ),
            m_Waypoints_( Waypoints ),
            m_ScanAreaLength_( ScanAreaLength ),
            m_ScanAreaWidth_( ScanAreaWidth ),
            m_ModelGroundResolution_( ModelGroundResolution ),
            m_TimePeriodBetweenFrames_( TimePeriodBetweenFrames ),
            m_ShortLegLength_( ShortLegLength ),
            m_NumOfFramesPerLongLeg_( NumOfFramesPerLongLeg ),
            m_TotalNumOfFrames_( TotalNumOfFrames ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    DroneScanRouteMsg::DroneScanRouteMsg(DroneScanRouteMsg&& other_) OMG_NOEXCEPT  : 
    dds_msgs::BaseMsg(std::move(other_)),
    m_Waypoints_ (std::move(other_.m_Waypoints_))
    ,
    m_ScanAreaLength_ (std::move(other_.m_ScanAreaLength_))
    ,
    m_ScanAreaWidth_ (std::move(other_.m_ScanAreaWidth_))
    ,
    m_ModelGroundResolution_ (std::move(other_.m_ModelGroundResolution_))
    ,
    m_TimePeriodBetweenFrames_ (std::move(other_.m_TimePeriodBetweenFrames_))
    ,
    m_ShortLegLength_ (std::move(other_.m_ShortLegLength_))
    ,
    m_NumOfFramesPerLongLeg_ (std::move(other_.m_NumOfFramesPerLongLeg_))
    ,
    m_TotalNumOfFrames_ (std::move(other_.m_TotalNumOfFrames_))
    {
    } 

    DroneScanRouteMsg& DroneScanRouteMsg::operator=(DroneScanRouteMsg&&  other_) OMG_NOEXCEPT {
        DroneScanRouteMsg tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void DroneScanRouteMsg::swap(DroneScanRouteMsg& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        dds_msgs::BaseMsg::swap(other_);
        swap(m_Waypoints_, other_.m_Waypoints_);
        swap(m_ScanAreaLength_, other_.m_ScanAreaLength_);
        swap(m_ScanAreaWidth_, other_.m_ScanAreaWidth_);
        swap(m_ModelGroundResolution_, other_.m_ModelGroundResolution_);
        swap(m_TimePeriodBetweenFrames_, other_.m_TimePeriodBetweenFrames_);
        swap(m_ShortLegLength_, other_.m_ShortLegLength_);
        swap(m_NumOfFramesPerLongLeg_, other_.m_NumOfFramesPerLongLeg_);
        swap(m_TotalNumOfFrames_, other_.m_TotalNumOfFrames_);
    }  

    bool DroneScanRouteMsg::operator == (const DroneScanRouteMsg& other_) const {
        if (!dds_msgs::BaseMsg::operator == (other_)){
            return false;
        }
        if (m_Waypoints_ != other_.m_Waypoints_) {
            return false;
        }
        if (m_ScanAreaLength_ != other_.m_ScanAreaLength_) {
            return false;
        }
        if (m_ScanAreaWidth_ != other_.m_ScanAreaWidth_) {
            return false;
        }
        if (m_ModelGroundResolution_ != other_.m_ModelGroundResolution_) {
            return false;
        }
        if (m_TimePeriodBetweenFrames_ != other_.m_TimePeriodBetweenFrames_) {
            return false;
        }
        if (m_ShortLegLength_ != other_.m_ShortLegLength_) {
            return false;
        }
        if (m_NumOfFramesPerLongLeg_ != other_.m_NumOfFramesPerLongLeg_) {
            return false;
        }
        if (m_TotalNumOfFrames_ != other_.m_TotalNumOfFrames_) {
            return false;
        }
        return true;
    }
    bool DroneScanRouteMsg::operator != (const DroneScanRouteMsg& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const DroneScanRouteMsg& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << static_cast<const dds_msgs::BaseMsg &>(sample);
        o << "Waypoints: " << sample.Waypoints()<<", ";
        o << "ScanAreaLength: " << sample.ScanAreaLength()<<", ";
        o << "ScanAreaWidth: " << sample.ScanAreaWidth()<<", ";
        o << "ModelGroundResolution: " << (int)sample.ModelGroundResolution() <<", ";
        o << "TimePeriodBetweenFrames: " << sample.TimePeriodBetweenFrames()<<", ";
        o << "ShortLegLength: " << sample.ShortLegLength()<<", ";
        o << "NumOfFramesPerLongLeg: " << sample.NumOfFramesPerLongLeg()<<", ";
        o << "TotalNumOfFrames: " << sample.TotalNumOfFrames() ;
        o <<"]";
        return o;
    }

    // ---- StartJpegGenerationMsg: 

    StartJpegGenerationMsg::StartJpegGenerationMsg() :
        m_PlatformType_(dds_msgs::EnumPlatform::None) ,
        m_GeoPathJpegFiles_ ("")  {
    }   

    StartJpegGenerationMsg::StartJpegGenerationMsg (
        uint8_t MsgId,
        uint32_t MsgCount,
        uint16_t MissionId,
        const dds_msgs::EnumPlatform& PlatformType,
        const std::string& GeoPathJpegFiles)
        :
            dds_msgs::BaseMsg(MsgId,MsgCount,MissionId ),
            m_PlatformType_( PlatformType ),
            m_GeoPathJpegFiles_( GeoPathJpegFiles ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    StartJpegGenerationMsg::StartJpegGenerationMsg(StartJpegGenerationMsg&& other_) OMG_NOEXCEPT  : 
    dds_msgs::BaseMsg(std::move(other_)),
    m_PlatformType_ (std::move(other_.m_PlatformType_))
    ,
    m_GeoPathJpegFiles_ (std::move(other_.m_GeoPathJpegFiles_))
    {
    } 

    StartJpegGenerationMsg& StartJpegGenerationMsg::operator=(StartJpegGenerationMsg&&  other_) OMG_NOEXCEPT {
        StartJpegGenerationMsg tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void StartJpegGenerationMsg::swap(StartJpegGenerationMsg& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        dds_msgs::BaseMsg::swap(other_);
        swap(m_PlatformType_, other_.m_PlatformType_);
        swap(m_GeoPathJpegFiles_, other_.m_GeoPathJpegFiles_);
    }  

    bool StartJpegGenerationMsg::operator == (const StartJpegGenerationMsg& other_) const {
        if (!dds_msgs::BaseMsg::operator == (other_)){
            return false;
        }
        if (m_PlatformType_ != other_.m_PlatformType_) {
            return false;
        }
        if (m_GeoPathJpegFiles_ != other_.m_GeoPathJpegFiles_) {
            return false;
        }
        return true;
    }
    bool StartJpegGenerationMsg::operator != (const StartJpegGenerationMsg& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const StartJpegGenerationMsg& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << static_cast<const dds_msgs::BaseMsg &>(sample);
        o << "PlatformType: " << sample.PlatformType()<<", ";
        o << "GeoPathJpegFiles: " << sample.GeoPathJpegFiles() ;
        o <<"]";
        return o;
    }

    // ---- ReportJpegGenerationLivenessMsg: 

    ReportJpegGenerationLivenessMsg::ReportJpegGenerationLivenessMsg() :
        m_NumOfJpegFiles_ (0U) ,
        m_Status_(dds_msgs::EnumJpegGenerationSts::None) ,
        m_ErrorCode_ (0)  {
    }   

    ReportJpegGenerationLivenessMsg::ReportJpegGenerationLivenessMsg (
        uint8_t MsgId,
        uint32_t MsgCount,
        uint16_t MissionId,
        uint16_t NumOfJpegFiles,
        const dds_msgs::EnumJpegGenerationSts& Status,
        uint8_t ErrorCode)
        :
            dds_msgs::BaseMsg(MsgId,MsgCount,MissionId ),
            m_NumOfJpegFiles_( NumOfJpegFiles ),
            m_Status_( Status ),
            m_ErrorCode_( ErrorCode ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    ReportJpegGenerationLivenessMsg::ReportJpegGenerationLivenessMsg(ReportJpegGenerationLivenessMsg&& other_) OMG_NOEXCEPT  : 
    dds_msgs::BaseMsg(std::move(other_)),
    m_NumOfJpegFiles_ (std::move(other_.m_NumOfJpegFiles_))
    ,
    m_Status_ (std::move(other_.m_Status_))
    ,
    m_ErrorCode_ (std::move(other_.m_ErrorCode_))
    {
    } 

    ReportJpegGenerationLivenessMsg& ReportJpegGenerationLivenessMsg::operator=(ReportJpegGenerationLivenessMsg&&  other_) OMG_NOEXCEPT {
        ReportJpegGenerationLivenessMsg tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void ReportJpegGenerationLivenessMsg::swap(ReportJpegGenerationLivenessMsg& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        dds_msgs::BaseMsg::swap(other_);
        swap(m_NumOfJpegFiles_, other_.m_NumOfJpegFiles_);
        swap(m_Status_, other_.m_Status_);
        swap(m_ErrorCode_, other_.m_ErrorCode_);
    }  

    bool ReportJpegGenerationLivenessMsg::operator == (const ReportJpegGenerationLivenessMsg& other_) const {
        if (!dds_msgs::BaseMsg::operator == (other_)){
            return false;
        }
        if (m_NumOfJpegFiles_ != other_.m_NumOfJpegFiles_) {
            return false;
        }
        if (m_Status_ != other_.m_Status_) {
            return false;
        }
        if (m_ErrorCode_ != other_.m_ErrorCode_) {
            return false;
        }
        return true;
    }
    bool ReportJpegGenerationLivenessMsg::operator != (const ReportJpegGenerationLivenessMsg& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const ReportJpegGenerationLivenessMsg& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << static_cast<const dds_msgs::BaseMsg &>(sample);
        o << "NumOfJpegFiles: " << sample.NumOfJpegFiles()<<", ";
        o << "Status: " << sample.Status()<<", ";
        o << "ErrorCode: <" << std::hex<<(int)sample.ErrorCode()  ;
        o <<"]";
        return o;
    }

    // ---- LasFileTransmissionStsMsg: 

    LasFileTransmissionStsMsg::LasFileTransmissionStsMsg() :
        m_Status_(dds_msgs::EnumLasFileTransmissionSts::None)  {
    }   

    LasFileTransmissionStsMsg::LasFileTransmissionStsMsg (
        uint8_t MsgId,
        uint32_t MsgCount,
        uint16_t MissionId,
        const dds_msgs::EnumLasFileTransmissionSts& Status)
        :
            dds_msgs::BaseMsg(MsgId,MsgCount,MissionId ),
            m_Status_( Status ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    LasFileTransmissionStsMsg::LasFileTransmissionStsMsg(LasFileTransmissionStsMsg&& other_) OMG_NOEXCEPT  : 
    dds_msgs::BaseMsg(std::move(other_)),
    m_Status_ (std::move(other_.m_Status_))
    {
    } 

    LasFileTransmissionStsMsg& LasFileTransmissionStsMsg::operator=(LasFileTransmissionStsMsg&&  other_) OMG_NOEXCEPT {
        LasFileTransmissionStsMsg tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void LasFileTransmissionStsMsg::swap(LasFileTransmissionStsMsg& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        dds_msgs::BaseMsg::swap(other_);
        swap(m_Status_, other_.m_Status_);
    }  

    bool LasFileTransmissionStsMsg::operator == (const LasFileTransmissionStsMsg& other_) const {
        if (!dds_msgs::BaseMsg::operator == (other_)){
            return false;
        }
        if (m_Status_ != other_.m_Status_) {
            return false;
        }
        return true;
    }
    bool LasFileTransmissionStsMsg::operator != (const LasFileTransmissionStsMsg& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const LasFileTransmissionStsMsg& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << static_cast<const dds_msgs::BaseMsg &>(sample);
        o << "Status: " << sample.Status() ;
        o <<"]";
        return o;
    }

    // ---- SingleUrlMsg: 

    SingleUrlMsg::SingleUrlMsg() :
        m_CloudUrl_ ("")  {
    }   

    SingleUrlMsg::SingleUrlMsg (
        uint8_t MsgId,
        uint32_t MsgCount,
        uint16_t MissionId,
        const std::string& CloudUrl)
        :
            dds_msgs::BaseMsg(MsgId,MsgCount,MissionId ),
            m_CloudUrl_( CloudUrl ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    SingleUrlMsg::SingleUrlMsg(SingleUrlMsg&& other_) OMG_NOEXCEPT  : 
    dds_msgs::BaseMsg(std::move(other_)),
    m_CloudUrl_ (std::move(other_.m_CloudUrl_))
    {
    } 

    SingleUrlMsg& SingleUrlMsg::operator=(SingleUrlMsg&&  other_) OMG_NOEXCEPT {
        SingleUrlMsg tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void SingleUrlMsg::swap(SingleUrlMsg& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        dds_msgs::BaseMsg::swap(other_);
        swap(m_CloudUrl_, other_.m_CloudUrl_);
    }  

    bool SingleUrlMsg::operator == (const SingleUrlMsg& other_) const {
        if (!dds_msgs::BaseMsg::operator == (other_)){
            return false;
        }
        if (m_CloudUrl_ != other_.m_CloudUrl_) {
            return false;
        }
        return true;
    }
    bool SingleUrlMsg::operator != (const SingleUrlMsg& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const SingleUrlMsg& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << static_cast<const dds_msgs::BaseMsg &>(sample);
        o << "CloudUrl: " << sample.CloudUrl() ;
        o <<"]";
        return o;
    }

    // ---- DoubleUrlMsg: 

    DoubleUrlMsg::DoubleUrlMsg() :
        m_GeoPath_ ("") ,
        m_CloudUrl_ ("")  {
    }   

    DoubleUrlMsg::DoubleUrlMsg (
        uint8_t MsgId,
        uint32_t MsgCount,
        uint16_t MissionId,
        const std::string& GeoPath,
        const std::string& CloudUrl)
        :
            dds_msgs::BaseMsg(MsgId,MsgCount,MissionId ),
            m_GeoPath_( GeoPath ),
            m_CloudUrl_( CloudUrl ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    DoubleUrlMsg::DoubleUrlMsg(DoubleUrlMsg&& other_) OMG_NOEXCEPT  : 
    dds_msgs::BaseMsg(std::move(other_)),
    m_GeoPath_ (std::move(other_.m_GeoPath_))
    ,
    m_CloudUrl_ (std::move(other_.m_CloudUrl_))
    {
    } 

    DoubleUrlMsg& DoubleUrlMsg::operator=(DoubleUrlMsg&&  other_) OMG_NOEXCEPT {
        DoubleUrlMsg tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void DoubleUrlMsg::swap(DoubleUrlMsg& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        dds_msgs::BaseMsg::swap(other_);
        swap(m_GeoPath_, other_.m_GeoPath_);
        swap(m_CloudUrl_, other_.m_CloudUrl_);
    }  

    bool DoubleUrlMsg::operator == (const DoubleUrlMsg& other_) const {
        if (!dds_msgs::BaseMsg::operator == (other_)){
            return false;
        }
        if (m_GeoPath_ != other_.m_GeoPath_) {
            return false;
        }
        if (m_CloudUrl_ != other_.m_CloudUrl_) {
            return false;
        }
        return true;
    }
    bool DoubleUrlMsg::operator != (const DoubleUrlMsg& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const DoubleUrlMsg& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << static_cast<const dds_msgs::BaseMsg &>(sample);
        o << "GeoPath: " << sample.GeoPath()<<", ";
        o << "CloudUrl: " << sample.CloudUrl() ;
        o <<"]";
        return o;
    }

    // ---- PlatformLocationMsg: 

    PlatformLocationMsg::PlatformLocationMsg() :
        m_PlatformType_(dds_msgs::EnumPlatform::None) ,
        m_PlatformId_ (0) ,
        m_PlatformSpeed_ (0) ,
        m_PlatformHeading_ (0ULL) ,
        m_Timestamp_ (0ULL)  {
    }   

    PlatformLocationMsg::PlatformLocationMsg (
        uint8_t MsgId,
        uint32_t MsgCount,
        uint16_t MissionId,
        const dds_msgs::EnumPlatform& PlatformType,
        uint8_t PlatformId,
        uint8_t PlatformSpeed,
        double PlatformHeading,
        const dds_msgs::GeoPoint& PlatformLocation,
        uint64_t Timestamp)
        :
            dds_msgs::BaseMsg(MsgId,MsgCount,MissionId ),
            m_PlatformType_( PlatformType ),
            m_PlatformId_( PlatformId ),
            m_PlatformSpeed_( PlatformSpeed ),
            m_PlatformHeading_( PlatformHeading ),
            m_PlatformLocation_( PlatformLocation ),
            m_Timestamp_( Timestamp ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    PlatformLocationMsg::PlatformLocationMsg(PlatformLocationMsg&& other_) OMG_NOEXCEPT  : 
    dds_msgs::BaseMsg(std::move(other_)),
    m_PlatformType_ (std::move(other_.m_PlatformType_))
    ,
    m_PlatformId_ (std::move(other_.m_PlatformId_))
    ,
    m_PlatformSpeed_ (std::move(other_.m_PlatformSpeed_))
    ,
    m_PlatformHeading_ (std::move(other_.m_PlatformHeading_))
    ,
    m_PlatformLocation_ (std::move(other_.m_PlatformLocation_))
    ,
    m_Timestamp_ (std::move(other_.m_Timestamp_))
    {
    } 

    PlatformLocationMsg& PlatformLocationMsg::operator=(PlatformLocationMsg&&  other_) OMG_NOEXCEPT {
        PlatformLocationMsg tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void PlatformLocationMsg::swap(PlatformLocationMsg& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        dds_msgs::BaseMsg::swap(other_);
        swap(m_PlatformType_, other_.m_PlatformType_);
        swap(m_PlatformId_, other_.m_PlatformId_);
        swap(m_PlatformSpeed_, other_.m_PlatformSpeed_);
        swap(m_PlatformHeading_, other_.m_PlatformHeading_);
        swap(m_PlatformLocation_, other_.m_PlatformLocation_);
        swap(m_Timestamp_, other_.m_Timestamp_);
    }  

    bool PlatformLocationMsg::operator == (const PlatformLocationMsg& other_) const {
        if (!dds_msgs::BaseMsg::operator == (other_)){
            return false;
        }
        if (m_PlatformType_ != other_.m_PlatformType_) {
            return false;
        }
        if (m_PlatformId_ != other_.m_PlatformId_) {
            return false;
        }
        if (m_PlatformSpeed_ != other_.m_PlatformSpeed_) {
            return false;
        }
        if (m_PlatformHeading_ != other_.m_PlatformHeading_) {
            return false;
        }
        if (m_PlatformLocation_ != other_.m_PlatformLocation_) {
            return false;
        }
        if (m_Timestamp_ != other_.m_Timestamp_) {
            return false;
        }
        return true;
    }
    bool PlatformLocationMsg::operator != (const PlatformLocationMsg& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const PlatformLocationMsg& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << static_cast<const dds_msgs::BaseMsg &>(sample);
        o << "PlatformType: " << sample.PlatformType()<<", ";
        o << "PlatformId: " << (int)sample.PlatformId() <<", ";
        o << "PlatformSpeed: " << (int)sample.PlatformSpeed() <<", ";
        o << "PlatformHeading: " << std::setprecision(15) <<sample.PlatformHeading()<<", ";
        o << "PlatformLocation: " << sample.PlatformLocation()<<", ";
        o << "Timestamp: " << sample.Timestamp() ;
        o <<"]";
        return o;
    }

} // namespace dds_msgs  

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        const dds_msgs::EnumMission default_enumerator<dds_msgs::EnumMission>::value = dds_msgs::EnumMission::None;
        template<>
        struct native_type_code< dds_msgs::EnumMission > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member EnumMission_g_tc_members[5]=
                {

                    {
                        (char *)"None",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumMission::None), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"AirBuild",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumMission::AirBuild), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"AirDiff",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumMission::AirDiff), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"GroundBuild",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumMission::GroundBuild), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"GroundDiff",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumMission::GroundDiff), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode EnumMission_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::EnumMission", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        5, /* Number of members */
                        EnumMission_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for EnumMission*/

                if (is_initialized) {
                    return &EnumMission_g_tc;
                }

                EnumMission_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                EnumMission_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                EnumMission_g_tc._data._annotations._defaultValue._u.long_value = 0;

                EnumMission_g_tc._data._sampleAccessInfo = sample_access_info();
                EnumMission_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &EnumMission_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo EnumMission_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo EnumMission_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &EnumMission_g_sampleAccessInfo;
                }

                EnumMission_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                EnumMission_g_sampleAccessInfo.memberAccessInfos = 
                EnumMission_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::EnumMission);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        EnumMission_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        EnumMission_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                EnumMission_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                EnumMission_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::EnumMission >;

                EnumMission_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &EnumMission_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin EnumMission_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &EnumMission_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< dds_msgs::EnumMission >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::EnumMission >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        const dds_msgs::EnumPlatform default_enumerator<dds_msgs::EnumPlatform>::value = dds_msgs::EnumPlatform::None;
        template<>
        struct native_type_code< dds_msgs::EnumPlatform > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member EnumPlatform_g_tc_members[3]=
                {

                    {
                        (char *)"None",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumPlatform::None), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Drone",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumPlatform::Drone), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"UGV",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumPlatform::UGV), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode EnumPlatform_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::EnumPlatform", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        EnumPlatform_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for EnumPlatform*/

                if (is_initialized) {
                    return &EnumPlatform_g_tc;
                }

                EnumPlatform_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                EnumPlatform_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                EnumPlatform_g_tc._data._annotations._defaultValue._u.long_value = 0;

                EnumPlatform_g_tc._data._sampleAccessInfo = sample_access_info();
                EnumPlatform_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &EnumPlatform_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo EnumPlatform_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo EnumPlatform_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &EnumPlatform_g_sampleAccessInfo;
                }

                EnumPlatform_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                EnumPlatform_g_sampleAccessInfo.memberAccessInfos = 
                EnumPlatform_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::EnumPlatform);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        EnumPlatform_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        EnumPlatform_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                EnumPlatform_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                EnumPlatform_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::EnumPlatform >;

                EnumPlatform_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &EnumPlatform_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin EnumPlatform_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &EnumPlatform_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< dds_msgs::EnumPlatform >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::EnumPlatform >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        const dds_msgs::EnumScan default_enumerator<dds_msgs::EnumScan>::value = dds_msgs::EnumScan::None;
        template<>
        struct native_type_code< dds_msgs::EnumScan > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member EnumScan_g_tc_members[3]=
                {

                    {
                        (char *)"None",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumScan::None), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Rectangular",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumScan::Rectangular), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"LocalSquare",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumScan::LocalSquare), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode EnumScan_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::EnumScan", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        EnumScan_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for EnumScan*/

                if (is_initialized) {
                    return &EnumScan_g_tc;
                }

                EnumScan_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                EnumScan_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                EnumScan_g_tc._data._annotations._defaultValue._u.long_value = 0;

                EnumScan_g_tc._data._sampleAccessInfo = sample_access_info();
                EnumScan_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &EnumScan_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo EnumScan_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo EnumScan_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &EnumScan_g_sampleAccessInfo;
                }

                EnumScan_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                EnumScan_g_sampleAccessInfo.memberAccessInfos = 
                EnumScan_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::EnumScan);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        EnumScan_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        EnumScan_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                EnumScan_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                EnumScan_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::EnumScan >;

                EnumScan_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &EnumScan_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin EnumScan_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &EnumScan_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< dds_msgs::EnumScan >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::EnumScan >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        const dds_msgs::EnumJpegGenerationSts default_enumerator<dds_msgs::EnumJpegGenerationSts>::value = dds_msgs::EnumJpegGenerationSts::None;
        template<>
        struct native_type_code< dds_msgs::EnumJpegGenerationSts > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member EnumJpegGenerationSts_g_tc_members[4]=
                {

                    {
                        (char *)"None",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumJpegGenerationSts::None), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Waiting",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumJpegGenerationSts::Waiting), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Generating",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumJpegGenerationSts::Generating), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Fail",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumJpegGenerationSts::Fail), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode EnumJpegGenerationSts_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::EnumJpegGenerationSts", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        EnumJpegGenerationSts_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for EnumJpegGenerationSts*/

                if (is_initialized) {
                    return &EnumJpegGenerationSts_g_tc;
                }

                EnumJpegGenerationSts_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                EnumJpegGenerationSts_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                EnumJpegGenerationSts_g_tc._data._annotations._defaultValue._u.long_value = 0;

                EnumJpegGenerationSts_g_tc._data._sampleAccessInfo = sample_access_info();
                EnumJpegGenerationSts_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &EnumJpegGenerationSts_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo EnumJpegGenerationSts_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo EnumJpegGenerationSts_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &EnumJpegGenerationSts_g_sampleAccessInfo;
                }

                EnumJpegGenerationSts_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                EnumJpegGenerationSts_g_sampleAccessInfo.memberAccessInfos = 
                EnumJpegGenerationSts_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::EnumJpegGenerationSts);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        EnumJpegGenerationSts_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        EnumJpegGenerationSts_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                EnumJpegGenerationSts_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                EnumJpegGenerationSts_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::EnumJpegGenerationSts >;

                EnumJpegGenerationSts_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &EnumJpegGenerationSts_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin EnumJpegGenerationSts_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &EnumJpegGenerationSts_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< dds_msgs::EnumJpegGenerationSts >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::EnumJpegGenerationSts >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        const dds_msgs::EnumLasFileTransmissionSts default_enumerator<dds_msgs::EnumLasFileTransmissionSts>::value = dds_msgs::EnumLasFileTransmissionSts::None;
        template<>
        struct native_type_code< dds_msgs::EnumLasFileTransmissionSts > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member EnumLasFileTransmissionSts_g_tc_members[5]=
                {

                    {
                        (char *)"None",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumLasFileTransmissionSts::None), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Finished",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumLasFileTransmissionSts::Finished), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Verified",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumLasFileTransmissionSts::Verified), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Error1",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumLasFileTransmissionSts::Error1), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Error2",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumLasFileTransmissionSts::Error2), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode EnumLasFileTransmissionSts_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::EnumLasFileTransmissionSts", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        5, /* Number of members */
                        EnumLasFileTransmissionSts_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for EnumLasFileTransmissionSts*/

                if (is_initialized) {
                    return &EnumLasFileTransmissionSts_g_tc;
                }

                EnumLasFileTransmissionSts_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                EnumLasFileTransmissionSts_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                EnumLasFileTransmissionSts_g_tc._data._annotations._defaultValue._u.long_value = 0;

                EnumLasFileTransmissionSts_g_tc._data._sampleAccessInfo = sample_access_info();
                EnumLasFileTransmissionSts_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &EnumLasFileTransmissionSts_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo EnumLasFileTransmissionSts_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo EnumLasFileTransmissionSts_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &EnumLasFileTransmissionSts_g_sampleAccessInfo;
                }

                EnumLasFileTransmissionSts_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                EnumLasFileTransmissionSts_g_sampleAccessInfo.memberAccessInfos = 
                EnumLasFileTransmissionSts_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::EnumLasFileTransmissionSts);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        EnumLasFileTransmissionSts_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        EnumLasFileTransmissionSts_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                EnumLasFileTransmissionSts_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                EnumLasFileTransmissionSts_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::EnumLasFileTransmissionSts >;

                EnumLasFileTransmissionSts_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &EnumLasFileTransmissionSts_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin EnumLasFileTransmissionSts_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &EnumLasFileTransmissionSts_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< dds_msgs::EnumLasFileTransmissionSts >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::EnumLasFileTransmissionSts >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        const dds_msgs::EnumCalculation default_enumerator<dds_msgs::EnumCalculation>::value = dds_msgs::EnumCalculation::None;
        template<>
        struct native_type_code< dds_msgs::EnumCalculation > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member EnumCalculation_g_tc_members[3]=
                {

                    {
                        (char *)"None",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumCalculation::None), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"NewModel",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumCalculation::NewModel), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"DiffAnalysis",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(dds_msgs::EnumCalculation::DiffAnalysis), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode EnumCalculation_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::EnumCalculation", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        EnumCalculation_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for EnumCalculation*/

                if (is_initialized) {
                    return &EnumCalculation_g_tc;
                }

                EnumCalculation_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                EnumCalculation_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                EnumCalculation_g_tc._data._annotations._defaultValue._u.long_value = 0;

                EnumCalculation_g_tc._data._sampleAccessInfo = sample_access_info();
                EnumCalculation_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &EnumCalculation_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo EnumCalculation_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo EnumCalculation_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &EnumCalculation_g_sampleAccessInfo;
                }

                EnumCalculation_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                EnumCalculation_g_sampleAccessInfo.memberAccessInfos = 
                EnumCalculation_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::EnumCalculation);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        EnumCalculation_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        EnumCalculation_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                EnumCalculation_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                EnumCalculation_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::EnumCalculation >;

                EnumCalculation_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &EnumCalculation_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin EnumCalculation_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &EnumCalculation_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< dds_msgs::EnumCalculation >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::EnumCalculation >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< dds_msgs::GeoPoint > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member GeoPoint_g_tc_members[3]=
                {

                    {
                        (char *)"Lat",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Lon",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Alt",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode GeoPoint_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::GeoPoint", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        GeoPoint_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for GeoPoint*/

                if (is_initialized) {
                    return &GeoPoint_g_tc;
                }

                GeoPoint_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                GeoPoint_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                GeoPoint_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                GeoPoint_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

                /* Initialize the values for member annotations. */
                GeoPoint_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
                GeoPoint_g_tc_members[0]._annotations._defaultValue._u.double_value = 0.0;
                GeoPoint_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
                GeoPoint_g_tc_members[0]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
                GeoPoint_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
                GeoPoint_g_tc_members[0]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;

                GeoPoint_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
                GeoPoint_g_tc_members[1]._annotations._defaultValue._u.double_value = 0.0;
                GeoPoint_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
                GeoPoint_g_tc_members[1]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
                GeoPoint_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
                GeoPoint_g_tc_members[1]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;

                GeoPoint_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
                GeoPoint_g_tc_members[2]._annotations._defaultValue._u.double_value = 0.0;
                GeoPoint_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
                GeoPoint_g_tc_members[2]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
                GeoPoint_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
                GeoPoint_g_tc_members[2]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;

                GeoPoint_g_tc._data._sampleAccessInfo = sample_access_info();
                GeoPoint_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &GeoPoint_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                dds_msgs::GeoPoint *sample;

                static RTIXCdrMemberAccessInfo GeoPoint_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo GeoPoint_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &GeoPoint_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    dds_msgs::GeoPoint);
                if (sample == NULL) {
                    return NULL;
                }

                GeoPoint_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Lat() - (char *)sample);

                GeoPoint_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Lon() - (char *)sample);

                GeoPoint_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Alt() - (char *)sample);

                GeoPoint_g_sampleAccessInfo.memberAccessInfos = 
                GeoPoint_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::GeoPoint);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        GeoPoint_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        GeoPoint_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                GeoPoint_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                GeoPoint_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::GeoPoint >;

                GeoPoint_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &GeoPoint_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin GeoPoint_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &GeoPoint_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< dds_msgs::GeoPoint >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::GeoPoint >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< dds_msgs::LocalScan > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member LocalScan_g_tc_members[2]=
                {

                    {
                        (char *)"SquareCenter",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"SquareSide",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode LocalScan_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::LocalScan", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        LocalScan_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for LocalScan*/

                if (is_initialized) {
                    return &LocalScan_g_tc;
                }

                LocalScan_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                LocalScan_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::GeoPoint>::get().native();
                LocalScan_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;

                /* Initialize the values for member annotations. */

                LocalScan_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                LocalScan_g_tc_members[1]._annotations._defaultValue._u.ushort_value = 0U;
                LocalScan_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                LocalScan_g_tc_members[1]._annotations._minValue._u.ushort_value = 0U;
                LocalScan_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                LocalScan_g_tc_members[1]._annotations._maxValue._u.ushort_value = 5000U;

                LocalScan_g_tc._data._sampleAccessInfo = sample_access_info();
                LocalScan_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &LocalScan_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                dds_msgs::LocalScan *sample;

                static RTIXCdrMemberAccessInfo LocalScan_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo LocalScan_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &LocalScan_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    dds_msgs::LocalScan);
                if (sample == NULL) {
                    return NULL;
                }

                LocalScan_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->SquareCenter() - (char *)sample);

                LocalScan_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->SquareSide() - (char *)sample);

                LocalScan_g_sampleAccessInfo.memberAccessInfos = 
                LocalScan_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::LocalScan);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        LocalScan_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        LocalScan_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                LocalScan_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                LocalScan_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::LocalScan >;

                LocalScan_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &LocalScan_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin LocalScan_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &LocalScan_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< dds_msgs::LocalScan >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::LocalScan >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< dds_msgs::BaseMsg > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member BaseMsg_g_tc_members[3]=
                {

                    {
                        (char *)"MsgId",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"MsgCount",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"MissionId",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode BaseMsg_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::BaseMsg", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        BaseMsg_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for BaseMsg*/

                if (is_initialized) {
                    return &BaseMsg_g_tc;
                }

                BaseMsg_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                BaseMsg_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                BaseMsg_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                BaseMsg_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;

                /* Initialize the values for member annotations. */
                BaseMsg_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                BaseMsg_g_tc_members[0]._annotations._defaultValue._u.octet_value = 0;
                BaseMsg_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                BaseMsg_g_tc_members[0]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                BaseMsg_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                BaseMsg_g_tc_members[0]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                BaseMsg_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                BaseMsg_g_tc_members[1]._annotations._defaultValue._u.ulong_value = 0UL;
                BaseMsg_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                BaseMsg_g_tc_members[1]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                BaseMsg_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                BaseMsg_g_tc_members[1]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                BaseMsg_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                BaseMsg_g_tc_members[2]._annotations._defaultValue._u.ushort_value = 0U;
                BaseMsg_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                BaseMsg_g_tc_members[2]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                BaseMsg_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                BaseMsg_g_tc_members[2]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                BaseMsg_g_tc._data._sampleAccessInfo = sample_access_info();
                BaseMsg_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &BaseMsg_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                dds_msgs::BaseMsg *sample;

                static RTIXCdrMemberAccessInfo BaseMsg_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo BaseMsg_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &BaseMsg_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    dds_msgs::BaseMsg);
                if (sample == NULL) {
                    return NULL;
                }

                BaseMsg_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->MsgId() - (char *)sample);

                BaseMsg_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->MsgCount() - (char *)sample);

                BaseMsg_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->MissionId() - (char *)sample);

                BaseMsg_g_sampleAccessInfo.memberAccessInfos = 
                BaseMsg_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::BaseMsg);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        BaseMsg_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        BaseMsg_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                BaseMsg_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                BaseMsg_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::BaseMsg >;

                BaseMsg_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &BaseMsg_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin BaseMsg_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &BaseMsg_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< dds_msgs::BaseMsg >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::BaseMsg >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< dds_msgs::MissionPlanMsg > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode MissionPlanMsg_g_tc_MissionName_string;
                static DDS_TypeCode MissionPlanMsg_g_tc_ScanArea_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,3L, NULL,NULL);
                static DDS_TypeCode MissionPlanMsg_g_tc_GeoPathJpegFiles_string;
                static DDS_TypeCode MissionPlanMsg_g_tc_GeoPathCurrModel_string;
                static DDS_TypeCode MissionPlanMsg_g_tc_GeoPathRefModel_string;
                static DDS_TypeCode MissionPlanMsg_g_tc_GeoPathDiffModel_string;
                static DDS_TypeCode MissionPlanMsg_g_tc_CloudUrlCurrModel_string;
                static DDS_TypeCode MissionPlanMsg_g_tc_CloudUrlRefModel_string;
                static DDS_TypeCode MissionPlanMsg_g_tc_CloudUrlDiffModel_string;

                static DDS_TypeCode_Member MissionPlanMsg_g_tc_members[27]=
                {

                    {
                        (char *)"MissionName",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"MissionType",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"StationId",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"PlatformType",/* Member name */
                        {
                            6,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"PlatformId",/* Member name */
                        {
                            7,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ScanType",/* Member name */
                        {
                            8,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ScanArea",/* Member name */
                        {
                            9,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ScanAreaGroundAvgAlt",/* Member name */
                        {
                            10,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"FlightAltAboveGroundAvgAlt",/* Member name */
                        {
                            11,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"TakeoffAltAboveSeaLevel",/* Member name */
                        {
                            12,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"FlightSpeed",/* Member name */
                        {
                            13,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"CameraHorizontalFOV",/* Member name */
                        {
                            14,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"CameraVerticalFOV",/* Member name */
                        {
                            15,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"CameraHorizontalResolution",/* Member name */
                        {
                            16,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"CameraVerticalResolution",/* Member name */
                        {
                            17,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"OverlapInFlightDirection",/* Member name */
                        {
                            18,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"OverlapInLateralDirection",/* Member name */
                        {
                            19,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"GimbalPitchAngle",/* Member name */
                        {
                            20,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"SquareCenter",/* Member name */
                        {
                            21,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"SquareSide",/* Member name */
                        {
                            22,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"GeoPathJpegFiles",/* Member name */
                        {
                            23,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"GeoPathCurrModel",/* Member name */
                        {
                            24,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"GeoPathRefModel",/* Member name */
                        {
                            25,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"GeoPathDiffModel",/* Member name */
                        {
                            26,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"CloudUrlCurrModel",/* Member name */
                        {
                            27,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"CloudUrlRefModel",/* Member name */
                        {
                            28,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"CloudUrlDiffModel",/* Member name */
                        {
                            29,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode MissionPlanMsg_g_tc =
                {{
                        DDS_TK_VALUE, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::MissionPlanMsg", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        27, /* Number of members */
                        MissionPlanMsg_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for MissionPlanMsg*/

                if (is_initialized) {
                    return &MissionPlanMsg_g_tc;
                }

                MissionPlanMsg_g_tc_MissionName_string = initialize_string_typecode((256L));
                MissionPlanMsg_g_tc_GeoPathJpegFiles_string = initialize_string_typecode((256L));
                MissionPlanMsg_g_tc_GeoPathCurrModel_string = initialize_string_typecode((256L));
                MissionPlanMsg_g_tc_GeoPathRefModel_string = initialize_string_typecode((256L));
                MissionPlanMsg_g_tc_GeoPathDiffModel_string = initialize_string_typecode((256L));
                MissionPlanMsg_g_tc_CloudUrlCurrModel_string = initialize_string_typecode((256L));
                MissionPlanMsg_g_tc_CloudUrlRefModel_string = initialize_string_typecode((256L));
                MissionPlanMsg_g_tc_CloudUrlDiffModel_string = initialize_string_typecode((256L));

                MissionPlanMsg_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                MissionPlanMsg_g_tc_ScanArea_array._data._typeCode =(RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::GeoPoint>::get().native();
                MissionPlanMsg_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&MissionPlanMsg_g_tc_MissionName_string;
                MissionPlanMsg_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::EnumMission>::get().native();
                MissionPlanMsg_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                MissionPlanMsg_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::EnumPlatform>::get().native();
                MissionPlanMsg_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                MissionPlanMsg_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::EnumScan>::get().native();
                MissionPlanMsg_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)& MissionPlanMsg_g_tc_ScanArea_array;
                MissionPlanMsg_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
                MissionPlanMsg_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                MissionPlanMsg_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
                MissionPlanMsg_g_tc_members[10]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                MissionPlanMsg_g_tc_members[11]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                MissionPlanMsg_g_tc_members[12]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                MissionPlanMsg_g_tc_members[13]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                MissionPlanMsg_g_tc_members[14]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                MissionPlanMsg_g_tc_members[15]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                MissionPlanMsg_g_tc_members[16]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                MissionPlanMsg_g_tc_members[17]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
                MissionPlanMsg_g_tc_members[18]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::GeoPoint>::get().native();
                MissionPlanMsg_g_tc_members[19]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                MissionPlanMsg_g_tc_members[20]._representation._typeCode = (RTICdrTypeCode *)&MissionPlanMsg_g_tc_GeoPathJpegFiles_string;
                MissionPlanMsg_g_tc_members[21]._representation._typeCode = (RTICdrTypeCode *)&MissionPlanMsg_g_tc_GeoPathCurrModel_string;
                MissionPlanMsg_g_tc_members[22]._representation._typeCode = (RTICdrTypeCode *)&MissionPlanMsg_g_tc_GeoPathRefModel_string;
                MissionPlanMsg_g_tc_members[23]._representation._typeCode = (RTICdrTypeCode *)&MissionPlanMsg_g_tc_GeoPathDiffModel_string;
                MissionPlanMsg_g_tc_members[24]._representation._typeCode = (RTICdrTypeCode *)&MissionPlanMsg_g_tc_CloudUrlCurrModel_string;
                MissionPlanMsg_g_tc_members[25]._representation._typeCode = (RTICdrTypeCode *)&MissionPlanMsg_g_tc_CloudUrlRefModel_string;
                MissionPlanMsg_g_tc_members[26]._representation._typeCode = (RTICdrTypeCode *)&MissionPlanMsg_g_tc_CloudUrlDiffModel_string;

                /* Initialize the values for member annotations. */
                MissionPlanMsg_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                MissionPlanMsg_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                MissionPlanMsg_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                MissionPlanMsg_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

                MissionPlanMsg_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[2]._annotations._defaultValue._u.octet_value = 0;
                MissionPlanMsg_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[2]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                MissionPlanMsg_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[2]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                MissionPlanMsg_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                MissionPlanMsg_g_tc_members[3]._annotations._defaultValue._u.enumerated_value = 0;

                MissionPlanMsg_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[4]._annotations._defaultValue._u.ushort_value = 0U;
                MissionPlanMsg_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[4]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                MissionPlanMsg_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[4]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                MissionPlanMsg_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                MissionPlanMsg_g_tc_members[5]._annotations._defaultValue._u.enumerated_value = 0;

                MissionPlanMsg_g_tc_members[7]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                MissionPlanMsg_g_tc_members[7]._annotations._defaultValue._u.short_value = 0;
                MissionPlanMsg_g_tc_members[7]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                MissionPlanMsg_g_tc_members[7]._annotations._minValue._u.short_value = -432;
                MissionPlanMsg_g_tc_members[7]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                MissionPlanMsg_g_tc_members[7]._annotations._maxValue._u.short_value = 3000;

                MissionPlanMsg_g_tc_members[8]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[8]._annotations._defaultValue._u.ushort_value = 0U;
                MissionPlanMsg_g_tc_members[8]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[8]._annotations._minValue._u.ushort_value = 0U;
                MissionPlanMsg_g_tc_members[8]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[8]._annotations._maxValue._u.ushort_value = 1500U;

                MissionPlanMsg_g_tc_members[9]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                MissionPlanMsg_g_tc_members[9]._annotations._defaultValue._u.short_value = 0;
                MissionPlanMsg_g_tc_members[9]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                MissionPlanMsg_g_tc_members[9]._annotations._minValue._u.short_value = -432;
                MissionPlanMsg_g_tc_members[9]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                MissionPlanMsg_g_tc_members[9]._annotations._maxValue._u.short_value = 3000;

                MissionPlanMsg_g_tc_members[10]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[10]._annotations._defaultValue._u.octet_value = 0;
                MissionPlanMsg_g_tc_members[10]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[10]._annotations._minValue._u.octet_value = 0;
                MissionPlanMsg_g_tc_members[10]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[10]._annotations._maxValue._u.octet_value = 40;

                MissionPlanMsg_g_tc_members[11]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[11]._annotations._defaultValue._u.octet_value = 0;
                MissionPlanMsg_g_tc_members[11]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[11]._annotations._minValue._u.octet_value = 0;
                MissionPlanMsg_g_tc_members[11]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[11]._annotations._maxValue._u.octet_value = 180;

                MissionPlanMsg_g_tc_members[12]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[12]._annotations._defaultValue._u.octet_value = 0;
                MissionPlanMsg_g_tc_members[12]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[12]._annotations._minValue._u.octet_value = 0;
                MissionPlanMsg_g_tc_members[12]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[12]._annotations._maxValue._u.octet_value = 180;

                MissionPlanMsg_g_tc_members[13]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[13]._annotations._defaultValue._u.ushort_value = 0U;
                MissionPlanMsg_g_tc_members[13]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[13]._annotations._minValue._u.ushort_value = 0U;
                MissionPlanMsg_g_tc_members[13]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[13]._annotations._maxValue._u.ushort_value = 15000U;

                MissionPlanMsg_g_tc_members[14]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[14]._annotations._defaultValue._u.ushort_value = 0U;
                MissionPlanMsg_g_tc_members[14]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[14]._annotations._minValue._u.ushort_value = 0U;
                MissionPlanMsg_g_tc_members[14]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[14]._annotations._maxValue._u.ushort_value = 15000U;

                MissionPlanMsg_g_tc_members[15]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[15]._annotations._defaultValue._u.octet_value = 0;
                MissionPlanMsg_g_tc_members[15]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[15]._annotations._minValue._u.octet_value = 0;
                MissionPlanMsg_g_tc_members[15]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[15]._annotations._maxValue._u.octet_value = 100;

                MissionPlanMsg_g_tc_members[16]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[16]._annotations._defaultValue._u.octet_value = 0;
                MissionPlanMsg_g_tc_members[16]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[16]._annotations._minValue._u.octet_value = 0;
                MissionPlanMsg_g_tc_members[16]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                MissionPlanMsg_g_tc_members[16]._annotations._maxValue._u.octet_value = 100;

                MissionPlanMsg_g_tc_members[17]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                MissionPlanMsg_g_tc_members[17]._annotations._defaultValue._u.short_value = 0;
                MissionPlanMsg_g_tc_members[17]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                MissionPlanMsg_g_tc_members[17]._annotations._minValue._u.short_value = -9000;
                MissionPlanMsg_g_tc_members[17]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                MissionPlanMsg_g_tc_members[17]._annotations._maxValue._u.short_value = 9000;

                MissionPlanMsg_g_tc_members[19]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[19]._annotations._defaultValue._u.ushort_value = 0U;
                MissionPlanMsg_g_tc_members[19]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[19]._annotations._minValue._u.ushort_value = 0U;
                MissionPlanMsg_g_tc_members[19]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                MissionPlanMsg_g_tc_members[19]._annotations._maxValue._u.ushort_value = 5000U;

                MissionPlanMsg_g_tc_members[21]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                MissionPlanMsg_g_tc_members[21]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                MissionPlanMsg_g_tc_members[24]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                MissionPlanMsg_g_tc_members[24]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                MissionPlanMsg_g_tc._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::BaseMsg >::get().native(); /* Base class */

                MissionPlanMsg_g_tc._data._sampleAccessInfo = sample_access_info();
                MissionPlanMsg_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &MissionPlanMsg_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                dds_msgs::MissionPlanMsg *sample;

                static RTIXCdrMemberAccessInfo MissionPlanMsg_g_memberAccessInfos[27] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo MissionPlanMsg_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &MissionPlanMsg_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    dds_msgs::MissionPlanMsg);
                if (sample == NULL) {
                    return NULL;
                }

                MissionPlanMsg_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->MissionName() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->MissionType() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->StationId() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->PlatformType() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->PlatformId() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ScanType() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ScanArea() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ScanAreaGroundAvgAlt() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[8].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->FlightAltAboveGroundAvgAlt() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[9].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->TakeoffAltAboveSeaLevel() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[10].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->FlightSpeed() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[11].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CameraHorizontalFOV() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[12].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CameraVerticalFOV() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[13].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CameraHorizontalResolution() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[14].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CameraVerticalResolution() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[15].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->OverlapInFlightDirection() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[16].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->OverlapInLateralDirection() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[17].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->GimbalPitchAngle() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[18].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->SquareCenter() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[19].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->SquareSide() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[20].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->GeoPathJpegFiles() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[21].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->GeoPathCurrModel() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[22].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->GeoPathRefModel() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[23].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->GeoPathDiffModel() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[24].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CloudUrlCurrModel() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[25].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CloudUrlRefModel() - (char *)sample);

                MissionPlanMsg_g_memberAccessInfos[26].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CloudUrlDiffModel() - (char *)sample);

                MissionPlanMsg_g_sampleAccessInfo.memberAccessInfos = 
                MissionPlanMsg_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::MissionPlanMsg);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        MissionPlanMsg_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        MissionPlanMsg_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                MissionPlanMsg_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                MissionPlanMsg_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::MissionPlanMsg >;

                MissionPlanMsg_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &MissionPlanMsg_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin MissionPlanMsg_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &MissionPlanMsg_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< dds_msgs::MissionPlanMsg >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::MissionPlanMsg >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< dds_msgs::GetDroneScanRouteMsg > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode GetDroneScanRouteMsg_g_tc_ScanArea_sequence;

                static DDS_TypeCode_Member GetDroneScanRouteMsg_g_tc_members[15]=
                {

                    {
                        (char *)"ScanType",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ScanArea",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ScanAreaGroundAvgAlt",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"FlightAltAboveGroundAvgAlt",/* Member name */
                        {
                            6,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"TakeoffAltAboveSeaLevel",/* Member name */
                        {
                            7,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"FlightSpeed",/* Member name */
                        {
                            8,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"CameraHorizontalFOV",/* Member name */
                        {
                            9,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"CameraVerticalFOV",/* Member name */
                        {
                            10,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"CameraHorizontalResolution",/* Member name */
                        {
                            11,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"CameraVerticalResolution",/* Member name */
                        {
                            12,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"OverlapInFlightDirection",/* Member name */
                        {
                            13,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"OverlapInLateralDirection",/* Member name */
                        {
                            14,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"GimbalPitchAngle",/* Member name */
                        {
                            15,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"SquareCenter",/* Member name */
                        {
                            16,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"SquareSide",/* Member name */
                        {
                            17,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode GetDroneScanRouteMsg_g_tc =
                {{
                        DDS_TK_VALUE, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::GetDroneScanRouteMsg", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        15, /* Number of members */
                        GetDroneScanRouteMsg_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for GetDroneScanRouteMsg*/

                if (is_initialized) {
                    return &GetDroneScanRouteMsg_g_tc;
                }

                GetDroneScanRouteMsg_g_tc_ScanArea_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< dds_msgs::GeoPoint, 3L > >((3L));

                GetDroneScanRouteMsg_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                GetDroneScanRouteMsg_g_tc_ScanArea_sequence._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::GeoPoint>::get().native();
                GetDroneScanRouteMsg_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::EnumScan>::get().native();
                GetDroneScanRouteMsg_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& GetDroneScanRouteMsg_g_tc_ScanArea_sequence;
                GetDroneScanRouteMsg_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
                GetDroneScanRouteMsg_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
                GetDroneScanRouteMsg_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
                GetDroneScanRouteMsg_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                GetDroneScanRouteMsg_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                GetDroneScanRouteMsg_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                GetDroneScanRouteMsg_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                GetDroneScanRouteMsg_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                GetDroneScanRouteMsg_g_tc_members[10]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                GetDroneScanRouteMsg_g_tc_members[11]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                GetDroneScanRouteMsg_g_tc_members[12]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
                GetDroneScanRouteMsg_g_tc_members[13]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::GeoPoint>::get().native();
                GetDroneScanRouteMsg_g_tc_members[14]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;

                /* Initialize the values for member annotations. */
                GetDroneScanRouteMsg_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                GetDroneScanRouteMsg_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                GetDroneScanRouteMsg_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                GetDroneScanRouteMsg_g_tc_members[2]._annotations._defaultValue._u.short_value = 0;
                GetDroneScanRouteMsg_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                GetDroneScanRouteMsg_g_tc_members[2]._annotations._minValue._u.short_value = -432;
                GetDroneScanRouteMsg_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                GetDroneScanRouteMsg_g_tc_members[2]._annotations._maxValue._u.short_value = 3000;

                GetDroneScanRouteMsg_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                GetDroneScanRouteMsg_g_tc_members[3]._annotations._defaultValue._u.short_value = 0;
                GetDroneScanRouteMsg_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                GetDroneScanRouteMsg_g_tc_members[3]._annotations._minValue._u.short_value = 0;
                GetDroneScanRouteMsg_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                GetDroneScanRouteMsg_g_tc_members[3]._annotations._maxValue._u.short_value = 1500;

                GetDroneScanRouteMsg_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                GetDroneScanRouteMsg_g_tc_members[4]._annotations._defaultValue._u.short_value = 0;
                GetDroneScanRouteMsg_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                GetDroneScanRouteMsg_g_tc_members[4]._annotations._minValue._u.short_value = -432;
                GetDroneScanRouteMsg_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                GetDroneScanRouteMsg_g_tc_members[4]._annotations._maxValue._u.short_value = 3000;

                GetDroneScanRouteMsg_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[5]._annotations._defaultValue._u.octet_value = 0;
                GetDroneScanRouteMsg_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[5]._annotations._minValue._u.octet_value = 0;
                GetDroneScanRouteMsg_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[5]._annotations._maxValue._u.octet_value = 40;

                GetDroneScanRouteMsg_g_tc_members[6]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[6]._annotations._defaultValue._u.octet_value = 0;
                GetDroneScanRouteMsg_g_tc_members[6]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[6]._annotations._minValue._u.octet_value = 0;
                GetDroneScanRouteMsg_g_tc_members[6]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[6]._annotations._maxValue._u.octet_value = 180;

                GetDroneScanRouteMsg_g_tc_members[7]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[7]._annotations._defaultValue._u.octet_value = 0;
                GetDroneScanRouteMsg_g_tc_members[7]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[7]._annotations._minValue._u.octet_value = 0;
                GetDroneScanRouteMsg_g_tc_members[7]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[7]._annotations._maxValue._u.octet_value = 180;

                GetDroneScanRouteMsg_g_tc_members[8]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                GetDroneScanRouteMsg_g_tc_members[8]._annotations._defaultValue._u.ushort_value = 0U;
                GetDroneScanRouteMsg_g_tc_members[8]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                GetDroneScanRouteMsg_g_tc_members[8]._annotations._minValue._u.ushort_value = 0U;
                GetDroneScanRouteMsg_g_tc_members[8]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                GetDroneScanRouteMsg_g_tc_members[8]._annotations._maxValue._u.ushort_value = 15000U;

                GetDroneScanRouteMsg_g_tc_members[9]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                GetDroneScanRouteMsg_g_tc_members[9]._annotations._defaultValue._u.ushort_value = 0U;
                GetDroneScanRouteMsg_g_tc_members[9]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                GetDroneScanRouteMsg_g_tc_members[9]._annotations._minValue._u.ushort_value = 0U;
                GetDroneScanRouteMsg_g_tc_members[9]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                GetDroneScanRouteMsg_g_tc_members[9]._annotations._maxValue._u.ushort_value = 15000U;

                GetDroneScanRouteMsg_g_tc_members[10]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[10]._annotations._defaultValue._u.octet_value = 0;
                GetDroneScanRouteMsg_g_tc_members[10]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[10]._annotations._minValue._u.octet_value = 0;
                GetDroneScanRouteMsg_g_tc_members[10]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[10]._annotations._maxValue._u.octet_value = 100;

                GetDroneScanRouteMsg_g_tc_members[11]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[11]._annotations._defaultValue._u.octet_value = 0;
                GetDroneScanRouteMsg_g_tc_members[11]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[11]._annotations._minValue._u.octet_value = 0;
                GetDroneScanRouteMsg_g_tc_members[11]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                GetDroneScanRouteMsg_g_tc_members[11]._annotations._maxValue._u.octet_value = 100;

                GetDroneScanRouteMsg_g_tc_members[12]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                GetDroneScanRouteMsg_g_tc_members[12]._annotations._defaultValue._u.short_value = 0;
                GetDroneScanRouteMsg_g_tc_members[12]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                GetDroneScanRouteMsg_g_tc_members[12]._annotations._minValue._u.short_value = -9000;
                GetDroneScanRouteMsg_g_tc_members[12]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                GetDroneScanRouteMsg_g_tc_members[12]._annotations._maxValue._u.short_value = 9000;

                GetDroneScanRouteMsg_g_tc_members[14]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                GetDroneScanRouteMsg_g_tc_members[14]._annotations._defaultValue._u.ushort_value = 0U;
                GetDroneScanRouteMsg_g_tc_members[14]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                GetDroneScanRouteMsg_g_tc_members[14]._annotations._minValue._u.ushort_value = 0U;
                GetDroneScanRouteMsg_g_tc_members[14]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                GetDroneScanRouteMsg_g_tc_members[14]._annotations._maxValue._u.ushort_value = 5000U;

                GetDroneScanRouteMsg_g_tc._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::BaseMsg >::get().native(); /* Base class */

                GetDroneScanRouteMsg_g_tc._data._sampleAccessInfo = sample_access_info();
                GetDroneScanRouteMsg_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &GetDroneScanRouteMsg_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                dds_msgs::GetDroneScanRouteMsg *sample;

                static RTIXCdrMemberAccessInfo GetDroneScanRouteMsg_g_memberAccessInfos[15] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo GetDroneScanRouteMsg_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &GetDroneScanRouteMsg_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    dds_msgs::GetDroneScanRouteMsg);
                if (sample == NULL) {
                    return NULL;
                }

                GetDroneScanRouteMsg_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ScanType() - (char *)sample);

                GetDroneScanRouteMsg_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ScanArea() - (char *)sample);

                GetDroneScanRouteMsg_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ScanAreaGroundAvgAlt() - (char *)sample);

                GetDroneScanRouteMsg_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->FlightAltAboveGroundAvgAlt() - (char *)sample);

                GetDroneScanRouteMsg_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->TakeoffAltAboveSeaLevel() - (char *)sample);

                GetDroneScanRouteMsg_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->FlightSpeed() - (char *)sample);

                GetDroneScanRouteMsg_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CameraHorizontalFOV() - (char *)sample);

                GetDroneScanRouteMsg_g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CameraVerticalFOV() - (char *)sample);

                GetDroneScanRouteMsg_g_memberAccessInfos[8].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CameraHorizontalResolution() - (char *)sample);

                GetDroneScanRouteMsg_g_memberAccessInfos[9].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CameraVerticalResolution() - (char *)sample);

                GetDroneScanRouteMsg_g_memberAccessInfos[10].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->OverlapInFlightDirection() - (char *)sample);

                GetDroneScanRouteMsg_g_memberAccessInfos[11].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->OverlapInLateralDirection() - (char *)sample);

                GetDroneScanRouteMsg_g_memberAccessInfos[12].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->GimbalPitchAngle() - (char *)sample);

                GetDroneScanRouteMsg_g_memberAccessInfos[13].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->SquareCenter() - (char *)sample);

                GetDroneScanRouteMsg_g_memberAccessInfos[14].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->SquareSide() - (char *)sample);

                GetDroneScanRouteMsg_g_sampleAccessInfo.memberAccessInfos = 
                GetDroneScanRouteMsg_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::GetDroneScanRouteMsg);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        GetDroneScanRouteMsg_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        GetDroneScanRouteMsg_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                GetDroneScanRouteMsg_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                GetDroneScanRouteMsg_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::GetDroneScanRouteMsg >;

                GetDroneScanRouteMsg_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &GetDroneScanRouteMsg_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin GetDroneScanRouteMsg_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &GetDroneScanRouteMsg_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< dds_msgs::GetDroneScanRouteMsg >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::GetDroneScanRouteMsg >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< dds_msgs::DroneScanRouteMsg > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode DroneScanRouteMsg_g_tc_Waypoints_sequence;

                static DDS_TypeCode_Member DroneScanRouteMsg_g_tc_members[8]=
                {

                    {
                        (char *)"Waypoints",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ScanAreaLength",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ScanAreaWidth",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ModelGroundResolution",/* Member name */
                        {
                            6,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"TimePeriodBetweenFrames",/* Member name */
                        {
                            7,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ShortLegLength",/* Member name */
                        {
                            8,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"NumOfFramesPerLongLeg",/* Member name */
                        {
                            9,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"TotalNumOfFrames",/* Member name */
                        {
                            10,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode DroneScanRouteMsg_g_tc =
                {{
                        DDS_TK_VALUE, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::DroneScanRouteMsg", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        8, /* Number of members */
                        DroneScanRouteMsg_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DroneScanRouteMsg*/

                if (is_initialized) {
                    return &DroneScanRouteMsg_g_tc;
                }

                DroneScanRouteMsg_g_tc_Waypoints_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< dds_msgs::GeoPoint, 100L > >((100L));

                DroneScanRouteMsg_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                DroneScanRouteMsg_g_tc_Waypoints_sequence._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::GeoPoint>::get().native();
                DroneScanRouteMsg_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& DroneScanRouteMsg_g_tc_Waypoints_sequence;
                DroneScanRouteMsg_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                DroneScanRouteMsg_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                DroneScanRouteMsg_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                DroneScanRouteMsg_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                DroneScanRouteMsg_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                DroneScanRouteMsg_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                DroneScanRouteMsg_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;

                /* Initialize the values for member annotations. */

                DroneScanRouteMsg_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[1]._annotations._defaultValue._u.ushort_value = 0U;
                DroneScanRouteMsg_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[1]._annotations._minValue._u.ushort_value = 0U;
                DroneScanRouteMsg_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[1]._annotations._maxValue._u.ushort_value = 20000U;

                DroneScanRouteMsg_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[2]._annotations._defaultValue._u.ushort_value = 0U;
                DroneScanRouteMsg_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[2]._annotations._minValue._u.ushort_value = 0U;
                DroneScanRouteMsg_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[2]._annotations._maxValue._u.ushort_value = 20000U;

                DroneScanRouteMsg_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                DroneScanRouteMsg_g_tc_members[3]._annotations._defaultValue._u.octet_value = 0;
                DroneScanRouteMsg_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                DroneScanRouteMsg_g_tc_members[3]._annotations._minValue._u.octet_value = 0;
                DroneScanRouteMsg_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                DroneScanRouteMsg_g_tc_members[3]._annotations._maxValue._u.octet_value = 100;

                DroneScanRouteMsg_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[4]._annotations._defaultValue._u.ushort_value = 0U;
                DroneScanRouteMsg_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[4]._annotations._minValue._u.ushort_value = 0U;
                DroneScanRouteMsg_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[4]._annotations._maxValue._u.ushort_value = 3000U;

                DroneScanRouteMsg_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[5]._annotations._defaultValue._u.ushort_value = 0U;
                DroneScanRouteMsg_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[5]._annotations._minValue._u.ushort_value = 0U;
                DroneScanRouteMsg_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[5]._annotations._maxValue._u.ushort_value = 20000U;

                DroneScanRouteMsg_g_tc_members[6]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[6]._annotations._defaultValue._u.ushort_value = 0U;
                DroneScanRouteMsg_g_tc_members[6]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[6]._annotations._minValue._u.ushort_value = 0U;
                DroneScanRouteMsg_g_tc_members[6]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[6]._annotations._maxValue._u.ushort_value = 3000U;

                DroneScanRouteMsg_g_tc_members[7]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[7]._annotations._defaultValue._u.ushort_value = 0U;
                DroneScanRouteMsg_g_tc_members[7]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[7]._annotations._minValue._u.ushort_value = 0U;
                DroneScanRouteMsg_g_tc_members[7]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                DroneScanRouteMsg_g_tc_members[7]._annotations._maxValue._u.ushort_value = 20000U;

                DroneScanRouteMsg_g_tc._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::BaseMsg >::get().native(); /* Base class */

                DroneScanRouteMsg_g_tc._data._sampleAccessInfo = sample_access_info();
                DroneScanRouteMsg_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &DroneScanRouteMsg_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                dds_msgs::DroneScanRouteMsg *sample;

                static RTIXCdrMemberAccessInfo DroneScanRouteMsg_g_memberAccessInfos[8] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DroneScanRouteMsg_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DroneScanRouteMsg_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    dds_msgs::DroneScanRouteMsg);
                if (sample == NULL) {
                    return NULL;
                }

                DroneScanRouteMsg_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Waypoints() - (char *)sample);

                DroneScanRouteMsg_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ScanAreaLength() - (char *)sample);

                DroneScanRouteMsg_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ScanAreaWidth() - (char *)sample);

                DroneScanRouteMsg_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ModelGroundResolution() - (char *)sample);

                DroneScanRouteMsg_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->TimePeriodBetweenFrames() - (char *)sample);

                DroneScanRouteMsg_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ShortLegLength() - (char *)sample);

                DroneScanRouteMsg_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->NumOfFramesPerLongLeg() - (char *)sample);

                DroneScanRouteMsg_g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->TotalNumOfFrames() - (char *)sample);

                DroneScanRouteMsg_g_sampleAccessInfo.memberAccessInfos = 
                DroneScanRouteMsg_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::DroneScanRouteMsg);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        DroneScanRouteMsg_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        DroneScanRouteMsg_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DroneScanRouteMsg_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DroneScanRouteMsg_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::DroneScanRouteMsg >;

                DroneScanRouteMsg_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DroneScanRouteMsg_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DroneScanRouteMsg_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &DroneScanRouteMsg_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< dds_msgs::DroneScanRouteMsg >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::DroneScanRouteMsg >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< dds_msgs::StartJpegGenerationMsg > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode StartJpegGenerationMsg_g_tc_GeoPathJpegFiles_string;

                static DDS_TypeCode_Member StartJpegGenerationMsg_g_tc_members[2]=
                {

                    {
                        (char *)"PlatformType",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"GeoPathJpegFiles",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode StartJpegGenerationMsg_g_tc =
                {{
                        DDS_TK_VALUE, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::StartJpegGenerationMsg", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        StartJpegGenerationMsg_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for StartJpegGenerationMsg*/

                if (is_initialized) {
                    return &StartJpegGenerationMsg_g_tc;
                }

                StartJpegGenerationMsg_g_tc_GeoPathJpegFiles_string = initialize_string_typecode((256L));

                StartJpegGenerationMsg_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                StartJpegGenerationMsg_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::EnumPlatform>::get().native();
                StartJpegGenerationMsg_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&StartJpegGenerationMsg_g_tc_GeoPathJpegFiles_string;

                /* Initialize the values for member annotations. */
                StartJpegGenerationMsg_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                StartJpegGenerationMsg_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                StartJpegGenerationMsg_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                StartJpegGenerationMsg_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                StartJpegGenerationMsg_g_tc._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::BaseMsg >::get().native(); /* Base class */

                StartJpegGenerationMsg_g_tc._data._sampleAccessInfo = sample_access_info();
                StartJpegGenerationMsg_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &StartJpegGenerationMsg_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                dds_msgs::StartJpegGenerationMsg *sample;

                static RTIXCdrMemberAccessInfo StartJpegGenerationMsg_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo StartJpegGenerationMsg_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &StartJpegGenerationMsg_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    dds_msgs::StartJpegGenerationMsg);
                if (sample == NULL) {
                    return NULL;
                }

                StartJpegGenerationMsg_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->PlatformType() - (char *)sample);

                StartJpegGenerationMsg_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->GeoPathJpegFiles() - (char *)sample);

                StartJpegGenerationMsg_g_sampleAccessInfo.memberAccessInfos = 
                StartJpegGenerationMsg_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::StartJpegGenerationMsg);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        StartJpegGenerationMsg_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        StartJpegGenerationMsg_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                StartJpegGenerationMsg_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                StartJpegGenerationMsg_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::StartJpegGenerationMsg >;

                StartJpegGenerationMsg_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &StartJpegGenerationMsg_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin StartJpegGenerationMsg_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &StartJpegGenerationMsg_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< dds_msgs::StartJpegGenerationMsg >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::StartJpegGenerationMsg >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< dds_msgs::ReportJpegGenerationLivenessMsg > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ReportJpegGenerationLivenessMsg_g_tc_members[3]=
                {

                    {
                        (char *)"NumOfJpegFiles",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Status",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ErrorCode",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ReportJpegGenerationLivenessMsg_g_tc =
                {{
                        DDS_TK_VALUE, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::ReportJpegGenerationLivenessMsg", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        ReportJpegGenerationLivenessMsg_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ReportJpegGenerationLivenessMsg*/

                if (is_initialized) {
                    return &ReportJpegGenerationLivenessMsg_g_tc;
                }

                ReportJpegGenerationLivenessMsg_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ReportJpegGenerationLivenessMsg_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                ReportJpegGenerationLivenessMsg_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::EnumJpegGenerationSts>::get().native();
                ReportJpegGenerationLivenessMsg_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                /* Initialize the values for member annotations. */
                ReportJpegGenerationLivenessMsg_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                ReportJpegGenerationLivenessMsg_g_tc_members[0]._annotations._defaultValue._u.ushort_value = 0U;
                ReportJpegGenerationLivenessMsg_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                ReportJpegGenerationLivenessMsg_g_tc_members[0]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                ReportJpegGenerationLivenessMsg_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                ReportJpegGenerationLivenessMsg_g_tc_members[0]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                ReportJpegGenerationLivenessMsg_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                ReportJpegGenerationLivenessMsg_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

                ReportJpegGenerationLivenessMsg_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                ReportJpegGenerationLivenessMsg_g_tc_members[2]._annotations._defaultValue._u.octet_value = 0;
                ReportJpegGenerationLivenessMsg_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                ReportJpegGenerationLivenessMsg_g_tc_members[2]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                ReportJpegGenerationLivenessMsg_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                ReportJpegGenerationLivenessMsg_g_tc_members[2]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                ReportJpegGenerationLivenessMsg_g_tc._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::BaseMsg >::get().native(); /* Base class */

                ReportJpegGenerationLivenessMsg_g_tc._data._sampleAccessInfo = sample_access_info();
                ReportJpegGenerationLivenessMsg_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &ReportJpegGenerationLivenessMsg_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                dds_msgs::ReportJpegGenerationLivenessMsg *sample;

                static RTIXCdrMemberAccessInfo ReportJpegGenerationLivenessMsg_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ReportJpegGenerationLivenessMsg_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ReportJpegGenerationLivenessMsg_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    dds_msgs::ReportJpegGenerationLivenessMsg);
                if (sample == NULL) {
                    return NULL;
                }

                ReportJpegGenerationLivenessMsg_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->NumOfJpegFiles() - (char *)sample);

                ReportJpegGenerationLivenessMsg_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Status() - (char *)sample);

                ReportJpegGenerationLivenessMsg_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ErrorCode() - (char *)sample);

                ReportJpegGenerationLivenessMsg_g_sampleAccessInfo.memberAccessInfos = 
                ReportJpegGenerationLivenessMsg_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::ReportJpegGenerationLivenessMsg);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ReportJpegGenerationLivenessMsg_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ReportJpegGenerationLivenessMsg_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ReportJpegGenerationLivenessMsg_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ReportJpegGenerationLivenessMsg_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::ReportJpegGenerationLivenessMsg >;

                ReportJpegGenerationLivenessMsg_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ReportJpegGenerationLivenessMsg_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ReportJpegGenerationLivenessMsg_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ReportJpegGenerationLivenessMsg_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< dds_msgs::ReportJpegGenerationLivenessMsg >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::ReportJpegGenerationLivenessMsg >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< dds_msgs::LasFileTransmissionStsMsg > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member LasFileTransmissionStsMsg_g_tc_members[1]=
                {

                    {
                        (char *)"Status",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode LasFileTransmissionStsMsg_g_tc =
                {{
                        DDS_TK_VALUE, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::LasFileTransmissionStsMsg", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        LasFileTransmissionStsMsg_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for LasFileTransmissionStsMsg*/

                if (is_initialized) {
                    return &LasFileTransmissionStsMsg_g_tc;
                }

                LasFileTransmissionStsMsg_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                LasFileTransmissionStsMsg_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::EnumLasFileTransmissionSts>::get().native();

                /* Initialize the values for member annotations. */
                LasFileTransmissionStsMsg_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                LasFileTransmissionStsMsg_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                LasFileTransmissionStsMsg_g_tc._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::BaseMsg >::get().native(); /* Base class */

                LasFileTransmissionStsMsg_g_tc._data._sampleAccessInfo = sample_access_info();
                LasFileTransmissionStsMsg_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &LasFileTransmissionStsMsg_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                dds_msgs::LasFileTransmissionStsMsg *sample;

                static RTIXCdrMemberAccessInfo LasFileTransmissionStsMsg_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo LasFileTransmissionStsMsg_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &LasFileTransmissionStsMsg_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    dds_msgs::LasFileTransmissionStsMsg);
                if (sample == NULL) {
                    return NULL;
                }

                LasFileTransmissionStsMsg_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Status() - (char *)sample);

                LasFileTransmissionStsMsg_g_sampleAccessInfo.memberAccessInfos = 
                LasFileTransmissionStsMsg_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::LasFileTransmissionStsMsg);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        LasFileTransmissionStsMsg_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        LasFileTransmissionStsMsg_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                LasFileTransmissionStsMsg_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                LasFileTransmissionStsMsg_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::LasFileTransmissionStsMsg >;

                LasFileTransmissionStsMsg_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &LasFileTransmissionStsMsg_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin LasFileTransmissionStsMsg_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &LasFileTransmissionStsMsg_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< dds_msgs::LasFileTransmissionStsMsg >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::LasFileTransmissionStsMsg >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< dds_msgs::SingleUrlMsg > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode SingleUrlMsg_g_tc_CloudUrl_string;

                static DDS_TypeCode_Member SingleUrlMsg_g_tc_members[1]=
                {

                    {
                        (char *)"CloudUrl",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode SingleUrlMsg_g_tc =
                {{
                        DDS_TK_VALUE, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::SingleUrlMsg", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        SingleUrlMsg_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for SingleUrlMsg*/

                if (is_initialized) {
                    return &SingleUrlMsg_g_tc;
                }

                SingleUrlMsg_g_tc_CloudUrl_string = initialize_string_typecode((256L));

                SingleUrlMsg_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                SingleUrlMsg_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&SingleUrlMsg_g_tc_CloudUrl_string;

                /* Initialize the values for member annotations. */
                SingleUrlMsg_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                SingleUrlMsg_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                SingleUrlMsg_g_tc._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::BaseMsg >::get().native(); /* Base class */

                SingleUrlMsg_g_tc._data._sampleAccessInfo = sample_access_info();
                SingleUrlMsg_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &SingleUrlMsg_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                dds_msgs::SingleUrlMsg *sample;

                static RTIXCdrMemberAccessInfo SingleUrlMsg_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo SingleUrlMsg_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &SingleUrlMsg_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    dds_msgs::SingleUrlMsg);
                if (sample == NULL) {
                    return NULL;
                }

                SingleUrlMsg_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CloudUrl() - (char *)sample);

                SingleUrlMsg_g_sampleAccessInfo.memberAccessInfos = 
                SingleUrlMsg_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::SingleUrlMsg);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        SingleUrlMsg_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        SingleUrlMsg_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                SingleUrlMsg_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                SingleUrlMsg_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::SingleUrlMsg >;

                SingleUrlMsg_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &SingleUrlMsg_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin SingleUrlMsg_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &SingleUrlMsg_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< dds_msgs::SingleUrlMsg >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::SingleUrlMsg >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< dds_msgs::DoubleUrlMsg > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode DoubleUrlMsg_g_tc_GeoPath_string;
                static DDS_TypeCode DoubleUrlMsg_g_tc_CloudUrl_string;

                static DDS_TypeCode_Member DoubleUrlMsg_g_tc_members[2]=
                {

                    {
                        (char *)"GeoPath",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"CloudUrl",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode DoubleUrlMsg_g_tc =
                {{
                        DDS_TK_VALUE, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::DoubleUrlMsg", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        DoubleUrlMsg_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DoubleUrlMsg*/

                if (is_initialized) {
                    return &DoubleUrlMsg_g_tc;
                }

                DoubleUrlMsg_g_tc_GeoPath_string = initialize_string_typecode((256L));
                DoubleUrlMsg_g_tc_CloudUrl_string = initialize_string_typecode((256L));

                DoubleUrlMsg_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                DoubleUrlMsg_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DoubleUrlMsg_g_tc_GeoPath_string;
                DoubleUrlMsg_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DoubleUrlMsg_g_tc_CloudUrl_string;

                /* Initialize the values for member annotations. */
                DoubleUrlMsg_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                DoubleUrlMsg_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                DoubleUrlMsg_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                DoubleUrlMsg_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                DoubleUrlMsg_g_tc._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::BaseMsg >::get().native(); /* Base class */

                DoubleUrlMsg_g_tc._data._sampleAccessInfo = sample_access_info();
                DoubleUrlMsg_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &DoubleUrlMsg_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                dds_msgs::DoubleUrlMsg *sample;

                static RTIXCdrMemberAccessInfo DoubleUrlMsg_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DoubleUrlMsg_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DoubleUrlMsg_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    dds_msgs::DoubleUrlMsg);
                if (sample == NULL) {
                    return NULL;
                }

                DoubleUrlMsg_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->GeoPath() - (char *)sample);

                DoubleUrlMsg_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->CloudUrl() - (char *)sample);

                DoubleUrlMsg_g_sampleAccessInfo.memberAccessInfos = 
                DoubleUrlMsg_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::DoubleUrlMsg);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        DoubleUrlMsg_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        DoubleUrlMsg_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DoubleUrlMsg_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DoubleUrlMsg_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::DoubleUrlMsg >;

                DoubleUrlMsg_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DoubleUrlMsg_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DoubleUrlMsg_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &DoubleUrlMsg_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< dds_msgs::DoubleUrlMsg >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::DoubleUrlMsg >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< dds_msgs::PlatformLocationMsg > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member PlatformLocationMsg_g_tc_members[6]=
                {

                    {
                        (char *)"PlatformType",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"PlatformId",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"PlatformSpeed",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"PlatformHeading",/* Member name */
                        {
                            6,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"PlatformLocation",/* Member name */
                        {
                            7,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Timestamp",/* Member name */
                        {
                            8,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode PlatformLocationMsg_g_tc =
                {{
                        DDS_TK_VALUE, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dds_msgs::PlatformLocationMsg", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        6, /* Number of members */
                        PlatformLocationMsg_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for PlatformLocationMsg*/

                if (is_initialized) {
                    return &PlatformLocationMsg_g_tc;
                }

                PlatformLocationMsg_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                PlatformLocationMsg_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::EnumPlatform>::get().native();
                PlatformLocationMsg_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                PlatformLocationMsg_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                PlatformLocationMsg_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                PlatformLocationMsg_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::GeoPoint>::get().native();
                PlatformLocationMsg_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;

                /* Initialize the values for member annotations. */
                PlatformLocationMsg_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                PlatformLocationMsg_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                PlatformLocationMsg_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                PlatformLocationMsg_g_tc_members[1]._annotations._defaultValue._u.octet_value = 0;
                PlatformLocationMsg_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                PlatformLocationMsg_g_tc_members[1]._annotations._minValue._u.octet_value = 0;
                PlatformLocationMsg_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                PlatformLocationMsg_g_tc_members[1]._annotations._maxValue._u.octet_value = 255;

                PlatformLocationMsg_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                PlatformLocationMsg_g_tc_members[2]._annotations._defaultValue._u.octet_value = 0;
                PlatformLocationMsg_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                PlatformLocationMsg_g_tc_members[2]._annotations._minValue._u.octet_value = 0;
                PlatformLocationMsg_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                PlatformLocationMsg_g_tc_members[2]._annotations._maxValue._u.octet_value = 200;

                PlatformLocationMsg_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
                PlatformLocationMsg_g_tc_members[3]._annotations._defaultValue._u.double_value = 0ULL;
                PlatformLocationMsg_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
                PlatformLocationMsg_g_tc_members[3]._annotations._minValue._u.double_value = -3.1415926;
                PlatformLocationMsg_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
                PlatformLocationMsg_g_tc_members[3]._annotations._maxValue._u.double_value = 3.1415926;

                PlatformLocationMsg_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                PlatformLocationMsg_g_tc_members[5]._annotations._defaultValue._u.ulong_long_value = 0ULL;
                PlatformLocationMsg_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                PlatformLocationMsg_g_tc_members[5]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                PlatformLocationMsg_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                PlatformLocationMsg_g_tc_members[5]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

                PlatformLocationMsg_g_tc._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< dds_msgs::BaseMsg >::get().native(); /* Base class */

                PlatformLocationMsg_g_tc._data._sampleAccessInfo = sample_access_info();
                PlatformLocationMsg_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &PlatformLocationMsg_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                dds_msgs::PlatformLocationMsg *sample;

                static RTIXCdrMemberAccessInfo PlatformLocationMsg_g_memberAccessInfos[6] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo PlatformLocationMsg_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &PlatformLocationMsg_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    dds_msgs::PlatformLocationMsg);
                if (sample == NULL) {
                    return NULL;
                }

                PlatformLocationMsg_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->PlatformType() - (char *)sample);

                PlatformLocationMsg_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->PlatformId() - (char *)sample);

                PlatformLocationMsg_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->PlatformSpeed() - (char *)sample);

                PlatformLocationMsg_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->PlatformHeading() - (char *)sample);

                PlatformLocationMsg_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->PlatformLocation() - (char *)sample);

                PlatformLocationMsg_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Timestamp() - (char *)sample);

                PlatformLocationMsg_g_sampleAccessInfo.memberAccessInfos = 
                PlatformLocationMsg_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(dds_msgs::PlatformLocationMsg);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        PlatformLocationMsg_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        PlatformLocationMsg_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                PlatformLocationMsg_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                PlatformLocationMsg_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< dds_msgs::PlatformLocationMsg >;

                PlatformLocationMsg_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &PlatformLocationMsg_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin PlatformLocationMsg_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &PlatformLocationMsg_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< dds_msgs::PlatformLocationMsg >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< dds_msgs::PlatformLocationMsg >::get())));
        }

    }
}

namespace dds { 
    namespace topic {

        void topic_type_support< dds_msgs::GeoPoint >::reset_sample(dds_msgs::GeoPoint& sample) 
        {
            sample.Lat(0.0);
            sample.Lon(0.0);
            sample.Alt(0.0);
        }

        void topic_type_support< dds_msgs::GeoPoint >::allocate_sample(dds_msgs::GeoPoint& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< dds_msgs::LocalScan >::reset_sample(dds_msgs::LocalScan& sample) 
        {
            ::rti::topic::reset_sample(sample.SquareCenter());
            sample.SquareSide(0U);
        }

        void topic_type_support< dds_msgs::LocalScan >::allocate_sample(dds_msgs::LocalScan& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.SquareCenter(),  -1, -1);
        }

        void topic_type_support< dds_msgs::BaseMsg >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                dds_msgs::BaseMsgPlugin_new,
                dds_msgs::BaseMsgPlugin_delete);
        }

        std::vector<char>& topic_type_support< dds_msgs::BaseMsg >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const dds_msgs::BaseMsg& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = BaseMsgPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = BaseMsgPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< dds_msgs::BaseMsg >::from_cdr_buffer(dds_msgs::BaseMsg& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = BaseMsgPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create dds_msgs::BaseMsg from cdr buffer");
        }

        void topic_type_support< dds_msgs::BaseMsg >::reset_sample(dds_msgs::BaseMsg& sample) 
        {
            sample.MsgId(0);
            sample.MsgCount(0UL);
            sample.MissionId(0U);
        }

        void topic_type_support< dds_msgs::BaseMsg >::allocate_sample(dds_msgs::BaseMsg& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< dds_msgs::MissionPlanMsg >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                dds_msgs::MissionPlanMsgPlugin_new,
                dds_msgs::MissionPlanMsgPlugin_delete);
        }

        std::vector<char>& topic_type_support< dds_msgs::MissionPlanMsg >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const dds_msgs::MissionPlanMsg& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = MissionPlanMsgPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = MissionPlanMsgPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< dds_msgs::MissionPlanMsg >::from_cdr_buffer(dds_msgs::MissionPlanMsg& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = MissionPlanMsgPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create dds_msgs::MissionPlanMsg from cdr buffer");
        }

        void topic_type_support< dds_msgs::MissionPlanMsg >::reset_sample(dds_msgs::MissionPlanMsg& sample) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::reset_sample(sample);

            sample.MissionName("");
            sample.MissionType(dds_msgs::EnumMission::None);
            sample.StationId(0);
            sample.PlatformType(dds_msgs::EnumPlatform::None);
            sample.PlatformId(0U);
            sample.ScanType(dds_msgs::EnumScan::None);
            ::rti::topic::reset_sample(sample.ScanArea());
            sample.ScanAreaGroundAvgAlt(0);
            sample.FlightAltAboveGroundAvgAlt(0U);
            sample.TakeoffAltAboveSeaLevel(0);
            sample.FlightSpeed(0);
            sample.CameraHorizontalFOV(0);
            sample.CameraVerticalFOV(0);
            sample.CameraHorizontalResolution(0U);
            sample.CameraVerticalResolution(0U);
            sample.OverlapInFlightDirection(0);
            sample.OverlapInLateralDirection(0);
            sample.GimbalPitchAngle(0);
            ::rti::topic::reset_sample(sample.SquareCenter());
            sample.SquareSide(0U);
            ::rti::topic::reset_sample(sample.GeoPathJpegFiles());
            sample.GeoPathCurrModel("");
            ::rti::topic::reset_sample(sample.GeoPathRefModel());
            ::rti::topic::reset_sample(sample.GeoPathDiffModel());
            sample.CloudUrlCurrModel("");
            ::rti::topic::reset_sample(sample.CloudUrlRefModel());
            ::rti::topic::reset_sample(sample.CloudUrlDiffModel());
        }

        void topic_type_support< dds_msgs::MissionPlanMsg >::allocate_sample(dds_msgs::MissionPlanMsg& sample, int, int) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::allocate_sample(sample, -1, -1);

            ::rti::topic::allocate_sample(sample.MissionName(),  -1, 256L);
            ::rti::topic::allocate_sample(sample.MissionType(),  -1, -1);
            ::rti::topic::allocate_sample(sample.PlatformType(),  -1, -1);
            ::rti::topic::allocate_sample(sample.ScanType(),  -1, -1);
            ::rti::topic::allocate_sample(sample.ScanArea(),  -1, -1);
            ::rti::topic::allocate_sample(sample.SquareCenter(),  -1, -1);
            ::rti::topic::allocate_sample(sample.GeoPathCurrModel(),  -1, 256L);
            ::rti::topic::allocate_sample(sample.CloudUrlCurrModel(),  -1, 256L);
        }

        void topic_type_support< dds_msgs::GetDroneScanRouteMsg >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                dds_msgs::GetDroneScanRouteMsgPlugin_new,
                dds_msgs::GetDroneScanRouteMsgPlugin_delete);
        }

        std::vector<char>& topic_type_support< dds_msgs::GetDroneScanRouteMsg >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const dds_msgs::GetDroneScanRouteMsg& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = GetDroneScanRouteMsgPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = GetDroneScanRouteMsgPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< dds_msgs::GetDroneScanRouteMsg >::from_cdr_buffer(dds_msgs::GetDroneScanRouteMsg& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = GetDroneScanRouteMsgPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create dds_msgs::GetDroneScanRouteMsg from cdr buffer");
        }

        void topic_type_support< dds_msgs::GetDroneScanRouteMsg >::reset_sample(dds_msgs::GetDroneScanRouteMsg& sample) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::reset_sample(sample);

            sample.ScanType(dds_msgs::EnumScan::None);
            ::rti::topic::reset_sample(sample.ScanArea());
            sample.ScanAreaGroundAvgAlt(0);
            sample.FlightAltAboveGroundAvgAlt(0);
            sample.TakeoffAltAboveSeaLevel(0);
            sample.FlightSpeed(0);
            sample.CameraHorizontalFOV(0);
            sample.CameraVerticalFOV(0);
            sample.CameraHorizontalResolution(0U);
            sample.CameraVerticalResolution(0U);
            sample.OverlapInFlightDirection(0);
            sample.OverlapInLateralDirection(0);
            sample.GimbalPitchAngle(0);
            ::rti::topic::reset_sample(sample.SquareCenter());
            sample.SquareSide(0U);
        }

        void topic_type_support< dds_msgs::GetDroneScanRouteMsg >::allocate_sample(dds_msgs::GetDroneScanRouteMsg& sample, int, int) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::allocate_sample(sample, -1, -1);

            ::rti::topic::allocate_sample(sample.ScanType(),  -1, -1);
            ::rti::topic::allocate_sample(sample.ScanArea(),  3L, -1);
            ::rti::topic::allocate_sample(sample.SquareCenter(),  -1, -1);
        }

        void topic_type_support< dds_msgs::DroneScanRouteMsg >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                dds_msgs::DroneScanRouteMsgPlugin_new,
                dds_msgs::DroneScanRouteMsgPlugin_delete);
        }

        std::vector<char>& topic_type_support< dds_msgs::DroneScanRouteMsg >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const dds_msgs::DroneScanRouteMsg& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DroneScanRouteMsgPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DroneScanRouteMsgPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< dds_msgs::DroneScanRouteMsg >::from_cdr_buffer(dds_msgs::DroneScanRouteMsg& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DroneScanRouteMsgPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create dds_msgs::DroneScanRouteMsg from cdr buffer");
        }

        void topic_type_support< dds_msgs::DroneScanRouteMsg >::reset_sample(dds_msgs::DroneScanRouteMsg& sample) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::reset_sample(sample);

            ::rti::topic::reset_sample(sample.Waypoints());
            sample.ScanAreaLength(0U);
            sample.ScanAreaWidth(0U);
            sample.ModelGroundResolution(0);
            sample.TimePeriodBetweenFrames(0U);
            sample.ShortLegLength(0U);
            sample.NumOfFramesPerLongLeg(0U);
            sample.TotalNumOfFrames(0U);
        }

        void topic_type_support< dds_msgs::DroneScanRouteMsg >::allocate_sample(dds_msgs::DroneScanRouteMsg& sample, int, int) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::allocate_sample(sample, -1, -1);

            ::rti::topic::allocate_sample(sample.Waypoints(),  100L, -1);
        }

        void topic_type_support< dds_msgs::StartJpegGenerationMsg >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                dds_msgs::StartJpegGenerationMsgPlugin_new,
                dds_msgs::StartJpegGenerationMsgPlugin_delete);
        }

        std::vector<char>& topic_type_support< dds_msgs::StartJpegGenerationMsg >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const dds_msgs::StartJpegGenerationMsg& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = StartJpegGenerationMsgPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = StartJpegGenerationMsgPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< dds_msgs::StartJpegGenerationMsg >::from_cdr_buffer(dds_msgs::StartJpegGenerationMsg& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = StartJpegGenerationMsgPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create dds_msgs::StartJpegGenerationMsg from cdr buffer");
        }

        void topic_type_support< dds_msgs::StartJpegGenerationMsg >::reset_sample(dds_msgs::StartJpegGenerationMsg& sample) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::reset_sample(sample);

            sample.PlatformType(dds_msgs::EnumPlatform::None);
            sample.GeoPathJpegFiles("");
        }

        void topic_type_support< dds_msgs::StartJpegGenerationMsg >::allocate_sample(dds_msgs::StartJpegGenerationMsg& sample, int, int) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::allocate_sample(sample, -1, -1);

            ::rti::topic::allocate_sample(sample.PlatformType(),  -1, -1);
            ::rti::topic::allocate_sample(sample.GeoPathJpegFiles(),  -1, 256L);
        }

        void topic_type_support< dds_msgs::ReportJpegGenerationLivenessMsg >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                dds_msgs::ReportJpegGenerationLivenessMsgPlugin_new,
                dds_msgs::ReportJpegGenerationLivenessMsgPlugin_delete);
        }

        std::vector<char>& topic_type_support< dds_msgs::ReportJpegGenerationLivenessMsg >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const dds_msgs::ReportJpegGenerationLivenessMsg& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ReportJpegGenerationLivenessMsgPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ReportJpegGenerationLivenessMsgPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< dds_msgs::ReportJpegGenerationLivenessMsg >::from_cdr_buffer(dds_msgs::ReportJpegGenerationLivenessMsg& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ReportJpegGenerationLivenessMsgPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create dds_msgs::ReportJpegGenerationLivenessMsg from cdr buffer");
        }

        void topic_type_support< dds_msgs::ReportJpegGenerationLivenessMsg >::reset_sample(dds_msgs::ReportJpegGenerationLivenessMsg& sample) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::reset_sample(sample);

            sample.NumOfJpegFiles(0U);
            sample.Status(dds_msgs::EnumJpegGenerationSts::None);
            sample.ErrorCode(0);
        }

        void topic_type_support< dds_msgs::ReportJpegGenerationLivenessMsg >::allocate_sample(dds_msgs::ReportJpegGenerationLivenessMsg& sample, int, int) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::allocate_sample(sample, -1, -1);

            ::rti::topic::allocate_sample(sample.Status(),  -1, -1);
        }

        void topic_type_support< dds_msgs::LasFileTransmissionStsMsg >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                dds_msgs::LasFileTransmissionStsMsgPlugin_new,
                dds_msgs::LasFileTransmissionStsMsgPlugin_delete);
        }

        std::vector<char>& topic_type_support< dds_msgs::LasFileTransmissionStsMsg >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const dds_msgs::LasFileTransmissionStsMsg& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = LasFileTransmissionStsMsgPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = LasFileTransmissionStsMsgPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< dds_msgs::LasFileTransmissionStsMsg >::from_cdr_buffer(dds_msgs::LasFileTransmissionStsMsg& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = LasFileTransmissionStsMsgPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create dds_msgs::LasFileTransmissionStsMsg from cdr buffer");
        }

        void topic_type_support< dds_msgs::LasFileTransmissionStsMsg >::reset_sample(dds_msgs::LasFileTransmissionStsMsg& sample) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::reset_sample(sample);

            sample.Status(dds_msgs::EnumLasFileTransmissionSts::None);
        }

        void topic_type_support< dds_msgs::LasFileTransmissionStsMsg >::allocate_sample(dds_msgs::LasFileTransmissionStsMsg& sample, int, int) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::allocate_sample(sample, -1, -1);

            ::rti::topic::allocate_sample(sample.Status(),  -1, -1);
        }

        void topic_type_support< dds_msgs::SingleUrlMsg >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                dds_msgs::SingleUrlMsgPlugin_new,
                dds_msgs::SingleUrlMsgPlugin_delete);
        }

        std::vector<char>& topic_type_support< dds_msgs::SingleUrlMsg >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const dds_msgs::SingleUrlMsg& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = SingleUrlMsgPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = SingleUrlMsgPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< dds_msgs::SingleUrlMsg >::from_cdr_buffer(dds_msgs::SingleUrlMsg& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = SingleUrlMsgPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create dds_msgs::SingleUrlMsg from cdr buffer");
        }

        void topic_type_support< dds_msgs::SingleUrlMsg >::reset_sample(dds_msgs::SingleUrlMsg& sample) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::reset_sample(sample);

            sample.CloudUrl("");
        }

        void topic_type_support< dds_msgs::SingleUrlMsg >::allocate_sample(dds_msgs::SingleUrlMsg& sample, int, int) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::allocate_sample(sample, -1, -1);

            ::rti::topic::allocate_sample(sample.CloudUrl(),  -1, 256L);
        }

        void topic_type_support< dds_msgs::DoubleUrlMsg >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                dds_msgs::DoubleUrlMsgPlugin_new,
                dds_msgs::DoubleUrlMsgPlugin_delete);
        }

        std::vector<char>& topic_type_support< dds_msgs::DoubleUrlMsg >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const dds_msgs::DoubleUrlMsg& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DoubleUrlMsgPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DoubleUrlMsgPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< dds_msgs::DoubleUrlMsg >::from_cdr_buffer(dds_msgs::DoubleUrlMsg& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DoubleUrlMsgPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create dds_msgs::DoubleUrlMsg from cdr buffer");
        }

        void topic_type_support< dds_msgs::DoubleUrlMsg >::reset_sample(dds_msgs::DoubleUrlMsg& sample) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::reset_sample(sample);

            sample.GeoPath("");
            sample.CloudUrl("");
        }

        void topic_type_support< dds_msgs::DoubleUrlMsg >::allocate_sample(dds_msgs::DoubleUrlMsg& sample, int, int) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::allocate_sample(sample, -1, -1);

            ::rti::topic::allocate_sample(sample.GeoPath(),  -1, 256L);
            ::rti::topic::allocate_sample(sample.CloudUrl(),  -1, 256L);
        }

        void topic_type_support< dds_msgs::PlatformLocationMsg >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                dds_msgs::PlatformLocationMsgPlugin_new,
                dds_msgs::PlatformLocationMsgPlugin_delete);
        }

        std::vector<char>& topic_type_support< dds_msgs::PlatformLocationMsg >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const dds_msgs::PlatformLocationMsg& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = PlatformLocationMsgPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = PlatformLocationMsgPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< dds_msgs::PlatformLocationMsg >::from_cdr_buffer(dds_msgs::PlatformLocationMsg& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = PlatformLocationMsgPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create dds_msgs::PlatformLocationMsg from cdr buffer");
        }

        void topic_type_support< dds_msgs::PlatformLocationMsg >::reset_sample(dds_msgs::PlatformLocationMsg& sample) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::reset_sample(sample);

            sample.PlatformType(dds_msgs::EnumPlatform::None);
            sample.PlatformId(0);
            sample.PlatformSpeed(0);
            sample.PlatformHeading(0ULL);
            ::rti::topic::reset_sample(sample.PlatformLocation());
            sample.Timestamp(0ULL);
        }

        void topic_type_support< dds_msgs::PlatformLocationMsg >::allocate_sample(dds_msgs::PlatformLocationMsg& sample, int, int) 
        {
            // Initialize base
            topic_type_support< dds_msgs::BaseMsg >::allocate_sample(sample, -1, -1);

            ::rti::topic::allocate_sample(sample.PlatformType(),  -1, -1);
            ::rti::topic::allocate_sample(sample.PlatformLocation(),  -1, -1);
        }

    }
}  

