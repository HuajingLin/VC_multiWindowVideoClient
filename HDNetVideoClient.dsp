# Microsoft Developer Studio Project File - Name="HDNetVideoClient" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=HDNetVideoClient - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "HDNetVideoClient.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "HDNetVideoClient.mak" CFG="HDNetVideoClient - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "HDNetVideoClient - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "HDNetVideoClient - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "HDNetVideoClient - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "HDNetVideoClient - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ..\HDNetVideoCentre\Debug\HDNetVideoCentre.lib /nologo /subsystem:windows /debug /machine:I386 /out:"..\Debug\HDNetVideoClient.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "HDNetVideoClient - Win32 Release"
# Name "HDNetVideoClient - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BackgroundPic.cpp
# End Source File
# Begin Source File

SOURCE=.\BmpButton.cpp
# End Source File
# Begin Source File

SOURCE=.\ControlButton.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgLogin.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMCDAddArea.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMCDAddEncoder.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMCDeviceConfig.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMCDModiChannel.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMCLocalConfig.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMCUserConfig.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMMLDeviceGroup.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMMLDeviceTree.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMMLeftDevices.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMMLeftOperate.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMMLeftPlay.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMMLOperateCruise.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMMLOperatePreset.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMMLOperatePtz.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMMLOperateVParam.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMMonitorLeft.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMMonitorRight.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMMRightList.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgMMRightTool.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgModifyPwd.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgModuleConfig.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgModuleMonitor.cpp
# End Source File
# Begin Source File

SOURCE=.\DragDropTreeCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\HDNetVideoClient.cpp
# End Source File
# Begin Source File

SOURCE=.\HDNetVideoClient.rc
# End Source File
# Begin Source File

SOURCE=.\HDNetVideoClientDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MultiWindow.cpp
# End Source File
# Begin Source File

SOURCE=.\MySliderControl.cpp
# End Source File
# Begin Source File

SOURCE=.\StateButton.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TabButton.cpp
# End Source File
# Begin Source File

SOURCE=.\tinystr.cpp
# End Source File
# Begin Source File

SOURCE=.\tinyxml.cpp
# End Source File
# Begin Source File

SOURCE=.\tinyxmlerror.cpp
# End Source File
# Begin Source File

SOURCE=.\tinyxmlparser.cpp
# End Source File
# Begin Source File

SOURCE=.\TreeDroptarget.cpp
# End Source File
# Begin Source File

SOURCE=.\VideoImage.cpp
# End Source File
# Begin Source File

SOURCE=.\VideoTitle.cpp
# End Source File
# Begin Source File

SOURCE=.\VideoWin.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DlgLogin.h
# End Source File
# Begin Source File

SOURCE=.\DlgMCDAddArea.h
# End Source File
# Begin Source File

SOURCE=.\DlgMCDAddEncoder.h
# End Source File
# Begin Source File

SOURCE=.\DlgMCDeviceConfig.h
# End Source File
# Begin Source File

SOURCE=.\DlgMCDModiChannel.h
# End Source File
# Begin Source File

SOURCE=.\DlgMCLocalConfig.h
# End Source File
# Begin Source File

SOURCE=.\DlgMCUserConfig.h
# End Source File
# Begin Source File

SOURCE=.\DlgMMLDeviceGroup.h
# End Source File
# Begin Source File

SOURCE=.\DlgMMLDeviceTree.h
# End Source File
# Begin Source File

SOURCE=.\DlgMMLeftDevices.h
# End Source File
# Begin Source File

SOURCE=.\DlgMMLeftOperate.h
# End Source File
# Begin Source File

SOURCE=.\DlgMMLeftPlay.h
# End Source File
# Begin Source File

SOURCE=.\DlgMMLOperateCruise.h
# End Source File
# Begin Source File

SOURCE=.\DlgMMLOperatePreset.h
# End Source File
# Begin Source File

SOURCE=.\DlgMMLOperatePtz.h
# End Source File
# Begin Source File

SOURCE=.\DlgMMLOperateVParam.h
# End Source File
# Begin Source File

SOURCE=.\DlgMMonitorLeft.h
# End Source File
# Begin Source File

SOURCE=.\DlgMMonitorRight.h
# End Source File
# Begin Source File

SOURCE=.\DlgMMRightList.h
# End Source File
# Begin Source File

SOURCE=.\DlgMMRightTool.h
# End Source File
# Begin Source File

SOURCE=.\DlgModifyPwd.h
# End Source File
# Begin Source File

SOURCE=.\DlgModuleConfig.h
# End Source File
# Begin Source File

SOURCE=.\DlgModuleMonitor.h
# End Source File
# Begin Source File

SOURCE=.\HDNetVideoClient.h
# End Source File
# Begin Source File

SOURCE=.\HDNetVideoClientDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\01PANE.bmp
# End Source File
# Begin Source File

SOURCE=.\res\01PANE_D.bmp
# End Source File
# Begin Source File

SOURCE=.\res\01PANE_O.bmp
# End Source File
# Begin Source File

SOURCE=.\res\04PANE.bmp
# End Source File
# Begin Source File

SOURCE=.\res\04PANE_D.bmp
# End Source File
# Begin Source File

SOURCE=.\res\04PANE_O.bmp
# End Source File
# Begin Source File

SOURCE=.\res\06PANE.bmp
# End Source File
# Begin Source File

SOURCE=.\res\06PANE_D.bmp
# End Source File
# Begin Source File

SOURCE=.\res\06PANE_O.bmp
# End Source File
# Begin Source File

SOURCE=.\res\09PANE.bmp
# End Source File
# Begin Source File

SOURCE=.\res\09PANE_D.bmp
# End Source File
# Begin Source File

SOURCE=.\res\09PANE_O.bmp
# End Source File
# Begin Source File

SOURCE=.\res\10PANE.bmp
# End Source File
# Begin Source File

SOURCE=.\res\10PANE_D.bmp
# End Source File
# Begin Source File

SOURCE=.\res\10PANE_O.bmp
# End Source File
# Begin Source File

SOURCE=.\res\13PANE.bmp
# End Source File
# Begin Source File

SOURCE=.\res\13PANE_D.bmp
# End Source File
# Begin Source File

SOURCE=.\res\13PANE_O.bmp
# End Source File
# Begin Source File

SOURCE=.\res\16PANE.bmp
# End Source File
# Begin Source File

SOURCE=.\res\16PANE_D.bmp
# End Source File
# Begin Source File

SOURCE=.\res\16PANE_O.bmp
# End Source File
# Begin Source File

SOURCE=.\res\36PANE.bmp
# End Source File
# Begin Source File

SOURCE=.\res\36PANE_D.bmp
# End Source File
# Begin Source File

SOURCE=.\res\36PANE_O.bmp
# End Source File
# Begin Source File

SOURCE=.\res\3DPos1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\3DPos2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\3DPos3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\3DPos4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\64PANE.bmp
# End Source File
# Begin Source File

SOURCE=.\res\64PANE_D.bmp
# End Source File
# Begin Source File

SOURCE=.\res\64PANE_O.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ApertureBig1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ApertureBig2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ApertureBig3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ApertureBig4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ApertureSmall1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ApertureSmall2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ApertureSmall3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ApertureSmall4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnConfig1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnConfig2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnConfig3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnConfigEn1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnConfigEn2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnConfigEn3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnLog1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnLog2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnLog3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnLogEn1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnLogEn2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnLogEn3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnMonitor1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnMonitor2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnMonitor3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnMonitorEn1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnMonitorEn2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btnMonitorEn3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CallPreset1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CallPreset2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CallPreset3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Capture1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Capture2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Capture3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CloseVideo1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CloseVideo2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CruiseStop1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CruiseStop2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CruiseStop3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\DefaultValue1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\DefaultValue2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\DefaultValue3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\DelPreset1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\DelPreset2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\DelPreset3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Down1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Down2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Down3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Down4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\DownLeft1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\DownLeft2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\DownLeft3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\DownLeft4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FocalBack1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FocalBack2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FocalBack3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FocalBack4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FocalFront1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FocalFront2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FocalFront3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FocalFront4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Fullscreen.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Fullscreen_D.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Fullscreen_O.bmp
# End Source File
# Begin Source File

SOURCE=.\res\HDNetVideoClient.ico
# End Source File
# Begin Source File

SOURCE=.\res\HDNetVideoClient.rc2
# End Source File
# Begin Source File

SOURCE=.\res\Left1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Left2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Left3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Left4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LeftRight1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LeftRight2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LeftRight3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LeftRight4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LeftUP1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LeftUP2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LeftUP3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LeftUP4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Light1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Light2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Light3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Light4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\MWinTopBack.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Next.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Next_D.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Next_O.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Play1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Play2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Play3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Previous.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Previous_D.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Previous_O.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Record1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Record2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Record3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Right1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Right2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Right3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Right4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\RightDown1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\RightDown2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\RightDown3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\RightDown4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\SetPreset1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\SetPreset2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\SetPreset3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sound1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sound2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sound3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Stop1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Stop2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Stop3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\StopAll1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\StopAll2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\StopAll3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tabBack11.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tabBack12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tabBack13.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tabBack21.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tabBack22.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Talk1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Talk2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Talk3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\top_bar_back.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Up1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Up2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Up3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Up4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\UpRight1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\UpRight2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\UpRight3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\UpRight4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\VParamTitle.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Wiper1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Wiper2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Wiper3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Wiper4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ZoomIn1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ZoomIn2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ZoomIn3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ZoomIn4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ZoomOut1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ZoomOut2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ZoomOut3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ZoomOut4.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
