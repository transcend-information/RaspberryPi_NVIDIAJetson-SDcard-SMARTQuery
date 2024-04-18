/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 021110-1307, USA.
 *
 * Modified to add field firmware update support,
 * those modifications are Copyright (c) 2016 SanDisk Corp.
 */

/* mmc_cmds.c */
int do_read_extcsd(int nargs, char **argv);
int do_write_extcsd(int nargs, char **argv);
int do_writeprotect_boot_get(int nargs, char **argv);
int do_writeprotect_boot_set(int nargs, char **argv);
int do_writeprotect_user_get(int nargs, char **argv);
int do_writeprotect_user_set(int nargs, char **argv);
int do_disable_512B_emulation(int nargs, char **argv);
int do_write_boot_en(int nargs, char **argv);
int do_boot_bus_conditions_set(int nargs, char **argv);
int do_write_bkops_en(int nargs, char **argv);
int do_hwreset_en(int nargs, char **argv);
int do_hwreset_dis(int nargs, char **argv);
int do_sanitize(int nargs, char **argv);
int do_status_get(int nargs, char **argv);
int do_create_gp_partition(int nargs, char **argv);
int do_enh_area_set(int nargs, char **argv);
int do_write_reliability_set(int nargs, char **argv);
int do_rpmb_write_key(int nargs, char **argv);
int do_rpmb_read_counter(int nargs, char **argv);
int do_rpmb_read_block(int nargs, char **argv);
int do_rpmb_write_block(int nargs, char **argv);
int do_cache_en(int nargs, char **argv);
int do_cache_dis(int nargs, char **argv);
int do_ffu(int nargs, char **argv);
int do_read_scr(int argc, char **argv);
int do_read_cid(int argc, char **argv);
int do_read_csd(int argc, char **argv);
int do_erase(int nargs, char **argv);
int do_general_cmd_read(int nargs, char **argv);
int do_softreset(int nargs, char **argv);
int do_preidle(int nargs, char **argv);
int do_alt_boot_op(int nargs, char **argv);


/* CID */
typedef struct cid_info {
	unsigned int mid;			// Manufacturer ID
	char sd_oid[3];				// OEM/Application ID
	unsigned int mmc_oid; 		// OEM/Application ID
	char pnm[7];				// Product Name
	unsigned int prv_major;		// Product Revision
	unsigned int prv_minor;		// Product Revision
	unsigned int psn;			// Serial Number
	unsigned int mdt_month;		// Manufacture Date Code
	unsigned int mdt_year;		// Manufacture Date Code
	unsigned int crc;			// CRC7 checksum
	unsigned int cbx;			// MMC specific
	char *manufacturer;
	char *type;
}CIDInfo;

/* SD SMART */
int do_SMART_buffer_dump(int nargs, char **argv); //Show SMART raw buffer
int show_SMART_info(int nargs, char **argv); //Show SMART info
int show_Health_info(int nargs, char **argv); //Show Health info
int show_df_info(char *device);
int show_product_id(char *device);
int is_transcend_reader(char *device);
int SCSI_CMD56(int *fd, char *block_data_buff);
int SCSI_CMD10(int *fd, char *block_data_buff);
int show_CID_info(int nargs, char **argv);
int show_SCSI_CID(int nargs, char **argv);
int process_cid(char *cid, char *type, CIDInfo *cid_info);//decode cid
int CMD56_data_in(int fd, int argCmd56, char *block_data_buff);
void dump_smart_data(char *block_data_buff);
void is_transcend_card(char *block_data_buff, char function);
void parsing_SMART_info(char *block_data_buff);
void parsing_Health_info(char *block_data_buff);
char* get_cid(char *dir, char *type);//Get cid info
char *read_file(char *name);
char *grabString(char* data, int start_pos, int length);
char *grabHex(char* data, int start_pos, int length);
double hexArrToDec(char *data, int start_pos, int length);