/* Target dependent code for ARC700, for GDB, the GNU debugger.

   Copyright 2005 Free Software Foundation, Inc.

   Contributed by ARC International (www.arc.com)

   Authors:
      Richard Stuckey <richard.stuckey@arc.com>

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

/******************************************************************************/
/*                                                                            */
/* Outline:                                                                   */
/*     This header file defines the initialization function for this module.  */
/*                                                                            */
/*     All the facilities of this module are accessed via information stored  */
/*     in the gdbarch structure by this function.                             */
/*                                                                            */
/******************************************************************************/

#ifndef ARC_JTAG_TDEP_H
#define ARC_JTAG_TDEP_H

struct gdbarch *arc_jtag_init (struct gdbarch *gdbarch);


#endif /* ARC_JTAG_TDEP_H */
/******************************************************************************/
