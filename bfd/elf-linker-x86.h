/* x86-specific ELF linker support between ld and bfd.
   Copyright (C) 2019 Free Software Foundation, Inc.

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

/* Used to pass x86-specific linker options from ld to bfd.  */
struct elf_linker_x86_params
{
  /* TRUE if BND prefix in PLT entries is always generated.  */
  unsigned int bndplt: 1;

  /* TRUE if IBT-enabled PLT entries should be generated.  */
  unsigned int ibtplt: 1;

  /* TRUE if GNU_PROPERTY_X86_FEATURE_1_IBT should be generated.  */
  unsigned int ibt: 1;

  /* TRUE if GNU_PROPERTY_X86_FEATURE_1_SHSTK should be generated.  */
  unsigned int shstk: 1;

  /* TRUE if we shouldn't check relocation overflow.  */
  unsigned int no_reloc_overflow_check: 1;

  /* TRUE if generate a 1-byte NOP as suffix for x86 call instruction.  */
  unsigned int call_nop_as_suffix : 1;

  /* The 1-byte NOP for x86 call instruction.  */
  char call_nop_byte;
};

extern void _bfd_elf_linker_x86_set_options
  (struct bfd_link_info *, struct elf_linker_x86_params *);