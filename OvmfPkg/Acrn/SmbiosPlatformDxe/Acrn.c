/*
 * Copyright (c) 2020, Rebecca Cran <rebecca@bsdio.com>
 * Copyright (c) 2014, Pluribus Networks, Inc.
 *
 * SPDX-License-Identifier: BSD-2-Clause-Patent
 */

#include "SmbiosPlatformDxe.h"

#define ACRN_SMBIOS_PHYSICAL_ADDRESS  0x000F0000
#define ACRN_SMBIOS_PHYSICAL_END      0x000FFFFF

/**
  Locates the acrn SMBIOS data if it exists

  @return SMBIOS_TABLE_ENTRY_POINT   Address of acrn SMBIOS data

**/
SMBIOS_TABLE_ENTRY_POINT *
GetAcrnSmbiosTables (
  VOID
  )
{
  UINT8                     *AcrnSmbiosPtr;
  SMBIOS_TABLE_ENTRY_POINT  *AcrnSmbiosEntryPointStructure;

  for (AcrnSmbiosPtr = (UINT8 *)(UINTN)ACRN_SMBIOS_PHYSICAL_ADDRESS;
       AcrnSmbiosPtr < (UINT8 *)(UINTN)ACRN_SMBIOS_PHYSICAL_END;
       AcrnSmbiosPtr += 0x10)
  {
    AcrnSmbiosEntryPointStructure = (SMBIOS_TABLE_ENTRY_POINT *)AcrnSmbiosPtr;

    if (!AsciiStrnCmp ((CHAR8 *)AcrnSmbiosEntryPointStructure->AnchorString, "_SM_", 4) &&
        !AsciiStrnCmp ((CHAR8 *)AcrnSmbiosEntryPointStructure->IntermediateAnchorString, "_DMI_", 5) &&
        IsEntryPointStructureValid (AcrnSmbiosEntryPointStructure))
    {
      return AcrnSmbiosEntryPointStructure;
    }
  }

  return NULL;
}
