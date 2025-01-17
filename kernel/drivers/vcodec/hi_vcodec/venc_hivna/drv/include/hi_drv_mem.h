/*
* Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.
*
* File Name     : hi_type.h
* Version       : Initial Draft
* Author        : Hisilicon multimedia software group
* Created       : 2005/4/23
*
* Last Modified :
* Description   : The common data type defination
* Function List :
*
* History       :
* 1.Date        : 2008/06/28
* Author      : c42025
* Modification: modified definition for HI_S8
*
* 2.Date        :   2008/10/31
* Author      :   z44949
* Modification:   Translate the chinese comment
*/
#ifndef __HI_MEM_H__
#define __HI_MEM_H__
#include "hi_type.h"
#include <linux/seq_file.h>
#include <linux/vmalloc.h>
#include <linux/hisi/hisi_ion.h>

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define MAX_MEM_NAME_LEN       (15)
#define MAX_KMALLOC_MEM_NODE   (16)    // 1 channel need 2 node ,there is have max 8 channels .
#define SMMU_RWERRADDR_SIZE    (128)

typedef struct
{
    HI_VOID* pStartVirAddr;
    HI_U64   u64StartPhyAddr;
    HI_U32   u32Size;
}MEM_BUFFER_S;

struct venc_mem_buf {
        HI_CHAR          node_name[MAX_MEM_NAME_LEN];
        HI_CHAR          zone_name[MAX_MEM_NAME_LEN];
        HI_VOID*         virt_addr;
        HI_U64           phys_addr;
        HI_U32           size;
};

/***********************************************************************************
    memory menage relative functions
***********************************************************************************/
HI_S32 HI_DRV_UserCopy(struct file *file, HI_U32 cmd, unsigned long arg, long (*func)(struct file *file, HI_U32 cmd, unsigned long uarg));

/**************************************platform.h**************************************************/
HI_S32 DRV_MEM_INIT(HI_VOID);
HI_S32 DRV_MEM_EXIT(HI_VOID);
HI_S32 DRV_MEM_KAlloc(const HI_CHAR* bufName, const HI_CHAR *zone_name, MEM_BUFFER_S *psMBuf);
HI_S32 DRV_MEM_KFree(const MEM_BUFFER_S *psMBuf);

/**************************************************************************************/

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_TYPE_H__ */


