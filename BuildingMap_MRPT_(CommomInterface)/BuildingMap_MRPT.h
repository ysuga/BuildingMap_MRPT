// -*- C++ -*-
/*!
* @file  BuildingMap_MRPT.h
* @brief Output ""rawlog"" file and map building.
* @date  $Date$
*
* $Id$
*/

#ifndef BUILDINGMAP_MRPT_H
#define BUILDINGMAP_MRPT_H

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>
#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

#include <mrpt/base.h>
#include <mrpt/utils.h>
#include <mrpt/obs.h>
#include <mrpt/slam.h>
#include <mrpt/gui.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">

// </rtc-template>

using namespace RTC;

using namespace mrpt::utils;
using namespace mrpt::poses;
using namespace mrpt::slam;
using namespace mrpt::opengl;
using namespace mrpt::gui;
using namespace mrpt::system;
using namespace mrpt::math;

/*!
* @class BuildingMap_MRPT
* @brief Output ""rawlog"" file and map building.
*
*/
class BuildingMap_MRPT
	: public RTC::DataFlowComponentBase
{
public:
	/*!
	* @brief constructor
	* @param manager Maneger Object
	*/
	BuildingMap_MRPT(RTC::Manager* manager);

	/*!
	* @brief destructor
	*/
	~BuildingMap_MRPT();

	// <rtc-template block="public_attribute">

	// </rtc-template>

	// <rtc-template block="public_operation">

	// </rtc-template>

	/***
	*
	* The initialize action (on CREATED->ALIVE transition)
	* formaer rtc_init_entry() 
	*
	* @return RTC::ReturnCode_t
	* 
	* 
	*/
	virtual RTC::ReturnCode_t onInitialize();

	/***
	*
	* The finalize action (on ALIVE->END transition)
	* formaer rtc_exiting_entry()
	*
	* @return RTC::ReturnCode_t
	* 
	* 
	*/
	// virtual RTC::ReturnCode_t onFinalize();

	/***
	*
	* The startup action when ExecutionContext startup
	* former rtc_starting_entry()
	*
	* @param ec_id target ExecutionContext Id
	*
	* @return RTC::ReturnCode_t
	* 
	* 
	*/
	// virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

	/***
	*
	* The shutdown action when ExecutionContext stop
	* former rtc_stopping_entry()
	*
	* @param ec_id target ExecutionContext Id
	*
	* @return RTC::ReturnCode_t
	* 
	* 
	*/
	// virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

	/***
	*
	* The activated action (Active state entry action)
	* former rtc_active_entry()
	*
	* @param ec_id target ExecutionContext Id
	*
	* @return RTC::ReturnCode_t
	* 
	* 
	*/
	virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

	/***
	*
	* The deactivated action (Active state exit action)
	* former rtc_active_exit()
	*
	* @param ec_id target ExecutionContext Id
	*
	* @return RTC::ReturnCode_t
	* 
	* 
	*/
	virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

	/***
	*
	* The execution action that is invoked periodically
	* former rtc_active_do()
	*
	* @param ec_id target ExecutionContext Id
	*
	* @return RTC::ReturnCode_t
	* 
	* 
	*/
	virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

	/***
	*
	* The aborting action when main logic error occurred.
	* former rtc_aborting_entry()
	*
	* @param ec_id target ExecutionContext Id
	*
	* @return RTC::ReturnCode_t
	* 
	* 
	*/
	// virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

	/***
	*
	* The error action in ERROR state
	* former rtc_error_do()
	*
	* @param ec_id target ExecutionContext Id
	*
	* @return RTC::ReturnCode_t
	* 
	* 
	*/
	// virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

	/***
	*
	* The reset action that is invoked resetting
	* This is same but different the former rtc_init_entry()
	*
	* @param ec_id target ExecutionContext Id
	*
	* @return RTC::ReturnCode_t
	* 
	* 
	*/
	// virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);

	/***
	*
	* The state update action that is invoked after onExecute() action
	* no corresponding operation exists in OpenRTm-aist-0.2.0
	*
	* @param ec_id target ExecutionContext Id
	*
	* @return RTC::ReturnCode_t
	* 
	* 
	*/
	// virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

	/***
	*
	* The action that is invoked when execution context's rate is changed
	* no corresponding operation exists in OpenRTm-aist-0.2.0
	*
	* @param ec_id target ExecutionContext Id
	*
	* @return RTC::ReturnCode_t
	* 
	* 
	*/
	// virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


protected:
	// <rtc-template block="protected_attribute">

	// </rtc-template>

	// <rtc-template block="protected_operation">

	// </rtc-template>

	// Configuration variable declaration
	// <rtc-template block="config_declare">
	/*!
	* 
	* - Name:  rightToLeft
	* - DefaultValue: 1
	*/
	int m_rightToLeft;
	/*!
	* 
	* - Name:  aperture
	* - DefaultValue: 270.0
	*/
	float m_aperture;
	// </rtc-template>

	// DataInPort declaration
	// <rtc-template block="inport_declare">
	TimedPose2D m_InOdometryPosition;
	/*!
	*/
	InPort<TimedPose2D> m_InOdometryPositionIn;
	RangeData m_rangeData;
	/*!
	*/
	InPort<RangeData> m_rangeDataIn;

	// </rtc-template>


	// DataOutPort declaration
	// <rtc-template block="outport_declare">

	// </rtc-template>

	// CORBA Port declaration
	// <rtc-template block="corbaport_declare">

	// </rtc-template>

	// Service declaration
	// <rtc-template block="service_declare">

	// </rtc-template>

	// Consumer declaration
	// <rtc-template block="consumer_declare">

	// </rtc-template>

private:
	// <rtc-template block="private_attribute">

	// </rtc-template>

	// <rtc-template block="private_operation">

	// </rtc-template>

	// Output rawlog:
	CFileGZOutputStream  outputFile;
	double now_x, now_y, now_theta;
	double past_x, past_y, past_theta;
	bool firstloop;

	// Building map:
	const char* OUT_DIR;

	// config file
	// ----------------------------------
	unsigned int rawlog_offset;
	string OUT_DIR_STD;
	int LOG_FREQUENCY;
	bool  SAVE_POSE_LOG;
	bool  SAVE_3D_SCENE;
	bool  CAMERA_3DSCENE_FOLLOWS_ROBOT;

	bool 	SHOW_PROGRESS_3D_REAL_TIME;
	int		SHOW_PROGRESS_3D_REAL_TIME_DELAY_MS;

	// log files:
	// ----------------------------------
	CFileOutputStream  f_log;
	CFileOutputStream  f_path;
	CFileOutputStream  f_pathOdo;

	// Checks:
	int	step;
	string								str;
	CSimpleMap							finalMap;
	float								t_exec;
	COccupancyGridMap2D::TEntropyInfo	entropy;

	// ICP-SLAM object:
	CMetricMapBuilderICP mapBuilder;

	// Create 3D window if requested:
	CDisplayWindow3DPtr	win3D;

};


extern "C"
{
	DLL_EXPORT void BuildingMap_MRPTInit(RTC::Manager* manager);
};

#endif // BUILDINGMAP_MRPT_H
