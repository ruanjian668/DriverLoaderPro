#pragma once
#include <string>

#include <windows.h>
#include <Winternl.h>
#include <Shlwapi.h>

#include <QMessageBox>

#include "CGLIB_String_Text.hpp"

class Driver_Load
{
public:
	Driver_Load() = default;
	~Driver_Load() = default;
private:
	bool Get_Driver_Handle();
public:
	bool Init(std::string Driver_Path);
	bool Register_Driver();
	bool Start_Driver();
	bool Stop_Driver();
	bool UnRegister_Driver();
public:
	bool Minifilter_Register_Driver();
public:
	bool Nt_Register_Driver();
	bool Nt_Start_Driver();
	bool Nt_Stop_Driver();
	bool Nt_UnRegister_Driver();
private:
	bool Enable_Debug();
public:
	unsigned long _Last_Error = 0;
private:
	std::string _Driver_Name;
	std::string _Driver_Path;
	std::string _Driver_Ext;
	SC_HANDLE _Drive_Handle = 0;
	SC_HANDLE _Server_Handle = 0;
	int Sys_File = 0;
private:
	typedef NTSTATUS(NTAPI *_NtLoadDriver)(IN PUNICODE_STRING DriverServiceName);
	typedef NTSTATUS(NTAPI *_NtUnLoadDriver)(IN PUNICODE_STRING DriverServiceName);
};

