ENTRY(_vectab)


MEMORY
{
    /* of the 128K flash, the last 8K is reserved just for constants. this allows 
     * calibration values to be added as constants and then simply flash just the
     * last 8K to update the calibration.
     * of the now remaining 120K, 2K is reserved for simulated EEPROM, so this is in the 
     * range:  0x0801D800..0x0801DFFF
     */
    FLASH_TEXT (rx)  : ORIGIN = 0x08004000, LENGTH = 102K
    FLASH_CONST (rx) : ORIGIN = 0x0801E000, LENGTH = 8K
    SRAM (rwx)       : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    __STACKSIZE__ = 1500;
    /* heap configured as 0 because this is the newlib heap. The FreeRTOS memory
     * management functions should be used.
     */
    __HEAPSIZE__  = 0;

    .text :
    {
        KEEP(*(.isr_vector))
        *(.text.cs3.init)
        *(.text .text.* .gnu.linkonce.t.*)
        *(.plt)
        *(.gnu.warning)
        *(.glue_7t) *(.glue_7) *(.vfp11_veneer)
        *(.ARM.extab* .gnu.linkonce.armextab.*)
        *(.gcc_except_table)
    } > FLASH_TEXT

    .eh_frame_hdr : ALIGN (4)
    {
      KEEP (*(.eh_frame_hdr))
      *(.eh_frame_entry .eh_frame_entry.*)
    } > FLASH_TEXT
  
    .eh_frame : ALIGN (4)
    {
      KEEP (*(.eh_frame)) *(.eh_frame.*)
    } > FLASH_TEXT

    /* .ARM.exidx is sorted, so has to go in its own output section.  */
    PROVIDE_HIDDEN (__exidx_start = .);
    .ARM.exidx :
    {
      *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > FLASH_TEXT
    PROVIDE_HIDDEN (__exidx_end = .);

    .constdata : ALIGN (4)
    {
      *(.rodata .rodata.* .gnu.linkonce.r.*)
    } > FLASH_CONST
    
    
    .rodata : ALIGN (4)
    {

    . = ALIGN(4);
    KEEP(*(.init))

    . = ALIGN(4);
    __preinit_array_start = .;
    KEEP (*(.preinit_array))
    __preinit_array_end = .;

    . = ALIGN(4);
    __init_array_start = .;
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array))
    __init_array_end = .;

    . = ALIGN(4);
    KEEP(*(.fini))

    . = ALIGN(4);
    __fini_array_start = .;
    KEEP (*(.fini_array))
    KEEP (*(SORT(.fini_array.*)))
    __fini_array_end = .;

    . = ALIGN(0x4);
    KEEP (*crtbegin.o(.ctors))
    KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*crtend.o(.ctors))

    . = ALIGN(0x4);
    KEEP (*crtbegin.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*crtend.o(.dtors))

    . = ALIGN (8);
    *(.rom)
    *(.rom.b .bss.rom)
        _etext = .;
    } > FLASH_TEXT


    .data : ALIGN (8)
    {
        _data = .;
        KEEP(*(.jcr))
        *(.got.plt) *(.got)
        *(.shdata)
        *(vtable)
        *(.data .data.* .gnu.linkonce.d.*)
        . = ALIGN (8);
        *(.ram)
        . = ALIGN (8);
        _edata = .;
    } > SRAM AT> FLASH_TEXT


    .bss : ALIGN (8)
    {
        _bss = .;
        *(.shbss)
        *(.bss .bss.* .gnu.linkonce.b.*)
        *(COMMON)
        . = ALIGN (8);
        *(.ram.b .bss.ram)
        _ebss = .;
        _heap = .;
        . = ALIGN(MAX(_heap + __HEAPSIZE__ , .), 4);
        _eheap = .;
        _stack = .;
        . = ALIGN(MAX(_stack + __STACKSIZE__ , .), 4);
        _estack = .;
        . = ALIGN (8);
        _end = .;
        __end = .;
    } > SRAM AT> FLASH_TEXT


  .stab 0 (NOLOAD) : { *(.stab) }
  .stabstr 0 (NOLOAD) : { *(.stabstr) }
  /* DWARF debug sections.
   * Symbols in the DWARF debugging sections are relative to
   * the beginning of the section so we begin them at 0.
   */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
  /* DWARF 2.1 */
  .debug_ranges   0 : { *(.debug_ranges) }
  /* SGI/MIPS DWARF 2 extensions */
  .debug_weaknames 0 : { *(.debug_weaknames) }
  .debug_funcnames 0 : { *(.debug_funcnames) }
  .debug_typenames 0 : { *(.debug_typenames) }
  .debug_varnames  0 : { *(.debug_varnames) }

  .note.gnu.arm.ident 0 : { KEEP (*(.note.gnu.arm.ident)) }
  .ARM.attributes 0 : { KEEP (*(.ARM.attributes)) }
  /DISCARD/ : { *(.note.GNU-stack) }
}


