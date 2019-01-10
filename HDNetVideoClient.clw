; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgMMRightList
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "HDNetVideoClient.h"

ClassCount=22
Class1=CHDNetVideoClientApp
Class2=CHDNetVideoClientDlg

ResourceCount=26
Resource2=IDD_MMR_LIST
Resource3=IDD_MCD_ADD_AREA
Resource4=IDD_MMLD_GROUP
Resource5=IDD_MML_PLAY
Resource6=IDD_MCD_MODIFY_CAMERA
Resource7=IDD_MODI_PWD
Resource8=IDD_LOGIN
Resource9=IDD_MMLO_CRUISE
Resource10=IDD_MC_LOCAL
Resource11=IDD_MML_OPERATE
Resource12=IDD_MM_RIGHT
Resource13=IDD_MMLO_PTZ
Resource14=IDD_MMR_TOOL
Resource15=IDD_MCD_ADD_ENCODER
Resource16=IDD_HDNETVIDEOCLIENT_DIALOG
Resource17=IDD_MC_DEVICE
Resource1=IDR_MAINFRAME
Class3=CDlgLogin
Class4=CDlgMMonitorLeft
Class5=CDlgMMonitorRight
Class6=CDlgMMLeftDevices
Class7=CDlgMMLeftOperate
Class8=CDlgMMLDeviceTree
Class9=CDlgMMLDeviceGroup
Class10=CDlgMMLOperatePtz
Class11=CDlgMMLOperatePreset
Class12=CDlgMMLOperateCruise
Class13=CDlgMMLOperateVParam
Class14=CDlgMMRightTool
Class15=CDlgMMRightList
Resource18=IDD_MMLO_VIDEO_PARAM
Resource19=IDD_MMLD_TREE
Class16=CDlgMCDeviceConfig
Resource20=IDD_MM_LEFT
Class17=CDlgMCUserConfig
Resource21=IDD_MODULE_CONFIG
Class18=CDlgMCLocalConfig
Resource22=IDD_MML_DEVICES
Class19=CDlgMCDAddArea
Resource23=IDD_MC_USER
Class20=CDlgMCDAddEncoder
Resource24=IDD_MMLO_PRESET
Class21=CDlgMCDModiChannel
Resource25=IDD_MODULE_MONITOR
Class22=CDlgMMLeftPlay
Resource26=IDR_MENU_CONF_DEVI

[CLS:CHDNetVideoClientApp]
Type=0
HeaderFile=HDNetVideoClient.h
ImplementationFile=HDNetVideoClient.cpp
Filter=N

[CLS:CHDNetVideoClientDlg]
Type=0
HeaderFile=HDNetVideoClientDlg.h
ImplementationFile=HDNetVideoClientDlg.cpp
Filter=D
LastObject=CHDNetVideoClientDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_HDNETVIDEOCLIENT_DIALOG]
Type=1
Class=CHDNetVideoClientDlg
ControlCount=9
Control1=IDC_LBL_TOOL_BAR,static,1342308352
Control2=IDC_BTN_MONITOR,button,1342242816
Control3=IDC_BTN_CONFIG,button,1342242816
Control4=IDC_BTN_LOG,button,1342242816
Control5=IDC_BTN_PLAYBACK,button,1073807360
Control6=IDC_BTN_MAP,button,1073807360
Control7=IDC_BTN_HELP,button,1073807360
Control8=IDC_STATIC_VERSION,static,1342308352
Control9=IDC_STATIC_USER,static,1342308352

[DLG:IDD_LOGIN]
Type=1
Class=CDlgLogin
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC_USER,static,1342308352
Control4=IDC_STATIC_PASSWORD,static,1342308352
Control5=IDC_COMBO_USER,combobox,1344340226
Control6=IDC_EDIT_PWD,edit,1350631584
Control7=IDC_BTN_MODIFY,button,1342242816
Control8=IDC_STATIC_LANGUAGE,static,1342308352
Control9=IDC_CHECK_LOGIN,button,1342242819
Control10=IDC_RADIO_CN,button,1342177289
Control11=IDC_RADIO_EN,button,1342177289
Control12=IDC_STATIC_INFO,static,1342308363

[DLG:IDD_MODI_PWD]
Type=1
Class=?
ControlCount=8
Control1=IDC_STATIC_OLD,static,1342308352
Control2=IDC_EDIT_OLD,edit,1350631584
Control3=IDC_STATIC_NEW,static,1342308352
Control4=IDC_EDIT_NEW,edit,1350631584
Control5=IDC_STATIC_NEW2,static,1342308352
Control6=IDC_EDIT_NEW2,edit,1350631584
Control7=IDC_BTN_OK,button,1342242816
Control8=IDC_STATIC,button,1342177287

[DLG:IDD_MODULE_CONFIG]
Type=1
Class=?
ControlCount=3
Control1=IDC_BTN_CONFIG_DEVI,button,1342242816
Control2=IDC_BTN_CONFIG_LOCAL,button,1342242816
Control3=IDC_BTN_CONFIG_USER,button,1342242816

[DLG:IDD_MODULE_MONITOR]
Type=1
Class=?
ControlCount=0

[DLG:IDD_MM_LEFT]
Type=1
Class=CDlgMMonitorLeft
ControlCount=0

[DLG:IDD_MML_DEVICES]
Type=1
Class=CDlgMMLeftDevices
ControlCount=2
Control1=IDC_BTN_LIST,button,1342242816
Control2=IDC_BTN_GROUP,button,1342242816

[DLG:IDD_MML_OPERATE]
Type=1
Class=CDlgMMLeftOperate
ControlCount=4
Control1=IDC_BTN_PTZ,button,1342242816
Control2=IDC_BTN_PRESET,button,1342242816
Control3=IDC_BTN_CRUISE,button,1342242816
Control4=IDC_BTN_VPARAM,button,1342242816

[DLG:IDD_MMLD_GROUP]
Type=1
Class=CDlgMMLDeviceGroup
ControlCount=1
Control1=IDC_TREE_DEVICE,SysTreeView32,1350631431

[DLG:IDD_MMLO_CRUISE]
Type=1
Class=CDlgMMLOperateCruise
ControlCount=4
Control1=IDC_BTN_STOP_CRUI,button,1342242816
Control2=IDC_BTN_START,button,1342242816
Control3=IDC_LIST_CRUISE,SysListView32,1350631425
Control4=IDC_BTN_SET_CRUISE,button,1342242816

[DLG:IDD_MMLO_PRESET]
Type=1
Class=CDlgMMLOperatePreset
ControlCount=4
Control1=IDC_BTN_PRESET_SET,button,1342242816
Control2=IDC_BTN_PRESET_CALL,button,1342242816
Control3=IDC_LIST_PRESET,SysListView32,1350631429
Control4=IDC_BTN_PRESET_DEL,button,1342242816

[DLG:IDD_MMLO_PTZ]
Type=1
Class=CDlgMMLOperatePtz
ControlCount=21
Control1=IDC_STATIC,button,1342177287
Control2=IDC_BTN_LEFTUP,button,1342242816
Control3=IDC_BTN_UP,button,1342242816
Control4=IDC_BTN_UPRIGHT,button,1342242816
Control5=IDC_BTN_LEFT,button,1342242816
Control6=IDC_BTN_LEFTRIGHT,button,1342242816
Control7=IDC_BTN_RIGHT,button,1342242816
Control8=IDC_BTN_LEFTDOWN,button,1342242816
Control9=IDC_BTN_DOWN,button,1342242816
Control10=IDC_BTN_RIGHTDOWN,button,1342242816
Control11=IDC_BTN_ZOOM1,button,1342242816
Control12=IDC_BTN_ZOOM2,button,1342242816
Control13=IDC_BTN_FOCAL1,button,1342242816
Control14=IDC_BTN_FOCAL2,button,1342242816
Control15=IDC_BTN_APERT1,button,1342242816
Control16=IDC_BTN_APERT2,button,1342242816
Control17=IDC_SLIDER_PTZ,msctls_trackbar32,1342242817
Control18=IDC_BTN_3D,button,1342242816
Control19=IDC_BTN_LIGHT,button,1342242816
Control20=IDC_BTN_WIPER,button,1342242816
Control21=IDC_STATIC_VALUE,static,1342308352

[DLG:IDD_MMLO_VIDEO_PARAM]
Type=1
Class=CDlgMMLOperateVParam
ControlCount=12
Control1=IDC_BTN_DEFAULT,button,1342242816
Control2=IDC_SLIDER_BRIGHT,msctls_trackbar32,1342242817
Control3=IDC_SLIDER_CONTRAST,msctls_trackbar32,1342242817
Control4=IDC_SLIDER_SATURAT,msctls_trackbar32,1342242817
Control5=IDC_SLIDER_SHARP,msctls_trackbar32,1342242817
Control6=IDC_SLIDER_SOUND,msctls_trackbar32,1342242817
Control7=IDC_STATIC_BRIGHT,static,1342308352
Control8=IDC_STATIC_CONTRAST,static,1342308352
Control9=IDC_STATIC_SATURAT,static,1342308352
Control10=IDC_STATIC_SHARP,static,1342308352
Control11=IDC_STATIC_SOUND,static,1342308352
Control12=IDC_STATIC_BACK,static,1342308352

[DLG:IDD_MM_RIGHT]
Type=1
Class=CDlgMMonitorRight
ControlCount=0

[DLG:IDD_MMR_LIST]
Type=1
Class=CDlgMMRightList
ControlCount=1
Control1=IDC_LIST_ALARM,SysListView32,1350631424

[DLG:IDD_MMLD_TREE]
Type=1
Class=CDlgMMLDeviceTree
ControlCount=1
Control1=IDC_TREE_DEVICE,SysTreeView32,1350631431

[DLG:IDD_MMR_TOOL]
Type=1
Class=CDlgMMRightTool
ControlCount=12
Control1=IDC_BTN_PANE1,button,1342242816
Control2=IDC_BTN_PANE4,button,1342242816
Control3=IDC_BTN_PANE6,button,1342242816
Control4=IDC_BTN_PANE9,button,1342242816
Control5=IDC_BTN_PANE10,button,1342242816
Control6=IDC_BTN_PANE13,button,1342242816
Control7=IDC_BTN_PANE16,button,1342242816
Control8=IDC_BTN_PANE36,button,1342242816
Control9=IDC_BTN_PANE64,button,1342242816
Control10=IDC_BTN_FULLSCREEN,button,1342242816
Control11=IDC_BTN_PREVI,button,1342242816
Control12=IDC_BTN_NEXT,button,1342242816

[CLS:CDlgLogin]
Type=0
HeaderFile=DlgLogin.h
ImplementationFile=DlgLogin.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgLogin
VirtualFilter=dWC

[CLS:CDlgMMonitorLeft]
Type=0
HeaderFile=DlgMMonitorLeft.h
ImplementationFile=DlgMMonitorLeft.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgMMonitorLeft
VirtualFilter=dWC

[CLS:CDlgMMonitorRight]
Type=0
HeaderFile=DlgMMonitorRight.h
ImplementationFile=DlgMMonitorRight.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgMMonitorRight
VirtualFilter=dWC

[CLS:CDlgMMLeftDevices]
Type=0
HeaderFile=DlgMMLeftDevices.h
ImplementationFile=DlgMMLeftDevices.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BTN_GROUP
VirtualFilter=dWC

[CLS:CDlgMMLeftOperate]
Type=0
HeaderFile=DlgMMLeftOperate.h
ImplementationFile=DlgMMLeftOperate.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgMMLeftOperate
VirtualFilter=dWC

[CLS:CDlgMMLDeviceTree]
Type=0
HeaderFile=DlgMMLDeviceTree.h
ImplementationFile=DlgMMLDeviceTree.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_TREE_DEVICE
VirtualFilter=dWC

[CLS:CDlgMMLDeviceGroup]
Type=0
HeaderFile=DlgMMLDeviceGroup.h
ImplementationFile=DlgMMLDeviceGroup.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgMMLDeviceGroup
VirtualFilter=dWC

[CLS:CDlgMMLOperatePtz]
Type=0
HeaderFile=DlgMMLOperatePtz.h
ImplementationFile=DlgMMLOperatePtz.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_SLIDER_PTZ

[CLS:CDlgMMLOperatePreset]
Type=0
HeaderFile=DlgMMLOperatePreset.h
ImplementationFile=DlgMMLOperatePreset.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CDlgMMLOperateCruise]
Type=0
HeaderFile=DlgMMLOperateCruise.h
ImplementationFile=DlgMMLOperateCruise.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LIST_CRUISE

[CLS:CDlgMMLOperateVParam]
Type=0
HeaderFile=DlgMMLOperateVParam.h
ImplementationFile=DlgMMLOperateVParam.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CDlgMMRightTool]
Type=0
HeaderFile=DlgMMRightTool.h
ImplementationFile=DlgMMRightTool.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_STATIC_BACK

[CLS:CDlgMMRightList]
Type=0
HeaderFile=DlgMMRightList.h
ImplementationFile=DlgMMRightList.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgMMRightList
VirtualFilter=dWC

[DLG:IDD_MC_DEVICE]
Type=1
Class=CDlgMCDeviceConfig
ControlCount=2
Control1=IDC_STATIC_INFO,static,1342308352
Control2=IDC_TREE_DEVICE,SysTreeView32,1350631431

[MNU:IDR_MENU_CONF_DEVI]
Type=1
Class=CDlgMCDeviceConfig
Command1=IDM_CD_ADD_AREA
Command2=IDM_CD_ADD_DEVICE
Command3=IDM_CD_DEL_NODE
CommandCount=3

[CLS:CDlgMCDeviceConfig]
Type=0
HeaderFile=DlgMCDeviceConfig.h
ImplementationFile=DlgMCDeviceConfig.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_TREE_DEVICE
VirtualFilter=dWC

[DLG:IDD_MC_USER]
Type=1
Class=CDlgMCUserConfig
ControlCount=4
Control1=IDC_BTN_ADD_USER,button,1342242816
Control2=IDC_BTN_MODI_USER,button,1342242816
Control3=IDC_BTN_DEL_USER,button,1342242816
Control4=IDC_LIST1,SysListView32,1350631424

[CLS:CDlgMCUserConfig]
Type=0
HeaderFile=DlgMCUserConfig.h
ImplementationFile=DlgMCUserConfig.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgMCUserConfig

[DLG:IDD_MC_LOCAL]
Type=1
Class=CDlgMCLocalConfig
ControlCount=3
Control1=IDC_BTN_ADD_USER,button,1342242816
Control2=IDC_BTN_MODI_USER,button,1342242816
Control3=IDC_BTN_DEL_USER,button,1342242816

[CLS:CDlgMCLocalConfig]
Type=0
HeaderFile=DlgMCLocalConfig.h
ImplementationFile=DlgMCLocalConfig.cpp
BaseClass=CDialog
Filter=D
LastObject=IDM_ADD_DEVICE

[DLG:IDD_MCD_ADD_AREA]
Type=1
Class=CDlgMCDAddArea
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC_TITLE,button,1342177287
Control4=IDC_STATIC_NAME,static,1342308352
Control5=IDC_EDIT_NAME,edit,1350631552
Control6=IDC_STATIC_UPNAME,static,1342308352
Control7=IDC_EDIT_UP_NAME,edit,1350633600

[CLS:CDlgMCDAddArea]
Type=0
HeaderFile=DlgMCDAddArea.h
ImplementationFile=DlgMCDAddArea.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgMCDAddArea

[DLG:IDD_MCD_ADD_ENCODER]
Type=1
Class=CDlgMCDAddEncoder
ControlCount=26
Control1=IDC_EDIT_NAME,edit,1350631552
Control2=IDC_COMBO_MODE,combobox,1344339971
Control3=IDC_IPADDRESS_DEVICE,SysIPAddress32,1342242816
Control4=IDC_EDIT_PORT,edit,1350631552
Control5=IDC_EDIT_USER,edit,1350631552
Control6=IDC_EDIT_PWD,edit,1350631552
Control7=IDC_EDIT_CHANNEL,edit,1350631552
Control8=IDC_EDIT_AREA,edit,1350633600
Control9=IDC_IPADDRESS_DNS,SysIPAddress32,1342242816
Control10=IDC_IPADDRESS_MULTICAST,SysIPAddress32,1342242816
Control11=IDC_EDIT_ID,edit,1350631552
Control12=IDC_SEARCH,button,1342242816
Control13=IDOK,button,1342242817
Control14=IDCANCEL,button,1342242816
Control15=IDC_STATIC_TITLE,button,1342177287
Control16=IDC_STATIC_NAME,static,1342308352
Control17=IDC_STATIC_IP,static,1342308352
Control18=IDC_STATIC_PORT,static,1342308352
Control19=IDC_STATIC_IPMODE,static,1342308352
Control20=IDC_STATIC_USER,static,1342308352
Control21=IDC_STATIC_PWD,static,1342308352
Control22=IDC_STATIC_CHANNEL,static,1342308352
Control23=IDC_STATIC_AREA,static,1342308352
Control24=IDC_STATIC_ID,static,1342308352
Control25=IDC_STATIC_DNS,static,1342308352
Control26=IDC_STATIC_MULTICAST,static,1342308352

[CLS:CDlgMCDAddEncoder]
Type=0
HeaderFile=DlgMCDAddEncoder.h
ImplementationFile=DlgMCDAddEncoder.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgMCDAddEncoder
VirtualFilter=dWC

[DLG:IDD_MCD_MODIFY_CAMERA]
Type=1
Class=CDlgMCDModiChannel
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TITLE,button,1342177287
Control4=IDC_STATIC_NAME,static,1342308352
Control5=IDC_EDIT_NAME,edit,1350631552
Control6=IDC_STATIC_NO,static,1342308352
Control7=IDC_EDIT_NO,edit,1350633600
Control8=IDC_STATIC_DEVI_NAME,static,1342308352
Control9=IDC_EDIT_DEVI_NAME,edit,1350633600
Control10=IDC_STATIC_DEVI_IP,static,1342308352
Control11=IDC_EDIT_DEVI_IP,edit,1350633600
Control12=IDC_STATIC_STREAM,static,1342308352
Control13=IDC_COMBO_STREAM,combobox,1344339971

[CLS:CDlgMCDModiChannel]
Type=0
HeaderFile=DlgMCDModiChannel.h
ImplementationFile=DlgMCDModiChannel.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgMCDModiChannel
VirtualFilter=dWC

[DLG:IDD_MML_PLAY]
Type=1
Class=CDlgMMLeftPlay
ControlCount=8
Control1=IDC_BTN_PLAY,button,1342242816
Control2=IDC_BTN_RECORD,button,1342242816
Control3=IDC_BTN_CAPTURE,button,1342242816
Control4=IDC_BTN_SOUND,button,1342242816
Control5=IDC_BTN_TALK,button,1342242816
Control6=IDC_BTN_STOP,button,1342242816
Control7=IDC_BTN_STOPALL,button,1342242816
Control8=IDC_STATIC,button,1342177287

[CLS:CDlgMMLeftPlay]
Type=0
HeaderFile=DlgMMLeftPlay.h
ImplementationFile=DlgMMLeftPlay.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgMMLeftPlay
VirtualFilter=dWC

