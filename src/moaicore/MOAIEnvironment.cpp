// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moaicore/MOAIEnvironment.h>
#include <moaicore/MOAILogMgr.h>
#include <aku/AKU.h>

//================================================================//
// local
//================================================================//

//----------------------------------------------------------------//
/**	@name	generateGUID
	@text	Generates a globally unique identifier

	@out	string GUID
*/
int MOAIEnvironment::_generateGUID ( lua_State* L ) {

	lua_pushstring ( L, MOAIEnvironment::Get ().getGUIDfunc ());
	return 1;
}

//----------------------------------------------------------------//
/**	@name	getAppDisplayName
	@text	Returns the app display name

	@out	string diaplyName
*/
int MOAIEnvironment::_getAppDisplayName ( lua_State* L  ) {

	lua_pushstring ( L, MOAIEnvironment::Get ().mAppDisplayName.c_str ());
	return 1;
}

//----------------------------------------------------------------//
/**	@name	getAppID
	@text	Returns the app ID

	@out	string appID
*/
int MOAIEnvironment::_getAppID ( lua_State* L  ) {

	lua_pushstring ( L, MOAIEnvironment::Get ().mAppID.c_str ());
	return 1;
}

//----------------------------------------------------------------//
/**	@name	getAppVersion
	@text	Returns the app version

	@out	string appVersion
*/
int MOAIEnvironment::_getAppVersion ( lua_State* L  ) {

	lua_pushstring ( L, MOAIEnvironment::Get ().mAppVersion.c_str ());
	return 1;
}

//----------------------------------------------------------------//
/**	@name	_getConnectionType
	@text	Gets whether the device is connected to WIFI, WWAN or nothing

	@out	string connectionType
*/
int MOAIEnvironment::_getConnectionType ( lua_State* L ) {

	u32 type = ( u32) MOAIEnvironment::Get ().getConnectivityFunc ();

	lua_pushinteger ( L, type );
	return 1;
}

//----------------------------------------------------------------//
/**	@name	getCPUABI
	@text	Returns the CPU ABI

	@out	string ABI
*/
int MOAIEnvironment::_getCPUABI ( lua_State* L  ) {

	lua_pushstring ( L, MOAIEnvironment::Get ().mCPUABI.c_str ());
	return 1;
}

//----------------------------------------------------------------//
/**	@name	getDevBrand
	@text	Returns the device brand

	@out	string brand
*/
int MOAIEnvironment::_getDevBrand ( lua_State* L  ) {

	lua_pushstring ( L, MOAIEnvironment::Get ().mDevBrand.c_str ());
	return 1;
}

//----------------------------------------------------------------//
/**	@name	getDevName
	@text	Returns the device name

	@out	string name
*/
int MOAIEnvironment::_getDevName ( lua_State* L  ) {

	lua_pushstring ( L, MOAIEnvironment::Get ().mDevName.c_str ());
	return 1;
}

//----------------------------------------------------------------//
/**	@name	getDevManufacturer
	@text	Returns the device manufacturer

	@out	string manufacturer
*/
int MOAIEnvironment::_getDevManufacturer ( lua_State* L  ) {

	lua_pushstring ( L, MOAIEnvironment::Get ().mDevManufacturer.c_str ());
	return 1;
}

//----------------------------------------------------------------//
/**	@name	getDevModel
	@text	Returns the device model

	@out	string model
*/
int MOAIEnvironment::_getDevModel ( lua_State* L  ) {

	lua_pushstring ( L, MOAIEnvironment::Get ().mDevModel.c_str ());
	return 1;
}

//----------------------------------------------------------------//
/**	@name	getDevProduct
	@text	Returns the device design name

	@out	string product
*/
int MOAIEnvironment::_getDevProduct ( lua_State* L  ) {

	lua_pushstring ( L, MOAIEnvironment::Get ().mDevProduct.c_str ());
	return 1;
}

//----------------------------------------------------------------//
/**	@name	getOSBrand
	@text	Returns the operating system brand

	@out	string brand
*/
int MOAIEnvironment::_getOSBrand ( lua_State* L  ) {

	cc8* brandStr = MOAIEnvironment::Get ().mOSBrand.c_str ();
	u32 brand;
	if ( strcmp ( brandStr, "Android" ))
		brand = OS_BRAND_ANDROID;
	else if ( strcmp ( brandStr, "iOS" ))
		brand = OS_BRAND_IOS;
	else
		brand = OS_BRAND_UNAVAILABLE;

	lua_pushinteger ( L, brand );
	return 1;
}

//----------------------------------------------------------------//
/**	@name	getOSVersion
	@text	Returns the operating system version

	@out	string version
*/
int MOAIEnvironment::_getOSVersion ( lua_State* L  ) {

	lua_pushstring ( L, MOAIEnvironment::Get ().mOSVersion.c_str ());
	return 1;
}

//----------------------------------------------------------------//
/**	@name	_getUDID
	@text	Returns the device unique identifier

	@out	string UDID
*/
int MOAIEnvironment::_getUDID ( lua_State* L  ) {

	lua_pushstring ( L, MOAIEnvironment::Get ().mUDID.c_str ());
	return 1;
}

//----------------------------------------------------------------//
/**	@name	_getViewSize
	@text	Returns the width and height of the view
	
	@out	int width
	@out	int height
*/
int MOAIEnvironment::_getViewSize ( lua_State* L  ) {

	USGfxDevice& gfxDevice = USGfxDevice::Get ();
	
	lua_pushnumber ( L, gfxDevice.GetWidth ());
	lua_pushnumber ( L, gfxDevice.GetHeight ());
	
	return 2;
}

//================================================================//
// MOAIEnvironment
//================================================================//

//----------------------------------------------------------------//
MOAIEnvironment::MOAIEnvironment () :
	mAppDisplayName ( "UNKNOWN" ),
	mAppID ( "UNKNOWN" ),
	mAppVersion ( "UNKNOWN" ),
	mCPUABI ( "UNKNOWN" ),
	mDevBrand ( "UNKNOWN" ),
	mDevName ( "UNKNOWN" ),
	mDevManufacturer ( "UNKNOWN" ),
	mDevModel ( "UNKNOWN" ),
	mDevProduct ( "UNKNOWN" ),
	mOSBrand ( "UNKNOWN" ),
	mOSVersion ( "UNKNOWN" ),
	mUDID ( "UNKNOWN" ) {

	RTTI_SINGLE ( USLuaObject )
}

//----------------------------------------------------------------//
MOAIEnvironment::~MOAIEnvironment () {
}

//----------------------------------------------------------------//
void MOAIEnvironment::RegisterLuaClass ( USLuaState& state ) {

	state.SetField ( -1, "CONNECTION_TYPE_NONE", ( u32 )CONNECTION_TYPE_NONE );
	state.SetField ( -1, "CONNECTION_TYPE_WIFI", ( u32 )CONNECTION_TYPE_WIFI );
	state.SetField ( -1, "CONNECTION_TYPE_WWAN", ( u32 )CONNECTION_TYPE_WWAN );
	
	state.SetField ( -1, "OS_BRAND_ANDROID", ( u32 )OS_BRAND_ANDROID );
	state.SetField ( -1, "OS_BRAND_IOS", ( u32 )OS_BRAND_IOS );
	state.SetField ( -1, "OS_BRAND_UNAVAILABLE", ( u32 )OS_BRAND_UNAVAILABLE );

	luaL_Reg regTable [] = {
		{ "generateGUID",			_generateGUID		 },
		{ "getAppDisplayName",		_getAppDisplayName	 },
		{ "getAppID",				_getAppID			 },
		{ "getAppVersion",			_getAppVersion		 },
		{ "getConnectionType",		_getConnectionType 	 },
		{ "getCPUABI",				_getCPUABI			 },
		{ "getDevBrand",			_getDevBrand		 },
		{ "getDevName",				_getDevName			 },
		{ "getDevManufacturer",		_getDevManufacturer	 },
		{ "getDevModel",			_getDevModel		 },
		{ "getDevProduct",			_getDevProduct		 },
		{ "getOSBrand",				_getOSBrand			 },
		{ "getOSVersion",			_getOSVersion		 },
		{ "getUDID",				_getUDID			 },
		{ "getViewSize",			_getViewSize		 },
		{ NULL, NULL }
	};

	luaL_register( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetAppDisplayName ( cc8* appName ) {
	mAppDisplayName = appName;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetAppID ( cc8* appID ) {
	mAppID = appID;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetAppVersion ( cc8* appVer ) {
	mAppVersion = appVer;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetConnectivityFunc ( long (*connFunc)(void) ) {
	getConnectivityFunc = connFunc;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetCPUABI ( cc8* abi ) {
	mCPUABI = abi;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetDevBrand( cc8* devBrand ) {
	mDevBrand = devBrand;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetDevName ( cc8* devName ) {
	mDevName = devName;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetDevManufacturer ( cc8* devMan ) {
	mDevManufacturer = devMan;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetDevModel ( cc8* devModel ) {
	mDevModel = devModel;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetDevProduct ( cc8* devProduct ) {
	mDevProduct = devProduct;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetGUIDFunc ( cc8* (*guidFunc)(void) ) {
	getGUIDfunc = guidFunc;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetHeightFunc ( int (*heightFunc)(void) ) {
	getHeightFunc = heightFunc;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetOSBrand ( cc8* osBrand ) {
	mOSBrand = osBrand;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetOSVersion ( cc8* osVer ) {
	mOSVersion = osVer;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetUDID ( cc8* udid ) {
	mUDID = udid;
}

//----------------------------------------------------------------//
void MOAIEnvironment::SetWidthFunc ( int (*widthFunc)(void) ) {
	getWidthFunc = widthFunc;
}

//----------------------------------------------------------------//
STLString MOAIEnvironment::ToString () {

	STLString info = "";
	info += mAppDisplayName += "\n";
	info += mAppID += "\n";
	info += mAppVersion += "\n";
	info += mCPUABI += "\n";
	info += mDevBrand += "\n";
	info += mDevName += "\n";
	info += mDevManufacturer += "\n";
	info += mDevModel += "\n";
	info += mDevProduct += "\n";
	info += mOSBrand += "\n";
	info += mOSVersion += "\n";
	info += mUDID += "\n";

	return info;
}