/* Disassembler structures definitions for the ARC.
   Copyright 1994, 1995, 1997, 1998, 2000, 2001
   Free Software Foundation, Inc.
   Copyright 2007 ARC International (UK) LTD
   Contributed by Doug Evans (dje@cygnus.com).

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */

#ifndef ARCDIS_H
#define ARCDIS_H

int ARCTangent_decodeInstr(bfd_vma address, disassemble_info* info);
int ARCompact_decodeInstr (bfd_vma address, disassemble_info* info);

#define __TRANSLATION_REQUIRED(state)	((state).acnt != 0)

#endif
