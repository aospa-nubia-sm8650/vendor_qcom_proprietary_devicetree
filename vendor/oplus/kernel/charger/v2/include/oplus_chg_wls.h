// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (C) 2020-2020 Oplus. All rights reserved.
 */

#ifndef __OPLUS_CHG_WLS_H__
#define __OPLUS_CHG_WLS_H__

#include <linux/completion.h>
#include <linux/mutex.h>
#include <linux/device.h>

/*#define WLS_QI_DEBUG*/
/*#define PM_REG_DEBUG*/

#define WLS_SUPPORT_OPLUS_CHG
#define OPLUS_CHG_DEBUG

#define OPLUS_CHG_WLS_AUTH_ENABLE

#define WLS_TRX_STATUS_READY		BIT(0)
#define WLS_TRX_STATUS_DIGITALPING	BIT(1)
#define WLS_TRX_STATUS_ANALOGPING	BIT(2)
#define WLS_TRX_STATUS_TRANSFER		BIT(3)

#define WLS_TRX_ERR_RXAC		BIT(0)
#define WLS_TRX_ERR_OCP			BIT(1)
#define WLS_TRX_ERR_OVP			BIT(2)
#define WLS_TRX_ERR_LVP			BIT(3)
#define WLS_TRX_ERR_FOD			BIT(4)
#define WLS_TRX_ERR_OTP			BIT(5)
#define WLS_TRX_ERR_CEPTIMEOUT		BIT(6)
#define WLS_TRX_ERR_RXEPT		BIT(7)
#define WLS_TRX_ERR_DEBUG_INFO_MASK	0x7f

#define WLS_CMD_INDENTIFY_ADAPTER	0xA1
#define WLS_CMD_INTO_FASTCHAGE		0xA2
#define WLS_CMD_GET_VENDOR_ID		0xA3
#define WLS_CMD_GET_EXTERN_CMD		0xA4
#define WLS_CMD_SET_NORMAL_MODE		0xA5
#define WLS_CMD_SET_QUIET_MODE		0xA6
#define WLS_CMD_SET_LED_BRIGHTNESS	0xAC
#define WLS_CMD_SET_CEP_TIMEOUT		0xAD
#define WLS_CMD_SET_FAN_SPEED		0xAE
#define WLS_CMD_GET_ENCRYPT_DATA1	0xB1
#define WLS_CMD_GET_ENCRYPT_DATA2	0xB2
#define WLS_CMD_GET_ENCRYPT_DATA3	0xB3
#define WLS_CMD_GET_ENCRYPT_DATA4	0xB4
#define WLS_CMD_GET_ENCRYPT_DATA5	0xB5
#define WLS_CMD_GET_ENCRYPT_DATA6	0xB6

#define WLS_CMD_GET_PRODUCT_ID		0xC4
#define WLS_CMD_SEND_BATT_TEMP_SOC	0xC5

#define WLS_CMD_SET_AES_DATA1		0xD1
#define WLS_CMD_SET_AES_DATA2		0xD2
#define WLS_CMD_SET_AES_DATA3		0xD3
#define WLS_CMD_SET_AES_DATA4		0xD4
#define WLS_CMD_SET_AES_DATA5		0xD5
#define WLS_CMD_SET_AES_DATA6		0xD6
#define WLS_CMD_GET_AES_DATA1		0xD7
#define WLS_CMD_GET_AES_DATA2		0xD8
#define WLS_CMD_GET_AES_DATA3		0xD9
#define WLS_CMD_GET_AES_DATA4		0xDA
#define WLS_CMD_GET_AES_DATA5		0xDB
#define WLS_CMD_GET_AES_DATA6		0xDC

#define WLS_CMD_GET_TX_ID		0x05
#define WLS_CMD_GET_TX_PWR		0x4A

#define WLS_MSG_TYPE_EXTENDED_MSG	0x5F
#define WLS_MSG_TYPE_STANDARD_MSG	0x4F

#define WLS_RESPONE_PRODUCT_ID		0x84
#define WLS_RESPONE_BATT_TEMP_SOC	0x85

#define WLS_RESPONE_ADAPTER_TYPE	0xF1
#define WLS_RESPONE_INTO_FASTCHAGE	0xF2
#define WLS_RESPONE_VENDOR_ID		0xF3
#define WLS_RESPONE_EXTERN_CMD		0xF4
#define WLS_RESPONE_INTO_NORMAL_MODE	0xF5
#define WLS_RESPONE_INTO_QUIET_MODE	0xF6
#define WLS_RESPONE_LED_BRIGHTNESS	0xFC
#define WLS_RESPONE_CEP_TIMEOUT		0xFD
#define WLS_RESPONE_FAN_SPEED		0xFE
#define WLS_RESPONE_READY_FOR_EPP	0xFA
#define WLS_RESPONE_WORKING_IN_EPP	0xFB
#define WLS_RESPONE_ENCRYPT_DATA1	0xE1
#define WLS_RESPONE_ENCRYPT_DATA2	0xE2
#define WLS_RESPONE_ENCRYPT_DATA3	0xE3
#define WLS_RESPONE_ENCRYPT_DATA4	0xE4
#define WLS_RESPONE_ENCRYPT_DATA5	0xE5
#define WLS_RESPONE_ENCRYPT_DATA6	0xE6
#define WLS_RESPONE_SET_AES_DATA1	0x91
#define WLS_RESPONE_SET_AES_DATA2	0x92
#define WLS_RESPONE_SET_AES_DATA3	0x93
#define WLS_RESPONE_SET_AES_DATA4	0x94
#define WLS_RESPONE_SET_AES_DATA5	0x95
#define WLS_RESPONE_SET_AES_DATA6	0x96
#define WLS_RESPONE_GET_AES_DATA1	0x97
#define WLS_RESPONE_GET_AES_DATA2	0x98
#define WLS_RESPONE_GET_AES_DATA3	0x99
#define WLS_RESPONE_GET_AES_DATA4	0x9A
#define WLS_RESPONE_GET_AES_DATA5	0x9B
#define WLS_RESPONE_GET_AES_DATA6	0x9C

#define WLS_ADAPTER_TYPE_MASK		0x07
#define WLS_ADAPTER_ID_MASK		0xF8
#define WLS_ADAPTER_POWER_MASK		0xF5
#define WLS_ADAPTER_TYPE_UNKNOWN	0x00
#define WLS_ADAPTER_TYPE_VOOC		0x01
#define WLS_ADAPTER_TYPE_SVOOC		0x02
#define WLS_ADAPTER_TYPE_USB		0x03
#define WLS_ADAPTER_TYPE_NORMAL		0x04
#define WLS_ADAPTER_TYPE_EPP		0x05
#define WLS_ADAPTER_TYPE_PD_65W		0x07

#define WLS_CHARGE_TYPE_DEFAULT		0x00
#define WLS_CHARGE_TYPE_FAST		0x01
#define WLS_CHARGE_TYPE_USB		0x02
#define WLS_CHARGE_TYPE_NORMAL		0x03
#define WLS_CHARGE_TYPE_EPP		0x04

#define WLS_TRX_MODE_VOL_MV		9500
#define WLS_FW_UPGRADE_VOL_MV		5500

#define WLS_CEP_ERR_MAX			3
#define WLS_RX_VOL_MAX_MV		20000
#define WLS_VOL_ADJUST_MAX		150
#define WLS_IBAT_MAX_MA			6000
#define WLS_CURR_ERR_MIN_MA		50

#define WLS_VOUT_DEFAULT_MV		5000
#define WLS_VOUT_EPP_MV			10000
#define WLS_VOUT_EPP_PLUS_MV		WLS_VOUT_EPP_MV
#define WLS_FASTCHG_MODE_VOL_MIN_MV	WLS_VOUT_EPP_MV
#define WLS_VOUT_FTM_MV			17000
#define WLS_VOUT_FASTCHG_INIT_MV	12000

#define WLS_CURR_WAIT_FAST_MA		300
#define WLS_CURR_STOP_CHG_MA		300
#define WLS_CURR_JEITA_CHG_MA		300
#define WLS_FASTCHG_CURR_50W_MAX_MA	2500
#define WLS_FASTCHG_CURR_45W_MAX_MA	2250
#define WLS_FASTCHG_CURR_40W_MAX_MA	2000
#define WLS_FASTCHG_CURR_30W_MAX_MA	1500
#define WLS_FASTCHG_CURR_20W_MAX_MA	1000
#define WLS_FASTCHG_CURR_15W_MAX_MA	800
#define WLS_FASTCHG_CURR_EXIT_MA	500
#define WLS_FASTCHG_CURR_ERR_MA		50
#define WLS_FASTCHG_CURR_MIN_MA		600
#define WLS_FASTCHG_CURR_DISCHG_MAX_MA	1000
#define WLS_FASTCHG_IOUT_CURR_MIN_MA	450

#define WLS_VOOC_PWR_MAX_MW		15000

#define WLS_MAX_STEP_CHG_ENTRIES	9
#define WLS_FOD_PARM_LEN_MAX		32
#define BCC_MAX_STEP_ENTRIES		5

#define WLS_SKIN_TEMP_MAX		500

#define WLS_BCC_STOP_CURR_NUM		5

#define WLS_SOC_NUM_MAX			3

#define CHARGE_FULL_FAN_THREOD_LO	350
#define CHARGE_FULL_FAN_THREOD_HI	380
#define QUIET_MODE_LED_BRIGHTNESS	3
#define QUIET_MODE_FAN_THR_SPEED	0

#define WLS_ADAPTER_MODEL_0		0x00
#define WLS_ADAPTER_MODEL_1		0x01
#define WLS_ADAPTER_MODEL_2		0x02
#define WLS_ADAPTER_MODEL_7		0x07
#define WLS_ADAPTER_MODEL_15		0x0F
#define WLS_ADAPTER_THIRD_PARTY		0x1F

#define WLS_AUTH_AES_RANDOM_LEN		16
#define WLS_AUTH_RANDOM_LEN		8
#define WLS_AUTH_ENCODE_LEN		8
#define WLS_AUTH_AES_ENCODE_LEN		16
#define WLS_ENCODE_MASK			3

#define WLS_RECEIVE_POWER_DEFAULT	12000
#define WLS_ADAPTER_POWER_45W_MAX_ID	4
#define WLS_RECEIVE_POWER_PD65W		50000

#define WLS_COOL_DOWN_LEVEL_MAX		32
#define WLS_BASE_NUM_MAX		32

#define WLS_QUIET_MODE_UNKOWN		-1
#define WLS_FASTCHG_MODE		0
#define WLS_SILENT_MODE			1
#define WLS_BATTERY_FULL_MODE		2
#define WLS_CALL_MODE			598
#define WLS_EXIT_CALL_MODE		599

#define FAN_PWM_PULSE_IN_SILENT_MODE			60
#define FAN_PWM_PULSE_IN_SILENT_MODE_DEFAULT		52
#define FAN_PWM_PULSE_IN_SILENT_MODE_V01		FAN_PWM_PULSE_IN_SILENT_MODE
#define FAN_PWM_PULSE_IN_SILENT_MODE_V02		FAN_PWM_PULSE_IN_SILENT_MODE_DEFAULT
#define FAN_PWM_PULSE_IN_SILENT_MODE_V03_07		FAN_PWM_PULSE_IN_SILENT_MODE_DEFAULT
#define FAN_PWM_PULSE_IN_SILENT_MODE_V08_15		40

#define FAN_PWM_PULSE_IN_FASTCHG_MODE			93
#define FAN_PWM_PULSE_IN_FASTCHG_MODE_DEFAULT		80
#define FAN_PWM_PULSE_IN_FASTCHG_MODE_V01		FAN_PWM_PULSE_IN_FASTCHG_MODE
#define FAN_PWM_PULSE_IN_FASTCHG_MODE_V02		FAN_PWM_PULSE_IN_FASTCHG_MODE_DEFAULT
#define FAN_PWM_PULSE_IN_FASTCHG_MODE_V03_07		FAN_PWM_PULSE_IN_FASTCHG_MODE_DEFAULT
#define FAN_PWM_PULSE_IN_FASTCHG_MODE_V08_15		70

#define FAN_PWM_PULSE_IN_SILENT_MODE_THR		(FAN_PWM_PULSE_IN_FASTCHG_MODE_V08_15 - 1)

#define CHG_CMD_DATA_LEN		256
#define CHG_CMD_TIME_MS			3000

enum wls_err_scene {
	WLS_ERR_SCENE_RX,
	WLS_ERR_SCENE_TX,
	WLS_ERR_SCENE_UPDATE,
};

static const char * const wls_err_scene_text[] = {
	[WLS_ERR_SCENE_RX] = "wls_rx_err",
	[WLS_ERR_SCENE_TX] = "wls_tx_err",
	[WLS_ERR_SCENE_UPDATE] = "wls_update_err",
};

enum oplus_chg_temp_region {
	BATT_TEMP_COLD = 0,	/*< -10*/
	BATT_TEMP_LITTLE_COLD,	/*-10-0*/
	BATT_TEMP_COOL,		/*0-5*/
	BATT_TEMP_LITTLE_COOL,	/*5-12*/
	BATT_TEMP_PRE_NORMAL,	/*12-16*/
	BATT_TEMP_NORMAL,	/*16-37.5*/
	BATT_TEMP_LITTLE_WARM,	/*37.5-44*/
	BATT_TEMP_WARM,		/*44-53*/
	BATT_TEMP_HOT,		/*>53*/
	BATT_TEMP_MAX,
};

enum oplus_chg_wls_rx_state {
	OPLUS_CHG_WLS_RX_STATE_DEFAULT,
	OPLUS_CHG_WLS_RX_STATE_BPP,
	OPLUS_CHG_WLS_RX_STATE_EPP,
	OPLUS_CHG_WLS_RX_STATE_EPP_PLUS,
	OPLUS_CHG_WLS_RX_STATE_FAST,
	OPLUS_CHG_WLS_RX_STATE_FFC,
	OPLUS_CHG_WLS_RX_STATE_DONE,
	OPLUS_CHG_WLS_RX_STATE_QUIET,
	OPLUS_CHG_WLS_RX_STATE_STOP,
	OPLUS_CHG_WLS_RX_STATE_DEBUG,
	OPLUS_CHG_WLS_RX_STATE_FTM,
	OPLUS_CHG_WLS_RX_STATE_ERROR,
};

enum oplus_chg_wls_fast_sub_state {
	OPLUS_CHG_WLS_FAST_SUB_STATE_INIT,
	OPLUS_CHG_WLS_FAST_SUB_STATE_WAIT_FAST,
	OPLUS_CHG_WLS_FAST_SUB_STATE_WAIT_IOUT,
	OPLUS_CHG_WLS_FAST_SUB_STATE_WAIT_VOUT,
	OPLUS_CHG_WLS_FAST_SUB_STATE_CHECK_IOUT,
	OPLUS_CHG_WLS_FAST_SUB_STATE_START,
};

enum oplus_chg_wls_trx_state {
	OPLUS_CHG_WLS_TRX_STATE_DEFAULT,
	OPLUS_CHG_WLS_TRX_STATE_READY,
	OPLUS_CHG_WLS_TRX_STATE_WAIT_PING,
	OPLUS_CHG_WLS_TRX_STATE_TRANSFER,
	OPLUS_CHG_WLS_TRX_STATE_OFF,
};

enum oplus_chg_wls_force_type {
	OPLUS_CHG_WLS_FORCE_TYPE_NOEN,
	OPLUS_CHG_WLS_FORCE_TYPE_BPP,
	OPLUS_CHG_WLS_FORCE_TYPE_EPP,
	OPLUS_CHG_WLS_FORCE_TYPE_EPP_PLUS,
	OPLUS_CHG_WLS_FORCE_TYPE_FAST,
	OPLUS_CHG_WLS_FORCE_TYPE_AUTO,
};

enum oplus_chg_wls_path_ctrl_type {
	OPLUS_CHG_WLS_PATH_CTRL_TYPE_DISABLE_ALL,
	OPLUS_CHG_WLS_PATH_CTRL_TYPE_ENABLE_NOR,
	OPLUS_CHG_WLS_PATH_CTRL_TYPE_DISABLE_NOR,
	OPLUS_CHG_WLS_PATH_CTRL_TYPE_ENABLE_FAST,
	OPLUS_CHG_WLS_PATH_CTRL_TYPE_DISABLE_FAST,
};

enum oplus_chg_wls_chg_mode {
	OPLUS_WLS_CHG_MODE_BPP,
	OPLUS_WLS_CHG_MODE_EPP,
	OPLUS_WLS_CHG_MODE_EPP_PLUS,
	OPLUS_WLS_CHG_MODE_AIRVOOC,
	OPLUS_WLS_CHG_MODE_AIRSVOOC,
	OPLUS_WLS_CHG_MODE_MAX,
};

enum oplus_chg_wls_batt_cl {
	OPLUS_WLS_CHG_BATT_CL_LOW,
	OPLUS_WLS_CHG_BATT_CL_HIGH,
	OPLUS_WLS_CHG_BATT_CL_MAX,
};

enum wls_status_keep_type {
	WLS_SK_NULL,
	WLS_SK_BY_KERNEL,
	WLS_SK_BY_HAL,
	WLS_SK_WAIT_TIMEOUT,
};

enum {
	WLS_VINDPM_DEFAULT,
	WLS_VINDPM_BPP,
	WLS_VINDPM_EPP,
	WLS_VINDPM_AIRVOOC,
	WLS_VINDPM_AIRSVOOC,
};

enum wls_dev_cmd_type {
	WLS_DEV_CMD_WLS_AUTH,
	WLS_DEV_CMD_FOD_PARAM,
};

enum {
	WLS_FAST_TEMP_0_TO_50,
	WLS_FAST_TEMP_50_TO_120,
	WLS_FAST_TEMP_120_TO_160,
	WLS_FAST_TEMP_160_TO_400,
	WLS_FAST_TEMP_400_TO_440,
	WLS_FAST_TEMP_MAX,
};

enum {
	WLS_FAST_SOC_0_TO_30,
	WLS_FAST_SOC_30_TO_70,
	WLS_FAST_SOC_70_TO_90,
	WLS_FAST_SOC_MAX,
};

enum {
	OPLUS_WLS_SKEWING_EPP,
	OPLUS_WLS_SKEWING_EPP_PLUS,
	OPLUS_WLS_SKEWING_AIRVOOC,
	OPLUS_WLS_SKEWING_MAX,
};

enum {
	WLS_BCC_TEMP_0_TO_50,
	WLS_BCC_TEMP_50_TO_120,
	WLS_BCC_TEMP_120_TO_160,
	WLS_BCC_TEMP_160_TO_400,
	WLS_BCC_TEMP_400_TO_440,
	WLS_BCC_TEMP_MAX,
};

enum {
	WLS_BCC_STOP_0_TO_30,
	WLS_BCC_STOP_30_TO_70,
	WLS_BCC_STOP_70_TO_90,
	WLS_BCC_STOP_MAX,
};

enum {
	WLS_BCC_SOC_0_TO_30,
	WLS_BCC_SOC_30_TO_70,
	WLS_BCC_SOC_70_TO_90,
	WLS_BCC_SOC_MAX,
};

enum oplus_chg_cmd_type {
	CMD_WLS_THIRD_PART_AUTH,
	CMD_UPDATE_UI_SOH,
	CMD_INIT_UI_SOH,
};

enum oplus_chg_cmd_error {
	CMD_ACK_OK,
	CMD_ERROR_CHIP_NULL,
	CMD_ERROR_DATA_NULL,
	CMD_ERROR_DATA_INVALID,
	CMD_ERROR_HIDL_NOT_READY,
	CMD_ERROR_TIME_OUT,
};

enum wls_topic_item {
	WLS_ITEM_PRESENT,
	WLS_ITEM_ONLINE,
	WLS_ITEM_VOUT,
	WLS_ITEM_IOUT,
	WLS_ITEM_WLS_TYPE,
	WLS_ITEM_REAL_TYPE,
	WLS_ITEM_STATUS_KEEP,
	WLS_ITEM_DOCK_TYPE,
	WLS_ITEM_MAX_POWER,
	WLS_ITEM_FASTCHG_STATUS,
	WLS_ITEM_BCC_MAX_CURR,
	WLS_ITEM_BCC_MIN_CURR,
	WLS_ITEM_BCC_EXIT_CURR,
	WLS_ITEM_BCC_TEMP_RANGE,
};

#ifdef OPLUS_CHG_DEBUG
ssize_t oplus_chg_wls_upgrade_fw_show(struct oplus_mms *mms, char *buf);
ssize_t oplus_chg_wls_upgrade_fw_store(struct oplus_mms *mms, const char *buf, size_t count);
#endif

int oplus_chg_wls_set_status_keep(struct oplus_mms *mms, enum wls_status_keep_type status_keep);
int oplus_chg_wls_get_break_sub_crux_info(struct oplus_mms *mms, char *crux_info);
ssize_t oplus_chg_wls_send_mutual_cmd(struct oplus_mms *mms, char *buf);
void oplus_chg_wls_response_mutual_cmd(struct oplus_mms *mms, const char *buf, size_t count);
#endif /* __OPLUS_CHG_WLS_H__ */