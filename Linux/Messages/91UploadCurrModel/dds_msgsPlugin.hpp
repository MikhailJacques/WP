

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from dds_msgs.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef dds_msgsPlugin_1583855809_h
#define dds_msgsPlugin_1583855809_h

#include "dds_msgs.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace dds_msgs {

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    EnumMissionPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    EnumMissionPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    EnumMissionPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    EnumMissionPluginSupport_print_data(
        const EnumMission *sample, const char *desc, int indent_level);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    EnumPlatformPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    EnumPlatformPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    EnumPlatformPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    EnumPlatformPluginSupport_print_data(
        const EnumPlatform *sample, const char *desc, int indent_level);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    EnumScanPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    EnumScanPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    EnumScanPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    EnumScanPluginSupport_print_data(
        const EnumScan *sample, const char *desc, int indent_level);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    EnumJpegGenerationStsPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    EnumJpegGenerationStsPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    EnumJpegGenerationStsPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    EnumJpegGenerationStsPluginSupport_print_data(
        const EnumJpegGenerationSts *sample, const char *desc, int indent_level);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    EnumLasFileTransmissionStsPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    EnumLasFileTransmissionStsPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    EnumLasFileTransmissionStsPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    EnumLasFileTransmissionStsPluginSupport_print_data(
        const EnumLasFileTransmissionSts *sample, const char *desc, int indent_level);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    EnumCalculationPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    EnumCalculationPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    EnumCalculationPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    EnumCalculationPluginSupport_print_data(
        const EnumCalculation *sample, const char *desc, int indent_level);

    #define GeoPointPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define GeoPointPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define GeoPointPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define GeoPointPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define GeoPointPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern GeoPoint*
    GeoPointPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern GeoPoint*
    GeoPointPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern GeoPoint*
    GeoPointPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    GeoPointPluginSupport_copy_data(
        GeoPoint *out,
        const GeoPoint *in);

    NDDSUSERDllExport extern void 
    GeoPointPluginSupport_destroy_data_w_params(
        GeoPoint *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    GeoPointPluginSupport_destroy_data_ex(
        GeoPoint *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    GeoPointPluginSupport_destroy_data(
        GeoPoint *sample);

    NDDSUSERDllExport extern void 
    GeoPointPluginSupport_print_data(
        const GeoPoint *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    GeoPointPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        GeoPoint *out,
        const GeoPoint *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    GeoPointPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const GeoPoint *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    GeoPointPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        GeoPoint **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    GeoPointPlugin_deserialize_from_cdr_buffer(
        GeoPoint *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    GeoPointPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    GeoPointPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    GeoPointPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    GeoPointPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    GeoPointPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        GeoPoint ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    #define LocalScanPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define LocalScanPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define LocalScanPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define LocalScanPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define LocalScanPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern LocalScan*
    LocalScanPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern LocalScan*
    LocalScanPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern LocalScan*
    LocalScanPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    LocalScanPluginSupport_copy_data(
        LocalScan *out,
        const LocalScan *in);

    NDDSUSERDllExport extern void 
    LocalScanPluginSupport_destroy_data_w_params(
        LocalScan *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    LocalScanPluginSupport_destroy_data_ex(
        LocalScan *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    LocalScanPluginSupport_destroy_data(
        LocalScan *sample);

    NDDSUSERDllExport extern void 
    LocalScanPluginSupport_print_data(
        const LocalScan *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    LocalScanPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        LocalScan *out,
        const LocalScan *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    LocalScanPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const LocalScan *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    LocalScanPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        LocalScan **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    LocalScanPlugin_deserialize_from_cdr_buffer(
        LocalScan *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    LocalScanPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    LocalScanPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    LocalScanPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    LocalScanPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    LocalScanPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        LocalScan ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct BaseMsg
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct BaseMsg)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * BaseMsg must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct BaseMsg.
    */
    typedef  class BaseMsg BaseMsgKeyHolder;

    #define BaseMsgPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define BaseMsgPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define BaseMsgPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define BaseMsgPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define BaseMsgPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define BaseMsgPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define BaseMsgPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern BaseMsg*
    BaseMsgPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern BaseMsg*
    BaseMsgPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern BaseMsg*
    BaseMsgPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    BaseMsgPluginSupport_copy_data(
        BaseMsg *out,
        const BaseMsg *in);

    NDDSUSERDllExport extern void 
    BaseMsgPluginSupport_destroy_data_w_params(
        BaseMsg *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    BaseMsgPluginSupport_destroy_data_ex(
        BaseMsg *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    BaseMsgPluginSupport_destroy_data(
        BaseMsg *sample);

    NDDSUSERDllExport extern void 
    BaseMsgPluginSupport_print_data(
        const BaseMsg *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern BaseMsg*
    BaseMsgPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern BaseMsg*
    BaseMsgPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    BaseMsgPluginSupport_destroy_key_ex(
        BaseMsgKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    BaseMsgPluginSupport_destroy_key(
        BaseMsgKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    BaseMsgPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    BaseMsgPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    BaseMsgPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    BaseMsgPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    BaseMsgPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        BaseMsg *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    BaseMsgPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        BaseMsg *out,
        const BaseMsg *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    BaseMsgPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const BaseMsg *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    BaseMsgPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        BaseMsg **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    BaseMsgPlugin_deserialize_from_cdr_buffer(
        BaseMsg *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    BaseMsgPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    BaseMsgPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    BaseMsgPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    BaseMsgPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    BaseMsgPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        BaseMsg ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    BaseMsgPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        BaseMsgKeyHolder *key, 
        const BaseMsg *instance);

    NDDSUSERDllExport extern RTIBool 
    BaseMsgPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        BaseMsg *instance, 
        const BaseMsgKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    BaseMsgPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    BaseMsgPlugin_new(void);

    NDDSUSERDllExport extern void
    BaseMsgPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct MissionPlanMsg
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct MissionPlanMsg)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * MissionPlanMsg must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct MissionPlanMsg.
    */
    typedef  class MissionPlanMsg MissionPlanMsgKeyHolder;

    #define MissionPlanMsgPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define MissionPlanMsgPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define MissionPlanMsgPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define MissionPlanMsgPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define MissionPlanMsgPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define MissionPlanMsgPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define MissionPlanMsgPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern MissionPlanMsg*
    MissionPlanMsgPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern MissionPlanMsg*
    MissionPlanMsgPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern MissionPlanMsg*
    MissionPlanMsgPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    MissionPlanMsgPluginSupport_copy_data(
        MissionPlanMsg *out,
        const MissionPlanMsg *in);

    NDDSUSERDllExport extern void 
    MissionPlanMsgPluginSupport_destroy_data_w_params(
        MissionPlanMsg *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    MissionPlanMsgPluginSupport_destroy_data_ex(
        MissionPlanMsg *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    MissionPlanMsgPluginSupport_destroy_data(
        MissionPlanMsg *sample);

    NDDSUSERDllExport extern void 
    MissionPlanMsgPluginSupport_print_data(
        const MissionPlanMsg *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern MissionPlanMsg*
    MissionPlanMsgPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern MissionPlanMsg*
    MissionPlanMsgPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    MissionPlanMsgPluginSupport_destroy_key_ex(
        MissionPlanMsgKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    MissionPlanMsgPluginSupport_destroy_key(
        MissionPlanMsgKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    MissionPlanMsgPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    MissionPlanMsgPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    MissionPlanMsgPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    MissionPlanMsgPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    MissionPlanMsgPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        MissionPlanMsg *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    MissionPlanMsgPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        MissionPlanMsg *out,
        const MissionPlanMsg *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    MissionPlanMsgPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const MissionPlanMsg *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    MissionPlanMsgPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        MissionPlanMsg **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    MissionPlanMsgPlugin_deserialize_from_cdr_buffer(
        MissionPlanMsg *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    MissionPlanMsgPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    MissionPlanMsgPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    MissionPlanMsgPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    MissionPlanMsgPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    MissionPlanMsgPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        MissionPlanMsg ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    MissionPlanMsgPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        MissionPlanMsgKeyHolder *key, 
        const MissionPlanMsg *instance);

    NDDSUSERDllExport extern RTIBool 
    MissionPlanMsgPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        MissionPlanMsg *instance, 
        const MissionPlanMsgKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    MissionPlanMsgPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    MissionPlanMsgPlugin_new(void);

    NDDSUSERDllExport extern void
    MissionPlanMsgPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct GetDroneScanRouteMsg
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct GetDroneScanRouteMsg)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * GetDroneScanRouteMsg must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct GetDroneScanRouteMsg.
    */
    typedef  class GetDroneScanRouteMsg GetDroneScanRouteMsgKeyHolder;

    #define GetDroneScanRouteMsgPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define GetDroneScanRouteMsgPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define GetDroneScanRouteMsgPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define GetDroneScanRouteMsgPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define GetDroneScanRouteMsgPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define GetDroneScanRouteMsgPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define GetDroneScanRouteMsgPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern GetDroneScanRouteMsg*
    GetDroneScanRouteMsgPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern GetDroneScanRouteMsg*
    GetDroneScanRouteMsgPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern GetDroneScanRouteMsg*
    GetDroneScanRouteMsgPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    GetDroneScanRouteMsgPluginSupport_copy_data(
        GetDroneScanRouteMsg *out,
        const GetDroneScanRouteMsg *in);

    NDDSUSERDllExport extern void 
    GetDroneScanRouteMsgPluginSupport_destroy_data_w_params(
        GetDroneScanRouteMsg *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    GetDroneScanRouteMsgPluginSupport_destroy_data_ex(
        GetDroneScanRouteMsg *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    GetDroneScanRouteMsgPluginSupport_destroy_data(
        GetDroneScanRouteMsg *sample);

    NDDSUSERDllExport extern void 
    GetDroneScanRouteMsgPluginSupport_print_data(
        const GetDroneScanRouteMsg *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern GetDroneScanRouteMsg*
    GetDroneScanRouteMsgPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern GetDroneScanRouteMsg*
    GetDroneScanRouteMsgPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    GetDroneScanRouteMsgPluginSupport_destroy_key_ex(
        GetDroneScanRouteMsgKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    GetDroneScanRouteMsgPluginSupport_destroy_key(
        GetDroneScanRouteMsgKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    GetDroneScanRouteMsgPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    GetDroneScanRouteMsgPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    GetDroneScanRouteMsgPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    GetDroneScanRouteMsgPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    GetDroneScanRouteMsgPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        GetDroneScanRouteMsg *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    GetDroneScanRouteMsgPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        GetDroneScanRouteMsg *out,
        const GetDroneScanRouteMsg *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    GetDroneScanRouteMsgPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const GetDroneScanRouteMsg *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    GetDroneScanRouteMsgPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        GetDroneScanRouteMsg **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    GetDroneScanRouteMsgPlugin_deserialize_from_cdr_buffer(
        GetDroneScanRouteMsg *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    GetDroneScanRouteMsgPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    GetDroneScanRouteMsgPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    GetDroneScanRouteMsgPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    GetDroneScanRouteMsgPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    GetDroneScanRouteMsgPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        GetDroneScanRouteMsg ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    GetDroneScanRouteMsgPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        GetDroneScanRouteMsgKeyHolder *key, 
        const GetDroneScanRouteMsg *instance);

    NDDSUSERDllExport extern RTIBool 
    GetDroneScanRouteMsgPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        GetDroneScanRouteMsg *instance, 
        const GetDroneScanRouteMsgKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    GetDroneScanRouteMsgPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    GetDroneScanRouteMsgPlugin_new(void);

    NDDSUSERDllExport extern void
    GetDroneScanRouteMsgPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct DroneScanRouteMsg
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct DroneScanRouteMsg)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * DroneScanRouteMsg must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct DroneScanRouteMsg.
    */
    typedef  class DroneScanRouteMsg DroneScanRouteMsgKeyHolder;

    #define DroneScanRouteMsgPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define DroneScanRouteMsgPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define DroneScanRouteMsgPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define DroneScanRouteMsgPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define DroneScanRouteMsgPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define DroneScanRouteMsgPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define DroneScanRouteMsgPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern DroneScanRouteMsg*
    DroneScanRouteMsgPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern DroneScanRouteMsg*
    DroneScanRouteMsgPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern DroneScanRouteMsg*
    DroneScanRouteMsgPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    DroneScanRouteMsgPluginSupport_copy_data(
        DroneScanRouteMsg *out,
        const DroneScanRouteMsg *in);

    NDDSUSERDllExport extern void 
    DroneScanRouteMsgPluginSupport_destroy_data_w_params(
        DroneScanRouteMsg *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    DroneScanRouteMsgPluginSupport_destroy_data_ex(
        DroneScanRouteMsg *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    DroneScanRouteMsgPluginSupport_destroy_data(
        DroneScanRouteMsg *sample);

    NDDSUSERDllExport extern void 
    DroneScanRouteMsgPluginSupport_print_data(
        const DroneScanRouteMsg *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern DroneScanRouteMsg*
    DroneScanRouteMsgPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern DroneScanRouteMsg*
    DroneScanRouteMsgPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    DroneScanRouteMsgPluginSupport_destroy_key_ex(
        DroneScanRouteMsgKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    DroneScanRouteMsgPluginSupport_destroy_key(
        DroneScanRouteMsgKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    DroneScanRouteMsgPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    DroneScanRouteMsgPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    DroneScanRouteMsgPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    DroneScanRouteMsgPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    DroneScanRouteMsgPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        DroneScanRouteMsg *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    DroneScanRouteMsgPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        DroneScanRouteMsg *out,
        const DroneScanRouteMsg *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    DroneScanRouteMsgPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const DroneScanRouteMsg *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    DroneScanRouteMsgPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        DroneScanRouteMsg **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    DroneScanRouteMsgPlugin_deserialize_from_cdr_buffer(
        DroneScanRouteMsg *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    DroneScanRouteMsgPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    DroneScanRouteMsgPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    DroneScanRouteMsgPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    DroneScanRouteMsgPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    DroneScanRouteMsgPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        DroneScanRouteMsg ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    DroneScanRouteMsgPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        DroneScanRouteMsgKeyHolder *key, 
        const DroneScanRouteMsg *instance);

    NDDSUSERDllExport extern RTIBool 
    DroneScanRouteMsgPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        DroneScanRouteMsg *instance, 
        const DroneScanRouteMsgKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    DroneScanRouteMsgPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    DroneScanRouteMsgPlugin_new(void);

    NDDSUSERDllExport extern void
    DroneScanRouteMsgPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct PlatformLocationMsg
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct PlatformLocationMsg)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * PlatformLocationMsg must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct PlatformLocationMsg.
    */
    typedef  class PlatformLocationMsg PlatformLocationMsgKeyHolder;

    #define PlatformLocationMsgPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define PlatformLocationMsgPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define PlatformLocationMsgPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define PlatformLocationMsgPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define PlatformLocationMsgPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define PlatformLocationMsgPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define PlatformLocationMsgPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PlatformLocationMsg*
    PlatformLocationMsgPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern PlatformLocationMsg*
    PlatformLocationMsgPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern PlatformLocationMsg*
    PlatformLocationMsgPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    PlatformLocationMsgPluginSupport_copy_data(
        PlatformLocationMsg *out,
        const PlatformLocationMsg *in);

    NDDSUSERDllExport extern void 
    PlatformLocationMsgPluginSupport_destroy_data_w_params(
        PlatformLocationMsg *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    PlatformLocationMsgPluginSupport_destroy_data_ex(
        PlatformLocationMsg *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    PlatformLocationMsgPluginSupport_destroy_data(
        PlatformLocationMsg *sample);

    NDDSUSERDllExport extern void 
    PlatformLocationMsgPluginSupport_print_data(
        const PlatformLocationMsg *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern PlatformLocationMsg*
    PlatformLocationMsgPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern PlatformLocationMsg*
    PlatformLocationMsgPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    PlatformLocationMsgPluginSupport_destroy_key_ex(
        PlatformLocationMsgKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    PlatformLocationMsgPluginSupport_destroy_key(
        PlatformLocationMsgKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    PlatformLocationMsgPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    PlatformLocationMsgPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    PlatformLocationMsgPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    PlatformLocationMsgPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    PlatformLocationMsgPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        PlatformLocationMsg *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    PlatformLocationMsgPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        PlatformLocationMsg *out,
        const PlatformLocationMsg *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    PlatformLocationMsgPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const PlatformLocationMsg *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    PlatformLocationMsgPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        PlatformLocationMsg **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    PlatformLocationMsgPlugin_deserialize_from_cdr_buffer(
        PlatformLocationMsg *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    PlatformLocationMsgPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    PlatformLocationMsgPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    PlatformLocationMsgPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    PlatformLocationMsgPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    PlatformLocationMsgPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        PlatformLocationMsg ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    PlatformLocationMsgPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        PlatformLocationMsgKeyHolder *key, 
        const PlatformLocationMsg *instance);

    NDDSUSERDllExport extern RTIBool 
    PlatformLocationMsgPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        PlatformLocationMsg *instance, 
        const PlatformLocationMsgKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    PlatformLocationMsgPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    PlatformLocationMsgPlugin_new(void);

    NDDSUSERDllExport extern void
    PlatformLocationMsgPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct StartJpegGenerationMsg
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct StartJpegGenerationMsg)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * StartJpegGenerationMsg must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct StartJpegGenerationMsg.
    */
    typedef  class StartJpegGenerationMsg StartJpegGenerationMsgKeyHolder;

    #define StartJpegGenerationMsgPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define StartJpegGenerationMsgPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define StartJpegGenerationMsgPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define StartJpegGenerationMsgPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define StartJpegGenerationMsgPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define StartJpegGenerationMsgPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define StartJpegGenerationMsgPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern StartJpegGenerationMsg*
    StartJpegGenerationMsgPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern StartJpegGenerationMsg*
    StartJpegGenerationMsgPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern StartJpegGenerationMsg*
    StartJpegGenerationMsgPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    StartJpegGenerationMsgPluginSupport_copy_data(
        StartJpegGenerationMsg *out,
        const StartJpegGenerationMsg *in);

    NDDSUSERDllExport extern void 
    StartJpegGenerationMsgPluginSupport_destroy_data_w_params(
        StartJpegGenerationMsg *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    StartJpegGenerationMsgPluginSupport_destroy_data_ex(
        StartJpegGenerationMsg *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    StartJpegGenerationMsgPluginSupport_destroy_data(
        StartJpegGenerationMsg *sample);

    NDDSUSERDllExport extern void 
    StartJpegGenerationMsgPluginSupport_print_data(
        const StartJpegGenerationMsg *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern StartJpegGenerationMsg*
    StartJpegGenerationMsgPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern StartJpegGenerationMsg*
    StartJpegGenerationMsgPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    StartJpegGenerationMsgPluginSupport_destroy_key_ex(
        StartJpegGenerationMsgKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    StartJpegGenerationMsgPluginSupport_destroy_key(
        StartJpegGenerationMsgKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    StartJpegGenerationMsgPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    StartJpegGenerationMsgPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    StartJpegGenerationMsgPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    StartJpegGenerationMsgPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    StartJpegGenerationMsgPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        StartJpegGenerationMsg *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    StartJpegGenerationMsgPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        StartJpegGenerationMsg *out,
        const StartJpegGenerationMsg *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    StartJpegGenerationMsgPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const StartJpegGenerationMsg *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    StartJpegGenerationMsgPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        StartJpegGenerationMsg **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    StartJpegGenerationMsgPlugin_deserialize_from_cdr_buffer(
        StartJpegGenerationMsg *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    StartJpegGenerationMsgPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    StartJpegGenerationMsgPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    StartJpegGenerationMsgPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    StartJpegGenerationMsgPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    StartJpegGenerationMsgPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        StartJpegGenerationMsg ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    StartJpegGenerationMsgPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        StartJpegGenerationMsgKeyHolder *key, 
        const StartJpegGenerationMsg *instance);

    NDDSUSERDllExport extern RTIBool 
    StartJpegGenerationMsgPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        StartJpegGenerationMsg *instance, 
        const StartJpegGenerationMsgKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    StartJpegGenerationMsgPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    StartJpegGenerationMsgPlugin_new(void);

    NDDSUSERDllExport extern void
    StartJpegGenerationMsgPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct ReportJpegGenerationLivenessMsg
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct ReportJpegGenerationLivenessMsg)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * ReportJpegGenerationLivenessMsg must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct ReportJpegGenerationLivenessMsg.
    */
    typedef  class ReportJpegGenerationLivenessMsg ReportJpegGenerationLivenessMsgKeyHolder;

    #define ReportJpegGenerationLivenessMsgPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define ReportJpegGenerationLivenessMsgPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ReportJpegGenerationLivenessMsgPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define ReportJpegGenerationLivenessMsgPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define ReportJpegGenerationLivenessMsgPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define ReportJpegGenerationLivenessMsgPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ReportJpegGenerationLivenessMsgPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ReportJpegGenerationLivenessMsg*
    ReportJpegGenerationLivenessMsgPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ReportJpegGenerationLivenessMsg*
    ReportJpegGenerationLivenessMsgPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ReportJpegGenerationLivenessMsg*
    ReportJpegGenerationLivenessMsgPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ReportJpegGenerationLivenessMsgPluginSupport_copy_data(
        ReportJpegGenerationLivenessMsg *out,
        const ReportJpegGenerationLivenessMsg *in);

    NDDSUSERDllExport extern void 
    ReportJpegGenerationLivenessMsgPluginSupport_destroy_data_w_params(
        ReportJpegGenerationLivenessMsg *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ReportJpegGenerationLivenessMsgPluginSupport_destroy_data_ex(
        ReportJpegGenerationLivenessMsg *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ReportJpegGenerationLivenessMsgPluginSupport_destroy_data(
        ReportJpegGenerationLivenessMsg *sample);

    NDDSUSERDllExport extern void 
    ReportJpegGenerationLivenessMsgPluginSupport_print_data(
        const ReportJpegGenerationLivenessMsg *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern ReportJpegGenerationLivenessMsg*
    ReportJpegGenerationLivenessMsgPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ReportJpegGenerationLivenessMsg*
    ReportJpegGenerationLivenessMsgPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    ReportJpegGenerationLivenessMsgPluginSupport_destroy_key_ex(
        ReportJpegGenerationLivenessMsgKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ReportJpegGenerationLivenessMsgPluginSupport_destroy_key(
        ReportJpegGenerationLivenessMsgKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ReportJpegGenerationLivenessMsgPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ReportJpegGenerationLivenessMsgPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ReportJpegGenerationLivenessMsgPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ReportJpegGenerationLivenessMsgPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ReportJpegGenerationLivenessMsgPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ReportJpegGenerationLivenessMsg *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ReportJpegGenerationLivenessMsgPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ReportJpegGenerationLivenessMsg *out,
        const ReportJpegGenerationLivenessMsg *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    ReportJpegGenerationLivenessMsgPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ReportJpegGenerationLivenessMsg *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    ReportJpegGenerationLivenessMsgPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        ReportJpegGenerationLivenessMsg **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ReportJpegGenerationLivenessMsgPlugin_deserialize_from_cdr_buffer(
        ReportJpegGenerationLivenessMsg *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    ReportJpegGenerationLivenessMsgPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ReportJpegGenerationLivenessMsgPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ReportJpegGenerationLivenessMsgPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ReportJpegGenerationLivenessMsgPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ReportJpegGenerationLivenessMsgPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ReportJpegGenerationLivenessMsg ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ReportJpegGenerationLivenessMsgPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        ReportJpegGenerationLivenessMsgKeyHolder *key, 
        const ReportJpegGenerationLivenessMsg *instance);

    NDDSUSERDllExport extern RTIBool 
    ReportJpegGenerationLivenessMsgPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        ReportJpegGenerationLivenessMsg *instance, 
        const ReportJpegGenerationLivenessMsgKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    ReportJpegGenerationLivenessMsgPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ReportJpegGenerationLivenessMsgPlugin_new(void);

    NDDSUSERDllExport extern void
    ReportJpegGenerationLivenessMsgPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct LasFileTransmissionStsMsg
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct LasFileTransmissionStsMsg)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * LasFileTransmissionStsMsg must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct LasFileTransmissionStsMsg.
    */
    typedef  class LasFileTransmissionStsMsg LasFileTransmissionStsMsgKeyHolder;

    #define LasFileTransmissionStsMsgPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define LasFileTransmissionStsMsgPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define LasFileTransmissionStsMsgPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define LasFileTransmissionStsMsgPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define LasFileTransmissionStsMsgPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define LasFileTransmissionStsMsgPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define LasFileTransmissionStsMsgPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern LasFileTransmissionStsMsg*
    LasFileTransmissionStsMsgPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern LasFileTransmissionStsMsg*
    LasFileTransmissionStsMsgPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern LasFileTransmissionStsMsg*
    LasFileTransmissionStsMsgPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    LasFileTransmissionStsMsgPluginSupport_copy_data(
        LasFileTransmissionStsMsg *out,
        const LasFileTransmissionStsMsg *in);

    NDDSUSERDllExport extern void 
    LasFileTransmissionStsMsgPluginSupport_destroy_data_w_params(
        LasFileTransmissionStsMsg *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    LasFileTransmissionStsMsgPluginSupport_destroy_data_ex(
        LasFileTransmissionStsMsg *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    LasFileTransmissionStsMsgPluginSupport_destroy_data(
        LasFileTransmissionStsMsg *sample);

    NDDSUSERDllExport extern void 
    LasFileTransmissionStsMsgPluginSupport_print_data(
        const LasFileTransmissionStsMsg *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern LasFileTransmissionStsMsg*
    LasFileTransmissionStsMsgPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern LasFileTransmissionStsMsg*
    LasFileTransmissionStsMsgPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    LasFileTransmissionStsMsgPluginSupport_destroy_key_ex(
        LasFileTransmissionStsMsgKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    LasFileTransmissionStsMsgPluginSupport_destroy_key(
        LasFileTransmissionStsMsgKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    LasFileTransmissionStsMsgPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    LasFileTransmissionStsMsgPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    LasFileTransmissionStsMsgPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    LasFileTransmissionStsMsgPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    LasFileTransmissionStsMsgPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        LasFileTransmissionStsMsg *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    LasFileTransmissionStsMsgPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        LasFileTransmissionStsMsg *out,
        const LasFileTransmissionStsMsg *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    LasFileTransmissionStsMsgPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const LasFileTransmissionStsMsg *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    LasFileTransmissionStsMsgPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        LasFileTransmissionStsMsg **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    LasFileTransmissionStsMsgPlugin_deserialize_from_cdr_buffer(
        LasFileTransmissionStsMsg *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    LasFileTransmissionStsMsgPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    LasFileTransmissionStsMsgPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    LasFileTransmissionStsMsgPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    LasFileTransmissionStsMsgPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    LasFileTransmissionStsMsgPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        LasFileTransmissionStsMsg ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    LasFileTransmissionStsMsgPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        LasFileTransmissionStsMsgKeyHolder *key, 
        const LasFileTransmissionStsMsg *instance);

    NDDSUSERDllExport extern RTIBool 
    LasFileTransmissionStsMsgPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        LasFileTransmissionStsMsg *instance, 
        const LasFileTransmissionStsMsgKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    LasFileTransmissionStsMsgPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    LasFileTransmissionStsMsgPlugin_new(void);

    NDDSUSERDllExport extern void
    LasFileTransmissionStsMsgPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct SingleUrlMsg
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct SingleUrlMsg)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * SingleUrlMsg must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct SingleUrlMsg.
    */
    typedef  class SingleUrlMsg SingleUrlMsgKeyHolder;

    #define SingleUrlMsgPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define SingleUrlMsgPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define SingleUrlMsgPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define SingleUrlMsgPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define SingleUrlMsgPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define SingleUrlMsgPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define SingleUrlMsgPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern SingleUrlMsg*
    SingleUrlMsgPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern SingleUrlMsg*
    SingleUrlMsgPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern SingleUrlMsg*
    SingleUrlMsgPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    SingleUrlMsgPluginSupport_copy_data(
        SingleUrlMsg *out,
        const SingleUrlMsg *in);

    NDDSUSERDllExport extern void 
    SingleUrlMsgPluginSupport_destroy_data_w_params(
        SingleUrlMsg *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    SingleUrlMsgPluginSupport_destroy_data_ex(
        SingleUrlMsg *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    SingleUrlMsgPluginSupport_destroy_data(
        SingleUrlMsg *sample);

    NDDSUSERDllExport extern void 
    SingleUrlMsgPluginSupport_print_data(
        const SingleUrlMsg *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern SingleUrlMsg*
    SingleUrlMsgPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern SingleUrlMsg*
    SingleUrlMsgPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    SingleUrlMsgPluginSupport_destroy_key_ex(
        SingleUrlMsgKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    SingleUrlMsgPluginSupport_destroy_key(
        SingleUrlMsgKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    SingleUrlMsgPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    SingleUrlMsgPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    SingleUrlMsgPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    SingleUrlMsgPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    SingleUrlMsgPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        SingleUrlMsg *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    SingleUrlMsgPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        SingleUrlMsg *out,
        const SingleUrlMsg *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    SingleUrlMsgPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const SingleUrlMsg *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    SingleUrlMsgPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        SingleUrlMsg **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    SingleUrlMsgPlugin_deserialize_from_cdr_buffer(
        SingleUrlMsg *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    SingleUrlMsgPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    SingleUrlMsgPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    SingleUrlMsgPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    SingleUrlMsgPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    SingleUrlMsgPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        SingleUrlMsg ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    SingleUrlMsgPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        SingleUrlMsgKeyHolder *key, 
        const SingleUrlMsg *instance);

    NDDSUSERDllExport extern RTIBool 
    SingleUrlMsgPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        SingleUrlMsg *instance, 
        const SingleUrlMsgKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    SingleUrlMsgPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    SingleUrlMsgPlugin_new(void);

    NDDSUSERDllExport extern void
    SingleUrlMsgPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct DoubleUrlMsg
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct DoubleUrlMsg)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * DoubleUrlMsg must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct DoubleUrlMsg.
    */
    typedef  class DoubleUrlMsg DoubleUrlMsgKeyHolder;

    #define DoubleUrlMsgPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define DoubleUrlMsgPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define DoubleUrlMsgPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define DoubleUrlMsgPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define DoubleUrlMsgPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define DoubleUrlMsgPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define DoubleUrlMsgPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern DoubleUrlMsg*
    DoubleUrlMsgPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern DoubleUrlMsg*
    DoubleUrlMsgPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern DoubleUrlMsg*
    DoubleUrlMsgPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    DoubleUrlMsgPluginSupport_copy_data(
        DoubleUrlMsg *out,
        const DoubleUrlMsg *in);

    NDDSUSERDllExport extern void 
    DoubleUrlMsgPluginSupport_destroy_data_w_params(
        DoubleUrlMsg *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    DoubleUrlMsgPluginSupport_destroy_data_ex(
        DoubleUrlMsg *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    DoubleUrlMsgPluginSupport_destroy_data(
        DoubleUrlMsg *sample);

    NDDSUSERDllExport extern void 
    DoubleUrlMsgPluginSupport_print_data(
        const DoubleUrlMsg *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern DoubleUrlMsg*
    DoubleUrlMsgPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern DoubleUrlMsg*
    DoubleUrlMsgPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    DoubleUrlMsgPluginSupport_destroy_key_ex(
        DoubleUrlMsgKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    DoubleUrlMsgPluginSupport_destroy_key(
        DoubleUrlMsgKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    DoubleUrlMsgPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    DoubleUrlMsgPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    DoubleUrlMsgPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    DoubleUrlMsgPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    DoubleUrlMsgPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        DoubleUrlMsg *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    DoubleUrlMsgPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        DoubleUrlMsg *out,
        const DoubleUrlMsg *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    DoubleUrlMsgPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const DoubleUrlMsg *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    DoubleUrlMsgPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        DoubleUrlMsg **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    DoubleUrlMsgPlugin_deserialize_from_cdr_buffer(
        DoubleUrlMsg *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    DoubleUrlMsgPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    DoubleUrlMsgPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    DoubleUrlMsgPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    DoubleUrlMsgPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    DoubleUrlMsgPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        DoubleUrlMsg ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    DoubleUrlMsgPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        DoubleUrlMsgKeyHolder *key, 
        const DoubleUrlMsg *instance);

    NDDSUSERDllExport extern RTIBool 
    DoubleUrlMsgPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        DoubleUrlMsg *instance, 
        const DoubleUrlMsgKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    DoubleUrlMsgPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    DoubleUrlMsgPlugin_new(void);

    NDDSUSERDllExport extern void
    DoubleUrlMsgPlugin_delete(struct PRESTypePlugin *);

} /* namespace dds_msgs  */

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* dds_msgsPlugin_1583855809_h */

