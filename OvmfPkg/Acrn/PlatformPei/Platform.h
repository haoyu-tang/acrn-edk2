/** @file
  Platform PEI module include file.

  Copyright (c) 2020, Rebecca Cran <rebecca@bsdio.com>
  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _PLATFORM_PEI_H_INCLUDED_
#define _PLATFORM_PEI_H_INCLUDED_

#include <IndustryStandard/E820.h>

VOID
AddIoMemoryBaseSizeHob (
  EFI_PHYSICAL_ADDRESS  MemoryBase,
  UINT64                MemorySize
  );

VOID
AddIoMemoryRangeHob (
  EFI_PHYSICAL_ADDRESS  MemoryBase,
  EFI_PHYSICAL_ADDRESS  MemoryLimit
  );

VOID
AddMemoryBaseSizeHob (
  EFI_PHYSICAL_ADDRESS  MemoryBase,
  UINT64                MemorySize
  );

VOID
AddMemoryRangeHob (
  EFI_PHYSICAL_ADDRESS  MemoryBase,
  EFI_PHYSICAL_ADDRESS  MemoryLimit
  );

VOID
AddReservedMemoryBaseSizeHob (
  EFI_PHYSICAL_ADDRESS  MemoryBase,
  UINT64                MemorySize,
  BOOLEAN               Cacheable
  );

VOID
AddressWidthInitialization (
  VOID
  );

VOID
Q35TsegMbytesInitialization (
  VOID
  );

VOID
Q35SmramAtDefaultSmbaseInitialization (
  VOID
  );

EFI_STATUS
PublishPeiMemory (
  VOID
  );

UINT32
GetSystemMemorySizeBelow4gb (
  VOID
  );

VOID
QemuUc32BaseInitialization (
  VOID
  );

VOID
InitializeRamRegions (
  VOID
  );

EFI_STATUS
PeiFvInitialization (
  VOID
  );

VOID
MemTypeInfoInitialization (
  VOID
  );

VOID
InstallFeatureControlCallback (
  VOID
  );

VOID
InstallClearCacheCallback (
  VOID
  );

EFI_STATUS
InitializeXen (
  VOID
  );

BOOLEAN
XenDetect (
  VOID
  );

VOID
AmdSevInitialize (
  VOID
  );

extern BOOLEAN  mXen;

VOID
XenPublishRamRegions (
  VOID
  );

RETURN_STATUS
AcrnGetSystemMemorySizeBelow4gb (
  OUT  UINT32               *MemSize
  );

RETURN_STATUS
AcrnGetSystemMemorySizeAbove4gb (
  OUT  UINT64               *MemSize
  );

extern EFI_BOOT_MODE  mBootMode;

extern BOOLEAN  mS3Supported;

extern UINT8  mPhysMemAddressWidth;

extern UINT32  mMaxCpuCount;

extern UINT16  mHostBridgeDevId;

extern BOOLEAN  mQ35SmramAtDefaultSmbase;

extern UINT32  mQemuUc32Base;

RETURN_STATUS
AcrnGetFirstNonAddress (
  OUT  UINT64               *MaxAddress
  );

RETURN_STATUS
AcrnFindPciMmio64Aperture (
  OUT  UINT64               *Pci64Base,
  OUT  UINT64               *Pci64Size
  );

RETURN_STATUS
AcrnPublishRamRegions (
  VOID
  );

#endif // _PLATFORM_PEI_H_INCLUDED_
