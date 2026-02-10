/** @file
  Provide InternalAcpiGetTimerTick for the acrn instance of the
  Base ACPI Timer Library

  Copyright (C) 2020, Rebecca Cran <rebecca@bsdio.com>
  Copyright (C) 2014, Gabriel L. Somlo <somlo@cmu.edu>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <Library/IoLib.h>
#include <OvmfPlatforms.h>

/**
  Internal function to read the current tick counter of ACPI.

  Read the current ACPI tick counter using the counter address cached
  by this instance's constructor.

  @return The tick counter read.

**/
UINT32
InternalAcpiGetTimerTick (
  VOID
  )
{
  //
  // Return the current ACPI timer value.
  //
  return IoRead32 (ACRN_ACPI_TIMER_IO_ADDR);
}
