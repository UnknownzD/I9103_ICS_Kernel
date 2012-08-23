/*
 * arch/arm/mach-tegra/include/mach/tegra_das.h
 *
 * Declarations of Tegra Digital Audio Switch (das)
 *
 * Copyright (c) 2010-2011, NVIDIA Corporation.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __MACH_TEGRA_DAS_H
#define __MACH_TEGRA_DAS_H

#include <linux/kernel.h>

#define APB_MISC_DAS_DAP_CTRL_SEL_0			(0xc00)
#define APB_MISC_DAS_DAP_CTRL_SEL_1			(0xc04)
#define APB_MISC_DAS_DAP_CTRL_SEL_2			(0xc08)
#define APB_MISC_DAS_DAP_CTRL_SEL_3			(0xc0c)
#define APB_MISC_DAS_DAP_CTRL_SEL_4			(0xc10)
#define APB_MISC_DAS_DAC_INPUT_DATA_CLK_SEL_0		(0xc40)
#define APB_MISC_DAS_DAC_INPUT_DATA_CLK_SEL_1		(0xc44)
#define APB_MISC_DAS_DAC_INPUT_DATA_CLK_SEL_2		(0xc48)
#ifdef CONFIG_MACH_N1
#define APB_MISC_DAS_DAC_INPUT_DATA_CLK_SEL_3		(0xc4c)

/*DAP control register bit*/
#define DAP_MS_SEL_SLAVE	(0<<31)
#define DAP_MS_SEL_MASTER	(1<<31)
#define DAP_SDATA1_TX		(0<<30)
#define DAP_SDATA1_RX		(1<<30)
#define DAP_SDATA2_TX		(0<<29)
#define DAP_SDATA2_RX		(1<<29)
#endif
#define DAP_MS_SEL_SHIFT		(31)
#define DAP_MS_SEL_DEFAULT_MASK		(0x1)
#define DAP_SDATA1_TX_RX_SHIFT		(30)
#define DAP_SDATA1_TX_RX_DEFAULT_MASK	(0x1)
#define DAP_SDATA2_RX_TX_SHIFT		(29)
#define DAP_SDATA2_RX_TX_DEFAULT_MASK	(0x1)
#define DAP_CTRL_SEL_SHIFT		(0)
#define DAP_CTRL_SEL_DEFAULT_MASK	(0x1f)

#define DAC_SDATA2_SEL_SHIFT		(28)
#define DAC_SDATA2_SEL_DEFAULT_MASK	(0xf)
#define DAC_SDATA1_SEL_SHIFT		(24)
#define DAC_SDATA1_SEL_DEFAULT_MASK	(0xf)
#define DAC_CLK_SEL_SHIFT		(0)
#define DAC_CLK_SEL_DEFAULT_MASK	(0xf)
#ifdef CONFIG_MACH_N1
/*DAC input data selection bit*/
#define DAC_SDATA2_SEL_DAP1	(0<<28)
#define DAC_SDATA2_SEL_DAP2	(1<<28)
#define DAC_SDATA2_SEL_DAP3	(2<<28)
#define DAC_SDATA2_SEL_DAP4	(3<<28)
#define DAC_SDATA2_SEL_DAP5	(4<<28)
#define DAC_SDATA1_SEL_DAP1	(0<<24)
#define DAC_SDATA1_SEL_DAP2	(1<<24)
#define DAC_SDATA1_SEL_DAP3	(2<<24)
#define DAC_SDATA1_SEL_DAP4	(3<<24)
#define DAC_SDATA1_SEL_DAP5	(4<<24)

#define DAC_CLK_SEL_DAP1	0
#define DAC_CLK_SEL_DAP2	1
#define DAC_CLK_SEL_DAP3	2
#define DAC_CLK_SEL_DAP4	3
#define DAC_CLK_SEL_DAP5	4
#endif

#define DAP_CTRL_SEL_DAC1		(0)
#define DAP_CTRL_SEL_DAC2		(1)
#define DAP_CTRL_SEL_DAC3		(2)
#define DAP_CTRL_SEL_DAP1		(16)
#define DAP_CTRL_SEL_DAP2		(17)
#define DAP_CTRL_SEL_DAP3		(18)
#define DAP_CTRL_SEL_DAP4		(19)
#define DAP_CTRL_SEL_DAP5		(20)

#define MAX_CONNECTIONLINES 8

enum tegra_das_port_type {
	tegra_das_port_none = 0,
	tegra_das_port_dap1,
	tegra_das_port_dap2,
	tegra_das_port_dap3,
	tegra_das_port_dap4,
	tegra_das_port_dap5,
	tegra_das_port_i2s1,
	tegra_das_port_i2s2,
	tegra_das_port_ac97
};

#define MAX_DAP_PORTS	(tegra_das_port_dap5 + 1)

/* defines possible hardware connected to DAP */
enum tegra_audio_codec_type {
	tegra_audio_codec_type_none = 0,
	tegra_audio_codec_type_hifi,
	tegra_audio_codec_type_voice,
	tegra_audio_codec_type_bluetooth,
	tegra_audio_codec_type_baseband,
	tegra_audio_codec_type_fm_radio,
};

/* index for possible connection based on the use case */
enum tegra_das_port_con_id {
	tegra_das_port_con_id_none = 0,
	tegra_das_port_con_id_hifi,
	tegra_das_port_con_id_voice,
	tegra_das_port_con_id_analog_radio,
	tegra_das_port_con_id_digital_radio,
	tegra_das_port_con_id_bt_codec,
	tegra_das_port_con_id_voicecall_no_bt,
	tegra_das_port_con_id_voicecall_no_bt_record,
	tegra_das_port_con_id_voicecall_with_bt,
	tegra_das_port_con_id_voicecall_with_bt_record,

	tegra_das_port_con_id_max
};

/* possible list of input/output devices */
#define audio_dev_none			(0x0)
#define audio_dev_all			(0xffffffff)

/* Inputs */
#define audio_dev_builtin_mic		(0x1)
#define audio_dev_mic			(0x2)
#define audio_dev_lineIn		(0x4)

/* Outputs */
#define audio_dev_speaker		(0x100)
#define audio_dev_earpiece		(0x200)
#define audio_dev_lineout		(0x400)
#define audio_dev_headphone		(0x800)
#define audio_dev_bt_a2dp		(0x1000)

/* Both */
#define audio_dev_aux			(0x10000)
#define audio_dev_headset		(0x20000)
#define audio_dev_radio			(0x40000)
#define audio_dev_bt_sco		(0x80000)

/* data format supported */
enum dac_dap_data_format {
	dac_dap_data_format_none = 0x0,
	dac_dap_data_format_i2s = 0x1,
	dac_dap_data_format_dsp = 0x2,
	dac_dap_data_format_rjm = 0x4,
	dac_dap_data_format_ljm = 0x8,

	dac_dap_data_format_all = 0x7FFFFFFF
};

struct audio_dev_property {
	unsigned int num_channels;
	unsigned int bits_per_sample;
	unsigned int rate;
	unsigned int dac_dap_data_comm_format;
};

/*
 * structure which contains dap endpoint
 * dac_port contains dac port for particular dap and
 * codec_type contains possible codec which can be connected to dap port
 */
struct tegra_dap_property {
	enum tegra_das_port_type dac_port;
	enum tegra_das_port_type dap_port;
	enum  tegra_audio_codec_type codec_type;
	struct audio_dev_property device_property;
};

struct tegra_das_con_line {
	enum tegra_das_port_type src;
	enum tegra_das_port_type dest;
	bool src_master;
};

struct tegra_das_con {
	enum tegra_das_port_con_id con_id;
	unsigned int num_entries;
	struct tegra_das_con_line con_line[MAX_CONNECTIONLINES];
};

struct tegra_das_platform_data {
	void *driver_data;
	const char *dap_clk;
	const struct tegra_dap_property
			tegra_dap_port_info_table[MAX_DAP_PORTS];
	const struct tegra_das_con tegra_das_con_table[MAX_DAP_PORTS];
};

struct tegra_das_mux_select {
	enum tegra_das_port_type port_type;
	u32 reg_offset;
	u32 mux_mask;
	u32 mux_shift;
	u32 sdata1_mask;
	u32 sdata1_shift;
	u32 sdata2_mask;
	u32 sdata2_shift;
	u32 ms_mode_mask;
	u32 ms_mode_shift;
	u32 mux_value;
};

struct das_regs_cache {
	u32 das_dap_ctrl_0;
	u32 das_dap_ctrl_1;
	u32 das_dap_ctrl_2;
	u32 das_dap_ctrl_3;
	u32 das_dap_ctrl_4;
	u32 das_dac_input_data_clk_0;
	u32 das_dac_input_data_clk_1;
	u32 das_dac_input_data_clk_2;
};

enum dap_connection_status {
	dap_connection_codec_slave,
	dap_connection_codec_master,
	dap_connection_bt_call,
	dap_connection_bt_voip,
	dap_connection_bt_call_nomix,
};


int tegra_das_open(void);

int tegra_das_close(void);

/*
 * Function to make connections between dac and dap.
 * con_id specifies the enum depending on the required port connections
 * enable, if true do connections else disconnect
 */
int tegra_das_set_connection(enum tegra_das_port_con_id new_con_id);

/*
 * Function to get current port connection for das
 */
int tegra_das_get_connection(void);

/*
 * Function to query if certain das port need to be
 * configured as master for current das connection
 */
bool tegra_das_is_port_master(enum tegra_audio_codec_type codec_type);

/*
 * Function to get data format for certain codec for current das connection
 */
int tegra_das_get_codec_data_fmt(enum tegra_audio_codec_type codec_type);

/*
 * Function to get dap Mclk handle
 */
struct clk *tegra_das_get_dap_mclk(void);

/*
 * Function to set power state on das's dap port
 * if is_normal is true then power mode is normal else tristated
 */
int tegra_das_power_mode(bool is_normal);

/*
 * Function to get the content of all the das registers
 */
void tegra_das_get_all_regs(struct das_regs_cache *regs);

/*
 * Function to set values in all the das registers
 */
void tegra_das_set_all_regs(struct das_regs_cache *regs);

#endif
